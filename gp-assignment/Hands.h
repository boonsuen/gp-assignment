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
#include "Shield.h"


float cYellow[] = { 1.0, 0.95, 0 };
float cRed[] = { 1, 63.0 / 255, 57.0 / 255 };

class Hands {
public:
    Utility u;
    float wholeAngleRight = 0;
    float wholeAngleLeft = 0;
    float wholeAngleMax = 50;
    float LowerArmAngleRight = 0;
    float LowerArmAngleLeft = 0;
    float LowerArmAngleMax = 50;

    void drawHands();
    void drawLeftHand();
    void drawRightHand();
    void drawShoulder();
    void drawShoulderPad();
    void drawUpperArm();
    void drawElbow();
    void drawLowerArm();
    void drawWrist();
    void drawPalm();
    void drawThumb();
    void drawFinger();

    void keyActions(unsigned char key);
   
};

void Hands::keyActions(unsigned char key) {
    if (key == 'Q' || key == 'q') {
        if (this->wholeAngleRight > -wholeAngleMax) {
            this->wholeAngleRight -= 1;
        }
    }
    else if (key == 'A' || key == 'a') {
        if (this->wholeAngleRight < wholeAngleMax) {
            this->wholeAngleRight += 1;
        }
    }
    else if (key == 'W' || key == 'w') {
        if (this->wholeAngleLeft > -wholeAngleMax) {
            this->wholeAngleLeft -= 1;
        }
    }
    else if (key == 'S' || key == 's') {
        if (this->wholeAngleLeft < wholeAngleMax) {
            this->wholeAngleLeft += 1;
        }
    }

    if (key == 'E' || key == 'e') {
        if (this->LowerArmAngleLeft < LowerArmAngleMax) {
            this->LowerArmAngleLeft += 1;
        }
    }
    else if (key == 'D' || key == 'd') {
        
        if (this->LowerArmAngleLeft > 0) {
            this->LowerArmAngleLeft -= 1;
        }
    }
    else if (key == 'R' || key == 'r') {
        if (this->LowerArmAngleRight < LowerArmAngleMax) {
            this->LowerArmAngleRight += 1;
        }
    }
    else if (key == 'F' || key == 'f') {
        if (this->LowerArmAngleRight > 0) {
            this->LowerArmAngleRight -= 1;
        }
    }

    if (key == '0') {
        this-> wholeAngleRight = 0;
        this-> wholeAngleLeft = 0;
        this-> LowerArmAngleRight = 0;
        this-> LowerArmAngleLeft = 0;
    }
}

void Hands::drawShoulder() {
    //No Movement
    glBindTexture(GL_TEXTURE_2D, 0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    u.drawCylinder(cBlack, 0.4, 0.4, 1.0, 30, 30, GLU_FILL, true, 5, 1.5, 0);
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
GLfloat UAV1[] = { static_cast<GLfloat>(uav1 + 0.2), 0, 0.6 }; GLfloat UAV5[] = { static_cast<GLfloat>(uav1 + 0.1), 0, -0.6 };
GLfloat UAV2[] = { static_cast<GLfloat>(uav2-0.2), 0, 0.6 }; GLfloat UAV6[] = { static_cast<GLfloat>(uav2 - 0.1), 0, -0.6 };
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
    glBindTexture(GL_TEXTURE_2D, 0);
    u.drawCube(1.4, 1.5, 1, cLightGrey, -3.3, 3.5, 0);

    //4th
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]); 
    glPushMatrix(); {
        glTranslatef(-4.05,1.8,0);
        u.drawSixFacesPolygon(UAV1, UAV2, UAV3, UAV4, UAV5, UAV6, UAV7, UAV8, cWhite);
        glPopMatrix();
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}

