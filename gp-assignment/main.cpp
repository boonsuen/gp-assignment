#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
const char* ICE_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/ice.bmp";
const char* WHITE_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/white.bmp";
const char* BLACK_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/black.bmp";
const char* BLACK_SWORD_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/black-sword.bmp";
const char* BLUE_SWORD_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/blue-sword.bmp";
const char* RED_SWORD_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/red-sword.bmp";
const char* BODY_RED_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/red.bmp";
const char* BODY_BLUE_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/blue.bmp";
const char* BODY_BACKPACK_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/backpack.bmp";
const char* BODY_SILVER_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/silver.bmp";
const char* BODY_ROCKET_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/rocketPower.bmp";
const char* SHIELD_HANDLE_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/HandleBlack.bmp";
const char* SKY_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/sky.bmp";
const char* LAND_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/land.bmp";
const char* MOON_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/moon.bmp";
const char* SUN_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/sun.bmp";
const char* NIGHT_SKY_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/night-sky.bmp";
const char* SCIFI_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/scifi.bmp";

const char* gunBody_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunBody.bmp";
const char* gunBodyUp_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunBodyUp.bmp";
const char* gunBodyBack_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunBodyBack.bmp";
const char* gunBodyBackBk_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunBodyBackBk.bmp";
const char* gunFront_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunFront.bmp";
const char* gunFrontUp_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunFrontUp.bmp";
const char* gunFrHandle_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunFrHandle.bmp";
const char* gunFrFrHandle_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunFrFrHandle.bmp";
const char* gunAim_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunAim.bmp";
const char* gunHandle_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunHandle.bmp";
const char* gunShoot_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/gunShoot.bmp";

#else
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
const char* ICE_TEXTURE_PATH = "ice.bmp";
const char* WHITE_TEXTURE_PATH = "white.bmp";
const char* BLACK_TEXTURE_PATH = "black.bmp";
const char* BLACK_SWORD_TEXTURE_PATH = "black-sword.bmp";
const char* BLUE_SWORD_TEXTURE_PATH = "blue-sword.bmp";
const char* RED_SWORD_TEXTURE_PATH = "red-sword.bmp";
const char* BODY_RED_TEXTURE_PATH = "red.bmp";
const char* BODY_BLUE_TEXTURE_PATH = "blue.bmp";
const char* BODY_BACKPACK_TEXTURE_PATH = "backpack.bmp";
const char* BODY_SILVER_TEXTURE_PATH = "silver.bmp";
const char* BODY_ROCKET_TEXTURE_PATH = "rocketPower.bmp";
const char* SHIELD_HANDLE_TEXTURE_PATH = "HandleBlack.bmp";
const char* SKY_TEXTURE_PATH = "sky.bmp";
const char* LAND_TEXTURE_PATH = "land.bmp";
const char* MOON_TEXTURE_PATH = "moon.bmp";
const char* SUN_TEXTURE_PATH = "sun.bmp";
const char* NIGHT_SKY_TEXTURE_PATH = "night-sky.bmp";
const char* SCIFI_TEXTURE_PATH = "scifi.bmp";

const char* gunBody_TEXTURE_PATH = "gunBody.bmp";
const char* gunBodyUp_TEXTURE_PATH = "gunBodyUp.bmp";
const char* gunBodyBack_TEXTURE_PATH = "gunBodyBack.bmp";
const char* gunBodyBackBk_TEXTURE_PATH = "gunBodyBackBk.bmp";
const char* gunFront_TEXTURE_PATH = "gunFront.bmp";
const char* gunFrontUp_TEXTURE_PATH = "gunFrontUp.bmp";
const char* gunFrHandle_TEXTURE_PATH = "gunFrHandle.bmp";
const char* gunFrFrHandle_TEXTURE_PATH = "gunFrFrHandle.bmp";
const char* gunAim_TEXTURE_PATH = "gunAim.bmp";
const char* gunHandle_TEXTURE_PATH = "gunHandle.bmp";
const char* gunShoot_TEXTURE_PATH = "gunShoot.bmp";
#endif

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Head.h"
#include "Body.h"
#include "Hands.h"
#include "Legs.h"
#include "Common.h"
#include "Sword.h"
#include "Shield.h"

// 1. Includes
// 2. Function headers
// 3. Global constants and variables
// 4. projection();
// 5. lighting();
// 7. display();
// 8. processNormalKeys();
// 9. processSpecialKeys();
// 10. Textures
// -- Image struct
// -- getint();
// -- getshort();
// -- imageLoad();
// -- loadTextures();
// 11. initGL();
// 12. main();

/*
 * -----------------------------------------------
 * FUNCTION HEADERS
 * -----------------------------------------------
 */
