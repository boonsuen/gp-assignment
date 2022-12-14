#pragma once
#ifndef Head_h
#define Head_h
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

class Head {
public:
    Utility u;
    float headHorizontalAngle = 0;
    float headHorizontalAngleMax = 45;
    float headVerticalAngle = 0;
    float headVerticalBackAngleMax = 20;
    
    void drawEye(bool isRed, bool isLeft);
    void drawFace();
    void drawBulletAnimation(float tx, float ty, float tz);
    void drawToppings();
    void drawCheek();
    void drawHead();
    void keyActions(unsigned char key);
};

void Head::drawEye(bool isRed, bool isLeft) {
    glPushMatrix();
    GLfloat eyeAttackModeColor[] = { 33.0/255, 242.0/255, 169.0/255 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, isRed ? cHeadRed : (attackMode ? eyeAttackModeColor : cEyeYellow));
    glColor3fv(isRed ? cHeadRed : (attackMode ? eyeAttackModeColor : cEyeYellow));
    if (isRed) {
        glScalef(1.15, 1.15, 1);
        glTranslatef(isLeft ? 0.15 : -0.15, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex3f(isLeft ? -2 : 2, -0.1, isRed ? 2.005 : 2.01);
    glVertex3f(isLeft ? -2 : 2, -0.2, isRed ? 2.005 : 2.01);
    glVertex3f(isLeft ? -1.4 : 1.4, -0.5, isRed ? 2.005 : 2.01);
    glVertex3f(isLeft ? -0.15 : 0.15, -0.3, isRed ? 2.005 : 2.01);
    glVertex3f(isLeft ? -0.15 : 0.15, -0.2, isRed ? 2.005 : 2.01);
    glEnd();
    glPopMatrix();
}

void Head::drawFace() {
    glBindTexture(GL_TEXTURE_2D, 0);
    drawEye(true, true);
    drawEye(true, false);
    drawEye(false, true);
    drawEye(false, false);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cWhite);
    glColor3fv(cWhite);
    glBegin(GL_POLYGON);
    glVertex3f(-2.1, -0.34, 2.01);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cLightGrey2);
    glColor3fv(cLightGrey2);
    glVertex3f(-2.1, -2.2, 2.01);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cWhite);
    glColor3fv(cWhite);
    glVertex3f(0, -2.7, 2.31);
    glVertex3f(-1.4, -0.65, 2.31);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0, -2.7, 2.31);
    glVertex3f(0, -0.45, 2.31);
    glVertex3f(-1.4, -0.65, 2.31);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(2.1, -0.34, 2.01);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cLightGrey2);
    glColor3fv(cLightGrey2);
    glVertex3f(2.1, -2.2, 2.01);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cWhite);
    glColor3fv(cWhite);
    glVertex3f(0, -2.7, 2.31);
    glVertex3f(1.4, -0.65, 2.31);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0, -2.7, 2.31);
    glVertex3f(0, -0.45, 2.31);
    glVertex3f(1.4, -0.65, 2.31);
    glEnd();

    // Nose
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cGrey);
    glColor3fv(cGrey);
    glBegin(GL_QUADS);
    glVertex3f(-0.6, -0.9, 2.315); glVertex3f(-0.6, -1.1, 2.315);
    glVertex3f(0, -0.95, 2.315); glVertex3f(0, -0.75, 2.315);
    glVertex3f(-0.6, -1.2, 2.315); glVertex3f(-0.6, -1.4, 2.315);
    glVertex3f(0, -1.25, 2.315); glVertex3f(0, -1.05, 2.315);
    glVertex3f(0.6, -0.9, 2.315); glVertex3f(0.6, -1.1, 2.315);
    glVertex3f(0, -0.95, 2.315); glVertex3f(0, -0.75, 2.315);
    glVertex3f(0.6, -1.2, 2.315); glVertex3f(0.6, -1.4, 2.315);
    glVertex3f(0, -1.25, 2.315); glVertex3f(0, -1.05, 2.315);
    glEnd();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cHeadRed);
    GLfloat lMouthV1[] = { -0.5, -2.65, 2.6 }; GLfloat lMouthV5[] = { -0.5, -2.65, 1.8 };
    GLfloat lMouthV2[] = { 0, -3, 2.8 };       GLfloat lMouthV6[] = { 0, -2.7, 1.8 };
    GLfloat lMouthV3[] = { 0, -2, 2.8 };       GLfloat lMouthV7[] = { 0, -2, 1.8 };
    GLfloat lMouthV4[] = { -0.5, -2.2, 2.6 };  GLfloat lMouthV8[] = { -0.5, -2.2, 1.8 };
    u.drawSixFacesPolygon(lMouthV1, lMouthV2, lMouthV3, lMouthV4,
        lMouthV5, lMouthV6, lMouthV7, lMouthV8, cHeadRed);
    GLfloat rMouthV1[] = { 0, -3, 2.8 };      GLfloat rMouthV5[] = { 0, -2.7, 1.8 };
    GLfloat rMouthV2[] = { 0.5, -2.65, 2.6 }; GLfloat rMouthV6[] = { 0.5, -2.65, 1.8 };
    GLfloat rMouthV3[] = { 0.5, -2.2, 2.6 };  GLfloat rMouthV7[] = { 0.5, -2.2, 1.8 };
    GLfloat rMouthV4[] = { 0, -2, 2.8 };      GLfloat rMouthV8[] = { 0, -2, 1.8 };
    u.drawSixFacesPolygon(rMouthV1, rMouthV2, rMouthV3, rMouthV4,
        rMouthV5, rMouthV6, rMouthV7, rMouthV8, cHeadRed);
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
}

