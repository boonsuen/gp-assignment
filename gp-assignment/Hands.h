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

    float LowerArmTurnAngleRight = 0;
    float LowerArmTurnAngleLeft = 0;
    float LowerArmTurnAngleMax = 90;

    float wristAngleRight = 0;
    float wristAngleLeft = 0;
    float wristAngleMax = 25;

    bool thumbCloseRight = false;
    bool finger1CloseRight = false;
    bool finger2CloseRight = false;
    bool finger3CloseRight = false;
    bool finger4CloseRight = false;

    bool thumbCloseLeft = false;
    bool finger1CloseLeft = false;
    bool finger2CloseLeft = false;
    bool finger3CloseLeft = false;
    bool finger4CloseLeft = false;

    float thumbCloseAngleRight = 0;
    float thumbCloseAngleLeft = 0;
    float finger1CloseAngleRight = 0;
    float finger1CloseAngleLeft = 0;
    float finger2CloseAngleRight = 0;
    float finger2CloseAngleLeft = 0;
    float finger3CloseAngleRight = 0;
    float finger3CloseAngleLeft = 0;
    float finger4CloseAngleRight = 0;
    float finger4CloseAngleLeft = 0;

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
    void drawFingerUp();
    void drawLeftThumb();
    void drawLeftFingers();
    void drawRightThumb();
    void drawRightFingers();

    void reset();

    void keyActions(unsigned char key);
   
};

void Hands::keyActions(unsigned char key) {
    // Right Arm Movement
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
        if (this->LowerArmAngleRight < LowerArmAngleMax) {
            this->LowerArmAngleRight += 1;
        }
    }
    else if (key == 's' || key == 's') {

        if (this->LowerArmAngleRight > 0) {
            this->LowerArmAngleRight -= 1;
        }
    }

    // Left Arm Movement
    else if (key == 'E' || key == 'e') {
        if (this->wholeAngleLeft > -wholeAngleMax) {
            this->wholeAngleLeft -= 1;
        }
    }
    else if (key == 'D' || key == 'd') {
        if (this->wholeAngleLeft < wholeAngleMax) {
            this->wholeAngleLeft += 1;
        }
    }
    else if (key == 'R' || key == 'r') {
        if (this->LowerArmAngleLeft < LowerArmAngleMax) {
            this->LowerArmAngleLeft += 1;
        }
    }
    else if (key == 'F' || key == 'f') {
        if (this->LowerArmAngleLeft > 0) {
            this->LowerArmAngleLeft -= 1;
        }
    }

    // Right Lower Arm Turn
    else if (key == 'Z' || key == 'z') {
        if (this->LowerArmTurnAngleRight > -LowerArmTurnAngleMax) {
            this->LowerArmTurnAngleRight -= 1;
        }
    }
    else if (key == 'X' || key == 'x') {
        if (this->LowerArmTurnAngleRight < LowerArmTurnAngleMax) {
            this->LowerArmTurnAngleRight += 1;
        }
    }

    // Left Lower Arm Turn
    else if (key == 'C' || key == 'c') {
        if (this->LowerArmTurnAngleLeft > -LowerArmTurnAngleMax) {
            this->LowerArmTurnAngleLeft -= 1;
        }
    }
    else if (key == 'V' || key == 'v') {
        if (this->LowerArmTurnAngleLeft < LowerArmTurnAngleMax) {
            this->LowerArmTurnAngleLeft += 1;
        }
    }

    // Right Wrist Movement
    else if (key == '1') {
        if (this->wristAngleRight < wristAngleMax) {
                this->wristAngleRight += 1;
        }
    }
    else if (key == '2') {
        if (this->wristAngleRight > -wristAngleMax) {
        this->wristAngleRight -= 1;
    
        }
    }

    // Left Wrist Movement
    else if (key == '4') {
        if (this->wristAngleLeft < wristAngleMax) {
            this->wristAngleLeft += 1;
        }
    }
    else if (key == '5') {
        if (this->wristAngleLeft > -wristAngleMax) {
            this->wristAngleLeft -= 1;

        }
    }

    // Right Thumb, Fingers Movement
    else if (key == 'T' || key == 't') {
        thumbCloseRight = !thumbCloseRight;
    }
    else if (key == 'Y' || key == 'y') {
        finger1CloseRight = !finger1CloseRight;
    }
    else if (key == 'U' || key == 'u') {
        finger2CloseRight = !finger2CloseRight;
    }
    else if (key == 'I' || key == 'i') {
        finger3CloseRight = !finger3CloseRight;
    }
    else if (key == 'O' || key == 'o') {
        finger4CloseRight = !finger4CloseRight;
    }
    else if (key == '6') {
        if (thumbCloseRight && finger1CloseRight
            && finger2CloseRight && finger3CloseRight
            && finger4CloseRight) {
            thumbCloseRight = false;
            finger1CloseRight = false;
            finger2CloseRight = false;
            finger3CloseRight = false;
            finger4CloseRight = false;
        }
        else {
            thumbCloseRight = true;
            finger1CloseRight = true;
            finger2CloseRight = true;
            finger3CloseRight = true;
            finger4CloseRight = true;
        }
    }

    // Left Thumb, Fingers Movement
    else if (key == 'G' || key == 'g') {
        thumbCloseLeft = !thumbCloseLeft;
    }
    else if (key == 'H' || key == 'h') {
        finger1CloseLeft = !finger1CloseLeft;
    }
    else if (key == 'J' || key == 'j') {
        finger2CloseLeft = !finger2CloseLeft;
    }
    else if (key == 'K' || key == 'k') {
        finger3CloseLeft = !finger3CloseLeft;
    }
    else if (key == 'L' || key == 'l') {
        finger4CloseLeft = !finger4CloseLeft;
    }
    else if (key == '9') {
        if (thumbCloseLeft && finger1CloseLeft 
            && finger2CloseLeft && finger3CloseLeft
            && finger4CloseLeft) {
            thumbCloseLeft = false;
            finger1CloseLeft = false;
            finger2CloseLeft = false;
            finger3CloseLeft = false;
            finger4CloseLeft = false;
        }
        else {
            thumbCloseLeft = true;
            finger1CloseLeft = true;
            finger2CloseLeft = true;
            finger3CloseLeft = true;
            finger4CloseLeft = true;
        }
    }

    // Reset
    else if (key == '0') {
        reset();
    }
}

