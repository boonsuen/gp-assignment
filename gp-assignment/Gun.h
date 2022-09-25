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
	void drawCubeTexture();
};

void drawCubeTexture(float length, float width, float height, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	glBegin(GL_QUADS);
	//Face size : Bottom
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(length, 0.0f, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(length, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	//Face 2 : Left
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, width, height);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, width, 0.0f);

	//Face 3 : Front
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, width, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(length, width, height);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(length, 0.0f, height);

	//Face 4 : Right
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(length, 0.0f, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(length, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(length, width, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(length, width, height);

	//Face 5 : Top
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(length, width, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, width, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, width, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(length, width, 0.0f);

	//Face 6 : Back
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(length, width, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(length, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, width, 0.0f);
	glEnd();
	glDeleteTextures(1, &texture);
}

void cylinderTexture(float baseRadius, float topRadius, float height, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);

	GLUquadric* cylinder = NULL;
	cylinder = gluNewQuadric();

	gluQuadricTexture(cylinder, TRUE);
	gluQuadricNormals(cylinder, GLU_SMOOTH);

	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, baseRadius, topRadius, height, 30, 30);

	gluDeleteQuadric(cylinder);
	glDeleteTextures(1, &texture);
}

void sphereTexture1(float radius, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);

	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();

	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);

	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, radius, 30, 30);

	gluDeleteQuadric(sphere);
	glDeleteTextures(1, &texture);
}


