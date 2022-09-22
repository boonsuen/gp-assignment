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
    void drawBody();
	void drawOverallBody();
	void rocketThrust();
	void drawBack();
};

void Body::drawOverallBody() {
	glPushMatrix();

	//base
	textures = u.loadTexture("red.bmp");
	u.drawShape(-0.45f, 0.15f, -0.435f, 0.135f, 0.8f, 0.8f, 1.0f, 1.0f, 0.0f, 0.2f, 0.025f, 0.175f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);

	//middle body
	glPushMatrix();
	//left middle
	u.drawShape_6(-0.475f, -0.275f, -0.5f, -0.3f, 1.0f, 1.0f, 1.4f, 1.4f, 0.015f, 0.185f, 0.015f, 0.35f, "red.bmp", "red.bmp", "red.bmp", "red.bmp", "red.bmp", "red.bmp");
	//middle middle
	u.drawShape_3(-0.275f, -0.025f, -0.3f, 0.0f, 1.0f, 1.0f, 1.4f, 1.4f, 0.015f, 0.125f, 0.015f, 0.25f, "blue.bmp", "blue.bmp", "blue.bmp");
	//right middle
	u.drawShape_6(-0.025f, 0.175f, 0.0f, 0.2f, 1.0f, 1.0f, 1.4f, 1.4f, 0.015f, 0.185f, 0.015f, 0.35f, "red.bmp", "red.bmp", "red.bmp", "red.bmp", "red.bmp", "red.bmp");

	//Design for middle middle
	glLineWidth(5.0f);

	textures = u.loadTexture("white.bmp");
	u.drawInnerBody(-0.3f, 1.35f, 0.3f, 0.0f, 1.35f, 0.3f);
	u.drawInnerBody(-0.3f, 1.25f, 0.25f, 0.0f, 1.25f, 0.25f);
	u.drawInnerBody(-0.3f, 1.15f, 0.225f, 0.0f, 1.15f, 0.225f);
	u.drawInnerBody(-0.3f, 1.05f, 0.175f, 0.0f, 1.05f, 0.175f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glLineWidth(1.0f);
	glPopMatrix();

	////connect right hand
	//textures = loadTexture("glowingYellow.bmp");
	//drawShape(-0.75f, -0.475f, -0.75f, -0.5f, 1.775f, 1.775f, 1.525f, 1.4f, 0.015f, 0.185f, 0.015f, 0.25f);
	//glDeleteTextures(1, &textures);
	//glDisable(GL_TEXTURE_2D);

	//Top
	textures = u.loadTexture("blue.bmp");
	u.drawShape(-0.5f, 0.2f, -0.475f, 0.175f, 1.4f, 1.4f, 1.75f, 1.75f, 0.015f, 0.35f, 0.015f, 0.185f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);

	////connect left hand
	//textures = loadTexture("glowingYellow.bmp");
	//drawShape(0.2f, 0.45f, 0.175f, 0.45f, 1.4f, 1.525f, 1.775f, 1.775f, 0.015f, 0.25f, 0.015f, 0.185f);
	//glDeleteTextures(1, &textures);
	//glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Body::rocketThrust() {
	glPushMatrix();
	//Left
	glPushMatrix();
	glTranslatef(0.0f, 0.7f, -0.55f);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -1.0f);
	glRotatef(-25.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(-0.0f, -1.0f, 1.0f);
	textures = u.loadTexture("blackSilver.bmp");
	u.drawCylinder(0.15f, 0.08f, 0.15f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	//Right
	glPushMatrix();
	glTranslatef(-0.3f, 0.7f, -0.55f);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -1.0f);
	glRotatef(-25.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(-0.0f, -1.0f, 1.0f);
	textures = u.loadTexture("blackSilver.bmp");
	u.drawCylinder(0.15f, 0.08f, 0.15f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glRotatef(0.9, 1, 1, 1);
	glPushMatrix();
	glTranslatef(-0.3f, 1.2f, -0.24f);
	glRotatef(-25.0f, 0.1f, 0.0f, 0.0f);
	glScalef(1.0, 1.0, 0.8);
	textures = u.loadTexture("rocketPower.bmp");
	u.drawSphere(0.11);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(0.3f, 0.0f, 0.0f);
	textures = u.loadTexture("rocketPower.bmp");
	u.drawSphere(0.11);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
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

	textures = u.loadTexture("backpack.bmp");
	u.drawShape(-0.4f, 0.1f, -0.4f, 0.1f, 1.2f, 1.2f, 1.4f, 1.4f, 0.2f, -0.485f, 0.2f, -0.185f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPopMatrix();

	//Sword
	glPushMatrix();
	glRotatef(90.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(0.0f, -0.1f, -2.0f);
	glScalef(1.0, 0.8, 1.0);
	textures = u.loadTexture("white.bmp");
	u.drawCylinder(0.05f, 0.05f, 0.3f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	textures = u.loadTexture("backpack.bmp");
	u.drawSphere(0.05);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.1f, 0.0f, 0.0f);
	glTranslatef(-0.27f, -0.1f, -2.0f);
	glScalef(1.0, 0.8, 1.0);
	textures = u.loadTexture("white.bmp");
	u.drawCylinder(0.05f, 0.05f, 0.3f);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
	textures = u.loadTexture("backpack.bmp");
	u.drawSphere(0.05);
	glDeleteTextures(1, &textures);
	glDisable(GL_TEXTURE_2D);
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