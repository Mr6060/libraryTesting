#pragma once
#ifndef _UTILS_HPP
#define _UTILS_HPP


struct Coords{
        int x;
        int y;
    };

void clampMousePos(Coords &mousePos, const int WIDTH, const int HEIGHT);

Coords getMousePos(sf::Window &parentWindow);



#endif