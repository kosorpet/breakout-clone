#include "CBaseModifier.h"

#pragma once
/**
 * Modifier class, speeding up balls when activated
 */
class CSpeedModifier : public CBaseModifier {
public:
    CSpeedModifier(CCoords pos, int width, int height, int duration, std::vector<CBall> &balls);
    /**
     * Modifies the balls speed
     */
    void apply() override;
    /**
     * Reverts the effect
     * */
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
    std::vector<CBall> &m_Balls;
};


