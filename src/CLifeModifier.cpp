#include "CLifeModifier.h"

CLifeModifier::CLifeModifier(CCoords pos, int width, int height, int duration,
                             CPaddle &paddle) : CBaseModifier(pos, width, height,
                                                              CColor{255, 0, 0},
                                                              duration), m_Paddle(paddle) {
    m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 3});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 3});
    m_Vertices.push_back(CCoords{m_Pos.m_X + 2 * m_Width / 3, m_Pos.m_Y});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height / 3});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 3, m_Pos.m_Y});
    m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 3});

}

std::unique_ptr<CBaseModifier> CLifeModifier::clone() const {
    return std::make_unique<CLifeModifier>(*this);
}

void CLifeModifier::apply() {
    m_Applied = true;
    m_Paddle.m_Lives.emplace_back(
            CLife(m_Paddle.m_Lives.back().getPos() + CCoords{m_Paddle.m_Lives.back().getWidth(), 0},
                  m_Paddle.m_Lives.back().getWidth(), m_Paddle.m_Lives.back().getHeight(), CColor{255, 0, 0}));
}

void CLifeModifier::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    for (size_t i = 0; i < m_Vertices.size() - 1; ++i)
        SDL_RenderDrawLine(renderer, m_Vertices[i].m_X, m_Vertices[i].m_Y, m_Vertices[i + 1].m_X,
                           m_Vertices[i + 1].m_Y);
}

void CLifeModifier::revert() const {
}
