#pragma once

#ifndef Head_hpp
#define Head_hpp
#endif

#include "Utility.hpp"

class Head {
public:
    Utility u;
    void drawEye(bool isRed, bool isLeft);
    void drawFace();
    void drawToppings();
    void drawCheek();
    void drawHead();
};
