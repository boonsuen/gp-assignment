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

/*
 * -----------------------------------------------
 * GLOBAL CONSTANT AND VARIABLES
 * -----------------------------------------------
 */
const int WINDOW_WIDTH = 300;
const int WINDOW_HEIGHT = 300;

// Texture
GLuint textures[3]; /* storage for 3 textures. */

/*
 * -----------------------------------------------
 * UTILITY AND DRAWING METHODS
 * -----------------------------------------------
 */
void drawCube(GLfloat size) {
    glBegin(GL_QUADS);
    // Face 1, bottom
//    glColor3f(1, 0, 0);
    glTexCoord2f(0.0, 1.0);  glVertex3f(0.0f, 0.0f, size);
    glTexCoord2f(1.0, 1.0);  glVertex3f(size, 0.0f, size);
    glTexCoord2f(1.0, 0.0);  glVertex3f(size, 0.0f, 0.0f);
    glTexCoord2f(0.0, 0.0);  glVertex3f(0.0f, 0.0f, 0.0f);

    // Face 2, back
//    glColor3f(1, 1, 0);
    glTexCoord2f(0, 1); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(0.0f, size, 0.0f);
    glTexCoord2f(1, 0); glVertex3f(size, size, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(size, 0.0f, 0.0f);

    // Face 3, right
//    glColor3f(1, 0, 1);
    glTexCoord2f(0, 1); glVertex3f(size, 0.0f, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(size, 0.0f, size);
    glTexCoord2f(1, 0); glVertex3f(size, size, size);
    glTexCoord2f(0, 0); glVertex3f(size, size, 0.0f);

    // Face 4, top
//    glColor3f(0, 0, 1);
    glTexCoord2f(0, 1); glVertex3f(size, size, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(size, size, size);
    glTexCoord2f(1, 0); glVertex3f(0.0f, size, size);
    glTexCoord2f(0, 0); glVertex3f(0.0f, size, 0.0f);

    // Face 5, left
//    glColor3f(0, 1, 0);
    glTexCoord2f(0, 1); glVertex3f(0.0f, size, 0.0f);
    glTexCoord2f(1, 1); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1, 0); glVertex3f(0.0f, 0.0f, size);
    glTexCoord2f(0, 0); glVertex3f(0.0f, size, size);

    // Face 6, front
//    glColor3f(0, 1, 1);
    glTexCoord2f(0, 1); glVertex3f(0.0f, size, size);
    glTexCoord2f(1, 1); glVertex3f(size, size, size);
    glTexCoord2f(1, 0); glVertex3f(size, 0.0f, size);
    glTexCoord2f(0, 0); glVertex3f(0.0f, 0.0f, size);
    glEnd();
}

void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum draw) {
    GLUquadricObj* sphere = NULL;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, draw);
    gluSphere(sphere, radius, slices, stacks);
    gluDeleteQuadric(sphere);
}

void projection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset projection matrix

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
    if (key == 'O' || key == 'o') {

    }
    else if (key == 'P' || key == 'p') {

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
    glClearDepth(1.0);        // Enables clearing of the depth buffer.
    glDepthFunc(GL_LESS); // The type of depth test to do.
    glEnable(GL_DEPTH_TEST); // Enables depth testing.
    glShadeModel(GL_SMOOTH); // Enables smooth color shading.

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // Reset the projection matrix.

    // Calculate the aspect ratio of the window.
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);

    // set up light number 1.
  //  glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient); // add lighting. (ambient)
  //  glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse); // add lighting. (diffuse)
  //  glLightfv(GL_LIGHT1, GL_POSITION, lightPosition); // set light position.
    glEnable(GL_LIGHT1);

    /* setup blending */
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);     // Set the blending function for translucency.
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot");

    /* Register the function to do all our OpenGL drawing. */
    glutDisplayFunc(display);
    /* Event if there are no events, redraw our gl scene. */
    glutIdleFunc(display);

    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    /* Initialize our window */
    initGL(WINDOW_WIDTH, WINDOW_HEIGHT);

    glutMainLoop();
    return 0;
}

// Tx, Ty
// Ry

// Includes headers
// Global constants and variables
// Utility and drawing methods
// projection();
// lighting();
// display();
// processNormalKeys();
// processSpecialKeys();
// Textures
// -- Image struct
// -- getint();
// -- getshort();
// -- imageLoad();
// -- loadTextures();
// initGL();
// main();