void projection();
void lighting();
void display();
void robotTransformationKeyActions(unsigned char key);

/*
 * -----------------------------------------------
 * GLOBAL CONSTANT AND VARIABLES
 * -----------------------------------------------
 */
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int FRAME_RATE = 15; // Refresh interval in milliseconds (1000/15 = 66 frames per second)
const float PI = 3.1415926535;

// ============== View & Projection & Transformation ==============
bool isOrtho = true; // Is ortho view
const float O_NEAR = -20, O_FAR = 40; // Ortho near far
const float P_NEAR = 0.1, P_FAR = 40; // Perspective near far
// Projection Transformtion (TX, TY, RY)
float pTx = 0, pTy = 0, ptSpeed = 1;  // Projection Translate X and Y
float pRy = 0, prSpeed = 2.0;         // Projection Rotate Y
const float MAX_ORTHO_PTX = 10; // 13
const float MAX_ORTHO_PTY = 7; // 12
const float MAX_PERSPECTIVE_PTX = 10;
const float MAX_PERSPECTIVE_PTY = 12;
// Model View Transformation (TZ, RX, RY, RZ)
float mTz = 0, mtSpeed = 1;  // Model View Translate Z (zoom)
float mRx = 0, mRy = 0, mRz = 0;
float robotTx = 0, robotTy = 0, robotTz = 0;
float rtSpeed = 0.5;
float robotRx = 0, robotRy = 0, robotRz = 0;
float rrSpeed = 1;

// =============== TEXTURE ================
bool isTexture = false;
const int TEXTURES_NO = 29;
GLuint textures[TEXTURES_NO]; /* storage for textures. */
const char* filenames[TEXTURES_NO] = {
    ICE_TEXTURE_PATH,           // 0
    WHITE_TEXTURE_PATH,         // 1
    BLACK_TEXTURE_PATH,         // 2
    BLACK_SWORD_TEXTURE_PATH,   // 3
    BLUE_SWORD_TEXTURE_PATH,    // 4
    RED_SWORD_TEXTURE_PATH,     // 5
    BODY_RED_TEXTURE_PATH,      // 6
    BODY_BLUE_TEXTURE_PATH,     // 7
    BODY_BACKPACK_TEXTURE_PATH, // 8
    BODY_SILVER_TEXTURE_PATH,   // 9
    BODY_ROCKET_TEXTURE_PATH,   // 10
    SHIELD_HANDLE_TEXTURE_PATH, // 11
    SKY_TEXTURE_PATH,           // 12
    LAND_TEXTURE_PATH,          // 13
    MOON_TEXTURE_PATH,          // 14
    SUN_TEXTURE_PATH,           // 15
    NIGHT_SKY_TEXTURE_PATH,     // 16
    SCIFI_TEXTURE_PATH,         // 17

    gunBody_TEXTURE_PATH,       //18
    gunBodyUp_TEXTURE_PATH, //19
    gunBodyBack_TEXTURE_PATH, //20
    gunBodyBackBk_TEXTURE_PATH, //21
    gunFront_TEXTURE_PATH,//22
    gunFrontUp_TEXTURE_PATH,//23
    gunFrHandle_TEXTURE_PATH,//24
    gunFrFrHandle_TEXTURE_PATH,//25
    gunAim_TEXTURE_PATH,//26
    gunHandle_TEXTURE_PATH,//27
    gunShoot_TEXTURE_PATH//28
};
int activeTexture = 0;
bool showSkybox = false;

// Status
bool defenseMode = false;
bool attackMode = false;

bool showGun = false;
bool showSword = false;
bool headAttackMode = false; 
bool gunAttackMode = false;
bool swordAttackMode = false;

// Body (together with Head and Hands) rotation
float bodyRotate = 0;
float bodyRotateMax = 45;

// =============== LIGHTING ================
bool isNightTheme = false;
float lightRX = 2.5, lightRY = 3.5, lightRZ = 3;
GLenum lightType = GL_DIFFUSE;

float amb[] = { 251.0/255, 255.0/255, 137.0/255 }; // ambient
float posA[] = { lightRX, lightRY, lightRZ};

float diff[] = { 1, 0, 0 };
float posD[] = { lightRX, lightRY, lightRZ};
float ambM[] = { 1.0, 1.0, 102.0/255 };

float spec[] = { 0.0, 0.0, 1.0 }; // specular
float specM[] = { 0.0, 0.0, 1.0 };
float posS[] = { lightRX, lightRY, lightRZ};
bool lightOn = false;

