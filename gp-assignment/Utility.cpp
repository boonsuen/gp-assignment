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
#include "Utility.hpp"
#include "common.h"

void Utility::drawRect(float width, float height, float color[], float tx, float ty, float tz) {
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

void Utility::drawRightTriangle(float width, float height, float color[], float tx, float ty, float tz) {
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
    GLUquadricObj *cylinder = NULL;
    cylinder = gluNewQuadric();
    gluQuadricDrawStyle(cylinder, draw);
    gluQuadricTexture(cylinder, true);
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
    GLUquadricObj *disk = NULL;
    disk = gluNewQuadric();
    gluQuadricDrawStyle(disk, draw);
    gluQuadricTexture(disk, true);
    gluDisk(disk, inner, outer, slices, loops);
    gluDeleteQuadric(disk);
    glPopMatrix();
}
