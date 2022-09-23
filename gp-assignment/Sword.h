#pragma once
#ifndef Hands_h
#define Hands_h
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
#include "Common.h"
#include "Utility.h"

class Sword {
public:
    Utility u;
    bool showSword = false;
    
    bool handleAnimated = false;
    float handleRotateY = 0;
    float handleScale = 0;
    
    bool topAnimated = false;
    float topScale = 0;
    float topTranslateY = 0;
    
    float smallKnifeScale = 0;
    
    float hiding = false;
    float hideScale = 1;
    
    void drawHandle();
    void drawSmallKnife();
    void drawKnife();
    void drawSword();
    void keyActions(unsigned char key);
};

void Sword::drawHandle() {
    glPushMatrix();
    glRotatef(handleRotateY, 0, 1, 0);
    glScalef(handleScale, handleScale, handleScale);
    if (handleRotateY < 360) {
        handleRotateY += 4;
    }
    if (handleScale < 1) {
        handleScale += 2.0/180;
    }
    if (handleScale >= 1 && handleRotateY >= 360) {
        handleAnimated = true;
    }
    
    GLfloat swordCenterLV1[] = { -1, 0, 0.3 }; GLfloat swordCenterLV5[] = { -1, 0, -0.3 };
    GLfloat swordCenterLV2[] = { 0, 0, 0.3 }; GLfloat swordCenterLV6[] = { 0, 0, -0.3 };
    GLfloat swordCenterLV3[] = { 0, 0.7, 0.3 }; GLfloat swordCenterLV7[] = { 0, 0.7, -0.3 };
    GLfloat swordCenterLV4[] = { -1, 0.4, 0.3 }; GLfloat swordCenterLV8[] = { -1, 0.4, -0.3 };
    u.drawSixFacesPolygon(swordCenterLV1, swordCenterLV2, swordCenterLV3, swordCenterLV4,
                          swordCenterLV5, swordCenterLV6, swordCenterLV7, swordCenterLV8, cWhite);
    GLfloat swordCenterRV1[] = { 0, 0, 0.3 }; GLfloat swordCenterRV5[] = { 0, 0, -0.3 };
    GLfloat swordCenterRV2[] = { 1, 0, 0.3 }; GLfloat swordCenterRV6[] = { 1, 0, -0.3 };
    GLfloat swordCenterRV3[] = { 1, 0.4, 0.3 }; GLfloat swordCenterRV7[] = { 1, 0.4, -0.3 };
    GLfloat swordCenterRV4[] = { 0, 0.7, 0.3 }; GLfloat swordCenterRV8[] = { 0, 0.7, -0.3 };
    u.drawSixFacesPolygon(swordCenterRV1, swordCenterRV2, swordCenterRV3, swordCenterRV4,
                          swordCenterRV5, swordCenterRV6, swordCenterRV7, swordCenterRV8, cWhite);
    u.drawCube(2.01, 0.05, 0.61, (swordAttackMode ? cHeadRed : cPrimaryLightBlue), 0, 0.1, 0);
    u.drawCube(2.01, 0.05, 0.61, (swordAttackMode ? cHeadRed : cPrimaryLightBlue), 0, 0.2, 0);
    u.drawCylinder(cBlack, 0.2, 0.2, 1.8, 30, 30, GLU_FILL, true, 0, -1.8, 0);
    
    glPopMatrix();
}

void Sword::drawSmallKnife() {
    GLfloat cSmallKnifeBlue[] = { 20.0/255, 106.0/255, 1 };
    GLfloat cSmallKnifeBlue2[] = { 110.0/255, 206.0/255, 1 };
    GLfloat cSmallKnifeRed[] = { 1, 10.0/255, 59.0/255 };
    GLfloat cSmallKnifeRed2[] = { 1, 140.0/255, 199.0/255 };
    
    glPushMatrix();
    glTranslatef(0, 1, 0);
    if (topAnimated) {
        glScalef(smallKnifeScale, 1, 1);
        if (smallKnifeScale < 1) {
            smallKnifeScale += 0.02;
        }
    }
    glBegin(GL_TRIANGLE_FAN);
    glColor3fv(swordAttackMode ? cSmallKnifeRed2 : cSmallKnifeBlue2);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.9, 0.2875, 0);
    glColor3fv(swordAttackMode ? cSmallKnifeRed : cSmallKnifeBlue);
    glTexCoord2f(1.0, 1.0); glVertex3f(0, 0, 0.08);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0.575, 0.08);
    
    glTexCoord2f(0.0, 1.0); glVertex3f(0, 0.575, -0.08);
    glTexCoord2f(1.0, 1.0); glVertex3f(0, 0, -0.08);
    glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0.08);
    glEnd();
    glPopMatrix();
}