// =============== COLORS ================
float cWhite[] = { 1, 1, 1 };
float cBlack[] = { 0.2, 0.2, 0.2 };
float cGrey[] = { 71.0/255, 68.0/255, 68.0/255 };
float cLightGrey[] = { 224.0/255, 227.0/255, 229.0/255 };
float cLightGrey2[] = { 190.0/255, 203.0/255, 215.0/255 };
float cHeadRed[] = { 1, 63.0/255, 57.0/255 };
float cEyeYellow[] = { 249.0/255, 1, 102.0/255 };
float cEarGrey[] = { 132.0/255, 134.0/255, 137.0/255 };
float cAntennaYellow[] = { 254.0/255, 223.0/255, 0 };
// Leg colors
float cDarkBlue[] = { 0, 28.0/255, 63.0/255 };
float cLightSkinGrey[] = { 233.0/255, 234.0/255, 245.0/255 };
float cLightSkinGrey2[] = { 213.0/255, 214.0/255, 219.0/255 };
float cPrimaryBlue[] = { 0, 23.0/255, 163.0/255 };
float cPrimaryLightBlue[] = { 0, 118.0/255, 237.0/255 };
float cLegBoost[] = { 1, 153.0/255, 0};

float cDarkGreen[] = { 0 ,0.6 , 0 };
float cDarkGreen1[] = { 0 , 0.5 , 0 };

void projection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (isOrtho) {
        glOrtho(-15, 15, -15, 15, O_NEAR, O_FAR);
    } else {
        gluPerspective(70, 1, P_NEAR, P_FAR);
    }
    // =============================================================
    // <<< IMPORTANT: TRANSFORM ONLY AFTER SETTING UP PROjECTION >>>
    // =============================================================
    glTranslatef(pTx, pTy, 0); // Translate X & Y for O and P projection
    glRotatef(pRy, 0, 1, 0);
}

void lighting() {
    posA[0] = lightRX;
    posA[1] = lightRY;
    posA[2] = lightRZ;

    posD[0] = lightRX;
    posD[1] = lightRY;
    posD[2] = lightRZ;

    posS[0] = lightRX;
    posS[1] = lightRY;
    posS[2] = lightRZ;
    
    if (isNightTheme) {
        amb[0] = 90.0/255;
        amb[1] = 159.0/255;
        amb[2] = 247.0/255;
        diff[0] = 0;
        diff[1] = 0;
        diff[2] = 1;
    } else {
        amb[0] = 251.0/255;
        amb[1] = 255.0/255;
        amb[2] = 137.0/255;
        diff[0] = 1;
        diff[1] = 0;
        diff[2] = 0;
    }
    
//    std::cout << lightRX << ":" << lightRY << ":" << lightRZ << std::endl;

    glEnable(GL_NORMALIZE);
    if (lightOn) {
        glEnable(GL_LIGHTING);
    } else {
        glDisable(GL_LIGHTING);
    }

    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_POSITION, posA);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambM);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, diff);
    glLightfv(GL_LIGHT1, GL_POSITION, posD);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);

    glLightfv(GL_LIGHT2, GL_SPECULAR, spec);
    glLightfv(GL_LIGHT2, GL_POSITION, posS);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void drawSkyBox(float width, float height, float depth) {
    glPushMatrix();
    glColor3fv(cWhite);
    
    glBindTexture(GL_TEXTURE_2D, textures[13]);
    glMaterialfv(GL_FRONT, GL_AMBIENT, cWhite);
    glBegin(GL_QUADS);
    // Face 1, bottom
    glNormal3f(0, 1, 0);
    glTexCoord2f(0.0, 1.0);  glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glTexCoord2f(1.0, 1.0);  glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(1.0, 0.0);  glVertex3f(width / 2, -(height / 2), depth / 2);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textures[isNightTheme ? 16 : 12]);
    glBegin(GL_QUADS);
    // Face 2, front
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 0); glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glTexCoord2f(1, 1); glVertex3f(-(width / 2), height / 2, depth / 2);
    glTexCoord2f(0, 1); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(0, 0); glVertex3f(width / 2, -(height / 2), depth / 2);

    // Face 3, right
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(width / 2, -(height / 2), depth / 2);
    glTexCoord2f(1, 0); glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(1, 1); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(0, 1); glVertex3f(width / 2, height / 2, depth / 2);

    // Face 4, top
    glNormal3f(0, -1, 0);
    glTexCoord2f(0.7, 0.4); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(0.7, 0.7); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(0.4, 0.7); glVertex3f(-(width / 2), height / 2, -(depth / 2));
    glTexCoord2f(0.4, 0.5); glVertex3f(-(width / 2), height / 2, depth / 2);

    // Face 5, left
    glNormal3f(1, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(-(width / 2), height / 2, depth / 2);
    glTexCoord2f(1, 0); glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), height / 2, -(depth / 2));

    // Face 6, back
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), height / 2, -(depth / 2));
    glTexCoord2f(1, 1); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(1, 0); glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glEnd();

    glPopMatrix();
}

