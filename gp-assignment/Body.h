#pragma once
#ifndef Body_h
#define Body_h
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

class Body {
public:
    Utility u;
    float rocketRotate = 0;
    void drawBody();
	void drawOverallBody();
	void rocketThrust();
	void drawBack();
};

GLfloat cBodyRed[] = { 226.0/255, 58.0/255, 52.0/255 };

void Body::drawOverallBody() {
	glPushMatrix();

	// Base
    glColor3fv(cWhite);
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
	u.drawShape(-0.45f, 0.15f, -0.435f, 0.135f, 0.8f, 0.8f, 1.0f, 1.0f, 0.0f, 0.2f, 0.025f, 0.175f);

    glColor3fv(cBodyRed);
	// Middle body
	glPushMatrix();
	// Left middle
    glBindTexture(GL_TEXTURE_2D, textures[6]);
	u.drawShape(-0.475f, -0.275f, -0.5f, -0.3f, 1.0f, 1.0f, 1.4f, 1.4f, 0.015f, 0.185f, 0.015f, 0.35f);
	// Middle middle
    GLfloat midleMiddleAttackModeColor[] = { 33.0/255, 242.0/255, 169.0/255 };
    glColor3fv(attackMode ? midleMiddleAttackModeColor : cPrimaryBlue);
    glBindTexture(GL_TEXTURE_2D, textures[7]);
	u.drawShape(-0.275f, -0.025f, -0.3f, 0.0f, 1.0f, 1.0f, 1.4f, 1.4f, 0.015f, 0.125f, 0.015f, 0.25f);
	// Right middle
    glColor3fv(cBodyRed);
    glBindTexture(GL_TEXTURE_2D, textures[6]);
	u.drawShape(-0.025f, 0.175f, 0.0f, 0.2f, 1.0f, 1.0f, 1.4f, 1.4f, 0.015f, 0.185f, 0.015f, 0.35f);

	// Design for middle middle
	glLineWidth(5.0f);

    glColor3fv(cWhite);
    glBindTexture(GL_TEXTURE_2D, textures[6]);
	u.drawInnerBody(-0.3f, 1.35f, 0.3f, 0.0f, 1.35f, 0.3f);
	u.drawInnerBody(-0.3f, 1.25f, 0.25f, 0.0f, 1.25f, 0.25f);
	u.drawInnerBody(-0.3f, 1.15f, 0.225f, 0.0f, 1.15f, 0.225f);
	u.drawInnerBody(-0.3f, 1.05f, 0.175f, 0.0f, 1.05f, 0.175f);
	glLineWidth(1.0f);
	glPopMatrix();

	////connect right hand
	//textures = loadTexture("glowingYellow.bmp");
	//drawShape(-0.75f, -0.475f, -0.75f, -0.5f, 1.775f, 1.775f, 1.525f, 1.4f, 0.015f, 0.185f, 0.015f, 0.25f);
	//glDeleteTextures(1, &textures);
	//glDisable(GL_TEXTURE_2D);

	// Top
    glColor3fv(cPrimaryLightBlue);
    glBindTexture(GL_TEXTURE_2D, textures[7]);
	u.drawShape(-0.5f, 0.2f, -0.475f, 0.175f, 1.4f, 1.4f, 1.75f, 1.75f, 0.015f, 0.35f, 0.015f, 0.185f);

	////connect left hand
	//textures = loadTexture("glowingYellow.bmp");
	//drawShape(0.2f, 0.45f, 0.175f, 0.45f, 1.4f, 1.525f, 1.775f, 1.775f, 0.015f, 0.25f, 0.015f, 0.185f);
	//glDeleteTextures(1, &textures);
	//glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Body::rocketThrust() {
	glPushMatrix();
    
	// Left
	glPushMatrix();
	glTranslatef(0.0f, 0.7f, -0.55f);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -1.0f);
	glRotatef(-25.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(-0.0f, -1.0f, 1.0f);
    glColor3fv(cLightGrey);
    glBindTexture(GL_TEXTURE_2D, textures[9]);
	u.drawCylinder(0.15f, 0.08f, 0.15f);
	glPopMatrix();
	glPopMatrix();
    
	// Right
	glPushMatrix();
	glTranslatef(-0.3f, 0.7f, -0.55f);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -1.0f);
	glRotatef(-25.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(-0.0f, -1.0f, 1.0f);
	u.drawCylinder(0.15f, 0.08f, 0.15f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
    
	glPushMatrix();
        glTranslatef(-0.3f, 1.2f, -0.24f);
        glRotatef(-25.0f, 0.1f, 0.0f, 0.0f);
        glScalef(1.0, 1.0, 0.8);
        {
        glColor3fv(isTexture ? cWhite : cPrimaryBlue);
        glBindTexture(GL_TEXTURE_2D, textures[10]);
            
        glPushMatrix();
        glRotatef(rocketRotate, 0, 1, 0);
        u.drawSphere(0.11);
        glPopMatrix();
            
        glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.0f);
        glRotatef(-rocketRotate, 0, 1, 0);
        u.drawSphere(0.11);
        glPopMatrix();
            
        rocketRotate += 1;
        }
	glPopMatrix();
}

void Body::drawBack() {
	glPushMatrix();

	//Back
	glPushMatrix();
	glTranslatef(0.0f, -0.025f, -0.19f);

	glPushMatrix();
	glTranslatef(-0.15f, 1.4875f, -0.085f);
	glRotatef(90.0f, -0.1f, 0.0f, 0.0f);
	glTranslatef(0.15f, -1.4875f, 0.085f);

    glColor3fv(isTexture ? cWhite : cDarkBlue);
    glBindTexture(GL_TEXTURE_2D, textures[8]);
	u.drawShape(-0.4f, 0.1f, -0.4f, 0.1f, 1.2f, 1.2f, 1.4f, 1.4f, 0.2f, -0.485f, 0.2f, -0.185f);

	glPopMatrix();
	glPopMatrix();

	//Sword
	glPushMatrix();
	glRotatef(90.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(0.0f, -0.1f, -2.0f);
	glScalef(1.0, 0.8, 1.0);
    glColor3fv(isTexture ? cWhite : cGrey);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
	u.drawCylinder(0.05f, 0.05f, 0.3f);
	u.drawSphere(0.05);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(-0.27f, -0.1f, -2.0f);
	glScalef(1.0, 0.8, 1.0);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glColor3fv(isTexture ? cWhite : cGrey);
	u.drawCylinder(0.05f, 0.05f, 0.3f);
	u.drawSphere(0.05);
	glPopMatrix();

	//Thrust
	glPushMatrix();
	rocketThrust();
	glPopMatrix();

	glPopMatrix();
}

void Body::drawBody() {
	glPushMatrix();
	drawOverallBody();
	drawBack();
	glPopMatrix();
}
