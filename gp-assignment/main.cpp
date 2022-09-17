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
// 6. Drawing classes
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
void drawCircle(GLfloat color[],
                float radiusX, float radiusY,
                float startingAngle, GLboolean isAntiClockWise, GLboolean isHalfCircle,
                float tx, float ty, float tz);
void drawCube(float width, float height, float depth, float color[], float tx, float ty, float tz);
void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum draw);
void drawCylinder(GLfloat color[],
                  GLdouble baseRadius, GLdouble topRadius, GLdouble height,
                  GLint slices, GLint stacks, GLenum draw,
                  float tx, float ty, float tz);
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

bool isOrtho = true; // Is ortho view
const float O_NEAR = -10, O_FAR = 10; // Ortho near far
const float P_NEAR = 0.1, P_FAR = 30; // Perspective near far
float pTx = 0, pTy = 0, ptSpeed = 0.1; // Translate for projection
float prSpeed = 2.0; // Rotate Y for projection

float ry = 90; // Rotate Y for Ortho (NO ROTATE Y FOR PERSPECTIVE!!!) and Model View

float mTx = 0, mTy = 0, mTz = 0, mtSpeed = 2; // Translate for modelview
float mRx = 0;

// Texture
GLuint textures[3]; /* storage for 3 textures. */

/*
 * -----------------------------------------------
 * UTILITY METHODS
 * -----------------------------------------------
 */
void drawRect(float width, float height, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex3f(-(width/2), height/2, 0);
    glTexCoord2f(1, 1); glVertex3f(width/2, height / 2, 0);
    glTexCoord2f(1, 0); glVertex3f(width/2, -(height/2), 0);
    glTexCoord2f(0, 0); glVertex3f(-(width/2), -(height/2), 0);
    glEnd();
    glPopMatrix();
}

void drawCircle(GLfloat color[],
                            float radiusX,
                            float radiusY,
                            float startingAngle,
                            GLboolean isAntiClockWise,
                            GLboolean isHalfCircle,
                            float tx,
                            float ty,
                            float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    glBegin(GL_TRIANGLE_FAN);
       if (isAntiClockWise) {
           for (float angle = startingAngle * PI / 180; angle <= (isHalfCircle ? (PI + startingAngle * PI / 180) : 2 * PI); angle += 2 * PI / 360) {
               float x = radiusX * cos(angle);
               float y = radiusY * sin(angle);
               glVertex2f(x, y);
           }
       } else {
           for (float angle = startingAngle * PI / 180; angle >= (isHalfCircle ? -PI : -2 * PI); angle -= 2 * PI / 360) {
               float x = radiusX * cos(angle);
               float y = radiusY * sin(angle);
               glVertex2f(x, y);
           }
       }
    glEnd();
    glPopMatrix();
}

void drawRightTriangle(float width, float height, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    
    glBegin(GL_TRIANGLES);
    glTexCoord2f(1, 1); glVertex3f(-(width/2), -(height/2), 0);
    glTexCoord2f(1, 0); glVertex3f(width/2, -(height/2), 0);
    glTexCoord2f(0, 0); glVertex3f(-(width/2), height/2, 0);
    glEnd();
    
    glPopMatrix();
}

void drawCube(float width, float height, float depth, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    
    glBegin(GL_QUADS);
    glColor3fv(color);
    // Face 1, bottom
    glTexCoord2f(0.0, 1.0);  glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glTexCoord2f(1.0, 1.0);  glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(1.0, 0.0);  glVertex3f(width / 2, -(height / 2), depth / 2);
    glTexCoord2f(0.0, 0.0);  glVertex3f(-(width / 2), -(height / 2), depth / 2);

    // Face 2, front
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glTexCoord2f(1, 1); glVertex3f(-(width / 2), height / 2, depth / 2);
    glTexCoord2f(1, 0); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(0, 0); glVertex3f(width / 2, -(height / 2), depth / 2);

    // Face 3, right
    glTexCoord2f(0, 1); glVertex3f(width / 2, -(height / 2), depth / 2);
    glTexCoord2f(1, 1); glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(1, 0); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(0, 0); glVertex3f(width / 2, height / 2, depth / 2);

    // Face 4, top
    glTexCoord2f(0, 1); glVertex3f(width / 2, height / 2, depth / 2);
    glTexCoord2f(1, 1); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(1, 0); glVertex3f(-(width / 2), height / 2, -(depth / 2));
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), height / 2, depth / 2);

    // Face 5, left
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), height / 2, depth / 2);
    glTexCoord2f(1, 1); glVertex3f(-(width / 2), -(height / 2), depth / 2);
    glTexCoord2f(1, 0); glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), height / 2, -(depth / 2));

    // Face 6, back
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), height / 2, -(depth / 2));
    glTexCoord2f(1, 1); glVertex3f(width / 2, height / 2, -(depth / 2));
    glTexCoord2f(1, 0); glVertex3f(width / 2, -(height / 2), -(depth / 2));
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), -(height / 2), -(depth / 2));
    glEnd();
    
    glPopMatrix();
}

