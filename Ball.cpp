#include "Ball.h"

Ball::Ball(RenderWindow& window, float x, float y, float radius, Color color, float speedX, float speedY) : m_window(window), m_xStep(speedX), m_yStep(speedY) {
    setRadius(radius);
    setFillColor(color);
    setOrigin(radius, radius);
    setPosition(x, y);
}

void Ball::setSpeedX(float speed) {
    m_xStep = speed;
}

void Ball::setSpeedY(float speed) {
    m_yStep = speed;
}

float Ball::speedX() {
    return m_xStep;
}

float Ball::speedY() {
    return m_yStep;
}


void Ball::update() {
    move(m_xStep, m_yStep);
    m_window.draw(*this);
}