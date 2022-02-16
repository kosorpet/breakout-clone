#include "CBaseModifier.h"

#pragma once

/**
 * Modifier class, adds two more balls to the screen
 */
class CSplitModifier : public CBaseModifier {
public:
    CSplitModifier(CCoords pos, int width, int height, int duration, std::vector<CBall> &balls);
    /**
     * Adds two more balls
     */
    void apply() override;
    /**
     * Destroys the extra balls
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


