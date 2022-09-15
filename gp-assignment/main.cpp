#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
const char* ICE_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-prac/Prac7/Prac7/ice.bmp";
const char* BOX_TEXTURE_PATH = "/Users/boonsuenoh/Documents/Dev/gp-prac/Prac7/Prac7/box.bmp";
#else
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
const char* ICE_TEXTURE_PATH = "ice.bmp";
const char* BOX_TEXTURE_PATH = "box.bmp";
#endif
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// 1. Includes
// 2. Function headers
// 2. Global constants and variables
// 3. Utility methods
// 4. projection();
// 5. lighting();
// 6. Drawing methods
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
void drawCube(float width, float height, float depth, float color[], float tx, float ty, float tz);
void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum draw);
void drawCylinder(GLfloat color[],
                  GLdouble baseRadius,
                  GLdouble topRadius,
                  GLdouble height,
                  GLint slices,
                  GLint stacks,
                  GLenum draw,
                  float tx,
                  float ty,
                  float tz);
void drawHead();
void drawBody();
void drawHands();
void drawLegs();
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

bool isOrtho = true; // Is ortho view
const float O_NEAR = -10, O_FAR = 10; // Ortho near far
const float P_NEAR = 0.1, P_FAR = 30; // Perspective near far
float pTx = 0, pTy = 0, ptSpeed = 0.1; // Translate for projection
float prSpeed = 2.0; // Rotate Y for projection

float ry = 0; // Rotate Y for Ortho (NO ROTATE Y FOR PERSPECTIVE!) and Model View

float mTx = 0, mTy = 0, mTz = 0, mtSpeed = 2; // Translate for modelview
float mRx = 0;

// Texture
GLuint textures[3]; /* storage for 3 textures. */

/*
 * -----------------------------------------------
 * UTILITY METHODS
 * -----------------------------------------------
 */
void drawCube(float width, float height, float depth, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    
    glBegin(GL_QUADS);
    glColor3fv(color);
    // Face 1, bottom
    glTexCoord2f(0.0, 1.0);  glVertex3f(0.0f, 0.0f, -depth);
    glTexCoord2f(1.0, 1.0);  glVertex3f(width, 0.0f, -depth);
    glTexCoord2f(1.0, 0.0);  glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(0.0, 0.0);  glVertex3f(0.0f, 0.0f, 0.0f);

    // Face 2, front
    glTexCoord2f(0, 1); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(1, 0); glVertex3f(width, height, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(width, 0.0f, 0.0f);

    // Face 3, right
    glTexCoord2f(0, 1); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(width, 0.0f, -depth);
    glTexCoord2f(1, 0); glVertex3f(width, height, -depth);
    glTexCoord2f(0, 0); glVertex3f(width, height, 0.0f);

    // Face 4, top
    glTexCoord2f(0, 1); glVertex3f(width, height, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(width, height, -depth);
    glTexCoord2f(1, 0); glVertex3f(0.0f, height, -depth);
    glTexCoord2f(0, 0); glVertex3f(0.0f, height, 0.0f);

    // Face 5, left
    glTexCoord2f(0, 1); glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1, 0); glVertex3f(0.0f, 0.0f, -depth);
    glTexCoord2f(0, 0); glVertex3f(0.0f, height, -depth);

    // Face 6, back
    glTexCoord2f(0, 1); glVertex3f(0.0f, height, -depth);
    glTexCoord2f(1, 1); glVertex3f(width, height, -depth);
    glTexCoord2f(1, 0); glVertex3f(width, 0.0f, -depth);
    glTexCoord2f(0, 0); glVertex3f(0.0f, 0.0f, -depth);
    glEnd();
    
    glPopMatrix();
}

void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum draw) {
    GLUquadricObj* sphere = NULL;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, draw);
    gluSphere(sphere, radius, slices, stacks);
    gluDeleteQuadric(sphere);
}

void drawCylinder(
                  GLfloat color[],
                  GLdouble baseRadius,
                  GLdouble topRadius,
                  GLdouble height,
                  GLint slices,
                  GLint stacks,
                  GLenum draw,
                  float tx,
                  float ty,
                  float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -height);
    glColor3fv(color);
    GLUquadricObj *cylinder = NULL;
    cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, draw);
    gluCylinder(cylinder, baseRadius, topRadius, height, slices, stacks);
    gluDeleteQuadric(cylinder);
    glPopMatrix();
}

// Colors
GLfloat cWhite[] = { 1, 1, 1 };

/*
 * -----------------------------------------------
 * DRAWING METHODS
 * -----------------------------------------------
 */
void drawHead() {
    
}

void drawBody() {
    
}

void drawHands() {
    
}

void drawLegs() {
    
}

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    projection();

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    drawCube(0.5);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    drawCube(-0.5);
    glPopMatrix();

    glutPostRedisplay();
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
    if (key == '1') {
        isOrtho = !isOrtho;
        if (isOrtho) {
            mTz = 0;
        } else {
            mTz = -15;
        }
    }

    glutPostRedisplay();
}

void processSpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {

    }
    else if (key == GLUT_KEY_DOWN) {

    }
    else if (key == GLUT_KEY_LEFT) {

    }
    else if (key == GLUT_KEY_RIGHT) {

    }

    glutPostRedisplay();
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

    return 1; // we're done.
}

// Load Bitmaps and convert to texture
GLvoid loadGLTextures(GLvoid) {
    Image* image1; // Load Texture
    Image* image2; // Load Texture

    // allocate space for texture.
    image1 = (Image*)malloc(sizeof(Image));
    if (image1 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if (!imageLoad(ICE_TEXTURE_PATH, image1)) {
        exit(1);
    }

    image2 = (Image*)malloc(sizeof(Image));
    if (image2 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    if (!imageLoad(BOX_TEXTURE_PATH, image2)) {
        exit(1);
    }

    // Create Textures
    glGenTextures(3, &textures[0]);

    // texture 1 (poor quality scaling)
    glBindTexture(GL_TEXTURE_2D, textures[0]);  // 2d texture (x and y size)
    // cheap scaling when image bigger than texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // cheap scaling when image samlled than texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // 2d texture level of detail 0 (normal), 3 components (red, green, blue), x size from
    // image, y size from image, border 0 (normal) rgb color data, unsigned byte data,
    // and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, image1->data);

    // texture 2 (linear scaling)
    glBindTexture(GL_TEXTURE_2D, textures[1]); // 2d texture (x and y size)
    // scale linearly when image bigger than texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // scale linearly when image smaller than texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, image2->data);

    // texture 3 (mipmapped scaling)
    glBindTexture(GL_TEXTURE_2D, textures[2]); // 2d textuer (x and y size)
    // scale linearly when image bigger than texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // scale linearly + mipmap when image smalled than texture.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, image1->data);

    // 2d texture 3 colors, width, height, RGB in that order, byte data, and the data.
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->sizeX, image1->sizeY, GL_BGR_EXT,
        GL_UNSIGNED_BYTE, image1->data);
}

/* A general OpenGL initialization function. Sets all of the initial parameters. */
GLvoid initGL(GLsizei width, GLsizei height) {
    loadGLTextures();
    glEnable(GL_TEXTURE_2D);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // This Will Clear the background Color to black.
    glClearDepth(1.0);    // Enables clearing of the depth buffer.
    glEnable(GL_DEPTH_TEST); // Enables depth testing.
    glShadeModel(GL_SMOOTH); // Enables smooth color shading.

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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
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
