#include "CLife.h"

CLife::CLife(CCoords pos, size_t width, size_t height, CColor color) : CObject(pos, width, height, color) {
    m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 3});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 3});
    m_Vertices.push_back(CCoords{m_Pos.m_X + 2 * m_Width / 3, m_Pos.m_Y});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height / 3});
    m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 3, m_Pos.m_Y});
    m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 3});
}

void CLife::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, getColor().r, getColor().g, getColor().b, 255);

    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    for (size_t i = 0; i < m_Vertices.size() - 1; ++i)
        SDL_RenderDrawLine(renderer, m_Vertices[i].m_X, m_Vertices[i].m_Y, m_Vertices[i + 1].m_X,
                           m_Vertices[i + 1].m_Y);
}
