#include "SDL2/SDL.h"

#pragma once

/**
 * Class for handling SDL input
 * */

class CInputManager {
public:
    explicit CInputManager(int width);
    /**
     * Reads user input using the SDL liberary
     */
    void readInput();
    /**
     * Resets inner state of the manager
     */
    void reset();
    /**
     * Check if spacebar has been pressed
     * @return true if SPACE is pressed, else false
     */
    bool getSpace() const {
        return m_Space;
    }
    /**
     * Gets the change in horizontal movement based on arrow keys left and right
     * scaled by the window width
     * @return Negative integer when LEFT ARROW is pressed
     * @return Positive integer when RIGHT ARROW is pressed
     */
    int getMovement() const {
        return m_Dx;
    }
    /**
     * Checks if quit has been requested by closing the window
     */
    bool quitRequested() const {
        return m_Quit;
    }

private:
    int m_Dx = 0;
    bool m_Space = false;
    bool m_Quit = false;

    int m_WindowWidth;
};
