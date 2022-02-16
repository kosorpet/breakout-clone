#include "CPaddle.h"
#include <iostream>

CPaddle::CPaddle(CCoords pos, size_t width, size_t height, CColor color) : CObject(pos, width, height, color) {

}

void CPaddle::move(int dx) {
    m_Pos.m_X += dx;
}

void CPaddle::draw(SDL_Renderer *renderer) const {
    SDL_Rect r{m_Pos.m_X, m_Pos.m_Y, m_Width, m_Height};
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    SDL_RenderFillRect(renderer, &r);
}