Head head;
Body body;
Hands hands;
Legs legs;

// Walking Animation
bool isWalking = false;
const int maxSteps = 10;
int stepsWalked = 0;
bool moveToward = true;

bool rightFirstUpWalked = false;
bool rightSecondUpWalked = false;
bool rightDownWalked = false;
bool leftFirstUpWalked = false;
bool leftSecondUpWalked = false;
bool leftDownWalked = false;

bool movingFront = false;
float maxOneLegMove = 0.2;
float oneLegMoved = 0;

bool isLeftLeg = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (lightOn) {
        glDisable(GL_LIGHTING);
        glPushMatrix();
        glTranslatef(lightRX, lightRY, lightRZ);
        glEnable(GL_TEXTURE_2D);
        if (isNightTheme) {
            glBindTexture(GL_TEXTURE_2D, textures[14]);
            GLfloat moonColor[] = { 45.0/255, 109.0/255, 237.0/255 };
            head.u.drawSphere(0.5, 30, 30, GLU_FILL, moonColor, 0, 0, 0);
        } else {
            glBindTexture(GL_TEXTURE_2D, textures[15]);
            GLfloat sunColor[] = { 246.0/255, 161.0/255, 38.0/255 };
            head.u.drawSphere(0.5, 30, 30, GLU_FILL, sunColor, 0, 0, 0);
        }
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }

    projection();
    lighting();
    
    if (showSkybox) {
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        drawSkyBox(27, 27, 27);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
    
    if (isTexture) {
        glEnable(GL_TEXTURE_2D);
    } else {
        glDisable(GL_TEXTURE_2D);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Model View Transformation
    glTranslatef(0, 0, mTz); // Translate for Model View
    glRotatef(mRx, 1, 0, 0);
    glRotatef(mRy, 0, 1, 0);
    glRotatef(mRz, 0, 0, 1);
    
    if (isOrtho) {
        glScalef(2, 2, 2);
    }
    
    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    
    attackMode = headAttackMode && gunAttackMode && swordAttackMode;
    
    glPushMatrix(); {
        // Robot transformation
        glTranslatef(robotTx, robotTy, robotTz);
        glRotatef(!moveToward ? 180 : 0, 0, 1, 0);
        glRotatef(robotRx, 1, 0, 0);
        glRotatef(robotRy, 0, 1, 0);
        glRotatef(robotRz, 0, 0, 1);
        glScalef(0.4, 0.4, 0.4);
        if (isWalking) {
            bool skip = false;
            if (stepsWalked >= maxSteps) {
                moveToward = !moveToward;
                stepsWalked = -3;
            }
            if (isLeftLeg) {
                if (leftFirstUpWalked == false) {
                    if (legs.hipAngleLeft > -40) {
                        legs.hipAngleLeft -= 1/45.0 * 40;
                    }
                    if (legs.kneeAngleLeft < legs.kneeAngleMax) {
                        legs.kneeAngleLeft += 1/45.0 * 50;
                    }
                    if (legs.hipAngleLeft <= -40 && legs.kneeAngleLeft >= legs.kneeAngleMax) {
                        leftFirstUpWalked = true;
                    }
                }
                if (leftFirstUpWalked == true && leftSecondUpWalked == false) {
                    if (legs.kneeAngleLeft > 35) {
                        legs.kneeAngleLeft -= 1;
                    }
                    if (legs.kneeAngleLeft <= 35) {
                        leftSecondUpWalked = true;
                        movingFront = true;
                    }
                }
                
                if (!movingFront) {
                    if (hands.wholeAngleLeft > -30) {
                        hands.wholeAngleLeft -= 1;
                    }
                    if (hands.wholeAngleLeft <= -20) {
                        if (hands.LowerArmAngleLeft < 20) {
                            hands.LowerArmAngleLeft += 1;
                        }
                    }
                } else {
                    if (hands.wholeAngleLeft < 0) {
                        hands.wholeAngleLeft += 1;
                    }
                    if (hands.LowerArmAngleLeft > 0) {
                        hands.LowerArmAngleLeft -= 1;
                    }
                }
                
                if (movingFront) {
                    if (oneLegMoved < maxOneLegMove) {
                        oneLegMoved += 0.005;
                        if (moveToward) {
                            robotTz += 0.005;
                        } else {
                            robotTz -= 0.005;
                        }
                    }
                    if (legs.hipAngleLeft < 0) {
                        legs.hipAngleLeft += 1/45.0 * 40;
                    }
                    if (legs.kneeAngleLeft > 0) {
                        legs.kneeAngleLeft -= 1/45.0 * 50;
                    }
                    if (oneLegMoved >= maxOneLegMove
                        && legs.hipAngleLeft >= 0
                        && legs.kneeAngleLeft <= 0) {
                        isLeftLeg = false;
                        oneLegMoved = 0;
                        movingFront = false;
                        
                        leftFirstUpWalked = false;
                        leftSecondUpWalked = false;
                        leftDownWalked = false;
                        stepsWalked += 1;
                    }
                }
            } else {
                if (rightFirstUpWalked == false) {
                    if (legs.hipAngleRight > -40) {
                        legs.hipAngleRight -= 1/45.0 * 40;
                    }
                    if (legs.kneeAngleRight < legs.kneeAngleMax) {
                        legs.kneeAngleRight += 1/45.0 * 50;
                    }
                    if (legs.hipAngleRight <= -40 && legs.kneeAngleRight >= legs.kneeAngleMax) {
                        rightFirstUpWalked = true;
                    }
                }
                if (rightFirstUpWalked == true && rightSecondUpWalked == false) {
                    if (legs.kneeAngleRight > 35) {
                        legs.kneeAngleRight -= 1;
                    }
                    if (legs.kneeAngleRight <= 35) {
                        rightSecondUpWalked = true;
                        movingFront = true;
                    }
                }
                
                if (!movingFront) {
                    if (hands.wholeAngleRight > -30) {
                        hands.wholeAngleRight -= 1;
                    }
                    if (hands.wholeAngleRight <= -20) {
                        if (hands.LowerArmAngleRight < 20) {
                            hands.LowerArmAngleRight += 1;
                        }
                    }
                } else {
                    if (hands.wholeAngleRight < 0) {
                        hands.wholeAngleRight += 1;
                    }
                    if (hands.LowerArmAngleRight > 0) {
                        hands.LowerArmAngleRight -= 1;
                    }
                }
                
                if (movingFront) {
                    if (oneLegMoved < maxOneLegMove) {
                        oneLegMoved += 0.005;
                        if (moveToward) {
                            robotTz += 0.005;
                        } else {
                            robotTz -= 0.005;
                        }
                    }
                    if (legs.hipAngleRight < 0) {
                        legs.hipAngleRight += 1/45.0 * 40;
                    }
                    if (legs.kneeAngleRight > 0) {
                        legs.kneeAngleRight -= 1/45.0 * 50;
                    }
                    if (oneLegMoved >= maxOneLegMove
                        && legs.hipAngleRight >= 0
                        && legs.kneeAngleRight <= 0) {
                        isLeftLeg = true;
                        oneLegMoved = 0;
                        movingFront = false;
                        
                        rightFirstUpWalked = false;
                        rightSecondUpWalked = false;
                        rightDownWalked = false;
                        stepsWalked += 1;
                    }
                }
            }
        }
        
        glPushMatrix(); {
            glPushMatrix(); {
                glRotatef(bodyRotate, 0, 1, 0);
                
                glPushMatrix();
                glTranslatef(0, 6.7, 0);
                glScalef(0.35, 0.35, 0.35);
                head.drawHead();
                glPopMatrix();
                
                glPushMatrix();
                glTranslatef(0.88, -4.8, 0);
                glScalef(6, 6, 6);
                body.drawBody();
                glPopMatrix();
                
                hands.drawHands();
            }
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(0, -4.3, 0);
            glScalef(0.70, 0.70, 0.70);
            legs.drawLegs();
            glPopMatrix();
        }
        glPopMatrix();
    }
    
    glPopMatrix();

    glutSwapBuffers();
}

bool legKeyMode = false;
bool handKeyMode = false;
bool robotTransformationKeyMode = false;

void robotTransformationKeyActions(unsigned char key) {
    if (key == 'Q' || key == 'q') { // Up
        if (isOrtho) {
            if (robotTy < 9) {
                robotTy += rtSpeed;
            }
        } else {
            if (robotTy < 9) {
                robotTy += rtSpeed;
            }
        }
    } else if (key == 'A' || key == 'a') {
        if (isOrtho) {
            if (robotTy > -9) {
                robotTy -= rtSpeed;
            }
        } else {
            if (robotTy > -9) {
                robotTy -= rtSpeed;
            }
        }
    } else if (key == 'W' || key == 'w') {
        if (isOrtho) {
            if (robotTx > -5) {
                robotTx -= rtSpeed;
            }
        } else {
            if (robotTx > -11) {
                robotTx -= rtSpeed;
            }
        }
    } else if (key == 'S' || key == 's') {
        if (isOrtho) {
            if (robotTx < 5) {
                robotTx += rtSpeed;
            }
        } else {
            if (robotTx < 11) {
                robotTx += rtSpeed;
            }
        }
    } else if (key == 'E' || key == 'e') {
        if (isOrtho) {
            if (robotTz < 9) {
                robotTz += rtSpeed;
            }
        } else {
            if (robotTz < 8) {
                robotTz += rtSpeed;
            }
        }
    } else if (key == 'D' || key == 'd') {
        if (isOrtho) {
            if (robotTz > -12) {
                robotTz -= rtSpeed;
            }
        } else {
            if (robotTz > -8) {
                robotTz -= rtSpeed;
            }
        }
    }
    std::cout << "TX: " << robotTx
              << ", TY: " << robotTy
              << ", TZ: " << robotTz << std::endl;
    
    if (key == 'K' || key == 'k') {
        robotRx += rrSpeed;
    } else if (key == 'M' || key == 'm') {
        robotRx -= rrSpeed;
    } else if (key == 'L' || key == 'l') {
        robotRy -= rrSpeed;
    } else if (key == 'R' || key == 'r') {
        robotRy += rrSpeed;
    } else if (key == 'Z' || key == 'z') {
        robotRz += rrSpeed;
    } else if (key == 'X' || key == 'x') {
        robotRz -= rrSpeed;
    }
    std::cout << "RX: " << robotRx
              << ", RY: " << robotRy
              << ", RZ: " << robotRz << std::endl;
    
    
    if (key == '0') {
        robotTx = 0;
        robotTy = 0;
        robotTz = 0;
        robotRx = 0;
        robotRy = 0;
        robotRz = 0;
    }
}

void processNormalKeys(unsigned char key, int x, int y) {
    // Legs
    if (key == '7') {
        legKeyMode = !legKeyMode;
    }
    if (legKeyMode) {
        legs.keyActions(key);
        return;
    }
    // Hands
    if (key == '8') {
        handKeyMode = !handKeyMode;
    }
    if (handKeyMode) {
        hands.keyActions(key);
        return;
    }
    // Robot transformations
    if (key == '9') {
        robotTransformationKeyMode = !robotTransformationKeyMode;
    }
    if (robotTransformationKeyMode) {
        robotTransformationKeyActions(key);
        return;
    }
    
    // Head (C/B/G/V)
    head.keyActions(key);
    // Body (O/P), rotation including body, hands, head
    if (key == 'O' || key == 'o') {
        if (bodyRotate > -bodyRotateMax) {
            bodyRotate -= 1;
        }
    } else if (key == 'P' || key == 'p') {
        if (bodyRotate < bodyRotateMax) {
            bodyRotate += 1;
        }
    }
    
    if (key == '0') { // Reset
        pTx = 0;
        pTy = 0;
        pRy = 0;
        mTz = isOrtho ? 0 : -13;
        mRx = 0;
        mRy = 0;
        mRz = 0;
        isWalking = false;
        stepsWalked = 0;
        legs.hipAngleLeft = 0;
        legs.hipAngleRight = 0;
        legs.kneeAngleLeft = 0;
        legs.kneeAngleRight = 0;
        hands.reset();
        moveToward = true;
        head.headHorizontalAngle = 0;
        head.headVerticalAngle = 0;
        bodyRotate = 0;
        lightOn = false;
        lightRX = 2.5;
        lightRY = 3.5;
        lightRZ = 3;
        showGun = false;
        showSword = false;
        hands.sword.reset();

    } else if (key == '1') { // Change ortho/perspective
        isOrtho = !isOrtho;
        if (isOrtho) {
            mTz = 0;
            if (lightRX <= -9) {
                lightRX = -9;
            } else if (lightRX >= 9) {
                lightRX = 9;
            }
            if (lightRY >= 9) {
                lightRY = 9;
            } else if (lightRY <= -9) {
                lightRY = -9;
            }
            if (lightRZ >= 9) {
                lightRZ = 9;
            } else if (lightRZ <= -9) {
                lightRZ = -9;
            }
        } else {
            mTz = -13;
        }
    } else if (key == 'D' || key == 'd') {
        if (isOrtho) {
            if (pTx > -MAX_ORTHO_PTX) {
                pTx -= ptSpeed;
            }
        } else {
            if (pTx > -MAX_PERSPECTIVE_PTX) {
                pTx -= ptSpeed;
            }
        }
    } else if (key == 'A' || key == 'a') {
        if (isOrtho) {
            if (pTx < MAX_ORTHO_PTX) {
                pTx += ptSpeed;
            }
        } else {
            if (pTx < MAX_PERSPECTIVE_PTX) {
                pTx += ptSpeed;
            }
        }
    } else if (key == 'S' || key == 's') {
        if (isOrtho) {
            if (pTy < MAX_ORTHO_PTY - 0.01) {
                pTy += ptSpeed;
            }
        } else {
            if (pTy < MAX_PERSPECTIVE_PTY - 0.01) {
                pTy += ptSpeed;
            }
        }
    } else if (key == 'W' || key == 'w') {
        if (isOrtho) {
            if (pTy > -MAX_ORTHO_PTY + 0.11) {
                pTy -= ptSpeed;
            }
        } else {
            if (pTy > -MAX_PERSPECTIVE_PTY + 0.11) {
                pTy -= ptSpeed;
            }
        }
    } else if (key == 'R' || key == 'r') {
        pRy += prSpeed;
    } else if (key == 'L' || key == 'l') {
        pRy -= prSpeed;
    } else if (key == 'K' || key == 'k') {
        mRx += prSpeed;
    } else if (key == 'M' || key == 'm') {
        mRx -= prSpeed;
    } else if (key == 'Z' || key == 'z') {
        mRz -= prSpeed;
    } else if (key == 'X' || key == 'x') {
        mRz += prSpeed;
    }
    
    std::cout << "pTx: " << pTx << ", "
              << "pTy: " << pTy << ", "
              << "pRy: " << pRy << std::endl;
    
    // Enter (Enable/disable texture)
    if (key == 13) {
        isTexture = !isTexture;
    } else if (key == '6') { // Change texture
        if (activeTexture == 0) {
            activeTexture = 1;
        } else if (activeTexture == 1) {
            activeTexture = 2;
        } else if (activeTexture == 2) {
            activeTexture = 3;
        } else if (activeTexture == 3) {
            activeTexture = 17;
        } else if (activeTexture == 17) {
            activeTexture = 0;
        }
    } else if (key == 'H' || key == 'h') { // Show/hide skybox
        showSkybox = !showSkybox;
    }
    // Space (Enable/disable lighting)
    if (key == 32) {
        lightOn = !lightOn;
    }
    
    // Weapons
    else if (key == '2') { // Head Attack Mode
        headAttackMode = !headAttackMode;
    }
    hands.gun.keyActions(key);
    hands.sword.keyActions(key);
    /* 
    Show/hide Gun (G)
    Show/hide Sword (B)
    Head Attack Mode (2)
    Gun Attack Mode (3)
    Sword Attack Mode(4) 
    */

    // Walking
    if (key == '5') {
        isWalking = !isWalking;
        if (isWalking) {
            robotRx = 0;
            robotRz = 0;
        }
    }
}

void processSpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_DOWN) {
        if (isOrtho) {
            if (mTz > -6) {
                mTz -= mtSpeed;
            }
        } else {
            if (mTz > -13) { // > -P_FAR
                mTz -= mtSpeed;
            }
        }
    } else if (key == GLUT_KEY_UP) {
        if (isOrtho) {
            if (mTz < 18) { // O_FAR - 2
                mTz += mtSpeed;
            }
        } else {
            if (mTz < -2) { // < P_FAR
                mTz += mtSpeed;
            }
        }
    } else if (key == GLUT_KEY_LEFT) {
        mRy += prSpeed;
    } else if (key == GLUT_KEY_RIGHT) {
        mRy -= prSpeed;
    } else if (key == GLUT_KEY_F1) {
        defenseMode = !defenseMode;
    }
    std::cout << "mTz: " << mTz << std::endl;
    
    // Lighting
    if (key == GLUT_KEY_F2) {
        if (isOrtho) {
            if (lightRX > -9) {
                lightRX -= 0.5; // Light left
            }
        } else {
            if (lightRX > -13) {
                lightRX -= 0.5; // Light left
            }
        }
    } else if (key == GLUT_KEY_F3) {
        if (isOrtho) {
            if (lightRX < 9) {
                lightRX += 0.5; // Light right
            }
        } else {
            if (lightRX < 13) {
                lightRX += 0.5; // Light right
            }
        }
    } else if (key == GLUT_KEY_F4) {
        if (isOrtho) {
            if (lightRY < 9) {
                lightRY += 0.5; // Light up
            }
        } else {
            if (lightRY < 13) {
                lightRY += 0.5; // Light up
            }
        }
    } else if (key == GLUT_KEY_F5) {
        if (isOrtho) {
            if (lightRY > -9) {
                lightRY -= 0.5; // Light down
            }
        } else {
            if (lightRY > -13) {
                lightRY -= 0.5; // Light down
            }
        }
    } else if (key == GLUT_KEY_F6) {
        if (isOrtho) {
            if (lightRZ < 9) {
                lightRZ += 0.5; // Light front
            }
        } else {
            if (lightRZ < 13) {
                lightRZ += 0.5; // Light front
            }
        }
    } else if (key == GLUT_KEY_F7) {
        if (isOrtho) {
            if (lightRZ > -9) {
                lightRZ -= 0.5; // Light back
            }
        } else {
            if (lightRZ > -13) {
                lightRZ -= 0.5; // Light back
            }
        }
    } else if (key == GLUT_KEY_F8) {
        isNightTheme = !isNightTheme;
    }
}

