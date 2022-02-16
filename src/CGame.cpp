#include "CGame.h"

CGame::CGame(size_t width, size_t height) : m_Width(width), m_Height(height), m_State(EGameState::INITIALIZED),
                                            m_Paddle(CCoords{m_Width / 2 - (m_Width / 5) / 2, m_Height - m_Height / 10},
                                                     m_Width / 5, m_Height / 25,
                                                     CColor{70, 165, 165}),
                                            m_CurrentLevel(0) {
}

CGame::CGame(const CGame &other)
        : m_Width(other.m_Width), m_Height(other.m_Height), m_Score(other.m_Score), m_State(other.m_State),
          m_Paddle(other.m_Paddle), m_Balls(other.m_Balls), m_Levels(other.m_Levels),
          m_CurrentLevel(other.m_CurrentLevel) {
    for (auto &modifier: other.m_Modifiers)
        m_Modifiers.push_back(modifier->clone());
}

CGame &CGame::operator=(CGame const &other) {
    if (this != &other) {
        for (auto &modifier: other.m_Modifiers)
            m_Modifiers.push_back(modifier->clone());
        m_Width = other.m_Width;
        m_Height = other.m_Height;
        m_Score = other.m_Score;
        m_State = other.m_State;
        m_Paddle = other.m_Paddle;
        m_Balls = other.m_Balls;
    }
    return *this;
}

int CGame::getScore() const {
    return m_Score;
}

bool CGame::isRunning() const {
    return m_State == EGameState::RUNNING;
}

void CGame::reset() {
    for (auto &modifier: m_Modifiers)
        if (modifier->isApplied())
            modifier->revert();
    m_Modifiers.clear();

    m_Balls.clear();
    m_Balls.emplace_back(CCoords{m_Width / 2 - (m_Height / 60) / 2, m_Height - 80}, 0, 0, m_Height / 60,
                         CColor{0, 0, 0}, m_Height / 80);

    m_Paddle.setPos(CCoords{m_Width / 2 - m_Paddle.getWidth() / 2, m_Paddle.getPos().m_Y});

    m_Paddle.m_Lives.clear();
    m_CurrentLevel = 0;
    m_Score = 0;

    for (auto &level: m_Levels)
        level.resetBricks();

    for (int i = 0; i < 3; ++i)
        m_Paddle.m_Lives.emplace_back(CCoords{i * m_Height / 20, m_Height - m_Height / 20}, m_Height / 20,
                                      m_Height / 20, CColor{255, 0, 0});

    m_State = EGameState::RUNNING;
}

void CGame::draw(CRenderer &renderer) const {
    m_Levels[m_CurrentLevel].draw(renderer);

    m_Paddle.draw(renderer.getRenderer());

    for (auto &ball: m_Balls)
        ball.draw(renderer.getRenderer());

    for (auto &modifier: m_Modifiers) {
        if (!modifier->isApplied())
            modifier->draw(renderer.getRenderer());
    }

    for (auto &life: m_Paddle.m_Lives)
        life.draw(renderer.getRenderer());
}

void CGame::update(const CInputManager &inputManager) {

    m_Paddle.move(inputManager.getMovement());

    for (auto &ball: m_Balls)
        ball.move(inputManager.getMovement(), inputManager.getSpace());

    for (auto &modifier: m_Modifiers) {
        if (!modifier->isApplied())
            modifier->move();
    }

    updateModifiers();
    checkCollisions();

    if (m_Levels[m_CurrentLevel].isCompleted()) {
        m_CurrentLevel++;

        for (auto &modifier: m_Modifiers)
            if (modifier->isApplied())
                modifier->revert();

        m_Paddle.setPos(CCoords{m_Width / 2 - m_Paddle.getWidth() / 2, m_Paddle.getPos().m_Y});
        m_Balls[0].attach(m_Paddle);
        m_Modifiers.clear();
    }
    if (m_CurrentLevel == m_Levels.size() || m_Paddle.m_Lives.empty())
        m_State = EGameState::FINISHED;
}

void CGame::checkCollisions() {
    //Ball paddle collision
    for (auto &ball: m_Balls)
        ball.checkCollision(m_Paddle);
    //Brick ball collision
    for (auto &brick: m_Levels[m_CurrentLevel].getBricks()) {
        if (!brick.isDestroyed())
            for (auto &ball: m_Balls)
                if (ball.checkCollision(brick)) {
                    m_Score += brick.getPoints();
                    spawnModifier(brick.getPos());
                }
    }
    //Window boundary checks
    checkBoundaries();
    //Modifier paddle collision
    for (auto &modifier : m_Modifiers) {
        if (!modifier->isApplied() &&
            m_Paddle.getPos().m_X < modifier->getPos().m_X + modifier->getWidth() &&
            m_Paddle.getPos().m_X + m_Paddle.getWidth() > modifier->getPos().m_X &&
            m_Paddle.getPos().m_Y < modifier->getPos().m_Y + modifier->getHeight() &&
            m_Paddle.getPos().m_Y + m_Paddle.getHeight() > modifier->getPos().m_Y) {
            modifier->apply();
        }
    }
}

