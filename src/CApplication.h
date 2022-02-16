#include "CRenderer.h"
#include "CGame.h"
#include "CInputManager.h"
#include "CScoreBoard.h"
#include "CLetter.h"

#pragma once
/**
 * Main application class, handles the whole game
 */
class CApplication {
public:
    CApplication(size_t width, size_t height);

    CApplication(const CApplication &) = delete;

    CApplication &operator=(const CApplication &) = delete;

    ~CApplication() = default;

    /**
     * Main method, runs the whole application
     *
     * @return 1 on error, 0 on success
     */
    int run();

private:
    //Draw the intro screen, wait for SPACE press
    void drawIntro();
    //Loops the game mechanics
    void loopGame();
    //Draw the scoreboard on screen
    void drawScoreBoard();

    int m_Width;
    int m_Height;

    CGame m_Game;
    CRenderer m_Renderer;
    CInputManager m_InputManager;
    CScoreBoard m_ScoreBoard;
    //Frame delay in milliseconds
    uint m_FrameDelay = 1000 / 60;
};