float headBulletTz1 = 0;
float headBulletTz2 = 0;
GLfloat bulletColor[] = { 249.0/255, 75.0/255, 44.0/255 };

class HeadBullet {
public:
    Utility u;
    void draw(float tz) {
        glPushMatrix();
        if (tz >= 0) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, bulletColor);
            u.drawSphere(0.2, 10, 10, GLU_FILL, bulletColor, 0, 0, tz);
        }
        glPopMatrix();
    }
};

HeadBullet headBullet;
void Head::drawBulletAnimation(float tx, float ty, float tz) {
    glBindTexture(GL_TEXTURE_2D, 0);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    if (headBulletTz1 > 50) {
        headBulletTz1 = 0;
    }
    if (headBulletTz2 >= 60) {
        headBulletTz2 = 0;
    }
    
    headBullet.draw(0 + headBulletTz1);
    headBullet.draw(-1 + headBulletTz1);
    headBullet.draw(-2 + headBulletTz1);
    headBullet.draw(-3 + headBulletTz1);
    headBullet.draw(-4 + headBulletTz1);
    
    headBullet.draw(-10 + headBulletTz2);
    headBullet.draw(-11 + headBulletTz2);
    headBullet.draw(-12 + headBulletTz2);
    headBullet.draw(-13 + headBulletTz2);
    headBullet.draw(-14 + headBulletTz2);
    
    if (!(headBulletTz2 > 50 && headBulletTz2 < 60)) {
        headBulletTz1 += 0.1;
    }
    headBulletTz2 += 0.1;
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
}

