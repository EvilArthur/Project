#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Wall.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Project Game");
    window.setFramerateLimit(60);

    Ball ball(window, window.getSize().x / 10, window.getSize().y / 2, 30.0, Color::Yellow, 5, 5);
    Wall wall(window, ball, 0, 0, window.getSize().x - 10, 10, Color::Green);
    Wall wall2(window, ball, 0, 10, 10, window.getSize().y - 10, Color::Blue);
    Wall wall3(window, ball, 10, window.getSize().y - 10, window.getSize().x - 10, 10, Color::Red);
    Wall wall4(window, ball, window.getSize().x - 10, 0, 10, window.getSize().y - 10, Color::Magenta);
    while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape)) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        ball.update();
        wall.update();
        wall2.update();
        wall3.update();
        wall4.update();
        window.display();
    }

    return 0;
}