void Hands::drawElbow() {
    //No Movement
    glBindTexture(GL_TEXTURE_2D, 0);
    u.drawCube(1, 0.5, 1, cBlack, -3.3, 1.6, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    /*u.drawCylinder(cWhite, 0.34, 0.34, 1.2, 30, 30, GLU_FILL, true, 1.6, 2.7, 0);*/
    u.drawCylinder(cGrey, 0.35, 0.35, 1.4, 10, 10, GLU_FILL, true, 1.6, 2.6, 0);
    //u.drawDisk(cBlack, 0.34, 0.37, 10, 10, GLU_FILL, 1.6, 2.6, 2.101, false);
    glPopMatrix();
}

void Hands::drawLowerArm() {
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    glPushMatrix(); {
        glTranslatef(-4, 1.4, 0);
        glScalef(1, -1, 1);
        glScalef(0.9, 0.9, 0.9);
        u.drawSixFacesPolygon(UAV1, UAV2, UAV3, UAV4, UAV5, UAV6, UAV7, UAV8, cWhite);
        glPopMatrix();
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    u.drawCube(1, 1, 1, cLightGrey, -3.3, 0, 0);

    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]); {
        u.drawCube(1.1, 0.6, 1.1, cWhite, -3.3, -0.5, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void Hands::drawWrist() {
    glPushMatrix(); {
        glTranslatef(-3.83, -1, 0);
        glScalef(0.7, 0.3, 0.7);
        u.drawSixFacesPolygon(UAV1, UAV2, UAV3, UAV4, UAV5, UAV6, UAV7, UAV8, cBlack);
        glPopMatrix();
    }
}

void Hands::drawPalm() {
    

    //Glove
    u.drawCube(0.4, 0.3, 0.7, cGrey, -3.3, -1.15, 0);
    glPushMatrix(); {

        glTranslatef(-3.5, -1.6, 0);
        glScalef(0.27, 0.3, 0.45);
        u.drawSixFacesPolygon(UAV1, UAV2, UAV3, UAV4, UAV5, UAV6, UAV7, UAV8, cGrey);
        glPopMatrix();
    }
}
void Hands::drawThumb() {
    glPushMatrix();
    glTranslatef(0,-0.23,-0.2);
    /*glRotatef(90, 1, 0, 0);
    glTranslatef(0, -1.15, 0);*/


    u.drawCube(0.24, 0.149, 0.65, cLightGrey, -3.3, -1.15, 0.32);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
    u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
    glPopMatrix();
    //u.drawCube(0.23, 0.15, 0.7, cGrey, -3.3, -1.15, 0.47);
    glPopMatrix();
}

void Hands::drawFinger() {
    u.drawCube(0.3, 0.3, 0.42, cLightGrey2, -3.3, -1.6, 0);

    glPushMatrix(); {
        glScalef(1,1,0.6);
        glRotatef(90,1,0,0);
        glTranslatef(0,0.87,1.2);
        u.drawCube(0.24, 0.15, 0.7, cLightGrey, -3.3, -1.15, 0.32);
        glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.07, 1.3);
        u.drawCube(0.24, 0.15, 0.7, cLightGrey, -3.3, -1.15, 0.32);
        glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.27, 1.3);
        u.drawCube(0.24, 0.15, 0.7, cLightGrey, -3.3, -1.15, 0.32);
        glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.47, 1.25);
        u.drawCube(0.24, 0.15, 0.7, cLightGrey, -3.3, -1.15, 0.32);
        glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();


}


void Hands::drawLeftHand() {
    glPushMatrix(); {
        /*glRotatef(180,0,1,0);*/
        glScalef(-1, 1, 1);

        drawShoulder();

        glPushMatrix();
        glTranslatef(3.04, 4.9, 0);
        glRotatef(wholeAngleLeft, 1, 0, 0);
        glTranslatef(-3.04, -4.9, 0);

        drawUpperArm();
        drawElbow();

        glPushMatrix(); {
            glTranslatef(3.04, 1.63, 0);
            glRotatef(-LowerArmAngleLeft, 1, 0, 0);
            glTranslatef(-3.04, -1.63, 0);
            drawLowerArm();

            glPushMatrix();
            glTranslatef(1, 0.2, 0);
            glScalef(1.3, 1.4, 1.7);
            drawWrist();
            drawPalm();
            drawThumb();
            drawFinger();
            glPopMatrix();
        } glPopMatrix();

        drawShoulderPad();

        glPopMatrix();

        glPopMatrix();
    }
}


void Hands::drawRightHand() {
    drawShoulder();

    glPushMatrix();
    glTranslatef(-3.04, 4.9, 0);
    glRotatef(wholeAngleRight, 1, 0, 0);
    glTranslatef(3.04, -4.9, 0);

    drawUpperArm();
    drawElbow();

    glPushMatrix(); {
        glTranslatef(-3.04, 1.63, 0);
        glRotatef(-LowerArmAngleRight, 1, 0, 0);
        glTranslatef(3.04, -1.63, 0);
        drawLowerArm();

        glPushMatrix();
        glTranslatef(1,0.2,0);
        glScalef(1.3,1.4,1.7);
        drawWrist();
        drawPalm();
        drawThumb();
        drawFinger();
        glPopMatrix();
    } glPopMatrix();

    drawShoulderPad();

    glPopMatrix();
}

void Hands::drawHands() {
    glPushMatrix();
    glTranslatef(0.14, 0, 0);
    drawLeftHand();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.14, 0, 0);
    drawRightHand();
    glPopMatrix();
}