void Sword::drawKnife() {
    // Sword Top
    glBindTexture(GL_TEXTURE_2D, textures[swordAttackMode ? 5 : 4]);
    if (handleAnimated) {
        glPushMatrix();
        glTranslatef(0, topTranslateY, 0);
        glScalef(1, topScale, topScale);
        if (topScale < 1) {
            topScale += 0.025;
        }
        if (topTranslateY < 5) {
            topTranslateY += 2.5/20;
        }
        if (topScale >= 1 && topTranslateY >= 5) {
            topAnimated = true;
        }
        GLfloat swordTopColorBlue[] = { 96.0/255, 146.0/255, 1 };
        GLfloat swordTopColorRed[] = { 1, 89.0/255, 73.0/255 };
        GLfloat swordTop1V1[] = { -1, 0.4, 0.3 }; GLfloat swordTop1V5[] = { -1, 0.4, -0.3 };
        GLfloat swordTop1V2[] = { 0, 0.4, 0.3 }; GLfloat swordTop1V6[] = { 0, 0.4, -0.3 };
        GLfloat swordTop1V3[] = { 0, 1.4, 0 }; GLfloat swordTop1V7[] = { 0, 1.4, 0 };
        GLfloat swordTop1V4[] = { -1, 0.4, 0.3 }; GLfloat swordTop1V8[] = { -1, 0.4, -0.3 };
        u.drawSixFacesPolygon(swordTop1V1, swordTop1V2, swordTop1V3, swordTop1V4,
                              swordTop1V5, swordTop1V6, swordTop1V7, swordTop1V8, swordAttackMode ? swordTopColorRed : swordTopColorBlue);
        GLfloat swordTop2V1[] = { 0, 0.4, 0.3 }; GLfloat swordTop2V5[] = { 0, 0.4, -0.3 };
        GLfloat swordTop2V2[] = { 1, 0.4, 0.3 }; GLfloat swordTop2V6[] = { 1, 0.4, -0.3 };
        GLfloat swordTop2V3[] = { 1, 0.4, 0.3 }; GLfloat swordTop2V7[] = { 1, 0.4, -0.3 };
        GLfloat swordTop2V4[] = { 0, 1.4, 0 }; GLfloat swordTop2V8[] = { 0, 1.4, 0 };
        u.drawSixFacesPolygon(swordTop2V1, swordTop2V2, swordTop2V3, swordTop2V4,
                              swordTop2V5, swordTop2V6, swordTop2V7, swordTop2V8, swordAttackMode ? swordTopColorRed : swordTopColorBlue);
        
        glTranslatef(0, -4.5, 0);
        GLfloat mainKnifeRed[] = { 216.0/255, 6.0/255, 48.0/255 };
        u.drawCylinder(swordAttackMode ? mainKnifeRed : cPrimaryBlue, 0.2, 0.2, 5, 10, 10, GLU_FILL, true, 0, 0, 0);
        glPopMatrix();
        
        if (topAnimated) {
            glPushMatrix();
            glTranslatef(0, 0.3, 0);
            glTranslatef(0, -0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glPopMatrix();
            
            glPushMatrix();
            glRotatef(180, 0, 1, 0);
            glTranslatef(0, 0.3, 0);
            glTranslatef(0, -0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glTranslatef(0, 0.575, 0);
            drawSmallKnife();
            glPopMatrix();
        }
    }
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
}

void Sword::drawSword() {
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    if (showSword) {
        drawHandle();
        drawKnife();
    }
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
}

void Sword::keyActions(unsigned char key) {
    if (key == '3') {
        showSword = !showSword;
        
        if (showSword == false) {
            handleAnimated = false;
            handleRotateY = 0;
            handleScale = 0;
            topAnimated = false;
            topScale = 0;
            topTranslateY = 0;
            
            smallKnifeScale = 0;
            
            swordAttackMode = false;
        }
    } else if (key == '4') {
        if (showSword) {
            swordAttackMode = !swordAttackMode;
        }
    }
}