/*
 * -----------------------------------------------
 * TEXTURES
 * -----------------------------------------------
 */
 /* Image type - contains height, width, and data */
struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char* data;
};
typedef struct Image Image;

/*
 * getint and getshort are help functions
 * to load bitmap byte by byte on SPARC platform.
 */

static unsigned int getint(FILE* fp) {
    int c, c1, c2, c3;

    // get 4 bytes
    c = getc(fp);
    c1 = getc(fp);
    c2 = getc(fp);
    c3 = getc(fp);

    return ((unsigned int)c) +
        (((unsigned int)c1) << 8) +
        (((unsigned int)c2) << 16) +
        (((unsigned int)c3) << 24);
}

static unsigned int getshort(FILE* fp) {
    int c, c1;

    // get 2 bytes
    c = getc(fp);
    c1 = getc(fp);

    return ((unsigned int)c) + (((unsigned int)c1) << 8);
}

int imageLoad(const char* filename, Image* image) {
    FILE* file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                         // standard counter.
    unsigned short int planes;     // number of planes in image (must be 1)
    unsigned short int bpp;         // number of bits per pixel (must be 24)

    // make sure the file is there.
    if ((file = fopen(filename, "rb")) == NULL) {
        printf("File Not Fond: %s\n", filename);
        return 0;
    }

    // seek through the bmp header, up to the width/height;
    fseek(file, 18, SEEK_CUR);

    // NO 100% errorchecking anymore!!!
    // read the width
    image->sizeX = getint(file);
    printf("Width of %s: %lu\n", filename, image->sizeX);

    // read the height
    image->sizeY = getint(file);
    printf("Height of %s: %lu\n", filename, image->sizeY);

    // calcualte the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;

    // read the planes
    planes = getshort(file);
    if (planes != 1) {
        printf("Planes from %s is not 1: %u\n", filename, planes);
        return 0;
    }

    // read the bpp
    bpp = getshort(file);
    if (bpp != 24) {
        printf("Bpp from %s is not 24: %u\n", filename, bpp);
        return 0;
    }

    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);

    // read the data.
    image->data = (char*)malloc(size);
    if (image->data == NULL) {
        printf("Error allocating memory for color-corrected image data");
        return 0;
    }

    if ((i = fread(image->data, size, 1, file)) != 1) {
        printf("Error reading image data from %s.\n", filename);
        return 0;
    }

    return 1;
}

