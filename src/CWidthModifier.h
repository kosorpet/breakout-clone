#include "CBaseModifier.h"

#pragma once

/**
 * Modifier class, enlarges the paddle
 */
class CWidthModifier : public CBaseModifier {
public:
    CWidthModifier(CCoords pos, int width, int height, int duration, CPaddle &paddle);
    /**
     * Doubles the paddle width
     */
    void apply() override;
    /**
     * Halves the paddle width
     */
    void revert() const override;
    /**
     * Draws modifier to screen
     * @param[in] renderer Pointer to SDL renderer
     */
    void draw(SDL_Renderer *renderer) const override;
    /**
     * Clone method
     * @return unique pointer to the modifier
     */
    std::unique_ptr<CBaseModifier> clone() const override;
private:
    CPaddle &m_Paddle;
};



