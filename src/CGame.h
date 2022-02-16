#include "EGameState.h"
#include "CInputManager.h"
#include "CRenderer.h"
#include "CPaddle.h"
#include "CBall.h"
#include "CLevel.h"
#include "CWidthModifier.h"
#include "CLifeModifier.h"
#include "CSpeedModifier.h"
#include "CBreakModifier.h"
#include "CSplitModifier.h"
#include <vector>

#pragma once
/**
 * Main game class, handles all the game mechanics and object
 * */
class CGame {
public:
    CGame(size_t width, size_t height);

    CGame ( const CGame & other );

    CGame & operator= ( CGame const & other );

    ~CGame () = default;
    /**
     * Update the game state based on user input
     * @param inputManager Input manager handling the input
     */
    void update(const CInputManager &inputManager);
    /**
     * Draw all of the game object to screen
     * @param renderer Renderer handling the graphics
     */
    void draw(CRenderer &renderer) const;
    /**
     * Reset the game objects, levels and score
     */
    void reset();
    /**
     * Loads and parses levels from text files
     */
    void loadLevels();
    /**
     * Check if the game is in running state
     * @return true if state is RUNNING, else false
     */
    bool isRunning() const;
    /**
     * Get the current score
     * @return score score earned by the player
     */
    int getScore() const;

private:
    //Handles all of the game object collisions
    void checkCollisions();
    //Checks object collisions with window edges
    void checkBoundaries();
    //Updates the modifier states, checks expired modifiers
    void updateModifiers();
    //Creates new modifiers upon brick breaks
    void spawnModifier(CCoords coords);

    int m_Width;
    int m_Height;

    int m_Score = 0;

    EGameState m_State;

    CPaddle m_Paddle;
    std::vector<CBall> m_Balls;
    std::vector<std::unique_ptr<CBaseModifier>> m_Modifiers;

    std::vector<CLevel> m_Levels;
    size_t m_CurrentLevel;
    //Chance to drop a modifier in %
    int DROP_CHANCE = 20;
};