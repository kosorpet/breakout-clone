#include "CBaseModifier.h"
#include "CLife.h"

#pragma once
/**
 * Modifier class, adding a life when activated
 */
class CLifeModifier : public CBaseModifier {
public:
    CLifeModifier(CCoords pos, int width, int height, int duration, CPaddle &paddle);
    /**
     * Gives extra life
     */
    void apply() override;
    /**
     * Empty method, life given is permanent
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


