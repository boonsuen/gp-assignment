#pragma once
#ifndef Legs_h
#define Legs_h
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

void Legs::drawFoot() {
    glBindTexture(GL_TEXTURE_2D, 0);
    GLfloat blueFV1[] = { -0.9, -1.5, 4 }; GLfloat blueFV5[] = { -0.9, -1.5, 0.5 };
    GLfloat blueFV2[] = { 0.9, -1.5, 4 }; GLfloat blueFV6[] = { 0.9, -1.5, 0.5 };
    GLfloat blueFV3[] = { 0.9, 0, 1 }; GLfloat blueFV7[] = { 0.9, 0, -0.5 };
    GLfloat blueFV4[] = { -0.9, 0, 1 }; GLfloat blueFV8[] = { -0.9, 0, -0.5 };
    u.drawSixFacesPolygon(blueFV1, blueFV2, blueFV3, blueFV4,
        blueFV5, blueFV6, blueFV7, blueFV8, cPrimaryLightBlue);
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    GLfloat whiteFV1[] = { -0.901, -1.1, 3.23 }; GLfloat whiteFV5[] = { -0.901, -1.1, 0.7 };
    GLfloat whiteFV2[] = { 0.901, -1.1, 3.23 }; GLfloat whiteFV6[] = { 0.901, -1.1, 0.7 };
    GLfloat whiteFV3[] = { 0.901, -0.17, 1.34 }; GLfloat whiteFV7[] = { 0.901, -0.5, 0.24 };
    GLfloat whiteFV4[] = { -0.901, -0.17, 1.34 }; GLfloat whiteFV8[] = { -0.901, -0.5, 0.24 };
    u.drawSixFacesPolygon(whiteFV1, whiteFV2, whiteFV3, whiteFV4,
        whiteFV5, whiteFV6, whiteFV7, whiteFV8, cWhite);
    glColor3fv(cLightSkinGrey2);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex3f(-0.8011, -1.1, 3.231);
    glVertex3f(-0.8011, -0.17, 1.341);
    glVertex3f(0.8011, -1.1, 3.231);
    glVertex3f(0.8011, -0.17, 1.341);
    glEnd();

    GLfloat darkBV1[] = { -0.8, -1.5, -0.1 }; GLfloat darkBV5[] = { -0.8, -1.5, -2 };
    GLfloat darkBV2[] = { 0.8, -1.5, -0.1 }; GLfloat darkBV6[] = { 0.8, -1.5, -2 };
    GLfloat darkBV3[] = { 0.8, -0.17, 0.2 }; GLfloat darkBV7[] = { 0.8, 0.5, -1.2 };
    GLfloat darkBV4[] = { -0.8, -0.17, 0.2 }; GLfloat darkBV8[] = { -0.8, 0.5, -1.2 };
    u.drawSixFacesPolygon(darkBV1, darkBV2, darkBV3, darkBV4,
        darkBV5, darkBV6, darkBV7, darkBV8, cDarkBlue);
    GLfloat blueBV1[] = { -0.801, -1, -1.5 }; GLfloat blueBV5[] = { -0.801, -1.5, -2.001 };
    GLfloat blueBV2[] = { 0.801, -1, -1.5 }; GLfloat blueBV6[] = { 0.801, -1.5, -2.001 };
    GLfloat blueBV3[] = { 0.801, 0, -1 }; GLfloat blueBV7[] = { 0.801, 0.5, -1.201 };
    GLfloat blueBV4[] = { -0.801, 0, -1 }; GLfloat blueBV8[] = { -0.801, 0.5, -1.201 };
    u.drawSixFacesPolygon(blueBV1, blueBV2, blueBV3, blueBV4,
        blueBV5, blueBV6, blueBV7, blueBV8, cPrimaryLightBlue);
}

