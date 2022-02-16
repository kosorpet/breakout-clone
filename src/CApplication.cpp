#include "CApplication.h"

using namespace std;

CApplication::CApplication(size_t width, size_t height) : m_Width(width), m_Height(height),
                                                          m_Game(m_Width, m_Height),
                                                          m_Renderer(m_Width, m_Height, CColor{237, 223, 205}),
                                                          m_InputManager(m_Width), m_ScoreBoard(m_Width, m_Height) {
}

int CApplication::run() {
    //Load the scoreboard file
    try {
        m_ScoreBoard.load("./examples/scoreboard.txt");
    }
    catch (const runtime_error &ex) {
        cout << ex.what() << endl;
        return 1;
    }
    //Load level files
    try {
        m_Game.loadLevels();
    }
    catch (const runtime_error &ex) {
        cout << ex.what() << endl;
        return 1;
    }
    //Initialize the renderer
    try {
        m_Renderer.init();
    }
    catch (const runtime_error &ex) {
        cout << ex.what() << endl;
        m_Renderer.quit();
        return 1;
    }

    drawIntro();
    while (!m_InputManager.quitRequested()) {
        m_Game.reset();
        loopGame();
        m_ScoreBoard.addScore(m_Game.getScore());
        drawScoreBoard();
        try {
            m_ScoreBoard.save("./examples/scoreboard.txt");
        }
        catch (const runtime_error &ex) {
            cout << ex.what() << endl;
            m_Renderer.quit();
            return 1;
        }
    }
    m_Renderer.quit();
    return 0;
}

void CApplication::drawIntro() {
    string title = "BREAKOUT";
    string spaceToPlay = "SPACE TO PLAY";
    vector<CLetter> titleLetters;

    for (int i = 0; i < static_cast<int>(title.size()); ++i)
        titleLetters.emplace_back(CCoords{m_Width / 2 - (static_cast<int>(title.length() - 1) / 2 * m_Width / 80) -
                                          (static_cast<int>(title.length()) * m_Width / 12 / 2) +
                                          (i * (m_Width / 12 + m_Width / 80)), m_Height / 3},
                                  m_Width / 12,
                                  m_Height / 10, CColor{0, 0, 0}, title[i]);
    for (int i = 0; i < static_cast<int>(spaceToPlay.size()); ++i)
        titleLetters.emplace_back(
                CCoords{m_Width / 2 - (static_cast<int>(spaceToPlay.length() - 1) / 2 * m_Width / 80) -
                        (static_cast<int>(spaceToPlay.length()) * m_Width / 40 / 2) +
                        (i * (m_Width / 40 + m_Width / 80)), 2 * m_Height / 3},
                m_Width / 40, m_Height / 20,
                CColor{0, 0, 0},
                spaceToPlay[i]);

    while (!m_InputManager.getSpace()) {

        m_InputManager.readInput();
        if (m_InputManager.quitRequested())
            return;

        m_Renderer.redrawBackground();
        m_InputManager.readInput();

        for (auto &letter: titleLetters)
            letter.draw(m_Renderer.getRenderer());

        m_Renderer.present();
    }
}
//Main game loop
void CApplication::loopGame() {
    while (m_Game.isRunning()) {
        uint frameStart = SDL_GetTicks();

        m_InputManager.readInput();
        if (m_InputManager.quitRequested())
            return;

        m_Renderer.redrawBackground();
        m_Game.draw(m_Renderer);
        m_Renderer.present();
        m_Game.update(m_InputManager);

        uint frameTime = SDL_GetTicks() - frameStart;
        if (m_FrameDelay > frameTime)
            SDL_Delay(m_FrameDelay - frameTime);
        else if (frameTime > 100)
            cout << "lag: " << frameTime << "ms" << endl;
    }
}

void CApplication::drawScoreBoard() {
    while (!m_InputManager.getSpace()) {

        if (m_InputManager.quitRequested())
            return;

        m_Renderer.redrawBackground();
        m_InputManager.readInput();

        m_ScoreBoard.draw(m_Renderer.getRenderer());
        m_Renderer.present();
    }
}
