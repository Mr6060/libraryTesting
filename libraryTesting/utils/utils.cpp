#include <iostream>
#include <SFML/Graphics.hpp>
#include "utils.hpp"

void clampMousePos(Coords &mousePos, const int WIDTH, const int HEIGHT){
    if(mousePos.x < 0)
        mousePos.x = 0;
    if(mousePos.x > WIDTH)
        mousePos.x = WIDTH;
    if(mousePos.y < 0)
        mousePos.y = 0;
    if(mousePos.y > HEIGHT)
        mousePos.y = HEIGHT;
}

Coords getMousePos(sf::Window &parentWindow){
    sf::Mouse mouse;
    Coords mouseCoords = {
        mouse.getPosition(parentWindow).x,
        mouse.getPosition(parentWindow).y
    };
    clampMousePos(mouseCoords, (const int)parentWindow.getSize().x, (const int)parentWindow.getSize().y);
    return mouseCoords;
}