void Legs::drawCalf() {
    glPushMatrix();
    u.drawCube(1.2, 1.2, 1.6, cDarkBlue, 0, 0.6, 0);
    glRotatef(90, 0, 0, 1);
    u.drawCylinder(cDarkBlue, 0.8, 0.8, 1.2, 30, 30, GLU_FILL, true, 0, -0.6, 0);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    u.drawCircle(cWhite, 0.5, 0.5, 0, true, false, true, 0, 0, -0.601);
    u.drawCircle(cWhite, 0.5, 0.5, 0, true, false, true, 0, 0, 0.601);
    glPopMatrix();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.601, 0.1, -0.5);
    glVertex3f(-0.601, 0.1, 0.5);
    glVertex3f(-0.601, -0.4, -0.28);
    glVertex3f(-0.601, 0.5, 0);
    glVertex3f(-0.601, -0.4, 0.28);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.601, 0.1, -0.5);
    glVertex3f(0.601, 0.1, 0.5);
    glVertex3f(0.601, -0.4, -0.28);
    glVertex3f(0.601, 0.5, 0);
    glVertex3f(0.601, -0.4, 0.28);
    glEnd();

    glPushMatrix(); {
        glTranslatef(0, 0.15, 0);

        glPushMatrix();
        glTranslatef(0, 0, 0.3);
        GLfloat whiteTV1[] = { -1.1, -1.5, 0.9 }; GLfloat whiteTV5[] = { -1.1, -2.45, 0.5 };
        GLfloat whiteTV2[] = { 1.1, -1.5, 0.9 }; GLfloat whiteTV6[] = { 1.1, -2.45, 0.5 };
        GLfloat whiteTV3[] = { 1.1, -0.3, 1 }; GLfloat whiteTV7[] = { 1.1, -0.5, 0.5 };
        GLfloat whiteTV4[] = { -1.1, -0.3, 1 }; GLfloat whiteTV8[] = { -1.1, -0.5, 0.5 };
        u.drawSixFacesPolygon(whiteTV1, whiteTV2, whiteTV3, whiteTV4,
            whiteTV5, whiteTV6, whiteTV7, whiteTV8, cWhite);
        u.drawCube(2.2, 1.95, 1.90, cWhite, 0, -0.975 - 0.5, -0.45);
        glColor3fv(cLightSkinGrey2);
        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex3f(-1.101, -1.5, 0.9);
        glVertex3f(-1.101, -0.3, 1);
        glVertex3f(1.101, -1.5, 0.9);
        glVertex3f(1.101, -0.3, 1);
        glVertex3f(-1.101, -1.5, 0.9);
        glVertex3f(-1.101, -2.45, 0.5);
        glVertex3f(1.101, -1.5, 0.9);
        glVertex3f(1.101, -2.45, 0.5);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(-1.101, -0.5, -1.395);
        glVertex3f(-1.101, -2.45, -1.395);
        glVertex3f(1.101, -0.5, -1.395);
        glVertex3f(1.101, -2.45, -1.395);
        glEnd();

        GLfloat kneeV1[] = { -0.5, -1.5, 1.2 }; GLfloat kneeV5[] = { -0.5, -2.45, 0.5 };
        GLfloat kneeV2[] = { 0.5, -1.5, 1.2 }; GLfloat kneeV6[] = { 0.5, -2.45, 0.5 };
        GLfloat kneeV3[] = { 0.5, -0.1, 1.4 }; GLfloat kneeV7[] = { 0.5, -0.5, 0.5 };
        GLfloat kneeV4[] = { -0.5, -0.1, 1.4 }; GLfloat kneeV8[] = { -0.5, -0.5, 0.5 };
        u.drawSixFacesPolygon(kneeV1, kneeV2, kneeV3, kneeV4,
            kneeV5, kneeV6, kneeV7, kneeV8, cLightGrey);
        GLfloat kneeBlueV1[] = { -0.501, -0.6, 1.35 }; GLfloat kneeBlueV5[] = { -0.5, -0.8, 0.5 };
        GLfloat kneeBlueV2[] = { 0.501, -0.6, 1.35 }; GLfloat kneeBlueV6[] = { 0.5, -0.8, 0.5 };
        GLfloat kneeBlueV3[] = { 0.501, -0.1, 1.401 }; GLfloat kneeBlueV7[] = { 0.5, -0.5, 0.5 };
        GLfloat kneeBlueV4[] = { -0.501, -0.1, 1.401 }; GLfloat kneeBlueV8[] = { -0.5, -0.5, 0.5 };
        u.drawSixFacesPolygon(kneeBlueV1, kneeBlueV2, kneeBlueV3, kneeBlueV4,
            kneeBlueV5, kneeBlueV6, kneeBlueV7, kneeBlueV8, cPrimaryBlue);
        glBegin(GL_LINE_LOOP);
        glVertex3f(0, -0.6, 1.35);
        glVertex3f(-0.5, -1.5, 1.201);
        glVertex3f(0.5, -1.5, 1.201);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex3f(0, -2.45, 0.501);
        glVertex3f(-0.5, -1.5, 1.201);
        glVertex3f(0.5, -1.5, 1.201);
        glEnd();
        glPopMatrix();
        u.drawCylinder(cWhite, 0.75, 1, 3.5, 10, 10, GLU_FILL, true, 0, -5.5, -0.1);
        glPushMatrix();
        glColor3fv(cLegBoost);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.25, -4.5, 0.83);
        glVertex3f(0.25, -4.5, 0.83);
        glVertex3f(0, -4, 0.8);
        glVertex3f(-0.25, -4, 0.8);
        glVertex3f(0.25, -4, 0.8);
        glVertex3f(0, -3.5, 0.77);
        glVertex3f(-0.25, -3.5, 0.77);
        glVertex3f(0.25, -3.5, 0.77);
        glVertex3f(0, -3, 0.74);
        glEnd();

        glColor3fv(cLightSkinGrey2);
        glBegin(GL_LINES);
        glVertex3f(-0.25, -5, 0.82);
        glVertex3f(-0.25, -2.4, 0.65);
        glVertex3f(0.25, -5, 0.82);
        glVertex3f(0.25, -2.4, 0.65);
        glEnd();

        glPopMatrix();
        glPushMatrix(); {
            glTranslatef(0, -4.5, -1);
            glRotatef(30, 1, 0, 0);
            u.drawCylinder(cLegBoost, 0.1, 0.3, 0.6, 10, 10, GLU_FILL, false, 0, 0, -0.2);
            glPopMatrix();
        }
        glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
        
        u.drawCylinder(cGrey, 0.5, 0.5, 1, 30, 30, GLU_FILL, true, 0, -6, -0.1);
        glPushMatrix();
        glRotatef(90, 0, 1, 0);
        u.drawHemisphere(0.3, 30, 30, cPrimaryLightBlue, 0, -5.55, -1.1);
        glRotatef(180, 0, 1, 0);
        u.drawHemisphere(0.3, 30, 30, cPrimaryLightBlue, 0, -5.55, -1.1);
        glPopMatrix();
        // Ankle
        glPushMatrix();
        glTranslatef(0, -5, 0);
        GLfloat ankle1V1[] = { -1.1, -0.5, 1.4 }; GLfloat ankle1V5[] = { -1.1, -0.9, 0 };
        GLfloat ankle1V2[] = { 1.1, -0.5, 1.4 }; GLfloat ankle1V6[] = { 1.1, -0.9, 0 };
        GLfloat ankle1V3[] = { 1.1, 0, 1.3 }; GLfloat ankle1V7[] = { 1.1, -0.2, 0 };
        GLfloat ankle1V4[] = { -1.1, 0, 1.3 }; GLfloat ankle1V8[] = { -1.1, -0.2, 0 };
        u.drawSixFacesPolygon(ankle1V1, ankle1V2, ankle1V3, ankle1V4,
            ankle1V5, ankle1V6, ankle1V7, ankle1V8, cLightGrey2);
        GLfloat ankle2V1[] = { -1.1, -0.9, 0 }; GLfloat ankle2V5[] = { -1.1, -0.5, -1.4 };
        GLfloat ankle2V2[] = { 1.1, -0.9, 0 }; GLfloat ankle2V6[] = { 1.1, -0.5, -1.4 };
        GLfloat ankle2V3[] = { 1.1, -0.2, 0 }; GLfloat ankle2V7[] = { 1.1, 0, -1.3 };
        GLfloat ankle2V4[] = { -1.1, -0.2, 0 }; GLfloat ankle2V8[] = { -1.1, 0, -1.3 };
        u.drawSixFacesPolygon(ankle2V1, ankle2V2, ankle2V3, ankle2V4,
            ankle2V5, ankle2V6, ankle2V7, ankle2V8, cLightGrey);
        glPopMatrix();

        glPopMatrix();
    }
}