void drawSixFacesPolygon(float v1[], float v2[], float v3[], float v4[],
                   float v5[], float v6[], float v7[], float v8[], float color[]) {
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3fv(color);
    // Face 1, bottom
    glTexCoord2f(0.0, 1.0);  glVertex3f(v5[0], v5[1], v5[2]);
    glTexCoord2f(1.0, 1.0);  glVertex3f(v6[0], v6[1], v6[2]);
    glTexCoord2f(1.0, 0.0);  glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(0.0, 0.0);  glVertex3f(v1[0], v1[1], v1[2]);

    // Face 2, front
    glTexCoord2f(0, 1); glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1, 1); glVertex3f(v4[0], v4[1], v4[2]);
    glTexCoord2f(1, 0); glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(0, 0); glVertex3f(v2[0], v2[1], v2[2]);

    // Face 3, right
    glTexCoord2f(0, 1); glVertex3f(v2[0], v2[1], v2[2]);
    glTexCoord2f(1, 1); glVertex3f(v6[0], v6[1], v6[2]);
    glTexCoord2f(1, 0); glVertex3f(v7[0], v7[1], v7[2]);
    glTexCoord2f(0, 0); glVertex3f(v3[0], v3[1], v3[2]);

    // Face 4, top
    glTexCoord2f(0, 1); glVertex3f(v3[0], v3[1], v3[2]);
    glTexCoord2f(1, 1); glVertex3f(v7[0], v7[1], v7[2]);
    glTexCoord2f(1, 0); glVertex3f(v8[0], v8[1], v8[2]);
    glTexCoord2f(0, 0); glVertex3f(v4[0], v4[1], v4[2]);

    // Face 5, left
    glTexCoord2f(0, 1); glVertex3f(v4[0], v4[1], v4[2]);
    glTexCoord2f(1, 1); glVertex3f(v1[0], v1[1], v1[2]);
    glTexCoord2f(1, 0); glVertex3f(v5[0], v5[1], v5[2]);
    glTexCoord2f(0, 0); glVertex3f(v8[0], v8[1], v8[2]);

    // Face 6, back
    glTexCoord2f(0, 1); glVertex3f(v8[0], v8[1], v8[2]);
    glTexCoord2f(1, 1); glVertex3f(v7[0], v7[1], v7[2]);
    glTexCoord2f(1, 0); glVertex3f(v6[0], v6[1], v6[2]);
    glTexCoord2f(0, 0); glVertex3f(v5[0], v5[1], v5[2]);
    glEnd();

    glPopMatrix();
}

void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum draw, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    
    GLUquadricObj* sphere = NULL;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, draw);
    gluSphere(sphere, radius, slices, stacks);
    gluDeleteQuadric(sphere);
    glPopMatrix();
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