void CGame::updateModifiers() {
    for (size_t i = 0; i < m_Modifiers.size(); ++i) {
        if (m_Modifiers[i]->isApplied())
            m_Modifiers[i]->tick();
        if (m_Modifiers[i]->expired()) {
            m_Modifiers[i]->revert();
            m_Modifiers.erase(m_Modifiers.begin() + i);
        }
    }
}

void CGame::spawnModifier(CCoords coords) {
    if (rand() % 100 < DROP_CHANCE) {
        int choice = (rand() % 5);
        switch (choice) {
            case 0:
                m_Modifiers.push_back(
                        CSpeedModifier(coords, m_Height / 20, m_Height / 20, 300, m_Balls).clone());
                break;
            case 1:
                m_Modifiers.push_back(
                        CLifeModifier(coords, m_Height / 20, m_Height / 20, -1, m_Paddle).clone());
                break;
            case 2:
                m_Modifiers.push_back(
                        CSplitModifier(coords, m_Height / 20, m_Height / 20, -1, m_Balls).clone());
                break;
            case 3:
                m_Modifiers.push_back(
                        CBreakModifier(coords, m_Height / 20, m_Height / 20, 200, m_Balls).clone());
                break;
            case 4:
                m_Modifiers.push_back(
                        CWidthModifier(coords, m_Height / 7, m_Width / 40, 600, m_Paddle).clone());
                break;
            default:
                break;
        }
    }
}

void CGame::loadLevels() {
    CLevel level1(m_Width, m_Height / 3);
    level1.load("./examples/level1.txt");
    m_Levels.push_back(level1);

    CLevel level2(m_Width, m_Height / 3);
    level2.load("./examples/level2.txt");
    m_Levels.push_back(level2);

    CLevel level3(m_Width, m_Height / 3);
    level3.load("./examples/level3.txt");
    m_Levels.push_back(level3);
}

void CGame::checkBoundaries() {
    //Check paddle boundary
    if (m_Paddle.getPos().m_X + m_Paddle.getWidth() >= m_Width)
        m_Paddle.setPos(CCoords{m_Width - m_Paddle.getWidth(), m_Paddle.getPos().m_Y});
    else if (m_Paddle.getPos().m_X <= 0) {
        m_Paddle.setPos(CCoords{0, m_Paddle.getPos().m_Y});
    }
    //Ball boundary check when attached
    if (m_Balls.front().isAttached()) {
        if (m_Balls.front().getPos().m_X + m_Paddle.getWidth() / 2 >= m_Width)
            m_Balls.front().setPos(CCoords{m_Width - (m_Paddle.getWidth() / 2) - (m_Balls[0].getWidth() / 2),
                                           m_Balls[0].getPos().m_Y});
        else if (m_Balls.front().getPos().m_X - m_Paddle.getWidth() / 2 + m_Balls[0].getWidth() / 2 <= 0)
            m_Balls.front().setPos(
                    CCoords{0 + (m_Paddle.getWidth() / 2) - (m_Balls[0].getWidth() / 2), m_Balls[0].getPos().m_Y});
    }
    //Ball boundary check
    for (size_t i = 0; i < m_Balls.size(); ++i) {
        if (m_Balls[i].getPos().m_X >= m_Width) {
            m_Balls[i].m_Xspeed *= -1;
            m_Balls[i].setPos(CCoords{m_Width - m_Balls[i].getWidth(), m_Balls[i].getPos().m_Y});
        } else if (m_Balls[i].getPos().m_X <= 0) {
            m_Balls[i].m_Xspeed *= -1;
            m_Balls[i].setPos(CCoords{0, m_Balls[i].getPos().m_Y});
        } else if (m_Balls[i].getPos().m_Y <= 0) {
            m_Balls[i].m_Yspeed *= -1;
            m_Balls[i].setPos(CCoords{m_Balls[i].getPos().m_X, 0});
        } else if (m_Balls[i].getPos().m_Y >= m_Height) {
            if (m_Balls.size() == 1) {
                m_Paddle.setPos(CCoords{m_Width / 2 - m_Paddle.getWidth() / 2, m_Paddle.getPos().m_Y});
                m_Balls[i].attach(m_Paddle);
                m_Paddle.m_Lives.pop_back();
            } else {
                m_Balls.erase(m_Balls.begin() + i);
            }
        }
    }
    //Modifier boundary check
    for (size_t i = 0; i < m_Modifiers.size(); i++)
        if (m_Modifiers[i]->getPos().m_Y + m_Modifiers[i]->getHeight() >= m_Height)
            m_Modifiers.erase(m_Modifiers.begin() + i);

}