// Load Bitmaps and convert to texture
GLvoid loadGLTextures(GLvoid) {
    // Create Textures
    glGenTextures(TEXTURES_NO, &textures[0]);
    
    for (int i = 0; i < TEXTURES_NO; i++) {
        // allocate space for texture.
        Image* image = (Image*)malloc(sizeof(Image));
        if (image == NULL) {
            printf("Error allocating space for image");
            exit(0);
        }
        if (!imageLoad(filenames[i], image)) {
            exit(1);
        }
        
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, image->sizeX, image->sizeY, 0,
            GL_BGR_EXT, GL_UNSIGNED_BYTE, image->data);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image->sizeX, image->sizeY, GL_BGR_EXT, GL_UNSIGNED_BYTE, image->data);
    }
}

/* A general OpenGL initialization function. Sets all of the initial parameters. */
GLvoid initGL(GLsizei width, GLsizei height) {
    loadGLTextures();
    glEnable(GL_TEXTURE_2D);

    glClearColor(63.0/255, 64.0/255, 239.0/255, 1); // This Will Clear the background Color to black.
    glClearDepth(1.0);    // Enables clearing of the depth buffer.
    glEnable(GL_DEPTH_TEST); // Enables depth testing.
    glShadeModel(GL_SMOOTH); // Enables smooth color shading.
    glEnable(0x809D);
    glEnable(GL_BLEND);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset the projection matrix.
}

/* Called back when timer expired */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(FRAME_RATE, timer, 0); // next timer call milliseconds later
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA | GLUT_MULTISAMPLE);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Robot");

    /* Register the function to do all our OpenGL drawing. */
    glutDisplayFunc(display);

    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    /* Initialize our window */
    initGL(WINDOW_WIDTH, WINDOW_HEIGHT);

    glutTimerFunc(0, timer, 0); // First timer call immediately
    glutMainLoop();
    return 0;
}


// --------------------- Notes ---------------------
// Projection transformation:
// Tx, Ty
// Ry (ortho only)
