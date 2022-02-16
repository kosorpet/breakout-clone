#include "CBrick.h"

CBrick::CBrick(CCoords pos, size_t width, size_t height, CColor color, bool solid, int points) : CObject(pos, width,
                                                                                                         height, color),
                                                                                                 m_IsSolid(solid),
                                                                                                 m_Points(points) {
}

bool CBrick::isDestroyed() const {
    return m_IsDestroyed;
}

void CBrick::setDestroyed(bool destroyed) {
    m_IsDestroyed = destroyed;
}

void CBrick::draw(SDL_Renderer *renderer) const {
    SDL_Rect r{m_Pos.m_X, m_Pos.m_Y, m_Width, m_Height};
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    SDL_RenderFillRect(renderer, &r);
}

bool CBrick::isSolid() const {
    return m_IsSolid;
}

int CBrick::getPoints() const {
    return m_Points;
}

