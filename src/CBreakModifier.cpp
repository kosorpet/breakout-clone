#include "CBreakModifier.h"

CBreakModifier::CBreakModifier(CCoords pos, int width, int height, int duration, std::vector<CBall> &balls) : CBaseModifier(pos, width, height,
                                                                CColor{0, 150, 0},
                                                                duration), m_Balls(balls) {
}

void CBreakModifier::apply() {
    m_Applied = true;
    for (auto &ball: m_Balls) {
        ball.m_Breakthrough = true;
        ball.setColor(m_Color);
    }
}

void CBreakModifier::revert() const {
    for (auto &ball: m_Balls) {
        ball.m_Breakthrough = false;
        ball.setColor(CColor{0, 0, 0});
    }
}

void CBreakModifier::draw(SDL_Renderer *renderer) const {
    SDL_Rect r{m_Pos.m_X, m_Pos.m_Y, m_Width, m_Height};
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    SDL_RenderFillRect(renderer, &r);
}

std::unique_ptr<CBaseModifier> CBreakModifier::clone() const {
    return std::make_unique<CBreakModifier>(*this);
}


