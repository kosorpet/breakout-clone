#include <set>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>
#include "CLetter.h"

#pragma once
/**
 * Class handling file I/O of the score
 */
class CScoreBoard {
public:
    CScoreBoard(int width, int height);
    /**
     * Loads score from given text file
     * @param filePath Path to text file with score
     */
    void load(const char *filePath);
    /**
     * Saves score to a given text file
     * @param filePath Path where to save the score
     */
    void save(const char *filePath);
    /**
     * Adds score to scoreboard
     * @param score Score reached by the player
     */
    void addScore(size_t score);
    /**
     * Draw the scoreboard
     * @param renderer Pointer to SDL renderer
     */
    void draw(SDL_Renderer *renderer) const;

private:
    int m_Width;
    int m_Height;

    int m_CurrentScore = 0;
    //Vector holding the scores
    std::vector<size_t> m_ScoreList;
};