void Legs::drawThigh() {
    u.drawCube(1.8, 1.5, 1.6, cDarkBlue, 0, -1.5, 0);
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    u.drawCylinder(cDarkBlue, 0.8, 0.8, 1.8, 30, 30, GLU_FILL, true, -2, -0.9, 0);
    glScalef(0.4, 1, 1);
    u.drawCylinder(cDarkBlue, 0.8, 0.8, 1.8, 30, 30, GLU_FILL, true, -2, -0.9, 0);
    glPopMatrix();

    GLfloat whiteV1[] = { -1.0, -5, 1 }; GLfloat whiteV5[] = { -1.0, -5.5, 0.5 };
    GLfloat whiteV2[] = { 1.0, -5, 1 }; GLfloat whiteV6[] = { 1.0, -5.5, 0.5 };
    GLfloat whiteV3[] = { 1.0, -3, 1 }; GLfloat whiteV7[] = { 1.0, -2.5, 0.5 };
    GLfloat whiteV4[] = { -1.0, -3, 1 }; GLfloat whiteV8[] = { -1.0, -2.5, 0.5 };
    u.drawSixFacesPolygon(whiteV1, whiteV2, whiteV3, whiteV4,
        whiteV5, whiteV6, whiteV7, whiteV8, cWhite);
    GLfloat whiteBV1[] = { -1.0, -5.5, 0.5 }; GLfloat whiteBV5[] = { -1.0, -5, -1 };
    GLfloat whiteBV2[] = { 1.0, -5.5, 0.5 }; GLfloat whiteBV6[] = { 1.0, -5, -1 };
    GLfloat whiteBV3[] = { 1.0, -2.5, 0.5 }; GLfloat whiteBV7[] = { 1.0, -2.5, -1 };
    GLfloat whiteBV4[] = { -1.0, -2.5, 0.5 }; GLfloat whiteBV8[] = { -1.0, -2.5, -1 };
    u.drawSixFacesPolygon(whiteBV1, whiteBV2, whiteBV3, whiteBV4,
        whiteBV5, whiteBV6, whiteBV7, whiteBV8, cWhite);

    glColor3fv(cLightSkinGrey2);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.01, -2.5, 0.5);
    glVertex3f(-1.01, -4, 0.5);
    glVertex3f(-1.01, -4.3, 0.3);
    glVertex3f(-1.01, -4.3, 0);
    glVertex3f(-1.01, -5.32, 0);

    glVertex3f(1.01, -2.5, 0.5);
    glVertex3f(1.01, -4, 0.5);
    glVertex3f(1.01, -4.3, 0.3);
    glVertex3f(1.01, -4.3, 0);
    glVertex3f(1.01, -5.32, 0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glTexCoord2f(1, 1); glVertex3f(-1, -5, 1.01);
    glTexCoord2f(1, 0); glVertex3f(1, -5, 1.01);
    glTexCoord2f(0, 1); glVertex3f(-1, -4, 1.01);
    glTexCoord2f(0, 0); glVertex3f(1, -4, 1.01);
    glColor3fv(cLightSkinGrey);
    glTexCoord2f(-1, 1); glVertex3f(-1, -3, 1.01);
    glTexCoord2f(0, 1); glVertex3f(1, -3, 1.01);
    glEnd();
}

