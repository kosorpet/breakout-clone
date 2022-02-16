#include "CWidthModifier.h"

using namespace std;

CWidthModifier::CWidthModifier(CCoords pos, int width, int height, int duration,
                               CPaddle &paddle) : CBaseModifier(pos, width, height,
                                                                CColor{255, 255, 0},
                                                                duration), m_Paddle(paddle) {
}

std::unique_ptr<CBaseModifier> CWidthModifier::clone() const {
    return make_unique<CWidthModifier>(*this);
}

void CWidthModifier::apply() {
    m_Applied = true;
    m_Paddle.setWidth(m_Paddle.getWidth() * 2);
    m_Paddle.setColor(m_Color);
    m_Paddle.setPos(CCoords{m_Paddle.getPos().m_X - 30, m_Paddle.getPos().m_Y});
}

void CWidthModifier::revert() const {
    m_Paddle.setWidth(m_Paddle.getWidth() / 2);
    m_Paddle.setColor(CColor{70, 165, 165});
    m_Paddle.setPos(CCoords{m_Paddle.getPos().m_X + 30, m_Paddle.getPos().m_Y});
}

void CWidthModifier::draw(SDL_Renderer *renderer) const {
    SDL_Rect r{m_Pos.m_X, m_Pos.m_Y, m_Width, m_Height};
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    SDL_RenderFillRect(renderer, &r);
}

