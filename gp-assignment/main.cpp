#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
const char* ICE_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/ice.bmp";
const char* WHITE_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/white.bmp";
const char* BLACK_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-assignment/gp-assignment/black.bmp";
#else
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
const char* ICE_TEXTURE_PATH = "ice.bmp";
const char* WHITE_TEXTURE_PATH = "white.bmp";
const char* BLACK_TEXTURE_PATH = "black.bmp";
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
const float O_NEAR = -10, O_FAR = 10; // Ortho near far
const float P_NEAR = 0.1, P_FAR = 40; // Perspective near far
float pTx = 0, pTy = 0, ptSpeed = 0.1; // Translate for projection
float prSpeed = 2.0; // Rotate Y for projection

float ry = 90; // Rotate Y for Ortho (NO ROTATE Y FOR PERSPECTIVE!!!) and Model View

float mTx = 0, mTy = 0, mTz = 0, mtSpeed = 2; // Translate for modelview
float mRx = 0;

// Texture
bool isTexture = false;
const int TEXTURES_NO = 3;
GLuint textures[TEXTURES_NO]; /* storage for 2 textures. */
const char* filenames[TEXTURES_NO] = {
    ICE_TEXTURE_PATH,
    WHITE_TEXTURE_PATH,
    BLACK_TEXTURE_PATH
};
int activeTexture = 0;

// Status
bool defenseMode = true;

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
        glOrtho(-10, 10, -10, 10, O_NEAR, O_FAR);
        glRotatef(ry, 0, 1, 0); // Rotate Y for ortho only!!!
    } else {
        gluPerspective(70, 1, P_NEAR, P_FAR);
    }
}

void lighting() {
   
}

Head head;
Body body;
Hands hands;
Legs legs;
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
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
        glRotatef(-ry, 0, 1, 0); // Rotate the object if perspective
    }
    
    // Clear texture
    glBindTexture(GL_TEXTURE_2D, textures[activeTexture]);
    
    glPushMatrix(); {
        glPushMatrix();
        glTranslatef(0, 8, 0); // 7
        glScalef(0.4, 0.4, 0.4);
        head.drawHead();
        glPopMatrix();
        body.drawBody();
        hands.drawHands();
        legs.drawLegs();
        glPopMatrix();
    }

    glutSwapBuffers();
}

bool legKeysMode = false;
bool handKeysMode = false;
void processNormalKeys(unsigned char key, int x, int y) {
    // Legs
    if (key == '7') {
        legKeysMode = !legKeysMode;
    }
    if (legKeysMode) {
        if (key == 'Q' || key == 'q') {
            std::cout << "Rotate left leg hip front" << std::endl;
        }
        if (key == 'A' || key == 'a') {
            std::cout << "Rotate left leg hip back" << std::endl;
        }
        if (key == 'W' || key == 'w') {
            std::cout << "Rotate left leg knee front" << std::endl;
        }
        if (key == 'S' || key == 's') {
            std::cout << "Rotate left leg knee back" << std::endl;
        }
        return;
    }
    
    // Hands
    if (key == '6') {
        handKeysMode = !handKeysMode;
    }
    if (handKeysMode) {
        if (key == 'Q' || key == 'q') {
            std::cout << "Hand stuff" << std::endl;
        }
        return;
    }
    
    if (key == '0') { // Reset
        pTx = 0;
        pTy = 0;
        ry = 0;
        mTx = 0;
        mTy = 0;
        mTz = isOrtho ? 0 : -15;
        mRx = 0;
    } else if (key == '1') { // Change ortho/perspective
        isOrtho = !isOrtho;
        if (isOrtho) {
            mTz = 0;
        } else {
            mTz = -15;
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
        if (activeTexture >= TEXTURES_NO - 1) {
            activeTexture = 0;
        } else {
            activeTexture++;
        }
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