void Legs::drawLeftLeg() {
    drawThigh();
    glPushMatrix();
    glTranslatef(0, -5.6, 0);
    drawCalf();
    glTranslatef(0, -5.5, 0);
    drawFoot();
    glPopMatrix();
}

void Legs::drawRightLeg() {
    drawThigh();
    glPushMatrix();
    glTranslatef(0, -5.6, 0);
    drawCalf();
    glTranslatef(0, -5.5, 0);
    drawFoot();
    glPopMatrix();
}

void Legs::drawLeftDefenseWaist() {
    GLfloat whiteLV1[] = { -2.08, -2.5, 2 }; GLfloat whiteLV5[] = { -2.38, -2.7, 1.5 };
    GLfloat whiteLV2[] = { 0, -3.5, 2 }; GLfloat whiteLV6[] = { 0, -3.7, 1.5 };
    GLfloat whiteLV3[] = { 0, 0, 2 }; GLfloat whiteLV7[] = { 0, 0, 1.5 };
    GLfloat whiteLV4[] = { -2.08, 0, 2 }; GLfloat whiteLV8[] = { -2.38, 0, 1.5 };
    u.drawSixFacesPolygon(whiteLV1, whiteLV2, whiteLV3, whiteLV4,
        whiteLV5, whiteLV6, whiteLV7, whiteLV8, cWhite);

    whiteLV1[2] = -2; whiteLV5[2] = -1.5;
    whiteLV2[2] = -2; whiteLV6[2] = -1.5;
    whiteLV3[2] = -2; whiteLV7[2] = -1.5;
    whiteLV4[2] = -2; whiteLV8[2] = -1.5;
    u.drawSixFacesPolygon(whiteLV1, whiteLV2, whiteLV3, whiteLV4,
        whiteLV5, whiteLV6, whiteLV7, whiteLV8, cWhite);

    glBindTexture(GL_TEXTURE_2D, 0);
    GLfloat red[] = { 219.0 / 255, 59.0 / 255, 45.0 / 255 };
    u.drawCube(1.1, 1.2, 0.2, red, -0.98, -0.7, 2);
    glColor3fv(cAntennaYellow);
    glBegin(GL_QUADS);
    glVertex3f(-1.58, -2.5, 2.002);
    glVertex3f(-0.4, -3, 2.002);
    glVertex3f(-0.4, -2.7, 2.002);
    glVertex3f(-1.58, -2.2, 2.002);
    glEnd();
    u.drawDisk(cGrey, 0.05, 0.13, 10, 10, GLU_FILL, -1.22, -1.02, 2.101, false);
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);

    glColor3fv(cLightSkinGrey2);
    glBegin(GL_LINES);
    glVertex3f(-1.28, -2.1, 2.01);
    glVertex3f(-1.28, -1.5, 2.01);
    glVertex3f(-0.7, -2.3, 2.01);
    glVertex3f(-0.7, -1.5, 2.01);
    glEnd();
}

