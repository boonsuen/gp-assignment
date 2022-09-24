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

/*
 * -----------------------------------------------
 * GLOBAL CONSTANT AND VARIABLES
 * -----------------------------------------------
 */
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int FRAME_RATE = 15; // Refresh interval in milliseconds (1000/15 = 66 frames per second)
const float PI = 3.1415926535;

// View & Projection & Transformation
bool isOrtho = true; // Is ortho view
const float O_NEAR = -20, O_FAR = 20; // Ortho near far
const float P_NEAR = 0.1, P_FAR = 40; // Perspective near far
float pTx = 0, pTy = 0, ptSpeed = 0.1; // Translate for projection
float prSpeed = 2.0; // Rotate Y for projection

float ry = 90; // Rotate Y for Ortho (NO ROTATE Y FOR PERSPECTIVE!!!) and Model View

float mTx = 0, mTy = 0, mTz = 0, mtSpeed = 2; // Translate for modelview
float mRx = 0;

// Texture
bool isTexture = false;
const int TEXTURES_NO = 14;
GLuint textures[TEXTURES_NO]; /* storage for 2 textures. */
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
};
int activeTexture = 0;
bool showSkybox = false;

// Status
bool defenseMode = true;
bool attackMode = false;
bool headAttackMode = false;
bool swordAttackMode = false;

// Colors
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

void projection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset projection matrix

    glTranslatef(pTx, pTy, 0); // Translate X & Y for O and P projection
        
    if (isOrtho) {
        glOrtho(-20, 20, -20, 20, O_NEAR, O_FAR);
        glRotatef(ry, 0, 1, 0); // Rotate Y for ortho only!!!
    } else {
        gluPerspective(70, 1, P_NEAR, P_FAR);
    }
}

void lighting() {
   
}

void drawSkyBox(float width, float height, float depth) {
    glPushMatrix();
    glColor3fv(cWhite);
    
    glBindTexture(GL_TEXTURE_2D, textures[13]);
    glBegin(GL_QUADS);
    // Face 1, bottom
    glTexCoord2f(0.0, 1.0);  glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glTexCoord2f(1.0, 1.0);  glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(1.0, 0.0);  glVertex3f(width / 2, -(height / 2), depth / 2);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textures[12]);
    glBegin(GL_QUADS);
    // Face 2, front
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), height / 2, depth / 2);
    glTexCoord2f(1, 1); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(1, 0); glVertex3f(width / 2, -(height / 2), depth / 2);

    // Face 3, right
    glTexCoord2f(0, 0); glVertex3f(width / 2, -(height / 2), depth / 2);
    glTexCoord2f(1, 0); glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(1, 1); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(0, 1); glVertex3f(width / 2, height / 2, depth / 2);

    // Face 4, top
    glTexCoord2f(0.7, 0.4); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(0.7, 0.7); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(0.4, 0.7); glVertex3f(-(width / 2), height / 2, -(depth / 2));
    glTexCoord2f(0.4, 0.5); glVertex3f(-(width / 2), height / 2, depth / 2);

    // Face 5, left
    glTexCoord2f(1, 1); glVertex3f(-(width / 2), height / 2, depth / 2);
    glTexCoord2f(1, 0); glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), height / 2, -(depth / 2));

    // Face 6, back
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
Sword sword;
Shield shield;

// Walking Animation
bool isWalking = false;
float wholeRobotTz = 0;
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
    
    if (!isOrtho && showSkybox) {
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

    projection();
    lighting();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(mTx, 0, mTz); // Translate for modelview
    glRotatef(mRx, 1, 0, 0);
        
    if (!isOrtho) {
        glRotatef(ry, 0, 1, 0); // Rotate the object if perspective
    }
    
    if (isOrtho) {
        glScalef(2, 2, 2);
    }
    
    // Clear texture
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    
    attackMode = headAttackMode && headAttackMode;
    
    glPushMatrix(); {
        glTranslatef(0, 0, wholeRobotTz);
        glRotatef(!moveToward ? 180 : 0, 0, 1, 0);
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
                            wholeRobotTz += 0.005;
                        } else {
                            wholeRobotTz -= 0.005;
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
                            wholeRobotTz += 0.005;
                        } else {
                            wholeRobotTz -= 0.005;
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
            glPushMatrix();
            glTranslatef(0, 6.5, 0);
            glScalef(0.35, 0.35, 0.35);
            head.drawHead();
            glPopMatrix();
            
            glPushMatrix();
            glTranslatef(0.9, -5, -0.3);
            glScalef(6, 6, 6);
            body.drawBody();
            glPopMatrix();
            
            hands.drawHands();
            
            glPushMatrix();
            glTranslatef(0, -4.3, 0);
            glScalef(0.70, 0.70, 0.70);
            legs.drawLegs();
            glPopMatrix();
        }
        glPopMatrix();
        
        
        sword.drawSword();
        
        glPushMatrix();
        glTranslatef(3.5, 1, 0.6);
        glRotatef(90, 1, 0, 0);
        glRotatef(-90, 0, 0, 1);
        glScalef(4, 4, 4);
//        shield.drawShield();
        glPopMatrix();
    }
    
    glPopMatrix();

    glutSwapBuffers();
}

