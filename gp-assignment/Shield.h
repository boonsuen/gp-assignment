#pragma once
#ifndef Shield_h
#define Shield_h
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

class Shield {
public:
	Utility u;
    float scale = 0;
    float translate = 0;
    
	void drawShield();
	void drawHandle();
};

void Shield::drawHandle() {
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textures[11]);
    
    u.drawCylinder(cDarkBlue, 0.05, 0.05, 0.2, 30, 30, GLU_FILL, true, 0.15, 0, -0.15);

    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    glPopMatrix();
}

float r = 0;
void Shield::drawShield() {
    r = 0;
    glPushMatrix();
    glTranslatef(0.146, 0.15, -0.145);
    glRotatef(r, 0, 1, 0);
    glTranslatef(-0.146, -0.15, 0.145);
    
    glPushMatrix();
    glTranslatef(0, 0.15, -0.145);
    glTranslatef(0, translate, 0);
    glScalef(1, scale, scale);
    glTranslatef(0, -0.15, 0.145);
    
    if (defenseMode) {
        if (scale < 1) {
            scale += 0.01;
        }
        if (translate > 0) {
            translate -= 0.002;
        }
    } else {
        if (scale >= 0) {
            scale -= 0.01;
            if (scale < 0) {
                scale = 0;
            }
        }
        if (translate <= 0.2) {
            translate += 0.002;
        }
    }
    
    drawHandle();
    
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.2f);
	glScalef(2.0f, 2.0f, 2.0f);

	glPushMatrix();
	glScalef(1.0f, 2.0f, 1.0f);
    glColor3fv(isTexture ? cWhite : cLightGrey);
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture == 2 ? 1 : 9]);
	u.shieldPentagon(0.0f, 0.03f);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9f, 1.7f, 0.9f);
	glTranslatef(0, -0.005, 0.005);
    glColor3fv(cHeadRed);
    glBindTexture(GL_TEXTURE_2D, textures[6]);
	u.shieldPentagon(0.0f, 0.04f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.04);

    glBindTexture(GL_TEXTURE_2D, 0);
    glColor3fv(cEyeYellow);
	u.starVertical(0.0f, 0.025f, 0.125f, 0.15f, 0.0f, 0.01f);
	u.starHorizontal(0.075f, 0.1f, 0.0f, 0.025f, 0.0f, 0.01f);
    
	glPopMatrix();
	glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
}
