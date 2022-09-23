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
	void DrawShield();
	void DrawHandle();
	void callShield();
};

void Shield::DrawHandle() {

	glPushMatrix();
	textures = u.loadTexture("HandleBlack.bmp");
	u.drawRectangle(0.0f, 0.3f, 0.0f, 0.05f, 0.0f, 0.05f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glRotatef(60.0f, 0.0f, 0.0f, -1.0f);
	glTranslatef(-0.2f, 0.0f, 0.0f);

	textures = u.loadTexture("HandleBlack.bmp");
	u.drawRectangle(0.0f, 0.2f, 0.0f, 0.05f, 0.0f, 0.05f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3f, 0.0f, 0.0f);
	glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.3f, -0.0f, -0.0f);

	glTranslatef(0.3f, 0.0f, 0.0f);

	textures = u.loadTexture("HandleBlack.bmp");
	u.drawRectangle(0.0f, 0.2f, 0.0f, 0.05f, 0.0f, 0.05f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

void Shield::DrawShield() {

	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.2f);
	glScalef(2.0f, 2.0f, 2.0f);

	glPushMatrix();
	glScalef(1.0f, 2.0f, 1.0f);
	textures = u.loadTexture("white.bmp");
	u.shieldPentagon(0.0f, 0.03f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9f, 1.7f, 0.9f);
	glTranslatef(0, -0.005, 0.005);
	textures = u.loadTexture("red.bmp");
	u.shieldPentagon(0.0f, 0.04f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.04);

	textures = u.loadTexture("yellow.bmp");
	u.starVertical(0.0f, 0.025f, 0.125f, 0.15f, 0.0f, 0.01f);
	u.starHorizontal(0.075f, 0.1f, 0.0f, 0.025f, 0.0f, 0.01f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPopMatrix();
}

void Shield::callShield() {

	glPushMatrix();
	glTranslatef(-0.2, 0.23f, -0.15f);
	glScalef(0.65f, 0.65f, 0.65f);

	DrawHandle();
	DrawShield();
	glPopMatrix();

}
