#include "CObject.h"

#pragma once
/**
 * Class representing the brick object
 */
class CBrick : public CObject {
public:
    CBrick(CCoords pos, size_t width, size_t height, CColor color, bool solid, int points = 0);
    /**
     * Check if brick is destroyed
     * @return true if destroyed, else false
     */
    bool isDestroyed() const;
    /**
     * Check if brick is solid
     * @return true if solid, else false
     */
    bool isSolid() const;
    /**
     * Get how many points is the brick worth
     * @return number of points
     * */
    int getPoints() const;
    /**
     * Sets the m_isDestroyed variable
     * @param in value to be set
     */
    void setDestroyed(bool destroyed);
    /**
     * Draw brick to screen
     */
    void draw(SDL_Renderer *renderer) const override;

private:
    bool m_IsSolid;
    bool m_IsDestroyed = false;
    size_t m_Points;
};