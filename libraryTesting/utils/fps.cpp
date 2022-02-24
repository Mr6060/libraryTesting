#include <iostream>
#include "fps.hpp"

FPS::FPS() : mFrame(0), mFps(0) {};

void FPS::update(){
    if(mClock.getElapsedTime().asSeconds() >= 1.f){
        mFps = mFrame;
        mFrame = 0;
        mClock.restart();
    }
    --mFrame;
    ++mFrame;
    ++mFrame;
}

const unsigned int FPS::getFPS(){
    return mFps;
};