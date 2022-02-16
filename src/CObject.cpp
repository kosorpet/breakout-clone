#include "CObject.h"

CObject::CObject(CCoords pos, size_t width, size_t height, CColor color) : m_Pos(pos), m_Width(width), m_Height(height),
                                                                           m_Color(color) {

}

int CObject::getWidth() const {
    return m_Width;
}

int CObject::getHeight() const {
    return m_Height;
}

CCoords CObject::getPos() const {
    return m_Pos;
}

CColor CObject::getColor() const {
    return m_Color;
}

void CObject::setPos(CCoords pos) {
    m_Pos = pos;
}

void CObject::setWidth(int width) {
    m_Width = width;
}

void CObject::setColor(CColor color) {
    m_Color = color;
}


