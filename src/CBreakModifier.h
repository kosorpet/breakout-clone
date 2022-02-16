#include "CBaseModifier.h"

#pragma once
/**
 * Modifier class with the multibreak effect
 */
class CBreakModifier : public CBaseModifier {
public:
    CBreakModifier(CCoords pos, int width, int height, int duration, std::vector<CBall> &balls);
    /**
     * Sets ball.m_Breakthrough to true, makes the balls break multiple blocks
     */
    void apply() override;
    /**
     * Reverts the effect
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
    std::vector<CBall> & m_Balls;
};


