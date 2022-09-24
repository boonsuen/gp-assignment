#pragma once

#ifndef Utility_h
#define Utility_h
#endif /* Utility_hpp */

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

using namespace std;

class Utility {
public:
    void drawRect(float width, float height, float color[], float tx, float ty, float tz);
    void drawCircle(GLfloat color[],
        float radiusX,
        float radiusY,
        float startingAngle,
        GLboolean isAntiClockWise,
        GLboolean isHalfCircle,
        GLboolean isLine,
        float tx,
        float ty,
        float tz);
    void drawLineCircle(GLfloat color[],
        float radiusX,
        float radiusY,
        float startingAngle,
        GLboolean isAntiClockWise,
        GLboolean isHalfCircle,
        float tx,
        float ty,
        float tz);
    void drawRightTriangle(float width,
        float height,
        float color[],
        float tx,
        float ty,
        float tz);
    void drawCube(float width,
        float height,
        float depth,
        float color[],
        float tx,
        float ty,
        float tz);
    void drawSixFacesPolygon(float v1[], float v2[], float v3[], float v4[],
        float v5[], float v6[], float v7[], float v8[], float color[]);
    void drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum draw, float color[], float tx, float ty, float tz);
    void drawCylinder(GLfloat color[],
        GLdouble baseRadius,
        GLdouble topRadius,
        GLdouble height,
        GLint slices,
        GLint stacks,
        GLenum draw,
        bool closed,
        float tx,
        float ty,
        float tz);
    void drawHemisphere(double r, int lats, int longs, GLfloat color[], float tx, float ty, float tz);
    void drawDisk(GLfloat color[],
        GLdouble inner,
        GLdouble outer,
        GLint slices,
        GLint loops,
        GLenum draw,
        float tx,
        float ty,
        float tz,
        bool isHorizontal);
    //TCM START
    void drawSphere(float r);
    void drawShape(float downMinX, float downMaxX, float upMinX, float upMaxX, float downMinY, float downMaxY, float upMinY, float upMaxY, float downMinZ, float downMaxZ, float upMinZ, float upMaxZ);
    void drawCylinder(double tr, double br, double h);
    void drawInnerBody(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
    void drawRectangle(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
    void starVertical(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
    void starHorizontal(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
    void shieldPentagon(float minZ, float maxZ);
    //TCM END
};

void Utility::drawRect(float width, float height, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    glBegin(GL_QUADS);
    glNormal3f(-(width / 2), height / 2, 0);
    glTexCoord2f(0, 1); glVertex3f(-(width / 2), height / 2, 0);
    glNormal3f(width / 2, height / 2, 0);
    glTexCoord2f(1, 1); glVertex3f(width / 2, height / 2, 0);
    glNormal3f(width / 2, -(height / 2), 0);
    glTexCoord2f(1, 0); glVertex3f(width / 2, -(height / 2), 0);
    glNormal3f(-(width / 2), -(height / 2), 0);
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), -(height / 2), 0);
    glEnd();
    glPopMatrix();
}

void Utility::drawCircle(GLfloat color[],
    float radiusX,
    float radiusY,
    float startingAngle,
    GLboolean isAntiClockWise,
    GLboolean isHalfCircle,
    GLboolean isLine,
    float tx,
    float ty,
    float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    glBegin(isLine ? GL_LINE_STRIP : GL_TRIANGLE_FAN);
    if (isAntiClockWise) {
        for (float angle = startingAngle * PI / 180; angle <= (isHalfCircle ? (PI + startingAngle * PI / 180) : 2 * PI); angle += 2 * PI / 360) {
            float x = radiusX * cos(angle);
            float y = radiusY * sin(angle);
            glVertex2f(x, y);
        }
    }
    else {
        for (float angle = startingAngle * PI / 180; angle >= (isHalfCircle ? -PI : -2 * PI); angle -= 2 * PI / 360) {
            float x = radiusX * cos(angle);
            float y = radiusY * sin(angle);
            glVertex2f(x, y);
        }
    }
    glEnd();
    glPopMatrix();
}

void Utility::drawLineCircle(GLfloat color[],
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
    glBegin(GL_LINE_STRIP);
    if (isAntiClockWise) {
        for (float angle = startingAngle * PI / 180; angle <= (isHalfCircle ? (PI + startingAngle * PI / 180) : 2 * PI); angle += 2 * PI / 360) {
            float x = radiusX * cos(angle);
            float y = radiusY * sin(angle);
            glVertex2f(x, y);
        }
    }
    else {
        for (float angle = startingAngle * PI / 180; angle >= (isHalfCircle ? -PI : -2 * PI); angle -= 2 * PI / 360) {
            float x = radiusX * cos(angle);
            float y = radiusY * sin(angle);
            glVertex2f(x, y);
        }
    }
    glEnd();
    glPopMatrix();
}

void Utility::drawRightTriangle(float width, float height, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);

    glBegin(GL_TRIANGLES);
    glTexCoord2f(1, 1); glVertex3f(-(width / 2), -(height / 2), 0);
    glTexCoord2f(1, 0); glVertex3f(width / 2, -(height / 2), 0);
    glTexCoord2f(0, 0); glVertex3f(-(width / 2), height / 2, 0);
    glEnd();

    glPopMatrix();
}

