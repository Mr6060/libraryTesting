#pragma once
#ifndef _FPS_HPP
#define _FPS_HPP

#include <SFML/Graphics.hpp>

class FPS{
    public:
        FPS();
        void update();
        const unsigned int getFPS();
    private:
        unsigned int mFrame;
        unsigned int mFps;
        sf::Clock mClock;
};

#endif