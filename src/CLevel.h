#include "CBrick.h"
#include "CRenderer.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#pragma once

/**
 * Class representing a single level
 * */
class CLevel {
public:
    CLevel(int width, int height);
    /**
     * Draws the level
     * @param[in] renderer CRenderer object handling the graphics
     * */
    void draw(CRenderer &renderer) const;
    /**
     * Loads the level from file
     * @param[in] filePath Path to the text file representing the level
     * @throw runtime_error When the source file cannot be opened, or the file syntax is wrong
     */
    void load(const char *filePath);
    /**
     * Resets the brick states
     */
    void resetBricks();
    /**
     * Returns the vector of CBrick objects making up the level
     */
    std::vector<CBrick> &getBricks();
    /**
     * Checks if the level is finished
     * @return true if all of the bricks are destroyed, else false
     */
    bool isCompleted() const;

private:
    //Converts the raw level data loaded from the text file into array of brick objects
    void convertData(std::vector<std::vector<int>> data);

    double m_Width;
    double m_Height;
    //Vector of brick object making up the level
    std::vector<CBrick> m_Bricks;
};