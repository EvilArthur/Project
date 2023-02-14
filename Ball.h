#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public CircleShape {
private:
    float m_xStep = 10;
    float m_yStep;
    Color color;
    RenderWindow& m_window;

public:
    Ball(RenderWindow& window, float x, float y, float radius, Color color, float speedX, float speedY);

    void setSpeedX(float step);

    void setSpeedY(float step);

    float speedX();

    float speedY();

    void update();


};