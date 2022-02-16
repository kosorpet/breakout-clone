#include <iostream>
#include "CInputManager.h"

CInputManager::CInputManager(int width) : m_WindowWidth(width) {

}

void CInputManager::readInput() {
    SDL_Event event;
    reset();
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            m_Quit = true;
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_SPACE]) {
        m_Space = true;
    } else if (state[SDL_SCANCODE_RIGHT]) {
        m_Dx = m_WindowWidth / 160;
    } else if (state[SDL_SCANCODE_LEFT]) {
        m_Dx = -m_WindowWidth / 160;
    }
}

void CInputManager::reset() {
    m_Dx = 0;
    m_Space = false;
}