void Head::drawToppings() {
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cLightGrey);
    u.drawCircle(cLightGrey, 3, 3, 0, true, false, false, 0, 0, 0);
    u.drawHemisphere(3.0, 30, 30, cLightGrey, 0, 0, 0);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cWhite);
    // Hat
    GLfloat whiteHatV1[] = { -0.5, 2.9, 1.8 }; GLfloat whiteHatV5[] = { -0.5, 2, -2.2 };
    GLfloat whiteHatV2[] = { 0.5, 2.9, 1.8 }; GLfloat whiteHatV6[] = { 0.5, 2, -2.2 };
    GLfloat whiteHatV3[] = { 0.35, 3.7, 1.5 }; GLfloat whiteHatV7[] = { 0.35, 3.3, -1.5 };
    GLfloat whiteHatV4[] = { -0.35, 3.7, 1.5 }; GLfloat whiteHatV8[] = { -0.35, 3.3, -1.5 };
    u.drawSixFacesPolygon(whiteHatV1, whiteHatV2, whiteHatV3, whiteHatV4,
        whiteHatV5, whiteHatV6, whiteHatV7, whiteHatV8, cWhite);
    whiteHatV5[1] = -2;
    whiteHatV6[1] = -2;
    u.drawSixFacesPolygon(whiteHatV1, whiteHatV2, whiteHatV3, whiteHatV4,
        whiteHatV5, whiteHatV6, whiteHatV7, whiteHatV8, cWhite);

    glPushMatrix(); {
        glBindTexture(GL_TEXTURE_2D, 0);
        GLfloat topAttackModeColor[] = { 124.0/255, 254.0/255, 210.0/255 };
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, attackMode ? topAttackModeColor : cGrey);
        glColor3fv(attackMode ? topAttackModeColor : cGrey);
        glBegin(GL_QUADS);
        glVertex3f(-0.35, 3, 1.801); glVertex3f(0.35, 3, 1.801);
        glVertex3f(0.25, 3.6, 1.601); glVertex3f(-0.25, 3.6, 1.601);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
        glPopMatrix();
    }

    glPushMatrix(); {
        glBindTexture(GL_TEXTURE_2D, 0);
        glTranslatef(0, 1.4, 2.43);
        glRotatef(30, 1, 0, 0);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cHeadRed);
        u.drawCube(1, 2, 2.7, cHeadRed, 0, 0, 0);
        glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    }
    glPopMatrix();

    // Antennas
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cAntennaYellow);
    glBindTexture(GL_TEXTURE_2D, 0);
    GLfloat yellowAntennaV1[] = { 1, 0.8, 3.2 }; GLfloat yellowAntennaV5[] = { 1, 0.7, 3.1 };
    GLfloat yellowAntennaV2[] = { 2.5, 5.2, 2.5 }; GLfloat yellowAntennaV6[] = { 2.4, 5.2, 2.4 };
    GLfloat yellowAntennaV3[] = { 2.5, 5.4, 2.5 }; GLfloat yellowAntennaV7[] = { 2.4, 5.4, 2.4 };
    GLfloat yellowAntennaV4[] = { 1, 0.8, 3.2 }; GLfloat yellowAntennaV8[] = { 1, 1.3, 3.1 };
    u.drawSixFacesPolygon(yellowAntennaV1, yellowAntennaV2, yellowAntennaV3, yellowAntennaV4,
        yellowAntennaV5, yellowAntennaV6, yellowAntennaV7, yellowAntennaV8, cAntennaYellow);
    yellowAntennaV1[0] = -1.0; yellowAntennaV5[0] = -1.0;
    yellowAntennaV2[0] = -2.5; yellowAntennaV6[0] = -2.4;
    yellowAntennaV3[0] = -2.5; yellowAntennaV7[0] = -2.4;
    yellowAntennaV4[0] = -1.0; yellowAntennaV8[0] = -1.0;
    u.drawSixFacesPolygon(yellowAntennaV1, yellowAntennaV2, yellowAntennaV3, yellowAntennaV4,
        yellowAntennaV5, yellowAntennaV6, yellowAntennaV7, yellowAntennaV8, cAntennaYellow);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cWhite);
    GLfloat whiteAntennaV1[] = { 0, 0.5, 3.3 }; GLfloat whiteAntennaV5[] = { 0, 0.4, 3.2 };
    GLfloat whiteAntennaV2[] = { 6, 2.2, 2.7 }; GLfloat whiteAntennaV6[] = { 5.9, 2.2, 2.6 };
    GLfloat whiteAntennaV3[] = { 6, 2.4, 2.7 }; GLfloat whiteAntennaV7[] = { 5.9, 2.4, 2.6 };
    GLfloat whiteAntennaV4[] = { 0, 0.8, 3.4 }; GLfloat whiteAntennaV8[] = { 0, 1.2, 3.3 };
    u.drawSixFacesPolygon(whiteAntennaV1, whiteAntennaV2, whiteAntennaV3, whiteAntennaV4,
        whiteAntennaV5, whiteAntennaV6, whiteAntennaV7, whiteAntennaV8, cWhite);
    whiteAntennaV2[0] = -6; whiteAntennaV6[0] = -5.9;
    whiteAntennaV3[0] = -6; whiteAntennaV7[0] = -5.9;
    u.drawSixFacesPolygon(whiteAntennaV1, whiteAntennaV2, whiteAntennaV3, whiteAntennaV4,
        whiteAntennaV5, whiteAntennaV6, whiteAntennaV7, whiteAntennaV8, cWhite);
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);

    // Ears
    glPushMatrix(); {
        if (headAttackMode) {
            this->drawBulletAnimation(2.6, 2, 0.2);
            this->drawBulletAnimation(-2.6, 2, 0.2);
        }
        glScalef(1, 1, 4.5);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cEarGrey);
        u.drawHemisphere(0.4, 20, 20, cEarGrey, 2.6, 2, 0.2);
        u.drawCircle(cGrey, 0.4, 0.4, 0, true, false, false, 2.6, 2, 0.2);
        u.drawCircle(cBlack, 0.3, 0.3, 0, true, false, false, 2.6, 2, 0.201);

        u.drawHemisphere(0.4, 20, 20, cEarGrey, -2.6, 2, 0.2);
        u.drawCircle(cGrey, 0.4, 0.4, 0, true, false, false, -2.6, 2, 0.2);
        u.drawCircle(cBlack, 0.3, 0.3, 0, true, false, false, -2.6, 2, 0.201);
    }
    glPopMatrix();
}

