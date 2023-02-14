#include "Wall.h"

float Wall::clamp(float value, float minn, float maxx) {
    if (value < minn) return minn;
    else if (value > maxx) return maxx;
    else return value;
}

int Wall::checkCollision(RectangleShape& wall, CircleShape& ball) {
    float closestX = clamp(ball.getPosition().x, wall.getPosition().x, wall.getPosition().x + wall.getSize().x);
    float closestY = clamp(ball.getPosition().y, wall.getPosition().y, wall.getPosition().y + wall.getSize().y);

    float distanceX = ball.getPosition().x - closestX;
    float distanceY = ball.getPosition().y - closestY;

    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    if (distanceSquared < ball.getRadius() * ball.getRadius() &&
        closestX != ball.getPosition().x &&
        closestY != ball.getPosition().y) {
        return 3;
    }
    else if (distanceSquared < ball.getRadius() * ball.getRadius() &&
        closestX == ball.getPosition().x) {
        return 2;
    }
    else if (distanceSquared < ball.getRadius() * ball.getRadius() &&
        closestY == ball.getPosition().y) {
        return 1;
    }
    else return 0;
}

Wall::Wall(RenderWindow& window, Ball& ball, float x, float y, float width, float height, Color clr) : m_window(window), m_ball(ball) {
    setSize(Vector2f(width, height));
    setPosition(x, y);
    setFillColor(clr);
}

void Wall::update() {
    if (checkCollision(*this, m_ball) != 0) {
        m_ball.setFillColor(this->getFillColor());
    }

    if (checkCollision(*this, m_ball) == 1) {
        m_ball.setSpeedX(-m_ball.speedX());
    }
    else if (checkCollision(*this, m_ball) == 2) {
        m_ball.setSpeedY(-m_ball.speedY());
    }
    else if (checkCollision(*this, m_ball) == 3) {
        m_ball.setSpeedX(-m_ball.speedX());
        m_ball.setSpeedY(-m_ball.speedY());
    }
    m_window.draw(*this);
}