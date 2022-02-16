#include "CBaseModifier.h"

CBaseModifier::CBaseModifier(CCoords pos, int width, int height, CColor color, int duration) : CObject(pos, width,
                                                                                                       height, color),
                                                                                               m_Duration(duration) {
}

void CBaseModifier::move() {
    m_Pos.m_Y += 2;
    for (auto &i : m_Vertices)
        i.m_Y += 2;
}

bool CBaseModifier::isApplied() const {
    return m_Applied;
}

bool CBaseModifier::expired() const {
    return m_Duration == 0;
}

void CBaseModifier::tick() {
    if (m_Duration != -1)
        m_Duration--;
}