void Head::drawCheek() {
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cWhite);
    u.drawCube(4.5, 2.5, 0.5, cWhite, 0, -2.5 / 2, -2 - 0.5 / 2);

    GLfloat whiteSideV1[] = { 2.25, -2.5, 2.5 }; GLfloat whiteSideV5[] = { 2.25, -2.5, -2.5 };
    GLfloat whiteSideV2[] = { 2.75, -2.0, 2.5 }; GLfloat whiteSideV6[] = { 2.75, -2.0, -2.5 };
    GLfloat whiteSideV3[] = { 2.75, 0, 2.5 }; GLfloat whiteSideV7[] = { 2.75, 0, -2.5 };
    GLfloat whiteSideV4[] = { 2.25, 0, 2.5 }; GLfloat whiteSideV8[] = { 2.25, 0, -2.5 };
    u.drawSixFacesPolygon(whiteSideV1, whiteSideV2, whiteSideV3, whiteSideV4,
        whiteSideV5, whiteSideV6, whiteSideV7, whiteSideV8, cWhite);
    whiteSideV1[0] = -2.25; whiteSideV5[0] = -2.25;
    whiteSideV2[0] = -2.75; whiteSideV6[0] = -2.75;
    whiteSideV3[0] = -2.75; whiteSideV7[0] = -2.75;
    whiteSideV4[0] = -2.25; whiteSideV8[0] = -2.25;
    u.drawSixFacesPolygon(whiteSideV1, whiteSideV2, whiteSideV3, whiteSideV4,
        whiteSideV5, whiteSideV6, whiteSideV7, whiteSideV8, cWhite);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cGrey);
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    u.drawRightTriangle(0.3, 0.3, cGrey, 2.5, 2.08, 2.505);
    glRotatef(180, 0, 1, 0);
    u.drawRightTriangle(0.3, 0.3, cGrey, 2.5, 2.08, -2.505);
    glPopMatrix();
    u.drawRect(0.3, 0.7, cGrey, 2.5, -0.7, 2.505);
    u.drawRect(0.3, 0.6, cGrey, 2.5, -1.63, 2.505);
    u.drawRect(0.3, 0.7, cGrey, -2.5, -0.7, 2.505);
    u.drawRect(0.3, 0.6, cGrey, -2.5, -1.63, 2.505);
}

void Head::drawHead() {
    glPushMatrix(); {
        glTranslatef(0, -2.4, 0);
        glRotatef(headHorizontalAngle, 0, 1, 0);
        glRotatef(headVerticalAngle, 1, 0, 0);
        glTranslatef(0, 2.4, 0);
        
        drawToppings();
        drawCheek();

        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cBlack);
        u.drawCube(4.5, 2.5, 4, cBlack, 0, -2.5 / 2, 0);
        drawFace();
        glPopMatrix();
    }
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cGrey);
    u.drawSphere(1.4, 30, 30, GLU_FILL, cGrey, 0, -2.4, 0);
}

void Head::keyActions(unsigned char key) {
    if (key == 'Y' || key == 'y') {
        if (this->headHorizontalAngle > -headHorizontalAngleMax) {
            this->headHorizontalAngle -= 1;
        }
    } else if (key == 'I' || key == 'i') {
        if (this->headHorizontalAngle < headHorizontalAngleMax) {
            this->headHorizontalAngle += 1;
        }
    } else if (key == 'U' || key == 'u') {
        if (this->headVerticalAngle > -headVerticalBackAngleMax) {
            this->headVerticalAngle -= 1;
        }
    } else if (key == 'J' || key == 'j') {
        if (this->headVerticalAngle < 8) {
            this->headVerticalAngle += 1;
        }
    }
}
