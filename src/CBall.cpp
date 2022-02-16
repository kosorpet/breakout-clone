#include "CBall.h"
#include <cmath>

using namespace std;

CBall::CBall(CCoords pos, int xspeed, int yspeed, size_t side, CColor color, int ballSpeed, bool attached) : CObject(pos, side, side, color),
                                                                                                             m_Xspeed(xspeed),
                                                                                                             m_Yspeed(yspeed),
                                                                                                             m_BallSpeed(ballSpeed),
                                                                                                             m_Attached(attached) {
}

void CBall::move(int dx, bool space) {
    if (space && isAttached())
        detach();

    if (m_Attached) {
        m_Pos.m_X += dx;
        return;
    }
    m_Pos.m_X += m_Xspeed;
    m_Pos.m_Y += m_Yspeed;
}

bool CBall::isAttached() const {
    return m_Attached;
}

void CBall::detach() {
    m_Attached = false;
    //Choose a random angle to release the ball
    double random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 2) - 1;
    m_Xspeed = -m_BallSpeed * sin(random * M_PI / 3);
    m_Yspeed = -m_BallSpeed * cos(random * M_PI / 3);
}

void CBall::checkCollision(const  CPaddle &paddle) {
    if (m_Pos.m_X < paddle.getPos().m_X + paddle.getWidth() &&
        m_Pos.m_X + m_Width > paddle.getPos().m_X &&
        m_Pos.m_Y < paddle.getPos().m_Y + paddle.getHeight() &&
        m_Pos.m_Y + m_Height > paddle.getPos().m_Y) {

        //Calculate intersect position
        double intersect = (paddle.getPos().m_X + paddle.getWidth() / 2) - m_Pos.m_X;
        //Normalize it between -1 and 1
        double normalizedIntersect = (intersect / (paddle.getWidth() / 2));
        //Calculate bounce angle depending on the distance from center of the paddle
        double bounceAngle = normalizedIntersect * (M_PI / 3);

        m_Yspeed = -m_BallSpeed * cos(bounceAngle);
        m_Xspeed = -m_BallSpeed * sin(bounceAngle);
    }
}

void CBall::attach(const CPaddle &paddle) {
    setPos(CCoords{paddle.getPos().m_X + paddle.getWidth() / 2 - m_Width / 2, paddle.getPos().m_Y - m_Height});
    m_Attached = true;
}

bool CBall::checkCollision(CBrick &brick) {
    if (m_Pos.m_X < brick.getPos().m_X + brick.getWidth() &&
        m_Pos.m_X + m_Width > brick.getPos().m_X &&
        m_Pos.m_Y < brick.getPos().m_Y + brick.getHeight() &&
        m_Pos.m_Y + m_Height > brick.getPos().m_Y) {

        //If break modifier is active, calculate collision with brick
        if (!m_Breakthrough) {
            //Calculate the sides of rectangle created by intersection
            int x1 = max(brick.getPos().m_X, m_Pos.m_X);
            int y1 = max(brick.getPos().m_Y, m_Pos.m_Y);

            int x2 = min(brick.getPos().m_X + brick.getWidth(), m_Pos.m_X + m_Width);
            int y2 = min(brick.getPos().m_Y + brick.getHeight(), m_Pos.m_Y + m_Height);

            int width = x2 - x1;
            int height = y2 - y1;

            //If height < width the intersection occurred from top or bottom of the brick
            //Else on the sides
            if (height < width) {
                m_Yspeed *= -1;
                if (m_Pos.m_Y > brick.getPos().m_Y)
                    m_Pos.m_Y = brick.getPos().m_Y + brick.getHeight() + 1;
                else
                    m_Pos.m_Y = brick.getPos().m_Y - m_Height - 1;
            } else {
                m_Xspeed *= -1;
                if (m_Pos.m_X > brick.getPos().m_X)
                    m_Pos.m_X = brick.getPos().m_X + brick.getWidth() + 1;
                else
                    m_Pos.m_X = brick.getPos().m_X - m_Width - 1;
            }
            if (brick.isSolid())
                return false;
            brick.setDestroyed(true);
            return true;
        } else {
            brick.setDestroyed(true);
            return true;
        }
    }
    return false;
}

void CBall::draw(SDL_Renderer *renderer) const {
    SDL_Rect r{m_Pos.m_X, m_Pos.m_Y, m_Width, m_Height};
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, 255);
    SDL_RenderFillRect(renderer, &r);
}


