#include <SDL2/SDL.h>
#include "CScoreBoard.h"
#include "CPaddle.h"
#include "CBrick.h"
#include "CBall.h"

#pragma once
/**
 * Class handling the SDL window and renderer
 */
class CRenderer {
public:

    CRenderer(size_t width, size_t height, CColor background);
    /**
     * Initializes the SDL subsystems, creates SDL window and renderer objects
     * @throw runtime_error If SDL cannot be initialized or either the window or
     * renderer cannot be created
     */
    void init();
    /**
     * Presents buffer to the screen
     * */
    void present();
    /**
     * Clears the screen using the background color
     */
    void redrawBackground();
    /**
     * @return Pointer to SDL renderer
     */
    SDL_Renderer *getRenderer();
    /**
     * Destroys window and renderer, quits SDL subsystems
     */
    void quit() const;

private:
    SDL_Renderer *m_Renderer = nullptr;
    SDL_Window *m_Window = nullptr;

    size_t m_WindowWidth;
    size_t m_WindowHeight;

    CColor m_Background;
};


