#pragma once

#if defined(__APPLE__)
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

extern const float PI;

extern bool isTexture;
extern GLuint textures[];
extern int activeTexture;

extern bool defenseMode;
extern bool attackMode;

extern bool showGun;
extern bool showSword;
extern bool headAttackMode;
extern bool gunAttackMode;
extern bool swordAttackMode;

extern float cWhite[];
extern float cBlack[];
extern float cGrey[];
extern float cLightGrey[];
extern float cLightGrey2[];
extern float cHeadRed[];
extern float cEyeYellow[];
extern float cEarGrey[];
extern float cAntennaYellow[];

extern float cDarkBlue[];
extern float cLightSkinGrey[];
extern float cLightSkinGrey2[];
extern float cPrimaryBlue[];
extern float cPrimaryLightBlue[];
extern float cLegBoost[];
