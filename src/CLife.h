#include "CObject.h"
#include <vector>

#pragma once
/**
 * Simple UI heart representing a single life
 * */
class CLife : public CObject {
public:
    CLife(CCoords pos, size_t width, size_t height, CColor color);
    /**
     * Draw the heart to the screen
     *  @param[in] renderer Pointer to SDL_Renderer rendering the game
     * */
    void draw(SDL_Renderer *renderer) const override;

private:
    //Vector of points making up the heart
    std::vector<CCoords> m_Vertices;
};

