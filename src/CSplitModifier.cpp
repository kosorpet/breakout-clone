#include "CSplitModifier.h"

CSplitModifier::CSplitModifier(CCoords pos, int width, int height, int duration, std::vector<CBall> &balls) : CBaseModifier(pos, width, height,
                                                                CColor{100, 100, 100},
                                                                duration) , m_Balls(balls){
}

std::unique_ptr<CBaseModifier> CSplitModifier::clone() const {
    return std::make_unique<CSplitModifier>(*this);
}

void CSplitModifier::draw(SDL_Renderer *renderer) const {
    SDL_Rect r{m_Pos.m_X, m_Pos.m_Y, m_Width, m_Height};
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    SDL_RenderFillRect(renderer, &r);
}

void CSplitModifier::apply() {
    m_Applied = true;
    for (size_t i = 0; i < 2; ++i) {
        CBall ball = CBall(m_Balls[0]);
        do {
            //Pick a random number betwee -1 and 1
            double random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 2.0) - 1;
            //Multiply by max angle
            double randomAngle = random * M_PI / 4;
            ball.m_Yspeed = sin(randomAngle) * m_Balls[0].m_Xspeed + cos(randomAngle) * m_Balls[0].m_Yspeed;
            ball.m_Xspeed = cos(randomAngle) * m_Balls[0].m_Xspeed - sin(randomAngle) * m_Balls[0].m_Yspeed;
        } while (ball.m_Yspeed == 0);
        m_Balls.push_back(ball);
    }
}

void CSplitModifier::revert() const {
    while (m_Balls.size() != 1)
        m_Balls.pop_back();
}