void Legs::drawRightDefenseWaist() {
    GLfloat whiteRV1[] = { 0, -3.5, 2 }; GLfloat whiteRV5[] = { 0, -3.7, 1.5 };
    GLfloat whiteRV2[] = { 2.08, -2.5, 2 }; GLfloat whiteRV6[] = { 2.38, -2.5, 1.5 };
    GLfloat whiteRV3[] = { 2.08, 0, 2 }; GLfloat whiteRV7[] = { 2.38, 0, 1.5 };
    GLfloat whiteRV4[] = { 0, 0, 2 }; GLfloat whiteRV8[] = { 0, 0, 1.5 };
    u.drawSixFacesPolygon(whiteRV1, whiteRV2, whiteRV3, whiteRV4,
        whiteRV5, whiteRV6, whiteRV7, whiteRV8, cWhite);

    whiteRV1[2] = -2; whiteRV5[2] = -1.5;
    whiteRV2[2] = -2; whiteRV6[2] = -1.5;
    whiteRV3[2] = -2; whiteRV7[2] = -1.5;
    whiteRV4[2] = -2; whiteRV8[2] = -1.5;
    u.drawSixFacesPolygon(whiteRV1, whiteRV2, whiteRV3, whiteRV4,
        whiteRV5, whiteRV6, whiteRV7, whiteRV8, cWhite);

    glBindTexture(GL_TEXTURE_2D, 0);
    GLfloat red[] = { 219.0 / 255, 59.0 / 255, 45.0 / 255 };
    u.drawCube(1.1, 1.2, 0.2, red, 0.98, -0.7, 2);
    glColor3fv(cAntennaYellow);
    glBegin(GL_QUADS);
    glVertex3f(1.58, -2.5, 2.002);
    glVertex3f(0.4, -3, 2.002);
    glVertex3f(0.4, -2.7, 2.002);
    glVertex3f(1.58, -2.2, 2.002);
    glEnd();
    u.drawDisk(cGrey, 0.05, 0.13, 10, 10, GLU_FILL, 1.22, -1.02, 2.101, false);
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);

    glColor3fv(cLightSkinGrey2);
    glBegin(GL_LINES);
    glVertex3f(1.28, -2.1, 2.01);
    glVertex3f(1.28, -1.5, 2.01);
    glVertex3f(0.7, -2.3, 2.01);
    glVertex3f(0.7, -1.5, 2.01);
    glEnd();
}