void drawHemisphere(double r, int lats, int longs, GLfloat color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    int halfLats = lats / 2;
    for (int i = 0; i <= halfLats; i++) {
        double lat0 = PI * (-0.5 + (double) (i - 1) / lats);
        double z0 = r * sin(lat0);
        double zr0 = cos(lat0);

        double lat1 = PI * (-0.5 + (double) i / lats);
        double z1 = r * sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= longs; j++) {
            double lng = 2 * PI * (double) (j - 1) / longs;
            double x = r * cos(lng);
            double y = r * sin(lng);

            double s1, s2, t;
            s1 = ((double) i) / halfLats;
            s2 = ((double) i + 1) / halfLats;
            t = ((double) j) / longs;

            glTexCoord2d(s1, t);
            glNormal3d(x * zr0, y * zr0, z0);
            glVertex3d(x * zr0, y * zr0, z0);

            glTexCoord2d(s2, t);
            glNormal3d(x * zr1, y * zr1, z1);
            glVertex3d(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
    glPopMatrix();
}

// Colors
GLfloat cWhite[] = { 1, 1, 1 };
GLfloat cBlack[] = { 0.2, 0.2, 0.2 };
GLfloat cGrey[] = { 71.0/255, 68.0/255, 68.0/255 };
GLfloat cLightGrey[] = { 224.0/255, 227.0/255, 229.0/255 };
GLfloat cLightGrey2[] = { 190.0/255, 203.0/255, 215.0/255 };
GLfloat cHeadRed[] = { 1, 63.0/255, 57.0/255 };
GLfloat cEyeYellow[] = { 249.0/255, 1, 102.0/255 };
GLfloat cEarGrey[] = { 132.0/255, 134.0/255, 137.0/255 };
GLfloat cAntennaYellow[] = { 254.0/255, 223.0/255, 0 };

/*
 * -----------------------------------------------
 * DRAWING CLASSES
 * -----------------------------------------------
 */
class Head {
public:
    static void drawEye(bool isRed, bool isLeft) {
        glPushMatrix();
        glColor3fv(isRed ? cHeadRed : cEyeYellow);
        if (isRed) {
            glScalef(1.15, 1.15, 1);
            glTranslatef(isLeft ? 0.15 : -0.15, 0, 0);
        }
        glBegin(GL_POLYGON);
        glVertex3f(isLeft ? -2    : 2   , -0.1, isRed ? 2.005 : 2.01);
        glVertex3f(isLeft ? -2    : 2   , -0.2, isRed ? 2.005 : 2.01);
        glVertex3f(isLeft ? -1.4  : 1.4 , -0.5, isRed ? 2.005 : 2.01);
        glVertex3f(isLeft ? -0.15 : 0.15, -0.3, isRed ? 2.005 : 2.01);
        glVertex3f(isLeft ? -0.15 : 0.15, -0.2, isRed ? 2.005 : 2.01);
        glEnd();
        glPopMatrix();
    }
    static void drawFace() {
        drawEye(true, true);
        drawEye(true, false);
        drawEye(false, true);
        drawEye(false, false);
        
        glColor3fv(cWhite);
        glBegin(GL_POLYGON);
        glVertex3f(-2.1, -0.34, 2.01);
        glColor3fv(cLightGrey2);
        glVertex3f(-2.1, -2.2, 2.01);
        glColor3fv(cWhite);
        glVertex3f(0, -2.7, 2.31);
        glVertex3f(-1.4, -0.65, 2.31);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0, -2.7, 2.31);
        glVertex3f(0, -0.45, 2.31);
        glVertex3f(-1.4, -0.65, 2.31);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex3f(2.1, -0.34, 2.01);
        glColor3fv(cLightGrey2);
        glVertex3f(2.1, -2.2, 2.01);
        glColor3fv(cWhite);
        glVertex3f(0, -2.7, 2.31);
        glVertex3f(1.4, -0.65, 2.31);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0, -2.7, 2.31);
        glVertex3f(0, -0.45, 2.31);
        glVertex3f(1.4, -0.65, 2.31);
        glEnd();
        
        // Nose
        glColor3fv(cGrey);
        glBegin(GL_QUADS);
        glVertex3f(-0.6, -0.9, 2.315); glVertex3f(-0.6, -1.1, 2.315);
        glVertex3f(0, -0.95, 2.315); glVertex3f(0, -0.75, 2.315);
        glVertex3f(-0.6, -1.2, 2.315); glVertex3f(-0.6, -1.4, 2.315);
        glVertex3f(0, -1.25, 2.315); glVertex3f(0, -1.05, 2.315);
        glVertex3f(0.6, -0.9, 2.315); glVertex3f(0.6, -1.1, 2.315);
        glVertex3f(0, -0.95, 2.315); glVertex3f(0, -0.75, 2.315);
        glVertex3f(0.6, -1.2, 2.315); glVertex3f(0.6, -1.4, 2.315);
        glVertex3f(0, -1.25, 2.315); glVertex3f(0, -1.05, 2.315);
        glEnd();
        
        GLfloat lMouthV1[] = { -0.5, -2.65, 2.6 }; GLfloat lMouthV5[] = { -0.5, -2.65, 1.8 };
        GLfloat lMouthV2[] = { 0, -3, 2.8 };       GLfloat lMouthV6[] = { 0, -2.7, 1.8 };
        GLfloat lMouthV3[] = { 0, -2, 2.8 };       GLfloat lMouthV7[] = { 0, -2, 1.8 };
        GLfloat lMouthV4[] = { -0.5, -2.2, 2.6 };  GLfloat lMouthV8[] = { -0.5, -2.2, 1.8 };
        drawSixFacesPolygon(lMouthV1, lMouthV2, lMouthV3, lMouthV4,
                            lMouthV5, lMouthV6, lMouthV7, lMouthV8, cHeadRed);
        GLfloat rMouthV1[] = { 0, -3, 2.8 };      GLfloat rMouthV5[] = { 0, -2.7, 1.8 };
        GLfloat rMouthV2[] = { 0.5, -2.65, 2.6 }; GLfloat rMouthV6[] = { 0.5, -2.65, 1.8 };
        GLfloat rMouthV3[] = { 0.5, -2.2, 2.6 };  GLfloat rMouthV7[] = { 0.5, -2.2, 1.8 };
        GLfloat rMouthV4[] = { 0, -2, 2.8 };      GLfloat rMouthV8[] = { 0, -2, 1.8 };
        drawSixFacesPolygon(rMouthV1, rMouthV2, rMouthV3, rMouthV4,
                            rMouthV5, rMouthV6, rMouthV7, rMouthV8, cHeadRed);
    }
    
    static void drawToppings() {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        drawHemisphere(3.0, 30, 30, cLightGrey, 0, 0, 0);
        glPopMatrix();
        
        glPushMatrix(); {
            glTranslatef(0, 1.4, 2.13);
            glRotatef(35, 1, 0, 0);
            drawCube(1, 2, 3, cHeadRed, 0, 0, 0);
            glPopMatrix();
        }
        
        GLfloat yellowAntennaV1[] = { 1, 0.8, 3.1 }; GLfloat yellowAntennaV5[] = { 1, 0.7, 3.0 };
        GLfloat yellowAntennaV2[] = { 2.5, 5.2, 2.5 }; GLfloat yellowAntennaV6[] = { 2.4, 5.2, 2.4 };
        GLfloat yellowAntennaV3[] = { 2.5, 5.4, 2.5 }; GLfloat yellowAntennaV7[] = { 2.4, 5.4, 2.4 };
        GLfloat yellowAntennaV4[] = { 1, 0.8, 3.2 }; GLfloat yellowAntennaV8[] = { 1, 1.3, 3.1 };
        drawSixFacesPolygon(yellowAntennaV1, yellowAntennaV2, yellowAntennaV3, yellowAntennaV4,
                            yellowAntennaV5, yellowAntennaV6, yellowAntennaV7, yellowAntennaV8, cAntennaYellow);
        yellowAntennaV1[0] = -1.0; yellowAntennaV5[0] = -1.0;
        yellowAntennaV2[0] = -2.5; yellowAntennaV6[0] = -2.4;
        yellowAntennaV3[0] = -2.5; yellowAntennaV7[0] = -2.4;
        yellowAntennaV4[0] = -1.0; yellowAntennaV8[0] = -1.0;
        drawSixFacesPolygon(yellowAntennaV1, yellowAntennaV2, yellowAntennaV3, yellowAntennaV4,
                            yellowAntennaV5, yellowAntennaV6, yellowAntennaV7, yellowAntennaV8, cAntennaYellow);
        
        GLfloat whiteAntennaV1[] = { 0, 0.5, 3.3 }; GLfloat whiteAntennaV5[] = { 0, 0.4, 3.2 };
        GLfloat whiteAntennaV2[] = { 6, 2.2, 2.7 }; GLfloat whiteAntennaV6[] = { 5.9, 2.2, 2.6 };
        GLfloat whiteAntennaV3[] = { 6, 2.4, 2.7 }; GLfloat whiteAntennaV7[] = { 5.9, 2.4, 2.6 };
        GLfloat whiteAntennaV4[] = { 0, 0.8, 3.4 }; GLfloat whiteAntennaV8[] = { 0, 1.2, 3.3 };
        drawSixFacesPolygon(whiteAntennaV1, whiteAntennaV2, whiteAntennaV3, whiteAntennaV4,
                            whiteAntennaV5, whiteAntennaV6, whiteAntennaV7, whiteAntennaV8, cWhite);
        whiteAntennaV2[0] = -6; whiteAntennaV6[0] = -5.9;
        whiteAntennaV3[0] = -6; whiteAntennaV7[0] = -5.9;
        drawSixFacesPolygon(whiteAntennaV1, whiteAntennaV2, whiteAntennaV3, whiteAntennaV4,
                            whiteAntennaV5, whiteAntennaV6, whiteAntennaV7, whiteAntennaV8, cWhite);
        
        // Ears
        glPushMatrix(); {
            glScalef(1, 1, 4.5);
            drawHemisphere(0.4, 20, 20, cEarGrey, 2.6, 2, 0.2);
            drawCircle(cGrey, 0.4, 0.4, 0, true, false, 2.6, 2, 0.2);
            drawCircle(cBlack, 0.3, 0.3, 0, true, false, 2.6, 2, 0.201);
            
            drawHemisphere(0.4, 20, 20, cEarGrey, -2.6, 2, 0.2);
            drawCircle(cGrey, 0.4, 0.4, 0, true, false, -2.6, 2, 0.2);
            drawCircle(cBlack, 0.3, 0.3, 0, true, false, -2.6, 2, 0.201);
        }
        glPopMatrix();
    }
    
    static void drawCheek() {
        drawCube(4.5, 2.5, 0.5, cWhite, 0, -2.5/2, -2 - 0.5/2);
        
        GLfloat whiteSideV1[] = { 2.25, -2.5, 2.5 }; GLfloat whiteSideV5[] = { 2.25, -2.5, -2.5 };
        GLfloat whiteSideV2[] = { 2.75, -2.0, 2.5 }; GLfloat whiteSideV6[] = { 2.75, -2.0, -2.5 };
        GLfloat whiteSideV3[] = { 2.75, 0, 2.5 }; GLfloat whiteSideV7[] = { 2.75, 0, -2.5 };
        GLfloat whiteSideV4[] = { 2.25, 0, 2.5 }; GLfloat whiteSideV8[] = { 2.25, 0, -2.5 };
        drawSixFacesPolygon(whiteSideV1, whiteSideV2, whiteSideV3, whiteSideV4,
                            whiteSideV5, whiteSideV6, whiteSideV7, whiteSideV8, cWhite);
        whiteSideV1[0] = -2.25; whiteSideV5[0] = -2.25;
        whiteSideV2[0] = -2.75; whiteSideV6[0] = -2.75;
        whiteSideV3[0] = -2.75; whiteSideV7[0] = -2.75;
        whiteSideV4[0] = -2.25; whiteSideV8[0] = -2.25;
        drawSixFacesPolygon(whiteSideV1, whiteSideV2, whiteSideV3, whiteSideV4,
                            whiteSideV5, whiteSideV6, whiteSideV7, whiteSideV8, cWhite);
        
        glPushMatrix();
        glRotatef(180, 0, 0, 1);
        drawRightTriangle(0.3, 0.3, cGrey, 2.5, 2.08, 2.501);
        glRotatef(180, 0, 1, 0);
        drawRightTriangle(0.3, 0.3, cGrey, 2.5, 2.08, -2.501);
        glPopMatrix();
        drawRect(0.3, 0.7, cGrey, 2.5, -0.7, 2.501);
        drawRect(0.3, 0.6, cGrey, 2.5, -1.63, 2.501);
        drawRect(0.3, 0.7, cGrey, -2.5, -0.7, 2.501);
        drawRect(0.3, 0.6, cGrey, -2.5, -1.63, 2.501);
    }
    
    static void drawHead() {
        drawToppings();
        drawCheek();
        
        glPushMatrix();
        drawCube(4.5, 2.5, 4, cBlack, 0, -2.5/2, 0);
        drawFace();
        glPopMatrix();

        drawSphere(1.4, 30, 30, GLU_FILL, cGrey, 0, -2.4, 0);
    }
};

