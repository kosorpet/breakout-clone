#include <iostream>

#pragma once

/**
 * Simple struct to represent Coordinates on the screen / vector
 */
struct CCoords {
    int m_X = 0;
    int m_Y = 0;

    CCoords operator+(CCoords other) const {
        return CCoords{m_X + other.m_X, m_Y + other.m_Y};
    }

};
