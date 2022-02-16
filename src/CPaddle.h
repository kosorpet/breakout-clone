#include "CObject.h"
#include "CLife.h"

#pragma once
/**
 * Paddle controlled by the player
 */
class CPaddle : public CObject {
public:
    CPaddle(CCoords pos, size_t width, size_t height, CColor color);
    /**
     * Handles the drawing the paddle
     * @param[in] renderer SDL renderer pointer
     */
    void draw(SDL_Renderer *renderer) const override;
    /**
     * Moves the paddle
     * @param[in] dx Difference in x position to be added to Paddle x position
     */
    void move(int dx);

    //Vector of remaining lives
    std::vector<CLife> m_Lives;
};