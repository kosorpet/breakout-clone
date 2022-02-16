#include "CPaddle.h"
#include "CBrick.h"
#include <vector>
#include <memory>

#pragma once

class CBall : public CObject {
public:

    CBall(CCoords pos, int xspeed, int yspeed, size_t side, CColor color, int ballSpeed, bool attached = true);

    /**
     * Check if ball is attached to paddle
     *
     * @return true if attached, else false
     */
    bool isAttached() const;

    /**
     * Detaches the ball from the paddle, gives the ball random direction
     */
    void detach();
    /**
     * Attaches the ball to the top of the paddle
     * @param[in] paddle Paddle object to attach to
     */
    void attach(const CPaddle &paddle);
    /**
     * Move the ball
     * @param[in] dx Amount to move left or right when the ball is attched
     * @param[in] space true if SPACE is pressed, else false
     */
    void move(int dx, bool space);
    /**
     * Check if ball collided with paddle, calculates bounce angle and velocity
     */
    void checkCollision(const CPaddle &paddle);
    /**
     * Check if ball collided with brick
     * @return true when collided, else false
     */
    bool checkCollision(CBrick &brick);
    /**
     * Draws the paddle
     * @param[in] renderer Pointer to SDL renderer
     */
    void draw(SDL_Renderer *renderer) const override;

    int m_Xspeed;
    int m_Yspeed;

    int m_BallSpeed = 7;

    bool m_Breakthrough = false;
    bool m_Attached;
};
