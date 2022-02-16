#include "CSpeedModifier.h"

CSpeedModifier::CSpeedModifier(CCoords pos, int width, int height, int duration, std::vector<CBall> &balls) : CBaseModifier(pos, width, height,
                                                                CColor{255, 0, 0},
                                                                duration), m_Balls(balls) {
}

void CSpeedModifier::apply() {
    m_Applied = true;
    for (auto &ball: m_Balls) {
        ball.setColor(CColor{255, 0, 0});
        ball.m_BallSpeed += 3;
    }
}

void CSpeedModifier::revert() const {
    for (auto &ball: m_Balls) {
        ball.setColor(CColor{0, 0, 0});
        ball.m_BallSpeed -= 3;
    }
}

std::unique_ptr<CBaseModifier> CSpeedModifier::clone() const {
    return std::make_unique<CSpeedModifier>(*this);
}

void CSpeedModifier::draw(SDL_Renderer *renderer) const {
    SDL_Rect r{m_Pos.m_X, m_Pos.m_Y, m_Width, m_Height};
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    SDL_RenderFillRect(renderer, &r);
}