void Utility::drawCube(float width, float height, float depth, float color[], float tx, float ty, float tz) {
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

void Utility::drawSixFacesPolygon(float v1[], float v2[], float v3[], float v4[],
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

void Utility::drawSphere(GLdouble radius, GLint slices, GLint stacks, GLenum draw, float color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);

    GLUquadricObj* sphere = NULL;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, draw);
    gluQuadricTexture(sphere, true);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, radius, slices, stacks);
    gluDeleteQuadric(sphere);
    glPopMatrix();
}

void Utility::drawCylinder(GLfloat color[],
    GLdouble baseRadius,
    GLdouble topRadius,
    GLdouble height,
    GLint slices,
    GLint stacks,
    GLenum draw,
    bool closed,
    float tx,
    float ty,
    float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -height);
    glColor3fv(color);
    GLUquadricObj* cylinder = NULL;
    cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, draw);
    gluQuadricTexture(cylinder, true);
    gluQuadricNormals(cylinder, GLU_SMOOTH);
    gluCylinder(cylinder, baseRadius, topRadius, height, slices, stacks);
    gluDeleteQuadric(cylinder);
    if (closed) {
        drawDisk(color, 0, baseRadius, 30, 30, GLU_FILL, 0, 0, 0, false);
        drawDisk(color, 0, baseRadius, 30, 30, GLU_FILL, 0, 0, height, false);
    }
    glPopMatrix();
}

void Utility::drawHemisphere(double r, int lats, int longs, GLfloat color[], float tx, float ty, float tz) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3fv(color);
    int halfLats = lats / 2;
    for (int i = 0; i <= halfLats; i++) {
        double lat0 = PI * (-0.5 + (double)(i - 1) / lats);
        double z0 = r * sin(lat0);
        double zr0 = cos(lat0);

        double lat1 = PI * (-0.5 + (double)i / lats);
        double z1 = r * sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= longs; j++) {
            double lng = 2 * PI * (double)(j - 1) / longs;
            double x = r * cos(lng);
            double y = r * sin(lng);

            double s1, s2, t;
            s1 = ((double)i) / halfLats;
            s2 = ((double)i + 1) / halfLats;
            t = ((double)j) / longs;

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

void Utility::drawDisk(GLfloat color[],
    GLdouble inner,
    GLdouble outer,
    GLint slices,
    GLint loops,
    GLenum draw,
    float tx,
    float ty,
    float tz,
    bool isHorizontal) {
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glRotatef(isHorizontal ? 90 : false, 1, 0, 0);
    glColor3fv(color);
    GLUquadricObj* disk = NULL;
    disk = gluNewQuadric();
    gluQuadricDrawStyle(disk, draw);
    gluQuadricTexture(disk, true);
    gluQuadricNormals(disk, GLU_SMOOTH);
    gluDisk(disk, inner, outer, slices, loops);
    gluDeleteQuadric(disk);
    glPopMatrix();
}

//TCM START
void Utility::drawSphere(float r)
{
    GLUquadricObj* sphere = NULL;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricTexture(sphere, true);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, r, 30, 30);
    gluDeleteQuadric(sphere);
}