void Legs::drawWaist() {
    // Defense Waist
    {
        glPushMatrix();
        glTranslatef(-0.92, -0.4, 0);
        glScalef(scaleX, scaleY, 1);
        drawLeftDefenseWaist();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.92, -0.4, 0);
        glScalef(scaleX, scaleY, 1);
        drawRightDefenseWaist();
        glPopMatrix();

        if (defenseMode) {
            if (scaleX < 1) {
                scaleX += 0.01;
            }
            if (scaleY < 1) {
                scaleY += 0.01;
            }
        }
        else {
            if (scaleX >= 0) {
                scaleX -= 0.01;
            }
            if (scaleY >= 0) {
                scaleY -= 0.01;
            }
        }
    }

    u.drawCube(8, 0.8, 4, cGrey, 0, 0, 0);

    GLfloat middleV1[] = { -0.9, -1.8, 2.5 }; GLfloat middleV5[] = { -0.9, -3, 1.6 };
    GLfloat middleV2[] = { 0.9, -1.8, 2.5 }; GLfloat middleV6[] = { 0.9, -3, 1.6 };
    GLfloat middleV3[] = { 0.9, -0.4, 2 }; GLfloat middleV7[] = { 0.9, -2.5, -2 };
    GLfloat middleV4[] = { -0.9, -0.4, 2 }; GLfloat middleV8[] = { -0.9, -2.5, -2 };
    u.drawSixFacesPolygon(middleV1, middleV2, middleV3, middleV4,
        middleV5, middleV6, middleV7, middleV8, cWhite);
    GLfloat middleV1B[] = { -0.9, -1, -2.3 }; GLfloat middleV5B[] = { -0.9, -2.5, -2 };
    GLfloat middleV2B[] = { 0.9, -1, -2.3 }; GLfloat middleV6B[] = { 0.9, -2.5, -2 };
    GLfloat middleV3B[] = { 0.9, -0.4, -2 }; GLfloat middleV7B[] = { 0.9, -0.4, 2 };
    GLfloat middleV4B[] = { -0.9, -0.4, -2 }; GLfloat middleV8B[] = { -0.9, -0.4, 2 };
    u.drawSixFacesPolygon(middleV1B, middleV2B, middleV3B, middleV4B,
        middleV5B, middleV6B, middleV7B, middleV8B, cWhite);

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    u.drawDisk(cGrey, 0.6, 1.1, 30, 30, GLU_FILL, 0, -1.55, 0.901, false);
    u.drawDisk(cGrey, 0.6, 1.1, 30, 30, GLU_FILL, 0, -1.55, -0.901, false);
    glRotatef(90, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    u.drawCylinder(cBlack, 0.6, 0.6, 6, 30, 30, GLU_FILL, true, -1.55, -3, 0);
    glPopMatrix();
}

void Legs::drawLegs() {
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    glPushMatrix();
    glTranslatef(0, 6, 0);

    glPushMatrix();
    glTranslatef(-2.2, 0, 0);
    drawLeftLeg();
    glTranslatef(4.4, 0, 0);
    drawRightLeg();
    glPopMatrix();

    drawWaist();
    glPopMatrix();
}
