#include "CRenderer.h"
#include "CObject.h"

using namespace std;

CRenderer::CRenderer(size_t width, size_t height, CColor background) : m_WindowWidth(width), m_WindowHeight(height),
                                                                       m_Background(background) {

}

void CRenderer::init() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw runtime_error(SDL_GetError());

    m_Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WindowWidth,
                                m_WindowHeight, 0);
    if (!m_Window)
        throw runtime_error(SDL_GetError());

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (!m_Renderer)
        throw runtime_error(SDL_GetError());
}

void CRenderer::redrawBackground() {
    SDL_SetRenderDrawColor(m_Renderer, m_Background.r, m_Background.g, m_Background.b, 255);
    SDL_RenderClear(m_Renderer);
}

void CRenderer::quit() const {
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    SDL_Quit();
}

void CRenderer::present() {
    SDL_RenderPresent(m_Renderer);
}

SDL_Renderer *CRenderer::getRenderer() {
    return m_Renderer;
}


