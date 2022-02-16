#include "CObject.h"
#include <vector>

#pragma once

/**
 * Simple letter representation
 */
class CLetter : public CObject {
public:
    CLetter(CCoords pos, size_t width, size_t height, CColor color, char character);
    /**
     * Draw the letter to screen
     * @param[in] renderer Pointer to SDL renderer
     */
    void draw(SDL_Renderer *renderer) const override;

private:
    //Vector of points, letter is drawn by connecting the points
    std::vector<CCoords> m_Vertices;
};