void Utility::drawShape(float downMinX, float downMaxX, float upMinX, float upMaxX, float downMinY, float downMaxY, float upMinY, float upMaxY, float downMinZ, float downMaxZ, float upMinZ, float upMaxZ) {
    //Back
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(upMinX, upMinY, upMinZ);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(downMinX, downMinY, downMinZ);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(downMaxX, downMaxY, downMinZ);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(upMaxX, upMaxY, upMinZ);
    glEnd();

    //Bottom
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(downMinX, downMinY, downMinZ);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(downMaxX, downMaxY, downMinZ);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(downMaxX, downMaxY, downMaxZ);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(downMinX, downMinY, downMaxZ);
    glEnd();

    //Left
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(upMaxX, upMaxY, upMinZ);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(downMaxX, downMaxY, downMinZ);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(downMaxX, downMaxY, downMaxZ);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(upMaxX, upMaxY, upMaxZ);
    glEnd();

    //Top
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(upMaxX, upMaxY, upMinZ);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(upMinX, upMinY, upMinZ);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(upMinX, upMinY, upMaxZ);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(upMaxX, upMaxY, upMaxZ);
    glEnd();

    //Right
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(upMinX, upMinY, upMinZ);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(downMinX, downMinY, downMinZ);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(downMinX, downMinY, downMaxZ);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(upMinX, upMinY, upMaxZ);
    glEnd();

    //Front
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(upMinX, upMinY, upMaxZ);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(downMinX, downMinY, downMaxZ);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(downMaxX, downMaxY, downMaxZ);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(upMaxX, upMaxY, upMaxZ);
    glEnd();
}

void Utility::drawCylinder(double tr, double br, double h) {
    GLUquadricObj* cylinder = NULL;
    cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluQuadricTexture(cylinder, true);
    gluQuadricNormals(cylinder, GLU_SMOOTH);
    gluCylinder(cylinder, tr, br, h, 30, 30);
    gluDeleteQuadric(cylinder);
}

void Utility::drawInnerBody(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
    glBegin(GL_LINES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(maxX, maxY, maxZ);
    glEnd();
}

void Utility::drawRectangle(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {

    //Back
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(minX, maxY, minZ);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(maxX, minY, minZ);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(maxX, maxY, minZ);
    glEnd();

    //Bottom
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(maxX, minY, minZ);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(maxX, minY, maxZ);
    glEnd();

    //Left
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(minX, maxY, maxZ);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(minX, maxY, minZ);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(minX, minY, maxZ);
    glEnd();

    //Top
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(minX, maxY, maxZ);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(minX, maxY, minZ);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(maxX, maxY, minZ);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(maxX, maxY, maxZ);
    glEnd();

    //Right
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(maxX, maxY, maxZ);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(maxX, maxY, minZ);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(maxX, minY, minZ);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(maxX, minY, maxZ);
    glEnd();

    //Front
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(minX, maxY, maxZ);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(maxX, minY, maxZ);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(maxX, maxY, maxZ);
    glEnd();

}

void Utility::starVertical(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, maxY, minZ);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, -maxY, minZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, -minY, minZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, maxY, minZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, -maxY, minZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, -minY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, maxY, maxZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, -maxY, maxZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, -minY, maxZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, maxY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, -maxY, maxZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, -minY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, maxY, minZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, maxY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, maxY, minZ);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, -maxY, minZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, -maxY, maxZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, maxY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, -maxY, minZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, -minY, minZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, -minY, maxZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, -maxY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, -minY, minZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, -maxY, minZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, -maxY, maxZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, -minY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, -maxY, minZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, -maxY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, maxY, maxZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, maxY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, maxY, minZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, maxY, maxZ);
    glEnd();


}

void Utility::starHorizontal(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, maxY, minZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, maxY, minZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(-minX, minZ);
    glVertex3f(-minX, minY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, -maxY, minZ);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, -maxY, minZ);
    glTexCoord2f(-minX, minZ);
    glVertex3f(-minX, minY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, maxY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, maxY, maxZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(-minX, maxZ);
    glVertex3f(-minX, minY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, -maxY, maxZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, -maxY, maxZ);
    glTexCoord2f(-minX, maxZ);
    glVertex3f(-minX, minY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, maxY, minZ);
    glTexCoord2f(-minX, minZ);
    glVertex3f(-minX, minY, minZ);
    glTexCoord2f(-minX, maxZ);
    glVertex3f(-minX, minY, maxZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, maxY, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, maxY, minZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, maxY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, maxY, maxZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, maxY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, maxY, minZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, maxY, maxZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(minX, minZ);
    glVertex3f(minX, minY, minZ);
    glTexCoord2f(minX, maxZ);
    glVertex3f(minX, minY, maxZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, -maxY, maxZ);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, -maxY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(maxX, minZ);
    glVertex3f(maxX, -maxY, minZ);
    glTexCoord2f(maxX, maxZ);
    glVertex3f(maxX, -maxY, maxZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, -maxY, maxZ);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, -maxY, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-maxX, minZ);
    glVertex3f(-maxX, -maxY, minZ);
    glTexCoord2f(-maxX, maxZ);
    glVertex3f(-maxX, -maxY, maxZ);
    glTexCoord2f(-minX, maxZ);
    glVertex3f(-minX, minY, maxZ);
    glTexCoord2f(-minX, minZ);
    glVertex3f(-minX, minY, minZ);
    glEnd();

}