void Hands::reset() {
    this-> wholeAngleRight = 0;
    this-> wholeAngleLeft = 0;
    this-> LowerArmAngleRight = 0;
    this-> LowerArmAngleLeft = 0;
    this-> thumbCloseAngleRight = 0;
    this-> thumbCloseAngleLeft = 0;
    this-> finger1CloseAngleRight = 0;
    this-> finger1CloseAngleLeft = 0;
    this-> finger2CloseAngleRight = 0;
    this-> finger2CloseAngleLeft = 0;
    this-> finger3CloseAngleRight = 0;
    this-> finger3CloseAngleLeft = 0;
    this-> finger4CloseAngleRight = 0;
    this-> finger4CloseAngleLeft = 0;

    this-> LowerArmTurnAngleRight = 0;
    this-> LowerArmTurnAngleLeft = 0;

    this-> wristAngleRight = 0;
    this-> wristAngleLeft = 0;

    this-> thumbCloseRight = false;
    this-> finger1CloseRight = false;
    this-> finger2CloseRight = false;
    this-> finger3CloseRight = false;
    this-> finger4CloseRight = false;

    this-> thumbCloseLeft = false;
    this-> finger1CloseLeft = false;
    this-> finger2CloseLeft = false;
    this-> finger3CloseLeft = false;
    this-> finger4CloseLeft = false;
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

void Hands::drawFingerUp() {
    u.drawCube(0.24, 0.15, 0.3, cLightGrey, -3.3, -1.15, 0.6);
}

void Hands::drawRightThumb() {
    glPushMatrix();
    glTranslatef(0, -0.23, -0.2);

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(thumbCloseAngleRight, 0, 1, 0);
        glTranslatef(3.3, 1.69, -0.52);
        u.drawCube(0.24, 0.149, 0.2, cLightGrey, -3.3, -1.15, 0.57);

        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(thumbCloseAngleRight, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPopMatrix();

    if (thumbCloseRight && thumbCloseAngleRight < 45) {
        thumbCloseAngleRight += 1;
    }
    else if (!thumbCloseRight && thumbCloseAngleRight > 0) {
        thumbCloseAngleRight -= 1;
    }
}

void Hands::drawLeftThumb() {
    glPushMatrix();
    glTranslatef(0, -0.23, -0.2);

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(thumbCloseAngleLeft, 0, 1, 0);
        glTranslatef(3.3, 1.69, -0.52);
        u.drawCube(0.24, 0.149, 0.2, cLightGrey, -3.3, -1.15, 0.57);

        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(thumbCloseAngleLeft, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPopMatrix();

    if (thumbCloseLeft && thumbCloseAngleLeft < 45) {
        thumbCloseAngleLeft += 1;
    }
    else if (!thumbCloseLeft && thumbCloseAngleLeft > 0) {
        thumbCloseAngleLeft -= 1;
    }
}

void Hands::drawLeftFingers() {
    u.drawCube(0.3, 0.3, 0.42, cLightGrey2, -3.3, -1.6, 0);

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger1CloseAngleLeft, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);

        glScalef(1,1,0.6);
        glRotatef(90,1,0,0);
        glTranslatef(0,0.87,1.2);
        drawFingerUp();
        glPushMatrix();

        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger1CloseAngleLeft, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger2CloseAngleLeft, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);

        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.07, 1.3);
        drawFingerUp();
        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger2CloseAngleLeft, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger3CloseAngleLeft, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);
        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.27, 1.3);
        drawFingerUp();
        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger3CloseAngleLeft, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger4CloseAngleLeft, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);
        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.47, 1.25);
        drawFingerUp();
        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger4CloseAngleLeft, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    if (finger1CloseLeft && finger1CloseAngleLeft < 45) {
        finger1CloseAngleLeft += 1;
    }
    else if (!finger1CloseLeft && finger1CloseAngleLeft > 0) {
        finger1CloseAngleLeft -= 1;
    }

    if (finger2CloseLeft && finger2CloseAngleLeft < 45) {
        finger2CloseAngleLeft += 1;
    }
    else if (!finger2CloseLeft && finger2CloseAngleLeft > 0) {
        finger2CloseAngleLeft -= 1;
    }

    if (finger3CloseLeft && finger3CloseAngleLeft < 45) {
        finger3CloseAngleLeft += 1;
    }
    else if (!finger3CloseLeft && finger3CloseAngleLeft > 0) {
        finger3CloseAngleLeft -= 1;
    }

    if (finger4CloseLeft && finger4CloseAngleLeft < 45) {
        finger4CloseAngleLeft += 1;
    }
    else if (!finger4CloseLeft && finger4CloseAngleLeft > 0) {
        finger4CloseAngleLeft -= 1;
    }
}