class Body {
public:
    static void drawBody() {
        
    }
};

class Hands {
public:
    static void drawHands() {
        
    }
};

class Legs {
public:
    static void drawLegs() {
        
    }
};

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
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glPushMatrix(); {
        Head::drawHead();
        Body::drawBody();
        Hands::drawHands();
        Legs::drawLegs();
        glPopMatrix();
    }

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
    
    // Reset
    if (key == 32) {
        pTx = 0;
        pTy = 0;
        ry = 0;
        mTx = 0;
        mTy = 0;
        mTz = isOrtho ? 0 : -15;
        mRx = 0;
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
    }
    else if (key == GLUT_KEY_DOWN) {
        if (isOrtho) {
            if (mTz < O_FAR) {
                mTz += mtSpeed;
            }
        } else {
            if (mTz < P_FAR) {
                mTz += mtSpeed;
            }
        }
    }
    else if (key == GLUT_KEY_LEFT) {
        mTx -= mtSpeed;
    }
    else if (key == GLUT_KEY_RIGHT) {
        mTx += mtSpeed;
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

    glClearColor(63.0/255, 64.0/255, 239.0/255, 1); // This Will Clear the background Color to black.
    glClearDepth(1.0);    // Enables clearing of the depth buffer.
    glEnable(GL_DEPTH_TEST); // Enables depth testing.
    glShadeModel(GL_SMOOTH); // Enables smooth color shading.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_MULTISAMPLE);
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
