#pragma once

#ifndef Utility_hpp
#define Utility_hpp
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
};