bool legKeyMode = false;
bool handKeyMode = false;
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
    
    // Head (C/B/G/V)
    head.keyActions(key);
    
    if (key == '0') { // Reset
        pTx = 0;
        pTy = 0;
        ry = 0;
        mTx = 0;
        mTy = 0;
        mTz = isOrtho ? 0 : -13;
        mRx = 0;
        isWalking = false;
        stepsWalked = 0;
        legs.hipAngleLeft = 0;
        legs.hipAngleRight = 0;
        legs.kneeAngleLeft = 0;
        legs.kneeAngleRight = 0;
        moveToward = true;
    } else if (key == '1') { // Change ortho/perspective
        isOrtho = !isOrtho;
        if (isOrtho) {
            mTz = 0;
        } else {
            mTz = -13;
        }
    } else if (key == 'A' || key == 'a') {
        pTx -= ptSpeed;
    } else if (key == 'D' || key == 'd') {
        pTx += ptSpeed;
    } else if (key == 'W' || key == 'w') {
        pTy += ptSpeed;
    } else if (key == 'S' || key == 's') {
        pTy -= ptSpeed;
    } else if (key == 'L' || key == 'l') {
        ry += prSpeed;
    } else if (key == 'R' || key == 'r') {
        ry -= prSpeed;
    } else if (key == 'K' || key == 'k') {
        mRx += prSpeed;
    } else if (key == 'M' || key == 'm') {
        mRx -= prSpeed;
    }
    
    // Enter (Enable/disable texture)
    if (key == 13) {
        isTexture = !isTexture;
    } else if (key == '6') { // Change texture
        if (activeTexture >= 2) {
            activeTexture = 0;
        } else {
            activeTexture++;
        }
    } else if (key == 'H' || key == 'h') { // Show/hide skybox
        showSkybox = !showSkybox;
    }
    
    // Weapons
    if (key == '2') {
        headAttackMode = !headAttackMode;
    }
    // 3 (Show/Hide Sword), 4 (Sword Attack Mode)
    sword.keyActions(key);
    // Walking
    if (key == '5') {
        isWalking = !isWalking;
    }
}

void processSpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        if (isOrtho) {
            if (mTz > O_NEAR) {
                mTz -= mtSpeed;
            }
        } else {
            if (mTz > -P_FAR) {
                mTz -= mtSpeed;
            }
        }
    } else if (key == GLUT_KEY_DOWN) {
        if (isOrtho) {
            if (mTz < O_FAR) {
                mTz += mtSpeed;
            }
        } else {
            if (mTz < P_FAR) {
                mTz += mtSpeed;
            }
        }
    } else if (key == GLUT_KEY_LEFT) {
        mTx -= mtSpeed;
    } else if (key == GLUT_KEY_RIGHT) {
        mTx += mtSpeed;
    } else if (key == GLUT_KEY_F1) {
        defenseMode = !defenseMode;
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
 * getint and getshort are help functions to load bitmap byte by byte on
 * SPARC platform.
 * I've got them from xv bitmap load routine because the original bmp loader didn't work
 * I've tried to change as less code as possible.
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

//    // texture 1 (poor quality scaling)
//    glBindTexture(GL_TEXTURE_2D, textures[0]);  // 2d texture (x and y size)
//    // cheap scaling when image bigger than texture.
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    // cheap scaling when image samlled than texture
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    // 2d texture level of detail 0 (normal), 3 components (red, green, blue), x size from
//    // image, y size from image, border 0 (normal) rgb color data, unsigned byte data,
//    // and finally the data itself.
//    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
//        GL_BGR_EXT, GL_UNSIGNED_BYTE, image1->data);
//
//    // texture 2 (linear scaling)
//    glBindTexture(GL_TEXTURE_2D, textures[1]); // 2d texture (x and y size)
//    // scale linearly when image bigger than texture.
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // scale linearly when image smaller than texture.
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0,
//        GL_BGR_EXT, GL_UNSIGNED_BYTE, image2->data);
//
//    // texture 3 (mipmapped scaling)
//    glBindTexture(GL_TEXTURE_2D, textures[2]); // 2d textuer (x and y size)
//    // scale linearly when image bigger than texture.
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // scale linearly + mipmap when image smalled than texture.
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
//    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
//        GL_BGR_EXT, GL_UNSIGNED_BYTE, image1->data);
//
//    // 2d texture 3 colors, width, height, RGB in that order, byte data, and the data.
//    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->sizeX, image1->sizeY, GL_BGR_EXT,
//        GL_UNSIGNED_BYTE, image1->data);
}

/* A general OpenGL initialization function. Sets all of the initial parameters. */
GLvoid initGL(GLsizei width, GLsizei height) {
    loadGLTextures();
    glEnable(GL_TEXTURE_2D);

    glClearColor(63.0/255, 64.0/255, 239.0/255, 1); // This Will Clear the background Color to black.
    glClearDepth(1.0);    // Enables clearing of the depth buffer.
    glEnable(GL_DEPTH_TEST); // Enables depth testing.
    glShadeModel(GL_SMOOTH); // Enables smooth color shading.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
