#include "CBall.h"
#include <vector>
#include <cmath>

#pragma once

/**
 * Class representing the base modifier from which all the modifiers are derived
 */

class CBaseModifier : public CObject {
public:
    CBaseModifier(CCoords pos, int width, int height, CColor color, int duration);

    /**
     * Virtual clone method
     * @return unique pointer to the modifier
     */
    virtual std::unique_ptr<CBaseModifier> clone() const = 0;

    /**
     * Applies effect to balls or paddle
     */
    virtual void apply() = 0;
    /**
     * Reverts given effect
     */
    virtual void revert() const = 0;
    /**
     * Moves the modifier down
     */
    void move();
    /**
     * Check if applied
     * @return true if applied, else false
     */
    bool isApplied() const;
    /**
     * Check if remaining duration is 0
     * @return true if m_Duration == 0 else false
     */
    bool expired() const;
    /**
     * Decrements duration
     */
    void tick();

protected:

    int m_Duration;

    std::vector<CCoords> m_Vertices;

    bool m_Applied = false;
};