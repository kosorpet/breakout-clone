#include "CCoords.h"
#include "CColor.h"
#include <SDL2/SDL.h>
#include <memory>

#pragma once

/**
 * Base game object class
 * */
class CObject {
public:

    CObject(CCoords pos, size_t width, size_t height, CColor color);
    /**
     * @return Width of the object
     */
    int getWidth() const;
    /**
     * @return Height of the object
     */
    int getHeight() const;
    /**
     * @return Position of the object
     */
    CCoords getPos() const;
    /**
     * @return Color of the object
     */
    CColor getColor() const;
    /**
     * @param[in] Color of the object
     */
    void setColor(CColor color);
    /**
     * @param[in] Position of the object
     */
    void setPos(CCoords pos);
    /**
     * @param[in] Width of the object
     */
    void setWidth(int width);
    /**
     * Virtual method, handles the drawing the object to the screen
     * @param[in] renderer SDL renderer pointer
     * */
    virtual void draw(SDL_Renderer *renderer) const = 0;

    virtual ~CObject() = default;

protected:
    CCoords m_Pos;

    int m_Width;
    int m_Height;

    CColor m_Color;
};