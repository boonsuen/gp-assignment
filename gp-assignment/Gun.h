#pragma once
#ifndef Gun_h
#define Gun_h
#endif

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#endif
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "common.h"
#include "Utility.h"

class Gun {
public:
	Utility u;
	void drawGun();

    void keyActions(unsigned char key);
};

void Gun::drawGun() {

}

void Gun::keyActions(unsigned char key) {
    if (key == 'G' || key == 'g') {
        showGun = !showGun;

        if (showGun == false) {
            gunAttackMode = false;
        }
    }
    else if (key == '3' && showGun) {
        gunAttackMode = !gunAttackMode;
    }
}
