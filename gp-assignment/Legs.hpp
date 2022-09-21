#pragma once

#ifndef Legs_hpp
#define Legs_hpp
#endif /* Legs_hpp */

#include "Utility.hpp"

class Legs {
public:
    Utility u;
    float scaleX = 0;
    float scaleY = 0;

    void drawFoot();
    void drawCalf();
    void drawThigh();
    void drawLeftLeg();
    void drawRightLeg();
    void drawLeftDefenseWaist();
    void drawRightDefenseWaist();
    void drawWaist();
    void drawLegs();
};