void Hands::drawRightFingers() {
    u.drawCube(0.3, 0.3, 0.42, cLightGrey2, -3.3, -1.6, 0);

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger1CloseAngleRight, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);

        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 0.87, 1.2);
        drawFingerUp();
        glPushMatrix();

        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger1CloseAngleRight, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger2CloseAngleRight, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);

        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.07, 1.3);
        drawFingerUp();
        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger2CloseAngleRight, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger3CloseAngleRight, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);
        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.27, 1.3);
        drawFingerUp();
        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger3CloseAngleRight, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    glPushMatrix(); {
        glTranslatef(-3.3, -1.69, 0.52);
        glRotatef(finger4CloseAngleRight, 0, 0, 1);
        glTranslatef(3.3, 1.69, -0.52);
        glScalef(1, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0, 1.47, 1.25);
        drawFingerUp();
        glPushMatrix();
        glTranslatef(-3.2, -1.69, 0.65);
        glRotatef(finger4CloseAngleRight, 0, 1, 0);
        glTranslatef(3.2, 1.69, -0.65);
        glRotatef(-90, 1, 0, 0);
        glScalef(1, 1.2, 1);
        u.drawCylinder(cWhite, 0.07, 0.05, 0.25, 30, 30, GLU_FILL, false, -3.3, -0.8, -1.15);
        u.drawCylinder(cWhite, 0.049, 0.049, 0.25, 30, 30, GLU_FILL, true, -3.3, -0.8, -1.15);
        glPopMatrix();
    } glPopMatrix();

    if (finger1CloseRight && finger1CloseAngleRight < 45) {
        finger1CloseAngleRight += 1;
    }
    else if (!finger1CloseRight && finger1CloseAngleRight > 0) {
        finger1CloseAngleRight -= 1;
    }

    if (finger2CloseRight && finger2CloseAngleRight < 45) {
        finger2CloseAngleRight += 1;
    }
    else if (!finger2CloseRight && finger2CloseAngleRight > 0) {
        finger2CloseAngleRight -= 1;
    }

    if (finger3CloseRight && finger3CloseAngleRight < 45) {
        finger3CloseAngleRight += 1;
    }
    else if (!finger3CloseRight && finger3CloseAngleRight > 0) {
        finger3CloseAngleRight -= 1;
    }

    if (finger4CloseRight && finger4CloseAngleRight < 45) {
        finger4CloseAngleRight += 1;
    }
    else if (!finger4CloseRight && finger4CloseAngleRight > 0) {
        finger4CloseAngleRight -= 1;
    }
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

            glTranslatef(-3.3, 1.63, 0);
            glRotatef(LowerArmTurnAngleLeft, 0, 1, 0);
            glTranslatef(3.3, -1.63, 0);
            glBindTexture(GL_TEXTURE_2D, 0);
            u.drawCube(1, 1, 1, cLightGrey, -3.3, 0, 0);

            glBindTexture(GL_TEXTURE_2D, textures[activeTexture]); {
                u.drawCube(1.1, 0.6, 1.1, cWhite, -3.3, -0.5, 0);
                glBindTexture(GL_TEXTURE_2D, 0);
            }

            glPushMatrix();
            glTranslatef(1, 0.2, 0);
            glScalef(1.3, 1.4, 1.7);
                drawWrist();
            glPushMatrix(); {
                glTranslatef(-3.31, -0.91, 0);
                glRotatef(wristAngleLeft, 0,0,1);
                glTranslatef(3.31, 0.91, 0);
                drawPalm();
                drawLeftThumb();
                drawLeftFingers();
            } glPopMatrix();
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

        glTranslatef(-3.3, 1.63, 0);
        glRotatef(LowerArmTurnAngleRight, 0, 1, 0);
        glTranslatef(3.3, -1.63, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        u.drawCube(1, 1, 1, cLightGrey, -3.3, 0, 0);

        glBindTexture(GL_TEXTURE_2D, textures[activeTexture]); {
            u.drawCube(1.1, 0.6, 1.1, cWhite, -3.3, -0.5, 0);
            glBindTexture(GL_TEXTURE_2D, 0);
        }

        glPushMatrix();
        glTranslatef(1,0.2,0);
        glScalef(1.3,1.4,1.7);
        drawWrist();
        glPushMatrix(); {
            glTranslatef(-3.31, -0.91, 0);
            glRotatef(wristAngleRight, 0, 0, 1);
            glTranslatef(3.31, 0.91, 0);
            drawPalm();
            drawRightThumb();
            drawRightFingers();
        } glPopMatrix();
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