void Gun::drawGun() {
	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);

	//////////////////////////////////////////////////front part
	glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cEyeYellow);
	u.drawCube(7, 4, 2, cEyeYellow,0,0,0);
	//drawCubeTexture(0.35, 0.2, 0.1, "gunFront.bmp");

	//////////////////////////////////////////////////////hand to hold
	glPushMatrix();
	glRotatef(5, 0, 0, 1);
	//glTranslatef(0.4, 0.01, 0.05);
	glTranslatef(8, 0.2, 1);
	glScalef(1.3, 0.5, 0.35);
	//sphereTexture(0.15, "gunFrFrHandle.bmp");
	glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cDarkGreen);
	u.drawSphere(3,30,30,GLU_FILL,cDarkGreen,0,0,0);
	glPopMatrix();

	/////////////////////////////////////////////////////down
	glPushMatrix();
	//glTranslatef(0.2, -0.03, -0.02);
	glTranslatef(4, -0.6, -0.4);
	//drawCubeTexture(0.2, 0.13, 0.13, "gunFrFrHandle.bmp");
	u.drawCube(4, 2.6, 2.6, cDarkGreen, 0, 0, 0);
	glPopMatrix();

	/////////////////////////////////////////////////////front
	glPushMatrix();
	//glTranslatef(0.25, 0.06, -0.005);
	glTranslatef(5, 1.2, 0.1);
	//drawCubeTexture(0.3, 0.15, 0.11, "gunFrontUp.bmp");
	u.drawCube(6, 3, 2.2, cDarkGreen1, 0, 0, 0);
	glPopMatrix();

	/////////////////////////////////////////////front up
	glPushMatrix();
	//glTranslatef(0.55, 0.05, -0.005);
	glTranslatef(11, 1, 0.1);
	//drawCubeTexture(0.2, 0.15, 0.11, "gunFrontUp.bmp");
	u.drawCube(4, 3, 2.2, cDarkGreen1, 0, 0, 0);
	glPopMatrix();

	///////////////////////////////////////front down
	glPushMatrix();
	//glTranslatef(0.55, 0.05, 0.05);
	glTranslatef(11, 1, 1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.05, 0.05, 0.17, "gunFrontUp.bmp");
	u.drawCylinder(cDarkGreen1,1, 1, 3.4,30,30,GLU_FILL,true,0,0,0);
	glPopMatrix();

	/////////////////////////////////////////place back and to shoot
	glPushMatrix();
	//glTranslatef(0.65, 0.035, 0.05);
	glTranslatef(13, 0.7, 1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.025, 0.025, 0.25, "gunAim.bmp");
	u.drawCylinder(cDarkGreen1, 0.5, 0.5, 5, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(0.9, 0.035, 0.05);
	glTranslatef(18, 0.7, 1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	u.drawCylinder(cDarkGreen1, 0.7, 0.7, 5, 30, 30, GLU_FILL, true, 0, 0, 0);
	//cylinderTexture(0.035, 0.035, 0.1, "gunShoot.bmp");
	glPopMatrix();

	/////////////////////////////////////////place to aim
	glPushMatrix();
	//glTranslatef(0.75, 0.15, 0.05);
	glTranslatef(15,3,1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	u.drawCylinder(cDarkGreen1, 0.5, 0.5, 1, 30, 30, GLU_FILL, true, 0, 0, 0);
	//cylinderTexture(0.025, 0.025, 0.05, "gunAim.bmp");
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(0.7, 0.24, 0.05);
	glTranslatef(14, 4.8, 1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	u.drawCylinder(cHeadRed, 0.8, 0.8, 0.6, 30, 30, GLU_FILL, true, 0, 0, 0);
	//cylinderTexture(0.04, 0.04, 0.03, "gunAim.bmp");
	glPopMatrix();

	///////////////////////////////////body
	glPushMatrix();
	//glTranslatef(-0.5, -0.05, 0);
	//drawCubeTexture(0.5, 0.2, 0.1, "gunBody.bmp");
	glTranslatef(-10, -1,0);
	u.drawCube(10, 4, 2, cBlack, 0, 0, 0);
	glPopMatrix();

	//////////////////////////////////body down
	glPushMatrix();
	//glTranslatef(-0.17, -0.15, 0);
	//drawCubeTexture(0.15, 0.1, 0.1, "gunFrHandle.bmp");
	glTranslatef(-3.4, -3, 0);
	u.drawCube(3, 2, 2, cGrey, 0, 0, 0);
	glPushMatrix();

	//glTranslatef(0.02, -0.15, 0);
	//drawCubeTexture(0.11, 0.15, 0.1, "gunFrHandle.bmp");
	glTranslatef(0.4, 3, 0);
	u.drawCube(2.2, 3, 2, cGrey, 0, 0, 0);
	glPopMatrix();
	glPopMatrix();

	////////////////////////////////body up
	glPushMatrix();
	//glTranslatef(-0.34, 0.23, 0.05);
	glTranslatef(-6.8, 4.6, 1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.02, 0.02, 0.3, "gunBodyUp.bmp");
	u.drawCylinder(cHeadRed, 0.4, 0.4, 6, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(0.01, 0.135, 0.05);
	glTranslatef(0.2, 2.7, 1);
	glRotatef(30, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.02, 0.02, 0.12, "gunBodyUp.bmp");
	u.drawCylinder(cWhite, 0.4, 0.4, 2.4, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(-0.44, 0.135, 0.05);
	glTranslatef(-8.8, 2.7, 1);
	glRotatef(50, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.02, 0.02, 0.15, "gunBodyUp.bmp");
	u.drawCylinder(cHeadRed, 0.4, 0.4, 3, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	///////////////////////////////handle
	glPushMatrix();
	//glTranslatef(-0.4, -0.3, 0.05);
	glTranslatef(-8, -6,1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.035, 0.035, 0.3, "gunHandle.bmp");
	u.drawCylinder(cHeadRed, 0.7, 0.7, 6, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	///////////////////////////////////////back
	glPushMatrix();                     //up
	//glTranslatef(-0.9, 0.1, 0.05);
	glTranslatef(-18, 2, 1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.02, 0.02, 0.4, "gunBodyBack.bmp");
	u.drawCylinder(cWhite, 4, 4, 8, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();                     //down
	//glTranslatef(-0.7, 0, 0.05);
	glTranslatef(-14, 0, 0.1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.02, 0.02, 0.2, "gunBodyBack.bmp");
	u.drawCylinder(cWhite, 0.4, 0.4, 4, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(-0.8, -0.06, 0.05);
	glTranslatef(-16, -1.2, 1);
	glRotatef(60, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.02, 0.02, 0.13, "gunBodyBack.bmp");
	u.drawCylinder(cWhite, 0.4, 0.4, 2.6, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(-0.89, -0.06, 0.05);
	glTranslatef(-17.8, -1.2, 1);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	//cylinderTexture(0.02, 0.02, 0.1, "gunBodyBack.bmp");
	u.drawCylinder(cWhite, 0.4, 0.4, 2, 30, 30, GLU_FILL, true, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();      //back
	//glTranslatef(-0.93, -0.08, 0.02);
	//drawCubeTexture(0.05, 0.2, 0.05, "gunBodyBackBk.bmp");
	glTranslatef(-18.6, -1.6, 0.4);
	u.drawCube(1, 4, 0.1, cWhite, 0, 0, 0);
	glPopMatrix();

	glPopMatrix();
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
