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
#include "common.h"
#include "Utility.h"

class Hands {
public:
    Utility u;
    void drawHands();
    void drawLeftHand();
    void drawRightHand();
    void drawShoulder();
    void drawShoulderPad();
    void drawUpperArm();
    //void drawElbow();
    //void drawLowerArm();
   
};

void Hands::drawShoulder() {
    // A cylinder that wont move
    glBindTexture(GL_TEXTURE_2D, 0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    u.drawCylinder(cBlack, 0.4, 0.4, 0.6, 30, 30, GLU_FILL, true, 5,2, 0);
    glPopMatrix();
}

GLfloat spv1 = -0.8, spv2 = -0.55;
GLfloat SPV1[] = { spv1, -1.4, 3.23 }; GLfloat SPV5[] = { spv1, -1.4, 1 };
GLfloat SPV2[] = { spv2, -1.4, 3.23 }; GLfloat SPV6[] = { spv2, -1.4, 1 };
GLfloat SPV3[] = { spv2, 0, 4 }; GLfloat SPV7[] = { spv2, -0.4, 0.7 };
GLfloat SPV4[] = { spv1, 0, 4 }; GLfloat SPV8[] = { spv1, -0.4, 0.7 };

GLfloat spv3 = spv1 - 0.2, spv4 = spv1 + 1.8;
GLfloat SPV1a[] = { spv3, -0.5, 3.53 }; GLfloat SPV5a[] = { spv3, -0.5, 0.7 };
GLfloat SPV2a[] = { spv4, -0.5, 3.53 }; GLfloat SPV6a[] = { spv4, -0.5, 0.7 };
GLfloat SPV3a[] = { spv4, 0.1, 4.3 }; GLfloat SPV7a[] = { spv4, 0.1, 0.4 };
GLfloat SPV4a[] = { spv3, 0.1, 4.3 }; GLfloat SPV8a[] = { spv3, 0.1, 0.4 };

void Hands::drawShoulderPad() {
    // Front + Back
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]); {
        glPushMatrix(); {
            glRotatef(-90, 0, 1, 0);
        
            glPushMatrix(); {
            glTranslatef(0, 6, 1.4);
            u.drawSixFacesPolygon(SPV1, SPV2, SPV3, SPV4,
            SPV5, SPV6, SPV7, SPV8, cWhite);
            glPopMatrix();
            }
        
            glPushMatrix(); {
            glTranslatef(1.35, 6, 1.4);
            u.drawSixFacesPolygon(SPV1, SPV2, SPV3, SPV4,
            SPV5, SPV6, SPV7, SPV8, cWhite);
            glPopMatrix();
            }

            glPopMatrix();
        }
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    // Top
    glPushMatrix(); {
        glRotatef(-90, 0, 1, 0);
        glTranslatef(0, 6, 1.4);
        u.drawSixFacesPolygon(SPV1a, SPV2a, SPV3a, SPV4a,
            SPV5a, SPV6a, SPV7a, SPV8a, cGrey);
        glPopMatrix();
    }
}

GLfloat uav1 = 0, uav2 = 1.5;
GLfloat UAV1[] = { uav1+0.2, 0, 0.75 }; GLfloat UAV5[] = { uav1 + 0.1, 0, -0.75 };
GLfloat UAV2[] = { uav2-0.2, 0, 0.75 }; GLfloat UAV6[] = { uav2 - 0.1, 0, -0.75 };
GLfloat UAV3[] = { uav2, 1, 0.75 }; GLfloat UAV7[] = { uav2, 1, -0.75 };
GLfloat UAV4[] = { uav1, 1, 0.75 }; GLfloat UAV8[] = { uav1, 1, -0.75 };
void Hands::drawUpperArm() {
    // 1st
    u.drawCube(1.45, 1.7,1, cGrey, -3.3,4.8,0);

    // 2nd
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]); {
        u.drawCube(1.5, 1.4, 1.1, cWhite, -3.3, 3.6, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    // 3rd
    u.drawCube(1.4, 1.5, 1, cWhite, -3.3, 3.5, 0);

    //4th
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]); 
    glPushMatrix(); {
        glTranslatef(-4.05,1.8,0);
        u.drawSixFacesPolygon(UAV1, UAV2, UAV3, UAV4, UAV5, UAV6, UAV7, UAV8, cWhite);
        glPopMatrix();
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}

void Hands::drawLeftHand() {
    glPushMatrix(); {
        /*glRotatef(180,0,1,0);*/
        glScalef(-1, 1, 1);
        drawRightHand();
        glPopMatrix();
    }
}

void Hands::drawRightHand() {
    drawShoulder();
    drawUpperArm();
    drawShoulderPad();
}

void Hands::drawHands() {
    drawLeftHand();
    drawRightHand();
}