void Utility::shieldPentagon(float minZ, float maxZ) {

    glBegin(GL_POLYGON);
    glTexCoord2f(-0.1f, minZ);
    glVertex3f(-0.1f, 0.2f, minZ);
    glTexCoord2f(0.1f, minZ);
    glVertex3f(0.1f, 0.2f, minZ);
    glTexCoord2f(0.16f, minZ);
    glVertex3f(0.16f, -0.09f, minZ);
    glTexCoord2f(0.0f, minZ);
    glVertex3f(0.0f, -0.25f, minZ);
    glTexCoord2f(-0.16f, minZ);
    glVertex3f(-0.16f, -0.09f, minZ);
    glEnd();

    glBegin(GL_POLYGON);
    glTexCoord2f(-0.1f, maxZ);
    glVertex3f(-0.1f, 0.2f, maxZ);
    glTexCoord2f(0.1f, maxZ);
    glVertex3f(0.1f, 0.2f, maxZ);
    glTexCoord2f(0.16f, maxZ);
    glVertex3f(0.16f, -0.09f, maxZ);
    glTexCoord2f(0.0f, maxZ);
    glVertex3f(0.0f, -0.25f, maxZ);
    glTexCoord2f(-0.16f, maxZ);
    glVertex3f(-0.16f, -0.09f, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-0.16f, minZ);
    glVertex3f(-0.16f, -0.09f, minZ);
    glTexCoord2f(0.0f, minZ);
    glVertex3f(0.0f, -0.25f, minZ);
    glTexCoord2f(0.0f, maxZ);
    glVertex3f(0.0f, -0.25f, maxZ);
    glTexCoord2f(-0.16f, maxZ);
    glVertex3f(-0.16f, -0.09f, maxZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-0.16f, minZ);
    glVertex3f(-0.16f, -0.09f, minZ);
    glTexCoord2f(-0.16f, maxZ);
    glVertex3f(-0.16f, -0.09f, maxZ);
    glTexCoord2f(-0.1f, maxZ);
    glVertex3f(-0.1f, 0.2f, maxZ);
    glTexCoord2f(-0.1f, minZ);
    glVertex3f(-0.1f, 0.2f, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(-0.1f, minZ);
    glVertex3f(-0.1f, 0.2f, minZ);
    glTexCoord2f(-0.1f, maxZ);
    glVertex3f(-0.1f, 0.2f, maxZ);
    glTexCoord2f(0.1f, maxZ);
    glVertex3f(0.1f, 0.2f, maxZ);
    glTexCoord2f(0.1f, minZ);
    glVertex3f(0.1f, 0.2f, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0.1f, minZ);
    glVertex3f(0.1f, 0.2f, minZ);
    glTexCoord2f(0.1f, maxZ);
    glVertex3f(0.1f, 0.2f, maxZ);
    glTexCoord2f(0.16f, maxZ);
    glVertex3f(0.16f, -0.09f, maxZ);
    glTexCoord2f(0.16f, minZ);
    glVertex3f(0.16f, -0.09f, minZ);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0.16f, minZ);
    glVertex3f(0.16f, -0.09f, minZ);
    glTexCoord2f(0.16f, maxZ);
    glVertex3f(0.16f, -0.09f, maxZ);
    glTexCoord2f(0.0f, maxZ);
    glVertex3f(0.0f, -0.25f, maxZ);
    glTexCoord2f(0.0f, minZ);
    glVertex3f(0.0f, -0.25f, minZ);
    glEnd();

}
//TCM END
