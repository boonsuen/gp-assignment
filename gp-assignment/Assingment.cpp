#include <Windows.h> 
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

#define WINDOW_TITLE "Robot"

//Arm
bool elbowRight = false, elbowLeft = false;
bool shoulderTurnRight = false, shoulderTurnLeft = false;
bool leftHandMove, rightHandMove;

//finger
bool fingerRight = false, fingerLeft = false;
float rotatThumb = 3, rotatfinger = 3;
float actRotatFingLeft, actRotatFing2Left, actRotatFing3Left;
float actRotatFingRight, actRotatFing2Right, actRotatFing3Right;
float actRotatThumbRight, actRotatThumbLeft;
float actRotateElbowRight, actRotateElbowLeft;
float actShoulderRight, actShoulderLeft;

//Weapon
bool gunShow = false, gunBig = false, gunSmall = false, gunShootMove = false;
float gunSp = 0.05, gunTransUp, gunTransFront, gunTransNear, gunScale, gunScaleSmall = 1, bulletMove, bulletSp = 1;
bool weaponShow = false, weaponBig = false, weaponSmall = false, weaponAttackMove = false, electricShow = false, weaponAttackDown = false;
float weaponSp = 0.05, weaponTransUp, weaponTransFront, weaponScale, weaponScaleSmall = 1;
int elect = 0, electSp = 1;

//Leg
bool walkRight, walkLeft, legMoveFront, legMoveBack, legMoveLeft, legMoveRight;
float walkRightKnee, walkUpRightKnee, walkLeftKnee, walkUpLeftKnee, legMoveX, legMoveY, legMoveSp = 2;
float walkSpeed = 2, walkKneeSpeed = 0.016;
float walking, walkingSp = 0.0064;

//Body
float angle = 0;
float x1 = 0, y3 = 0, x2 = 0, y2 = 0;

//head
float headRotatex = 0;
float headRotatey = 0;

//move
float sliding = 0;
float slideMove = 0;
float flyingX = 0;
float flyingY = 0;

//thruster
bool isTurbo = false;
float fireLengthCone, fireLengthCylin;
int fire = 0, fireSp = 1;

//Projection
bool isOrtho = true;

bool txView, tyView = true;
float tx = 0, ty = 0, tz = 0, tSpeed = 0.1;
float Ry = 0, Rx = -11, rSpeed = 5;
float orthoview = 1;                 //yong 

//lighting
bool isLightOn = false;
float amb[] = { 1, 1, 1 };    //white color  ambient light
float lightPosition[] = { 0, 3, 0 };
float lSpeed = 0.1;
float posD[] = { 1,-1,0 };//diff light positionat right(5,0,0)

//Texture
BITMAP BMP;             //bitmap structure
HBITMAP hBMP = NULL;    //bitmap handle
LPCSTR bodyText[2] = { "black steel.bmp", "white.bmp" };
LPCSTR jointText[2] = { "white.bmp","Rusty Black Steel.bmp" };
int changeBody1 = 0, changeBody2 = 1, changeJoint1 = 0;
bool isTexture = true;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:              //WM = window message, when click cross button window
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:                                     //press long key
		if (wParam == VK_ESCAPE)                         //Param = parameter, VK = virtual key
			PostQuitMessage(0);

		else if (wParam == 0x33)        //3 = space to reset
		{
			walkRight = false;
			walkLeft = false;
			fingerLeft = false;
			elbowLeft = false;
			shoulderTurnLeft = false;
			fingerRight = false;
			elbowRight = false;
			shoulderTurnRight = false;
			headRotatex = 0;
			headRotatey = 0;
			walking = 0;
			legMoveFront = false;
			legMoveBack = false;
			legMoveLeft = false;
			legMoveRight = false;
			legMoveX = 0;
			legMoveY = 0;
			sliding = 0;
			slideMove = 0;
			flyingX = 0;
			flyingY = 0;
			isTurbo = false;
			if(weaponBig == true)
				weaponSmall = true;
			if(gunBig == true)
				gunSmall = true;
		}

		else if (wParam == 0x36)                      //6 = change color
		{
			if (changeBody1 == 0) {
				changeBody1 = 1;
				changeBody2 = 0;
				changeJoint1 = 1;
			}
			else if (changeBody1 == 1) {
				changeBody1 = 0;
				changeBody2 = 1;
				changeJoint1 = 0;
			}
		}
		else if (wParam == 0x34) {                     //hand Movement
			if (leftHandMove == false)
				leftHandMove = true;
			else if (leftHandMove == true)
				leftHandMove = false;
		}
		else if (wParam == 0x35) {
			if (rightHandMove == false)
				rightHandMove = true;
			else if (rightHandMove == true)
				rightHandMove = false;
		}
		else if (wParam == 0x52) {                                  //r = finger 
			if (leftHandMove == true && fingerLeft == false)        //left hand
				fingerLeft = true;
			else if (leftHandMove == true && fingerLeft == true)
				fingerLeft = false;

			if (rightHandMove == true && fingerRight == false)        //right hand
				fingerRight = true;
			else if (rightHandMove == true && fingerRight == true)
				fingerRight = false;
		}
		else if (wParam == 0x54) {                                  //t = elbow 
			if (leftHandMove == true && elbowLeft == false)        //left hand
				elbowLeft = true;
			else if (leftHandMove == true && elbowLeft == true)
				elbowLeft = false;

			if (rightHandMove == true && elbowRight == false)  //right hand
				elbowRight = true;
			else if (rightHandMove == true && elbowRight == true)
				elbowRight = false;
		}
		else if (wParam == 'F') {                                     //f = shoulder
			if (leftHandMove == true && shoulderTurnLeft == false)        //left hand
				shoulderTurnLeft = true;
			else if (leftHandMove == true && shoulderTurnLeft == true)
				shoulderTurnLeft = false;

			if (rightHandMove == true && shoulderTurnRight == false)  //right hand
				shoulderTurnRight = true;
			else if (rightHandMove == true && shoulderTurnRight == true)
				shoulderTurnRight = false;
		}

		else if (wParam == 0x37) {                  //7 = gun
			gunShow = true;
			gunBig = false;
			gunSmall = false;
		}
		else if (wParam == 0x38) {                  //8 = save gun
			if (gunBig == true)
				gunSmall = true;
		}
		else if (wParam == 0x4F)                    //o = gun shoot
			gunShootMove = true;

		else if (wParam == 0x39) {                  //9 = weapon
			weaponShow = true;
			weaponBig = false;
			weaponSmall = false;
		}
		else if (wParam == 0x30) {                  //0 = weapon////////////////////////////////////////////////////////////////////////////
			if (weaponBig == true)
				weaponSmall = true;
		}
		else if (wParam == 0x50) {                 //p = weapon attack
			if (weaponAttackMove == false)
				weaponAttackMove = true;
			else if (weaponAttackMove == true) {
				weaponAttackMove = false;
				weaponAttackDown = false;
			}
		}

		else if (wParam == 0x4D) {               //m = walking
			if (walkRight == true || walkLeft == true) {
				walkRight = false;
				walkLeft = false;
			}
			else if (walkRight == false)
				walkRight = true;
		}

		else if (wParam == 'H') {
			if (legMoveFront == false) {
				legMoveFront = true;
				legMoveBack = false;
			}
			else if (legMoveBack == false) {
				legMoveBack = true;
				legMoveFront = false;
			}
		}
		else if (wParam == 'N') {
			if (legMoveLeft == false) {
				legMoveLeft = true;
				legMoveRight = false;
			}
			else if (legMoveRight == false) {
				legMoveRight = true;
				legMoveLeft = false;
			}
		}
		///////////////////////////////////////////////////////////projection
		else if (wParam == 0x31)                //KEY 1= change view
			isOrtho = !isOrtho;

		else if (wParam == 0x32) {              //key 2 = translatef x or y
			if (txView == false && tyView == true) {
				txView = true;
				tyView = false;
			}
			else if (tyView == false && txView == true) {
				tyView = true;
				txView = false;
			}
		}

		else if (wParam == 0x41)             //key A = view rotate
			Ry -= rSpeed;

		else if (wParam == 0x44)             //key D = view rotate
			Ry += rSpeed;

		else if (wParam == 0x57) {            //key W = view rotate
			if (tyView == true && ty > -0.3)
				ty -= tSpeed;
			else if (txView == true && tx > -0.2)
				tx -= tSpeed;
		}
		else if (wParam == 0x53) {             //key S = view rotate
			if (tyView == true && ty < 0.3)
				ty += tSpeed;
			else if (txView == true && tx < 0.2)
				tx += tSpeed;
		}
		else if (wParam == 'Q') {             //key q = view rotate
			if (isOrtho && tz < 0.8)
				tz += tSpeed;
			else if (!isOrtho && tz < 1.4)
				tz += tSpeed;
		}
		else if (wParam == 'E') {             //key e = view rotate
			if (isOrtho && tz > -0.1)
				tz -= tSpeed;
			else if (!isOrtho && tz > -0.5)
				tz -= tSpeed;
		}

		else if (wParam == VK_UP) {
			if (flyingY < 1) {
				isTurbo = true;
				flyingY += 0.1;
			}
		}
		else if (wParam == VK_DOWN) {
			if (flyingY <= 0) {
				isTurbo = false;
			}
			else {
				isTurbo = true;
				flyingY -= 0.1;
			}
		}
		else if (wParam == VK_LEFT) {
			if (flyingX >= -1) {
				flyingX -= 0.1;
			}
		}
		else if (wParam == VK_RIGHT) {
			if (flyingX <= 1) {
				flyingX += 0.1;
			}
		}

		else if (wParam == 0x5A)      //key z = object z 
		{
			if (slideMove < 1) {
				isTurbo = true;
				sliding = 30;
				slideMove += 0.3;
			}
		}
		else if (wParam == 0x58)      //key x
		{
			if (slideMove > -2) {
				isTurbo = true;
				sliding = -30;
				slideMove -= 0.3;
			}
		}
		///////////////////////////////yong 
		//head rotate
		else if (wParam == 'C') {
			if (headRotatex > -20)
				headRotatex -= 0.5;
		}
		else if (wParam == 'B') {
			if (headRotatex < 20)
				headRotatex += 0.5;
		}
		else if (wParam == 'G') {
			if (headRotatey < 5)
				headRotatey += 0.5;
		}
		else if (wParam == 'V') {
			if (headRotatey > -3)
				headRotatey -= 0.5;
		}
		//Light
		else if (wParam == 'I')                          //I = light up
			lightPosition[1] += lSpeed;

		else if (wParam == 'K')                          //K = light down
			lightPosition[1] -= lSpeed;

		else if (wParam == 'J')                           //J = light left	
			lightPosition[0] -= lSpeed;

		else if (wParam == 'L')                          //L = light right
			lightPosition[0] += lSpeed;

		else if (wParam == 'Y')                         //Y = light back
			lightPosition[2] -= lSpeed;

		else if (wParam == 'U')                         //U = light front
			lightPosition[2] += lSpeed;
		else if (wParam == VK_SPACE)                         //space = light
		{
			isLightOn = !isLightOn;
		}
		else if (wParam == VK_RETURN)                         //enter = enable/disable texture
		{
			isTexture = !isTexture;
		}

		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)          //ini = initalize
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

//////////////////////////////////Texture
GLuint loadTexture(LPCSTR filename) {

	//Get from Step 1
	GLuint texture = 0;     //texture name

	//Step 3: Initialize texture info
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), filename, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);

	//Step 4: Assign texture to polygon
	if (isTexture == true) {
		glEnable(GL_TEXTURE_2D);
	}
	else glDisable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	//From Step 5
	DeleteObject(hBMP);
	return texture;
}

//////////////////////////////////////Usually Use
void drawCube(float length, float width, float height) {
	glBegin(GL_QUADS);
	//Face 1? front
	glVertex3f(0.0f, 0.0f, height);
	glVertex3f(length, 0.0f, height);
	glVertex3f(length, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	//Face 2? left
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, height);
	glVertex3f(0.0f, width, height);
	glVertex3f(0.0f, width, 0.0f);
	//Face 3? top
	glVertex3f(0.0f, 0.0f, height);
	glVertex3f(0.0f, width, height);
	glVertex3f(length, width, height);
	glVertex3f(length, 0.0f, height);
	//Face 4? right
	glVertex3f(length, 0.0f, height);
	glVertex3f(length, 0.0f, 0.0f);
	glVertex3f(length, width, 0.0f);
	glVertex3f(length, width, height);
	//Face 5? behind
	glVertex3f(length, width, height);
	glVertex3f(0.0f, width, height);
	glVertex3f(0.0f, width, 0.0f);
	glVertex3f(length, width, 0.0f);
	//Face 6? bottom
	glVertex3f(length, width, 0.0f);
	glVertex3f(length, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, width, 0.0f);
	glEnd();
}

void drawCubeTexture(float length, float width, float height, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	glBegin(GL_QUADS);
	//Face size : Bottom
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(length, 0.0f, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(length, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	//Face 2 : Left
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, width, height);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, width, 0.0f);

	//Face 3 : Front
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, width, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(length, width, height);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(length, 0.0f, height);

	//Face 4 : Right
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(length, 0.0f, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(length, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(length, width, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(length, width, height);

	//Face 5 : Top
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(length, width, height);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, width, height);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, width, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(length, width, 0.0f);

	//Face 6 : Back
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(length, width, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(length, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, width, 0.0f);
	glEnd();
	glDeleteTextures(1, &texture);
}

void sphere(float radius) {
	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();

	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, radius, 30, 30);

	gluDeleteQuadric(sphere);
}

void sphereTexture(float radius, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);

	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();

	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);

	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, radius, 30, 30);

	gluDeleteQuadric(sphere);
	glDeleteTextures(1, &texture);
}

void sphereTexture1(float radius, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);

	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();

	gluQuadricTexture(sphere, TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);

	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, radius, 30, 30);

	gluDeleteQuadric(sphere);
	glDeleteTextures(1, &texture);
}

void cylinder(float baseRadius, float topRadius, float height) {
	GLUquadric* cylinDownkAim = NULL;
	cylinDownkAim = gluNewQuadric();

	gluQuadricDrawStyle(cylinDownkAim, GLU_FILL);
	gluCylinder(cylinDownkAim, baseRadius, topRadius, height, 30, 30);

	gluDeleteQuadric(cylinDownkAim);
}

void cylinderTexture(float baseRadius, float topRadius, float height, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);

	GLUquadric* cylinder = NULL;
	cylinder = gluNewQuadric();

	gluQuadricTexture(cylinder, TRUE);
	gluQuadricNormals(cylinder, GLU_SMOOTH);

	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, baseRadius, topRadius, height, 30, 30);

	gluDeleteQuadric(cylinder);
	glDeleteTextures(1, &texture);
}

///////////////////////////////////body
void drawsphere() {
	GLUquadricObj* sphere = NULL;
	sphere = gluNewQuadric();

	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, 0.2, 20, 20);
	gluDeleteQuadric(sphere);
}

void drawCone(float topRadius, float height, int slices, int stacks, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	gluQuadricTexture(cylinder, TRUE);
	gluQuadricNormals(cylinder, GLU_SMOOTH);

	gluQuadricDrawStyle(cylinder, GLU_POINT);
	gluCylinder(cylinder, 0.01, topRadius, height, slices, stacks);
	gluDeleteQuadric(cylinder);
	glDeleteTextures(1, &texture);
};

void drawCircle(float radius) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y3);

	for (angle = 0; angle <= 360; angle += 0.2) {
		x2 = x1 + radius * (cos(angle));
		y2 = y3 + radius * (sin(angle));
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawCylinder(float baseRadius, float topRadius, float height, int slices, int stacks, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);

	drawCircle(baseRadius);
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();

	gluQuadricTexture(cylinder, TRUE);
	gluQuadricNormals(cylinder, GLU_SMOOTH);

	gluQuadricDrawStyle(cylinder, GLU_FILL);
	gluCylinder(cylinder, baseRadius, topRadius, height, slices, stacks);
	gluDeleteQuadric(cylinder);

	glPushMatrix();
	glTranslatef(0, 0, height);
	drawCircle(topRadius);
	glPopMatrix();

	glDeleteTextures(1, &texture);
};

void drawCylinder2(float baseRadius, float topRadius, float height, int slices, int stacks, LPCSTR filename) {//use for glu point

	GLuint texture;
	texture = loadTexture(filename);
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();

	gluQuadricTexture(cylinder, TRUE);
	gluQuadricNormals(cylinder, GLU_SMOOTH);


	gluQuadricDrawStyle(cylinder, GLU_POINT);
	gluCylinder(cylinder, baseRadius, topRadius, height, slices, stacks);
	gluDeleteQuadric(cylinder);
	glDeleteTextures(1, &texture);
};

void drawCylinderLine(float baseRadius, float topRadius, float height, int slices, int stacks, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	gluQuadricTexture(cylinder, TRUE);
	gluQuadricNormals(cylinder, GLU_SMOOTH);

	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, baseRadius, topRadius, height, slices, stacks);
	gluDeleteQuadric(cylinder);
	glDeleteTextures(1, &texture);
};


void turbo(LPCSTR filename) {

	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);
	drawCircle(0.03);
	cylinderTexture(0.031, 0.051, 0.02, filename);
	if (!isTexture)
	{
		glColor3f(0, 0, 0);
	}
	else glColor3f(1, 1, 1);
	drawCylinderLine(0.029, 0.049, 0.02, 10, 1, "weaponHandle.bmp");
	if (isTurbo) {
		if (!isTexture)
		{
			glColor3f(0, 0, 1);
		}
		else glColor3f(1, 1, 1);
		fire += fireSp;
		if (fire % 2 == 0) {
			fireLengthCone = 0.0625;
			fireLengthCylin = 0.025;
		}
		else {
			fireLengthCone = 0.05;
			fireLengthCylin = 0.02;
		}
		if (fire > 100) {
			fire = 0;
		}
		drawCone(0.05, fireLengthCone, 50, 50, "fire.bmp");
		glPushMatrix();
		glTranslatef(0, 0, 0.05);
		drawCylinder2(0.048, fireLengthCylin, 0.03, 30, 30, "fire.bmp");
		glPopMatrix();
	}
}

void thruster(LPCSTR filename1, LPCSTR filename2) {
	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(-0.2, 0.25, 0.35);
	glRotatef(180, 1, 0, 0);
	drawCubeTexture(0.4, 0.5, 0.1, filename1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.09, 0.15, 0.36);
	turbo(filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.09, 0.15, 0.36);
	turbo(filename2);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.09, 0, 0.36);
	turbo(filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.09, 0, 0.36);
	turbo(filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.09, -0.15, 0.36);
	turbo(filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.09, -0.15, 0.36);
	turbo(filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.09, -0.15, 0.36);
	turbo(filename2);
	glPopMatrix();

	//	below
	glPushMatrix();
	glRotatef(90, 1, 0, 0);

	glPushMatrix();
	glTranslatef(-0.09, 0.3, 0.251);
	turbo(filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.09, 0.3, 0.251);
	turbo(filename2);
	glPopMatrix();

	glPopMatrix();

}

void bodyUp(float width, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);

	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	//Face 1£º front
	glTexCoord2f(0, 1);
	glVertex3f(-0.05, 0.3f, -0.05);
	glTexCoord2f(1, 1);
	glVertex3f(-0.45f, 0.35f, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-0.45, 0.2f, 0.0f);
	glTexCoord2f(0, 0);
	glVertex3f(0.0f, 0.0f, -0.1);
	//Face 2£º right
	glTexCoord2f(0, 1);
	glVertex3f(0.0f, 0.0f, -0.1);
	glTexCoord2f(1, 1);
	glVertex3f(0.0f, 0.0f, width + 0.1);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, 0.3f, width + 0.05);
	glTexCoord2f(0, 0);
	glVertex3f(-0.05, 0.3f, -0.05);

	//Face 3£º top
	glTexCoord2f(0, 1);
	glVertex3f(-0.05, 0.3f, -0.05);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, 0.3f, width + 0.05);
	glTexCoord2f(1, 0);
	glVertex3f(-0.45f, 0.35f, width);
	glTexCoord2f(0, 0);
	glVertex3f(-0.45f, 0.35f, 0);
	//Face 4£º left
	glTexCoord2f(0, 1);
	glVertex3f(-0.45f, 0.35f, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-0.45, 0.2f, 0.0f);
	glTexCoord2f(1, 0);
	glVertex3f(-0.45, 0.2f, width);
	glTexCoord2f(0, 0);
	glVertex3f(-0.45f, 0.35f, width);

	//Face 5£º behind
	glTexCoord2f(0, 1);
	glVertex3f(-0.45f, 0.35f, width);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, 0.3f, width + 0.05);
	glTexCoord2f(1, 0);
	glVertex3f(0.0f, 0.0f, width + 0.1);
	glTexCoord2f(0, 0);
	glVertex3f(-0.45, 0.2f, width);

	//Face 6£º bottom
	glTexCoord2f(0, 1);
	glVertex3f(-0.45, 0.2f, width);
	glTexCoord2f(1, 1);
	glVertex3f(-0.45, 0.2f, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.0f, 0.0f, -0.1);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, width + 0.1);

	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void bodyUpMid(float width, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);

	glBegin(GL_TRIANGLES);
	//Face 1£º front
	glTexCoord2f(1, 1);
	glVertex3f(-0.02, 0.1f, -0.075);
	glTexCoord2f(1, 0);
	glVertex3f(0, 0.075f, -0.075);
	glTexCoord2f(0, 0);
	glVertex3f(0.0f, 0.0f, -0.1);
	glEnd();

	//Face 5£º behind
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.02, 0.1f, width + 0.075);
	glTexCoord2f(1, 0);
	glVertex3f(0, 0.075f, width + 0.075);
	glTexCoord2f(0, 0);
	glVertex3f(0.0f, 0.0f, width + 0.1);
	glEnd();

	glBegin(GL_QUADS);
	//Face 1£º front
	glTexCoord2f(0, 1);
	glVertex3f(-0.02, 0.1f, -0.075);
	glTexCoord2f(1, 1);
	glVertex3f(0.0f, 0.075f, -0.075);
	glTexCoord2f(1, 0);
	glVertex3f(0.0f, 0.175f, -0.06);
	glTexCoord2f(0, 0);
	glVertex3f(-0.035, 0.2, -0.06);


	//Face 5£º behind
	glTexCoord2f(0, 1);
	glVertex3f(-0.02, 0.1f, width + 0.075);
	glTexCoord2f(1, 1);
	glVertex3f(0.0f, 0.075f, width + 0.075);
	glTexCoord2f(1, 0);
	glVertex3f(0.0f, 0.175f, width + 0.06);
	glTexCoord2f(0, 0);
	glVertex3f(-0.035, 0.2, width + 0.06);
	glEnd();

	glBegin(GL_QUADS);
	//Face 1£º front
	glTexCoord2f(0, 1);
	glVertex3f(0.0f, 0.175f, -0.06);
	glTexCoord2f(1, 1);
	glVertex3f(-0.035, 0.2, -0.06);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, 0.3, -0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0.29, -0.05);

	//Face 5£º behind
	glTexCoord2f(0, 1);
	glVertex3f(0.0f, 0.175f, width + 0.06);
	glTexCoord2f(1, 1);
	glVertex3f(-0.035, 0.2, width + 0.06);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, 0.3, width + 0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0.29, width + 0.05);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void tri(LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);


	glBegin(GL_TRIANGLES);
	//front
	glTexCoord2f(1, 1);
	glVertex3f(0.0, 0, -0.1);
	glTexCoord2f(1, 0);
	glVertex3f(0.15, 0, -0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, 0.065, -0.05);
	//back
	glTexCoord2f(1, 1);
	glVertex3f(0.15, 0, 0.05);
	glTexCoord2f(1, 0);
	glVertex3f(0.0, 0, 0.1);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, 0.065, 0.05);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0.15, 0.065, -0.05);
	glTexCoord2f(1, 1);
	glVertex3f(0.15, 0.065, 0.05);
	glTexCoord2f(1, 0);
	glVertex3f(0.15, 0, 0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, 0, -0.05);
	//bottom
	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 0.1);
	glTexCoord2f(1, 1);
	glVertex3f(0.0, 0, -0.1);
	glTexCoord2f(1, 0);
	glVertex3f(0.15, 0, -0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, 0, 0.05);
	//top
	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 0.1);
	glTexCoord2f(1, 1);
	glVertex3f(0, 0, -0.1);
	glTexCoord2f(1, 0);
	glVertex3f(0.15, 0.065, -0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, 0.065, 0.05);

	glEnd();

	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

}

void bodyMidTri(float width, LPCSTR filename) {
	tri(filename);
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	tri(filename);
	glPopMatrix();
}

void bodyMid(float width, LPCSTR filename1, LPCSTR filename2) {
	bodyMidTri(width, filename2);
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);


	float i, j;
	glPushMatrix();
	glScalef(0.5, 0.6, 0.7);
	glTranslatef(0, 0, 0.1);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	drawCylinder(0.2, 0.2, 0.6, 30, 30, filename1);
	glPopMatrix();
	for (j = 0.1; j < 0.7; j += 0.1) {
		for (i = 0; i < 360; i += 30) {
			if (!isTexture)
			{
				glColor3f(0, 0, 1);
			}
			else glColor3f(1, 1, 1);
			glPushMatrix();
			glRotatef(-i, 0, 1, 0);
			glTranslatef(0.2, -j, 0);
			drawCubeTexture(0.07, 0.07, 0.07, filename2);
			glPopMatrix();
		}
	}
	glPopMatrix();
}

void bodySide(float width, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	//Face 1£º front
	glTexCoord2f(0, 1);
	glVertex3f(0.15, 0.07f, -0.05);
	glTexCoord2f(1, 1);
	glVertex3f(0.15, -0.07, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.45f, 0.05f, 0.03);
	glTexCoord2f(0, 0);
	glVertex3f(0.45, 0.2, 0.025);

	//Face 2£º right
	glTexCoord2f(0, 1);
	glVertex3f(0.45, 0.2, 0.025);
	glTexCoord2f(1, 1);
	glVertex3f(0.45f, 0.05f, 0.03);
	glTexCoord2f(1, 0);
	glVertex3f(0.45f, 0.05f, width - 0.03);
	glTexCoord2f(0, 0);
	glVertex3f(0.45, 0.2, width - 0.025);

	//Face 3£º top
	glTexCoord2f(0, 1);
	glVertex3f(0.45, 0.2, width - 0.025);
	glTexCoord2f(1, 1);
	glVertex3f(0.45, 0.2, 0.025);
	glTexCoord2f(1, 0);
	glVertex3f(0.15, 0.07f, -0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, 0.07f, width + 0.05);
	//Face 4£º left
	glTexCoord2f(0, 1);
	glVertex3f(0.15, 0.07f, width + 0.05);
	glTexCoord2f(1, 1);
	glVertex3f(0.15, 0.07f, -0.05);
	glTexCoord2f(1, 0);
	glVertex3f(0.15, -0.07, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, -0.07, width);

	//Face 5£º behind
	glTexCoord2f(0, 1);
	glVertex3f(0.15, -0.07, width);
	glTexCoord2f(1, 1);
	glVertex3f(0.15, 0.07f, width + 0.05);
	glTexCoord2f(1, 0);
	glVertex3f(0.45, 0.2, width - 0.025);
	glTexCoord2f(0, 0);
	glVertex3f(0.45, 0.05, width - 0.03);

	//Face 6£º bottom
	glTexCoord2f(0, 1);
	glVertex3f(0.45, 0.05, width - 0.03);
	glTexCoord2f(1, 1);
	glVertex3f(0.45, 0.05, 0.03);
	glTexCoord2f(1, 0);
	glVertex3f(0.15, -0.07, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0.15, -0.07, width);

	glEnd();

	glPushMatrix();
	glTranslatef(-0.43, 0.13, 0.01);
	drawCylinder(0.01, 0.01, 0.17, 50, 50, "WHITE.BMP");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 0.1, 0.01);
	drawCylinder(0.01, 0.01, 0.18, 50, 50, "WHITE.BMP");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.37, 0.08, 0.01);
	drawCylinder(0.01, 0.01, 0.19, 50, 50, "WHITE.BMP");
	glPopMatrix();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void bodyRight(float width, LPCSTR filename) {
	bodySide(width, filename);
	glPushMatrix();
	glScalef(0.9, 0.95, 1);
	glTranslatef(0, -0.13, 0);
	bodySide(width, filename);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -0.26, 0);
	glScalef(0.8, 0.9, 1);
	bodySide(width, filename);
	glPopMatrix();
}

void lowerBody(float width, LPCSTR filename1, LPCSTR filename2) {
	GLuint textures[2];
	textures[0] = loadTexture(filename1);
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	//Face 1£º front
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.27, -0.1);
	glTexCoord2f(1, 1);
	glVertex3f(-0.3, -0.4, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-0.3, -0.5f, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.6, -0.1);

	//Face 2£º right
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.6, -0.1);
	glTexCoord2f(1, 1);
	glVertex3f(0, -0.6, width + 0.1);
	glTexCoord2f(1, 0);
	glVertex3f(0, -0.27, width + 0.1);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.27, -0.1);

	//Face 3£º top
	glTexCoord2f(0, 1);
	glVertex3f(-0.3, -0.4, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0, -0.27, -0.1);
	glTexCoord2f(1, 0);
	glVertex3f(0, -0.27, width + 0.1);
	glTexCoord2f(0, 0);
	glVertex3f(-0.3, -0.4, width);
	//Face 4£º left
	glTexCoord2f(0, 1);
	glVertex3f(-0.3, -0.4, width);
	glTexCoord2f(1, 1);
	glVertex3f(-0.3, -0.4, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-0.3, -0.5f, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-0.3, -0.5f, width);


	//Face 5£º behind
	glTexCoord2f(0, 1);
	glVertex3f(-0.3, -0.5f, width);
	glTexCoord2f(1, 1);
	glVertex3f(-0.3, -0.4, width);
	glTexCoord2f(1, 0);
	glVertex3f(0, -0.27, width + 0.1);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.6, width + 0.1);

	//Face 6£º bottom
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.6, width + 0.1);
	glTexCoord2f(1, 1);
	glVertex3f(0, -0.6, -0.1);
	glTexCoord2f(1, 0);
	glVertex3f(-0.3, -0.5f, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-0.3, -0.5f, width);

	glEnd();
	glDeleteTextures(1, &textures[0]);
	glDisable(GL_TEXTURE_2D);

	if (!isTexture)
	{
		glColor3f(0, 0, 1);
	}
	else glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(-0.2, -0.3, -0.1);
	drawCylinder(0.07, 0.07, 0.4, 30, 30, filename2);
	glPopMatrix();

}

void neck(float width, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0, 0.29, (width / 2) - 0.15);
	glTexCoord2f(1, 1);
	glVertex3f(-0.15, 0.3, width / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-0.15, 0.36, width / 2);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0.35, (width / 2) - 0.15);

	glTexCoord2f(0, 1);
	glVertex3f(0, 0.29, (width / 2) + 0.15);
	glTexCoord2f(1, 1);
	glVertex3f(-0.15, 0.3, width / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-0.15, 0.36, width / 2);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0.35, (width / 2) + 0.15);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.15, 0.36, width / 2);
	glVertex3f(0, 0.35, (width / 2) + 0.15);
	glVertex3f(0, 0.35, (width / 2) - 0.15);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void body(float width, LPCSTR filename1, LPCSTR filename2) {
	bodyUp(width, filename1);
	bodyUpMid(width, filename2);
	if (!isTexture)
	{
		glColor3f(0, 0, 0);
	}
	else glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(-0.245, 0.2, -0.045);
	drawCircle(0.035);
	glTranslatef(0, 0, -0.001);
	drawCircle(0.03);
	glPopMatrix();
	//thruster
	glPushMatrix();
	glTranslatef(-0.25, 0.2, -0.06);
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);
	cylinder(0.05, 0.02, 0.05);
	if (!isTexture)
	{
		glColor3f(0, 0, 0);
	}
	else glColor3f(1, 1, 1);
	drawCylinderLine(0.049, 0.019, 0.049, 7, 2, "weaponHandle.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.245, 0.2, -0.05);
	drawCircle(0.035);
	glTranslatef(0, 0, -0.001);
	drawCircle(0.03);
	glPopMatrix();
	////////////////////////////////////////
	glPushMatrix();
	glTranslatef(0.25, 0.2, -0.075);
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);
	cylinder(0.05, 0.02, 0.05);
	if (!isTexture)
	{
		glColor3f(0, 0, 0);
	}
	else glColor3f(1, 1, 1);
	drawCylinderLine(0.049, 0.019, 0.049, 7, 2, "weaponHandle.bmp");
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -width);
	bodyUp(width, filename1);
	bodyUpMid(width, filename2);
	glPopMatrix();

	bodyMid(width, filename1, filename2);
	bodyRight(width, filename1);

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -width);
	bodyRight(width, filename1);
	glPopMatrix();

	//lowerbody
	glPushMatrix();
	glTranslatef(0, -0.08, 0);
	lowerBody(width, filename1, filename2);

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -width);
	lowerBody(width, filename1, filename2);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-0.2, -0.61, 0.3);
	drawCubeTexture(0.2, 0.15, 0.05, filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.34, -0.61, 0.2);
	glRotatef(90, 0, 1, 0);
	drawCubeTexture(0.2, 0.15, 0.05, filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.05, -0.58, 0.3);
	glRotatef(90, 0, 1, 0);
	drawCubeTexture(0.4, 0.1, 0.1, filename2);
	glPopMatrix();

	//

	neck(width, filename2);

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -0.2);
	neck(width, filename2);
	glPopMatrix();

	thruster(filename1, filename2);

}

void face(float width, LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	//Face 1£º front
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.27, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-0.1, -0.35, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.5f, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.55, 0);

	//Face 2£º right
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.55, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0, -0.55, width);
	glTexCoord2f(1, 0);
	glVertex3f(0, -0.27, width);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.27, 0);


	//Face 3£º top
	glTexCoord2f(0, 1);
	glVertex3f(-0.1, -0.35, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0, -0.27, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0, -0.27, width);
	glTexCoord2f(0, 0);
	glVertex3f(-0.1, -0.35, width);
	//Face 4£º left
	glTexCoord2f(0, 1);
	glVertex3f(-0.1, -0.35, width);
	glTexCoord2f(1, 1);
	glVertex3f(-0.1, -0.35, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.5f, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-0.05, -0.5f, width);


	//Face 5£º behind
	glTexCoord2f(0, 1);
	glVertex3f(-0.05, -0.5f, width);
	glTexCoord2f(1, 1);
	glVertex3f(-0.1, -0.35, width);
	glTexCoord2f(1, 0);
	glVertex3f(0, -0.27, width);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.55, width);

	//Face 6£º bottom
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.55, width);
	glTexCoord2f(1, 1);
	glVertex3f(0, -0.55, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.5f, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-0.05, -0.5f, width);

	glEnd();

	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void mouth(LPCSTR filename) {
	GLuint texture;
	texture = loadTexture(filename);
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-0.015, -0.45, -0.025);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, -0.45, 0.02);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.47, 0.02);
	glTexCoord2f(0, 0);
	glVertex3f(0.01, -0.47, -0.025);
	glEnd();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-0.015, -0.45, 0.025);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, -0.45, -0.04);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.47, -0.04);
	glTexCoord2f(0, 0);
	glVertex3f(0.01, -0.47, 0.025);
	glEnd();
	glPopMatrix();

	//LEFT
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.5, -0.02);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, -0.5, 0.03);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.475, 0.02);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.475, -0.015);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.505, -0.01);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, -0.505, 0.06);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.525, 0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.525, -0.01);
	glEnd();

	//RIGHT
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.5, 0.02);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, -0.5, -0.06);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.475, -0.05);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.475, 0.015);
	glEnd();


	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.505, 0.01);
	glTexCoord2f(1, 1);
	glVertex3f(-0.05, -0.505, -0.07);
	glTexCoord2f(1, 0);
	glVertex3f(-0.05, -0.525, -0.06);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.525, 0.01);
	glEnd();
	glPopMatrix();

	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void head(float width, LPCSTR filename1, LPCSTR filename2) {
	GLuint textures[2];
	textures[0] = loadTexture(filename1);
	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);

	//MASK
	glPushMatrix();
	glTranslatef(0, 0, -0.02);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-0.06, -0.525, 0.025);
	glTexCoord2f(1, 1);
	glVertex3f(-0.095, -0.4, 0.02);
	glTexCoord2f(1, 0);
	glVertex3f(0.03, -0.45, -0.1);
	glTexCoord2f(0, 0);
	glVertex3f(0.03, -0.6, -0.05);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.02);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0.12, -0.525, 0.025);
	glTexCoord2f(1, 1);
	glVertex3f(0.16, -0.4, 0.025);
	glTexCoord2f(1, 0);
	glVertex3f(0.03, -0.45, -0.1);
	glTexCoord2f(0, 0);
	glVertex3f(0.03, -0.6, -0.05);
	glEnd();
	glPopMatrix();

	//head
	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0, 0.01, 0);
	glBegin(GL_TRIANGLES);
	//Face 1£º top
	glTexCoord2f(0, 0.5);
	glVertex3f(-0.1, -0.349, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0.03, -0.23, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.03, -0.4, -0.167);


	glEnd();

	glBegin(GL_TRIANGLES);
	//Face 1£º top
	glTexCoord2f(1, 1);
	glVertex3f(0.03, -0.23, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.03, -0.4, -0.167);
	glTexCoord2f(0, 0.5);
	glVertex3f(0.16, -0.349, 0);

	glEnd();
	glPopMatrix();

	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(0, 0.1, 0);
	glScalef(1.2, 1.2, 1);

	glPushMatrix();
	glTranslatef(0, -0.55, 0);
	drawCube(0.05, 0.28, width);
	glPopMatrix();

	face(width, filename1);
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(-0.05, 0, -width);
	face(width, filename1);
	glPopMatrix();

	glDeleteTextures(1, &textures[0]);
	glDisable(GL_TEXTURE_2D);
	textures[1] = loadTexture(filename2);

	//eye
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(0.03, -0.07, 0.02);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.33, -0.2);
	glTexCoord2f(1, 1);
	glVertex3f(-0.13, -0.28, -0.02);
	glTexCoord2f(1, 0);
	glVertex3f(-0.12, -0.35, -0.02);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.39, -0.15);
	glEnd();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(0, -0.33, 0.2);
	glTexCoord2f(1, 1);
	glVertex3f(-0.13, -0.28, 0.02);
	glTexCoord2f(1, 0);
	glVertex3f(-0.12, -0.35, 0.02);
	glTexCoord2f(0, 0);
	glVertex3f(0, -0.39, 0.15);
	glEnd();
	glPopMatrix();
	glPopMatrix();


	//ear
	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);

	glPushMatrix();
	glRotatef(-20, 0, 0, 1);
	glTranslatef(0.26, -0.35, 0);
	drawCube(0.02, 0.15, 0.05);
	glPopMatrix();

	glPushMatrix();
	glRotatef(20, 0, 0, 1);
	glTranslatef(-0.23, -0.37, 0);
	drawCube(0.02, 0.15, 0.05);
	glPopMatrix();


	//mouth
	glPushMatrix();
	glTranslatef(0.03, -0.01, -0.095);
	mouth(filename2);
	glPopMatrix();

	glPopMatrix();


	glDeleteTextures(1, &textures[1]);
	glDisable(GL_TEXTURE_2D);

}

void headAndBody(LPCSTR filename1, LPCSTR filename2) {
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -0.2);

	glPushMatrix();
	glTranslatef(0, 0.4, 0);
	body(0.2, filename1, filename2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.02, 1.3, 0.05);
	glRotatef(headRotatex, 0, 1, 0);
	glRotatef(headRotatey, 1, 0, 0);
	head(0.1, filename1, filename2);
	glPopMatrix();
	glPopMatrix();
}

//////////////////////////////////////Weapon
void electricDown() {
	GLuint texture;
	texture = loadTexture("electric.bmp");
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.35, -0.2, 0);
	glVertex3f(0.4, -0.25, 0);
	glVertex3f(0.35, -0.3, 0);
	glVertex3f(0.4, -0.35, 0);
	glVertex3f(0.35, -0.4, 0);
	glVertex3f(0.4, -0.45, 0);
	glVertex3f(0.35, -0.5, 0);
	glVertex3f(0.4, -0.55, 0);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void electricUp() {
	GLuint texture;
	texture = loadTexture("electric.bmp");
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.35, -0.5, -0.1);
	glVertex3f(0.3, -0.5, -0.05);
	glVertex3f(0.25, -0.5, -0.1);
	glVertex3f(0.2, -0.5, -0.05);
	glVertex3f(0.15, -0.5, -0.1);
	glVertex3f(0.1, -0.5, 0);
	glVertex3f(0.05, -0.5, 0.05);
	glVertex3f(0, -0.5, 0.1);
	glVertex3f(-0.05, -0.5, 0.05);
	glVertex3f(-0.1, -0.5, 0);
	glVertex3f(-0.15, -0.5, -0.05);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void electricFlash() {
	electricDown();
	glPushMatrix();
	glTranslatef(0, -0.1, 0.1);
	glRotatef(45, 1, 0, 0);
	electricDown();

	glPushMatrix();
	glTranslatef(0, 0, 0.25);
	glRotatef(45, 1, 0, 0);
	electricDown();

	glPushMatrix();
	glTranslatef(0, -0.2, 0);
	glRotatef(45, 1, 0, 0);
	electricDown();

	glPushMatrix();
	glRotatef(45, 1, 0, 0);
	electricDown();

	glPushMatrix();
	glRotatef(45, 1, 0, 0);
	electricDown();

	glPushMatrix();
	glTranslatef(0, 0, 0.2);
	glRotatef(45, 1, 0, 0);
	electricDown();

	glPushMatrix();
	glRotatef(15, 1, 0, 0);
	electricDown();

	glPushMatrix();
	glRotatef(45, 1, 0, 0);
	electricDown();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	/////////////////////////////////////////////////////
	electricUp();
	glPushMatrix();
	glTranslatef(0, 0.1, 0.1);
	glRotatef(45, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, 0, 0.3);
	glRotatef(45, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotatef(90, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, -0.3, 0.5);
	glRotatef(90, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glRotatef(90, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, -0.2, 0.9);
	glRotatef(90, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, -0.5, 0.5);
	glRotatef(90, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, -0.1, 0.5);
	glRotatef(90, 1, 0, 0);
	electricUp();

	glPushMatrix();
	glTranslatef(0, -0.1, 0.5);
	glRotatef(90, 1, 0, 0);
	electricUp();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void weaponAttack() {
	elect += electSp;
	if (elect % 2 == 0) {
		electricFlash();
	}
	if (elect > 100) {
		elect = 0;
	}
	elbowLeft = true;
	shoulderTurnLeft = true;
	if (weaponAttackDown == true) {
		shoulderTurnLeft = false;
		elbowLeft = false;
	}
}

void weapon()
{
	glPushMatrix();
	if (weaponBig == true && weaponSmall == false) {
		if (weaponScale < 1) {
			weaponScale += weaponSp;
			weaponTransUp = 0;
			weaponTransFront = 0;
			weaponScaleSmall = 1;
		}
		glTranslatef(0.6, -1, 0.05);
		glScalef(weaponScale, weaponScale, weaponScale);

		if (weaponAttackMove == true) {
			weaponAttack();
		}
	}
	if (weaponBig == false && weaponSmall == false) {
		glTranslatef(0.4, 0.05, 0.07);
		glScalef(0.2, 0.1, 0.2);
	}
	if (weaponSmall == true) {
		if (weaponScaleSmall > 0) {
			weaponScaleSmall -= weaponSp;
		}
		glTranslatef(0.6, -1, 0.05);
		glScalef(weaponScaleSmall, weaponScaleSmall, weaponScaleSmall);
	}

	/////////////////////////////////////handle
	glPushMatrix();
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.05, 0.05, 1.5, "weaponHandle.bmp");
	glPopMatrix();

	////////////////////////////////////////////////sphere fill handle at back
	glPushMatrix();
	glTranslatef(0, 1.47, 0);
	sphereTexture(0.05, "weaponHandle.bmp");
	glPopMatrix();

	//////////////////////////////////////in front handle
	glPushMatrix();
	glTranslatef(-0.3, -0.2, 0);
	glRotatef(90, 0, 1, 0);
	cylinderTexture(0.2, 0.2, 0.6, "weaponLogo.bmp");
	glPopMatrix();

	//////////////////////////////////////top left in front handle, red color one
	glPushMatrix();
	glTranslatef(-0.3, -0.2, 0);
	glRotatef(90, 0, 1, 0);
	cylinderTexture(0.205, 0.205, 0.15, "weaponLogo.bmp");
	glPopMatrix();

	//////////////////////////////////////top right in front handle
	glPushMatrix();
	glTranslatef(0.15, -0.2, 0);
	glRotatef(90, 0, 1, 0);
	cylinderTexture(0.205, 0.205, 0.15, "weaponLogo.bmp");
	glPopMatrix();

	////////////////////////////////////////////////right side sphere to fill cylinder 
	glPushMatrix();
	glTranslatef(0.3, -0.2, 0);
	glScalef(0.1, 1, 1);
	sphereTexture(0.2, "weapon.bmp");
	glPopMatrix();

	////////////////////////////////////////////////left side sphere to fill cylinder 
	glPushMatrix();
	glTranslatef(-0.3, -0.2, 0);
	glScalef(0.1, 1, 1);
	sphereTexture(0.2, "weapon.bmp");
	glPopMatrix();

	////////////////////////////////////////////////////////connect handle and hammer
	glPushMatrix();
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.07, 0.052, 0.1, "weaponFront.bmp");
	glPopMatrix();
	glPopMatrix();
}

void weaponTrans() {
	glPushMatrix();
	if (weaponTransUp <= 1.1) {
		weaponTransUp += weaponSp;
	}
	glTranslatef(0, -weaponTransUp, 0);

	glPushMatrix();
	if (weaponTransUp > 1.1 && weaponTransFront <= 0.15) {
		weaponTransFront += gunSp;
	}
	glTranslatef(weaponTransFront, 0, 0);

	if (weaponTransFront > 0.15) {
		weaponBig = true;
		weaponShow = false;
		weaponScale = 0;
	}
	weapon();
	glPopMatrix();
	glPopMatrix();
}

//////////////////////////////////////Gun
void gunExplore() {
	glPushMatrix();
	glTranslatef(4, 0, 0);
	sphereTexture(0.3, "fire.bmp");
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void gunShoot() {
	glPushMatrix();
	if (bulletMove < 3) {
		bulletMove += bulletSp;

		if (bulletMove > 2.9)
			gunExplore();
	}
	else
		bulletMove = 0;

	glTranslatef(bulletMove, 0, 0);

	glPushMatrix();
	glTranslatef(0.8, 0.035, 0.05);
	glRotatef(-90, 0, 1, 0);
	cylinderTexture(0.001, 0.023, 0.05, "bullet.bmp");

	glPushMatrix();
	glTranslatef(0, 0, 0.05);
	cylinderTexture(0.023, 0.023, 0.1, "bullet.bmp");
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void gun() {
	if (!isTexture)
	{
		glColor3f(1, 0, 1);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	if (gunBig == true && gunSmall == false) {
		if (gunScale < 1) {
			gunScale += gunSp;
			gunTransUp = 0;
			gunTransFront = 0;
			gunTransNear = 0;
			gunScaleSmall = 1;
		}
		glTranslatef(1, 0.35, 0);
		glScalef(gunScale, gunScale, gunScale);

		if (gunScale > 0.9) {
			fingerRight = true;
			elbowRight = true;
		}

		if (gunShootMove == true)
			gunShoot();
	}
	if (gunBig == false && gunSmall == false) {
		glTranslatef(0.3, 0.1, 0.08);
		glScalef(0.2, 0.2, 0.2);
	}
	if (gunSmall == true) {
		if (gunScaleSmall > 0) {
			gunScaleSmall -= gunSp;
		}
		glTranslatef(1, 0.35, 0);
		glScalef(gunScaleSmall, gunScaleSmall, gunScaleSmall);
		elbowRight = false;
		fingerRight = false;
	}

	//////////////////////////////////////////////////front part
	drawCubeTexture(0.35, 0.2, 0.1, "gunFront.bmp");

	//////////////////////////////////////////////////////hand to hold
	glPushMatrix();
	glRotatef(5, 0, 0, 1);
	glTranslatef(0.4, 0.01, 0.05);
	glScalef(1.3, 0.5, 0.35);
	sphereTexture(0.15, "gunFrFrHandle.bmp");
	glPopMatrix();

	/////////////////////////////////////////////////////down
	glPushMatrix();
	glTranslatef(0.2, -0.03, -0.02);
	drawCubeTexture(0.2, 0.13, 0.13, "gunFrFrHandle.bmp");
	glPopMatrix();

	/////////////////////////////////////////////////////front
	glPushMatrix();
	glTranslatef(0.25, 0.06, -0.005);
	drawCubeTexture(0.3, 0.15, 0.11, "gunFrontUp.bmp");
	glPopMatrix();

	/////////////////////////////////////////////front up
	glPushMatrix();
	glTranslatef(0.55, 0.05, -0.005);
	drawCubeTexture(0.2, 0.15, 0.11, "gunFrontUp.bmp");
	glPopMatrix();

	///////////////////////////////////////front down
	glPushMatrix();
	glTranslatef(0.55, 0.05, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.05, 0.05, 0.17, "gunFrontUp.bmp");
	glPopMatrix();

	/////////////////////////////////////////place back and to shoot
	glPushMatrix();
	glTranslatef(0.65, 0.035, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.025, 0.025, 0.25, "gunAim.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.9, 0.035, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.035, 0.035, 0.1, "gunShoot.bmp");
	glPopMatrix();

	/////////////////////////////////////////place to aim
	glPushMatrix();
	glTranslatef(0.75, 0.15, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.025, 0.025, 0.05, "gunAim.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0.24, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.04, 0.04, 0.03, "gunAim.bmp");
	glPopMatrix();

	///////////////////////////////////body
	glPushMatrix();
	glTranslatef(-0.5, -0.05, 0);
	drawCubeTexture(0.5, 0.2, 0.1, "gunBody.bmp");
	glPopMatrix();

	//////////////////////////////////body down
	glPushMatrix();
	glTranslatef(-0.17, -0.15, 0);
	drawCubeTexture(0.15, 0.1, 0.1, "gunFrHandle.bmp");

	glPushMatrix();
	glTranslatef(0.02, -0.15, 0);
	drawCubeTexture(0.11, 0.15, 0.1, "gunFrHandle.bmp");
	glPopMatrix();
	glPopMatrix();

	////////////////////////////////body up
	glPushMatrix();
	glTranslatef(-0.34, 0.23, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.02, 0.02, 0.3, "gunBodyUp.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.01, 0.135, 0.05);
	glRotatef(30, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.02, 0.02, 0.12, "gunBodyUp.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.44, 0.135, 0.05);
	glRotatef(50, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.02, 0.02, 0.15, "gunBodyUp.bmp");
	glPopMatrix();

	///////////////////////////////handle
	glPushMatrix();
	glTranslatef(-0.4, -0.3, 0.05);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.035, 0.035, 0.3, "gunHandle.bmp");
	glPopMatrix();

	///////////////////////////////////////back
	glPushMatrix();                     //up
	glTranslatef(-0.9, 0.1, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.02, 0.02, 0.4, "gunBodyBack.bmp");
	glPopMatrix();

	glPushMatrix();                     //down
	glTranslatef(-0.7, 0, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.02, 0.02, 0.2, "gunBodyBack.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8, -0.06, 0.05);
	glRotatef(60, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.02, 0.02, 0.13, "gunBodyBack.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.89, -0.06, 0.05);
	glRotatef(90, 0, 0, -1);
	glRotatef(270, 1, 0, 0);
	cylinderTexture(0.02, 0.02, 0.1, "gunBodyBack.bmp");
	glPopMatrix();

	glPushMatrix();      //back
	glTranslatef(-0.93, -0.08, 0.02);
	drawCubeTexture(0.05, 0.2, 0.05, "gunBodyBackBk.bmp");
	glPopMatrix();
	glPopMatrix();
}

void gunTrans() {
	glPushMatrix();
	if (gunTransUp <= 0.3) {
		gunTransUp += gunSp;
	}
	glTranslatef(0, gunTransUp, 0);

	glPushMatrix();
	if (gunTransUp > 0.3 && gunTransFront <= 0.7) {
		gunTransFront += gunSp;
	}
	glTranslatef(gunTransFront, 0, 0);

	glPushMatrix();
	if (gunTransFront > 0.6 && gunTransNear <= 0.1) {
		gunTransNear += gunSp;
	}
	glTranslatef(0, 0, -gunTransNear);

	if (gunTransNear > 0.1) {
		gunBig = true;
		gunShow = false;
		gunScale = 0;
	}
	gun();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

//////////////////////////////////////hand
void shoulder(LPCSTR textBody1) {
	GLuint texture;
	texture = loadTexture(textBody1);

	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	//Face size : Bottom
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.1, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.1, 0.05);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.55, 0.1, 0.05);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.55, 0.1, 0.5);

	//Face 2 : Left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.1, 0.05);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.55, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.55, 0.55);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.1, 0.5);

	//Top
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.55, 0.55);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.55, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.75, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 0.75, 0.55);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.55, 0.7, 0.55);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.55, 0.7, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.4, 0.7, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.4, 0.7, 0.55);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.75, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.75, 0.55);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.4, 0.7, 0.55);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.4, 0.7, 0);

	//Front and Back
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.1, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35, 0.55, 0.75);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.55, 0.55, 0.75);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.55, 0.1, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.35, 0.55, -0.25);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.1, 0.05);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.55, 0.1, 0.05);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.55, 0.55, -0.25);

	//////////////////////////////////////
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.55, 0.55);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35, 0.55, 0.75);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.4, 0.7, 0.55);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.75, 0.55);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.35, 0.55, 0.75);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.4, 0.7, 0.55);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.55, 0.7, 0.55);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.55, 0.55, 0.75);

	///////////////////////////////////////
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.55, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35, 0.55, -0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.4, 0.7, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.75, 0);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.4, 0.7, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35, 0.55, -0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.55, 0.55, -0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.55, 0.7, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//Face 3 : Front
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.2, -0.1, 0.5);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.55, 0.55);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35, 0.55, 0.75);

	//Face 6 : Back
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35, 0.55, -0.25);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.2, -0.1, 0.05);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.55, 0);
	glEnd();

	glBegin(GL_POLYGON);
	//Face 4 : Right
	glTexCoord2f(0.02f, 1.0f);
	glVertex3f(0.55, 0.7, 0.55);
	glTexCoord2f(0.0f, 0.7f);
	glVertex3f(0.55, 0.7, 0);
	glTexCoord2f(0.2f, 0.0f);
	glVertex3f(0.55, 0.55, -0.25);
	glTexCoord2f(0.8f, 0.0f);
	glVertex3f(0.55, 0.1, 0.05);
	glTexCoord2f(1.0f, 0.7f);
	glVertex3f(0.55, 0.1, 0.5);
	glTexCoord2f(0.8f, 1.0f);
	glVertex3f(0.55, 0.55, 0.75);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void upHand(LPCSTR textBody1, LPCSTR textJoin1) {

	if (!isTexture)
	{
		glColor3f(1, 1, 1);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0, 0.025, 0.025);

	glPushMatrix();                         //sphere 1 connect
	glTranslatef(0.1, 0.07, 0.07);
	sphereTexture(0.07, textJoin1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 0, 0);

	glPushMatrix();
	glTranslatef(0.7, 0.15, 0);
	glRotatef(180, 0, 0, 1);

	GLuint texture;
	texture = loadTexture(textJoin1);

	glBegin(GL_TRIANGLES);    //Pyramid connection
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.15, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.075, 0.075);

	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.075, 0.075);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.15, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.15, 0.15);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.15, 0.15);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.075, 0.075);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 0.15);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0.15);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.075, 0.075);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glEnd();

	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();              //Big Quads Arm
	glTranslatef(0.2, 0, 0);
	drawCubeTexture(0.5, 0.15, 0.15, textBody1);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void robotArmDecor1(float point, float point2) {
	if (!isTexture)
	{
		glColor3f(0, 0, 1);
	}
	else glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.03, point);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.1, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0, point2);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.17, point);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.1, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.2, point2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0, 0.1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, point2);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.1, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0, 0.2, point2);
	glEnd();
}

void robotArmDecor2() {
	if (!isTexture)
	{
		glColor3f(0, 0, 1);
	}
	else glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.03, 0.17);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.1, 0.2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 0.3);

	glVertex3f(0, 0.2, 0.2);
	glVertex3f(0.5, 0.17, 0.17);
	glVertex3f(0, 0.1, 0.2);
	glVertex3f(0, 0.2, 0.3);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0.2);
	glVertex3f(0, 0.1, 0.2);
	glVertex3f(0, 0, 0.3);

	glVertex3f(0, 0.2, 0.2);
	glVertex3f(0, 0.1, 0.2);
	glVertex3f(0, 0.2, 0.3);
	glEnd();
}

void robotArm(LPCSTR textBody1, LPCSTR textBody2, LPCSTR textJoin1)
{
	GLuint texture;
	texture = loadTexture(textJoin1);

	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);    //Pyramid on Arm
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.2, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.1, 0.1);

	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.1, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.2, 0.2);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.2, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.1, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0, 0.2);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.1, 0.1, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();         //Big Quads Arm
	texture = loadTexture(textBody1);

	glBegin(GL_QUADS);
	//Face size : Bottom
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.03, 0.17);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.03, 0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);

	//Face 2 : Left
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0, 0.2);

	//Face 3 : Front
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0.2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.17, 0.17);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.03, 0.17);

	//Face 4 : Right
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.03, 0.17);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, 0.03, 0.03);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.17, 0.03);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.17, 0.17);

	//Face 5 : Top
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.17, 0.17);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.2, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.17, 0.03);

	//Face 6 : Back
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.17, 0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.03, 0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.2, 0);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	/////////////////////////////////////decoration
	texture = loadTexture(textBody2);

	glPushMatrix();              //first
	glTranslatef(0, 0, -0.0001);
	robotArmDecor1(0.03, -0.1);
	glPopMatrix();

	glPushMatrix();               //second
	glTranslatef(0, -0.0001, 0);
	glRotatef(90, 1, 0, 0);
	robotArmDecor1(-0.03, 0.1);
	glPopMatrix();

	glPushMatrix();              //third
	glTranslatef(0, 0, 0.0001);
	robotArmDecor2();
	glPopMatrix();

	glPushMatrix();               //fourth
	glTranslatef(0, 0.0001, 0.2);
	glRotatef(-90, 1, 0, 0);
	robotArmDecor2();
	glPopMatrix();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void palm(LPCSTR textBody1) {
	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.5, 0, 0.1);
	drawCubeTexture(0.15, 0.2, 0.05, textBody1);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void thumb(LPCSTR textBody2) {
	if (!isTexture)
	{
		glColor3f(1, 1, 1);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.5, 0.19, 0.1);
	drawCubeTexture(0.05, 0.06, 0.05, textBody2);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void robotFinger(LPCSTR textBody2)
{
	if (!isTexture)
	{
		glColor3f(1, 1, 1);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();                     //finger connector
	glTranslatef(0.636, 0.025, 0.12);
	sphereTexture(0.02, textBody2);                       //first

	glPushMatrix();
	glTranslatef(0, 0.05, 0);
	sphereTexture(0.02, textBody2);

	glPushMatrix();
	glTranslatef(0, 0.05, 0);
	sphereTexture(0.02, textBody2);

	glPushMatrix();
	glTranslatef(0, 0.05, 0);
	sphereTexture(0.02, textBody2);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();                        //first
	glTranslatef(0.65, 0.05, 0.1);
	glRotatef(-90, 0, 0, 1);
	glScalef(0.1, 0.1, 0.1);
	drawCubeTexture(0.5, 0.7, 0.5, textBody2);

	glPushMatrix();	                       //second
	glTranslatef(-0.5, 0, 0);
	drawCubeTexture(0.5, 0.7, 0.5, textBody2);

	glPushMatrix();	                       //third
	glTranslatef(-0.5, 0, 0);
	drawCubeTexture(0.5, 0.7, 0.5, textBody2);

	glPushMatrix();	                       //fourth
	glTranslatef(-0.5, 0, 0);
	drawCubeTexture(0.5, 0.7, 0.5, textBody2);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void leftHand() {
	glPushMatrix();               //rotate shoulder up
	if (shoulderTurnLeft == true) {
		if (actShoulderLeft < 90) {
			actShoulderLeft += rotatfinger;
		}
		glTranslatef(-0.6, 0.13, 0);
		glRotatef(actShoulderLeft, 0, 0, -1);
		glTranslatef(0.6, -0.13, 0);
		if (actShoulderLeft > 80) {
			weaponAttackDown = true;
		}
	}
	else if (shoulderTurnLeft == false) {
		if (actShoulderLeft > 0) {
			actShoulderLeft -= rotatfinger;
		}
		glTranslatef(-0.6, 0.13, 0);
		glRotatef(actShoulderLeft, 0, 0, -1);
		glTranslatef(0.6, -0.13, 0);
	}

	glPushMatrix();
	glTranslatef(-0.6, 0.1, -0.05);
	glScalef(0.7, 0.7, 1);
	sphereTexture(0.1, jointText[changeJoint1]);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75, -0.045, 0.32);//0.225);

	glRotatef(-90, 1, 0, 0);
	glScalef(0.5, 0.5, 0.5);

	shoulder(bodyText[changeBody1]);                     //shoulder
	glPopMatrix();

	upHand(bodyText[changeBody1], jointText[changeJoint1]);      //UpHand

	glPushMatrix();                                  //rotate elbow up
	if (elbowLeft == true) {
		if (actRotateElbowLeft > -90) {
			actRotateElbowLeft -= rotatfinger;
		}
		glRotatef(actRotateElbowLeft, 0, 0, 1);
	}
	else if (elbowLeft == false) {
		if (actRotateElbowLeft < 0) {
			actRotateElbowLeft += rotatfinger;
		}
		glRotatef(actRotateElbowLeft, 0, 0, 1);
	}

	if (weaponShow == true)                           ///////Weapon
		weaponTrans();

	if (weaponBig == true || weaponSmall == true) {
		weapon();
		if (weaponBig == true)
			fingerLeft = true;
		if (weaponSmall == true)
			fingerLeft = false;
	}

	robotArm(bodyText[changeBody1], bodyText[changeBody2], jointText[changeJoint1]);                   //arm

	glPushMatrix();
	glTranslatef(0, 0.02, 0);
	glScalef(1, 0.8, 1);
	palm(bodyText[changeBody1]);             //palm
	glPopMatrix();

	glPushMatrix();                        //left thumb connector
	glTranslatef(0.525, 0.01, 0.12);
	sphereTexture(0.02, jointText[changeJoint1]);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.02, 0);
	glScalef(1, 0.8, 1);
	if (fingerLeft == true) {
		if (actRotatThumbLeft <= 90) {                     //rotate thumb
			actRotatThumbLeft += rotatThumb;
		}
		glTranslatef(0, 0, 0.1);
		glRotatef(actRotatThumbLeft, 1, 0, 0);
		glTranslatef(0, 0, -0.1);
	}
	else if (fingerLeft == false) {
		if (actRotatThumbLeft > 0) {                    //rotate thumb
			actRotatThumbLeft -= rotatThumb;
		}
		glTranslatef(0, 0, 0.1);
		glRotatef(actRotatThumbLeft, 1, 0, 0);
		glTranslatef(0, 0, -0.1);
	}

	glTranslatef(0, -0.25, 0);

	thumb(bodyText[changeBody2]);                 //thumb
	glPopMatrix();
	/////////////////////////////////////////////////////////
	glPushMatrix();                     //first finger
	glTranslatef(0, 0.02, 0);
	glScalef(1, 0.8, 1);

	if (fingerLeft == true) {
		if (actRotatFingLeft <= 80) {           //rotate finger1
			actRotatFingLeft += rotatfinger;
		}

		glTranslatef(0.65, 0, 0.1);
		glRotatef(actRotatFingLeft, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.1);
	}
	else if (fingerLeft == false) {
		if (actRotatFingLeft > 0) {           //rotate finger1
			actRotatFingLeft -= rotatfinger;
		}

		glTranslatef(0.65, 0, 0.1);
		glRotatef(actRotatFingLeft, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.1);
	}
	robotFinger(bodyText[changeBody2]);

	/////////////////////////
	glPushMatrix();
	glTranslatef(0.05, 0, 0);

	if (fingerLeft == true) {
		if (actRotatFing2Left <= 45) {           //rotate finger2
			actRotatFing2Left += rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing2Left, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}
	else if (fingerLeft == false) {
		if (actRotatFing2Left > 0) {           //rotate finger2
			actRotatFing2Left -= rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing2Left, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}

	robotFinger(bodyText[changeBody2]);
	/////////////////////////////////////
	glPushMatrix();
	glTranslatef(0.05, 0, 0);

	if (fingerLeft == true) {
		if (actRotatFing3Left <= 60) {           //rotate finger3
			actRotatFing3Left += rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing3Left, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}
	else if (fingerLeft == false) {
		if (actRotatFing3Left > 0) {           //rotate finger3
			actRotatFing3Left -= rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing3Left, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}

	robotFinger(bodyText[changeBody2]);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void rightHand() {
	glPushMatrix();               //rotate shoulder up
	if (shoulderTurnRight == true) {
		if (actShoulderRight > -90) {
			actShoulderRight -= rotatfinger;
		}
		glTranslatef(-0.6, 0.11, 0);
		glRotatef(actShoulderRight, 0, 0, -1);
		glTranslatef(0.6, -0.11, 0);
	}
	else if (shoulderTurnRight == false) {
		if (actShoulderRight < 0) {
			actShoulderRight += rotatfinger;
		}
		glTranslatef(-0.6, 0.11, 0);
		glRotatef(actShoulderRight, 0, 0, -1);
		glTranslatef(0.6, -0.11, 0);
	}

	glPushMatrix();                 //connect shoulder and body
	glTranslatef(-0.6, 0.1, -0.05);
	glScalef(0.7, 0.7, 1);
	sphereTexture(0.1, jointText[changeJoint1]);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75, -0.01, 0.32);
	glRotatef(-90, 1, 0, 0);

	glScalef(0.5, 0.5, 0.5);

	shoulder(bodyText[changeBody1]);       //shoulder
	glPopMatrix();

	upHand(bodyText[changeBody1], jointText[changeJoint1]);

	glPushMatrix();               //rotate elbow up
	if (elbowRight == true) {
		if (actRotateElbowRight < 90) {
			actRotateElbowRight += rotatfinger;
		}

		glTranslatef(0, 0.2, 0);
		glRotatef(actRotateElbowRight, 0, 0, 1);
		glTranslatef(0, -0.2, 0);
	}
	else if (elbowRight == false) {
		if (actRotateElbowRight > 0) {
			actRotateElbowRight -= rotatfinger;
		}

		glTranslatef(0, 0.2, 0);
		glRotatef(actRotateElbowRight, 0, 0, 1);
		glTranslatef(0, -0.2, 0);
	}

	if (gunShow == true) {                               //Gun Show
		if (fingerRight == true)
			fingerRight = false;

		gunTrans();
	}

	if (gunBig == true || gunSmall == true) {
		gun();
		if (gunSmall == true)
			fingerRight = false;
	}

	robotArm(bodyText[changeBody1], bodyText[changeBody2], jointText[changeJoint1]);    //arm

	glPushMatrix();
	glTranslatef(0, 0.02, 0);
	glScalef(1, 0.8, 1);
	palm(bodyText[changeBody1]);      //palm
	glPopMatrix();

	glPushMatrix();                        // thumb connector
	glTranslatef(0.525, 0.19, 0.12);
	sphereTexture(0.02, bodyText[changeBody2]);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	if (fingerRight == true) {
		if (actRotatThumbRight >= -90) {           //rotate thumb
			actRotatThumbRight -= rotatThumb;
		}

		glTranslatef(0, 0.18, 0.1);
		glRotatef(actRotatThumbRight, 1, 0, 0);
		glTranslatef(0, -0.18, -0.1);
	}
	else if (fingerRight == false) {
		if (actRotatThumbRight < 0) {           //rotate thumb
			actRotatThumbRight += rotatThumb;
		}

		glTranslatef(0, 0.18, 0.1);
		glRotatef(actRotatThumbRight, 1, 0, 0);
		glTranslatef(0, -0.18, -0.1);
	}
	glTranslatef(0, -0.01, 0);

	thumb(bodyText[changeBody2]);            //thumb
	glPopMatrix();
	///////////////////////////////////////
	glPushMatrix();                     //first finger
	glTranslatef(0, 0.02, 0);
	glScalef(1, 0.8, 1);

	if (fingerRight == true) {
		if (actRotatFingRight <= 80) {           //rotate finger1
			actRotatFingRight += rotatfinger;
		}

		glTranslatef(0.65, 0, 0.1);
		glRotatef(actRotatFingRight, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.1);
	}
	else if (fingerRight == false) {
		if (actRotatFingRight > 0) {           //rotate finger1
			actRotatFingRight -= rotatfinger;
		}

		glTranslatef(0.65, 0, 0.1);
		glRotatef(actRotatFingRight, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.1);
	}

	robotFinger(bodyText[changeBody2]);

	/////////////////////////
	glPushMatrix();
	glTranslatef(0.05, 0, 0);

	if (fingerRight == true) {
		if (actRotatFing2Right <= 45) {           //rotate finger2
			actRotatFing2Right += rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing2Right, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}
	else if (fingerRight == false) {
		if (actRotatFing2Right > 0) {           //rotate finger2
			actRotatFing2Right -= rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing2Right, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}

	robotFinger(bodyText[changeBody2]);
	/////////////////////////////////////
	glPushMatrix();
	glTranslatef(0.05, 0, 0);

	if (fingerRight == true) {
		if (actRotatFing3Right <= 60) {           //rotate finger3
			actRotatFing3Right += rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing3Right, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}
	else if (fingerRight == false) {
		if (actRotatFing3Right > 0) {           //rotate finger3
			actRotatFing3Right -= rotatfinger;
		}

		glTranslatef(0.65, 0, 0.09);
		glRotatef(actRotatFing3Right, 0, 1, 0);
		glTranslatef(-0.65, 0, -0.09);
	}

	robotFinger(bodyText[changeBody2]);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void hand() {
	glPushMatrix();
	glTranslatef(0, 0.15, 0);
	glScalef(1, 0.8, 1);

	glPushMatrix();
	glTranslatef(0.5, 0, 0.22);  //can change
	glRotatef(-90, 0, 0, 1);  //cannot
	glRotatef(-90, 1, 0, 0);  //cannot

	leftHand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, -0.02);  //can change
	glRotatef(-90, 0, 0, 1);   //cannot
	glRotatef(90, 1, 0, 0);    //cannot

	rightHand();
	glPopMatrix();
	glPopMatrix();
}

///////////////////////////////////////////////Leg
void sharpCorner(LPCSTR textBody2) {
	if (!isTexture)
	{
		glColor3f(0, 0, 1);
	}
	else glColor3f(1, 1, 1);
	GLuint texture;
	texture = loadTexture(textBody2);

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, 0.1, -0.002);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.075, 0.3, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.3, -0.002);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, 0.3, -0.002);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.075, 0.3, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.3, -0.002);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.3, -0.002);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.075, 0.3, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.1, -0.002);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.1, -0.002);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.075, 0.3, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.1, -0.002);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
}

void upLeg(LPCSTR textBody1, LPCSTR textBody2) {
	if (!isTexture)
	{
		glColor3f(1, 1, 1);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	glScalef(0.5, 0.6, 0.3);
	drawCubeTexture(0.5, 1, 0.5, textBody1);

	GLuint texture;
	texture = loadTexture("metal porcealin.bmp");

	glPushMatrix();
	glTranslatef(0.075, 0.4, 0.5);

	glBegin(GL_QUADS);                  //up leg back
	//Face 2 : Left
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.5, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 0.4, 0.4);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0.25, 0.4);

	//Face 3 : Front                 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.4, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.25, 0.4);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35, 0.25, 0.4);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35, 0.4, 0.4);

	//Face 4 : Right
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.35, 0.25, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35, 0, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35, 0.5, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35, 0.4, 0.4);

	//Face 5 : Top                     
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.35, 0.4, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0, 0.4, 0.4);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 0.5, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35, 0.5, 0);

	//Face 6 : Bottom
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.25, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35, 0.25, 0.4);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35, 0, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glEnd();
	glPopMatrix();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

	texture = loadTexture(textBody2);

	glBegin(GL_QUADS);                //decoration
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0, -0.001);  //front
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 1, -0.001);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 1, -0.001);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, 0, -0.001);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.35, 0, -0.001);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35, 1, -0.001);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 1, -0.001);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0, -0.001);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.501, 1, 0);       //right
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.501, 1, 0.15);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.501, 0, 0.15);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.501, 0, 0);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.501, 1, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.501, 1, 0.35);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.501, 0, 0.35);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.501, 0, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.001, 1, 0);       //left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.001, 1, 0.15);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.001, 0, 0.15);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.001, 0, 0);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.001, 1, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.001, 1, 0.35);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.001, 0, 0.35);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.001, 0, 0.5);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

	sharpCorner(textBody1);                         //right sharp corner

	glPushMatrix();
	glTranslatef(0, 0.3, 0);
	sharpCorner(textBody1);

	glPushMatrix();
	glTranslatef(0, 0.3, 0);
	sharpCorner(textBody1);

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();           //left sharp corner
	glTranslatef(0.34, 0, 0);
	sharpCorner(textBody1);

	glPushMatrix();
	glTranslatef(0, 0.3, 0);
	sharpCorner(textBody1);

	glPushMatrix();
	glTranslatef(0, 0.3, 0);
	sharpCorner(textBody1);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();                  //up leg back Thruster
	glTranslatef(0.13, 0.3, 0.2);
	glRotatef(35, 1, 0, 0);

	turbo(jointText[changeBody1]);
	glPopMatrix();
}

void leftUpLeg(LPCSTR textBody1, LPCSTR textBody2, LPCSTR textJoin1)
{
	glPushMatrix();
	glTranslatef(0.4, 0.73, 0.08);
	glScalef(0.7, 1, 0.7);
	sphereTexture(0.1, textJoin1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.27, 0.1, 0);
	upLeg(textBody1, textBody2);
	glPopMatrix();
}

void rightUpLeg(LPCSTR textBody1, LPCSTR textBody2, LPCSTR textJoin1)
{
	glPushMatrix();
	glTranslatef(-0.4, 0.73, 0.08);
	glScalef(0.7, 1, 0.7);
	sphereTexture(0.1, textJoin1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.53, 0.1, 0);
	upLeg(textBody1, textBody2);
	glPopMatrix();
}

void downLeg(LPCSTR textBody1, LPCSTR textBody2, LPCSTR textJoin1) {
	if (!isTexture)
	{
		glColor3f(1, 0, 0);
	}
	else glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0, 0.3, -0.13);
	glRotatef(60, 1, 0, 0);
	cylinderTexture(0.001, 0.05, 0.2, "metal porcealin.bmp");
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1, 0.2, 0.1);    //become smaller

	glPushMatrix();            //knee
	glTranslatef(0, 0.55, 0.45);
	glScalef(1, 0.2, 1);
	sphereTexture(1.2, "metal porcealin.bmp");
	glPopMatrix();

	GLuint texture;
	texture = loadTexture(textJoin1);

	glBegin(GL_QUADS);          //top
	glTexCoord2f(0.0f, 0.0f);        //back
	glVertex3f(0, 0.6, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 1.6, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1, 1, 1);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0.6, 0);        //front
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 1, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 1.6, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 1, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 1.6, 1);         //right
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 0.6, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 1, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 1.6, 1);         //left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, 1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 0.6, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 1, 0.5);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

	texture = loadTexture(textBody1);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);     //right
	glVertex3f(0, 0.6, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, 1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1, -1, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, -0.6, 0);

	glTexCoord2f(0.0f, 0.0f);     //left
	glVertex3f(0, 0.6, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, 1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1, -1, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0, -0.6, 0);

	glTexCoord2f(0.0f, 0.0f);     //back
	glVertex3f(1, 1, 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, -2, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1, -2, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1, 1, 1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.5f, 1.0f);       //down
	glVertex3f(0, -0.6, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1, -1, 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, -1, 1);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

	texture = loadTexture(textBody1);
	glBegin(GL_QUADS);          //ankle
	glTexCoord2f(0.0f, 0.0f);     //front
	glVertex3f(-0.5, -0.8, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.8, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -1.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -1.5, 0.5);

	glTexCoord2f(0.0f, 0.0f);       //right
	glVertex3f(0.5, -0.8, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, -1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1, -1.5, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -1.5, 0.5);

	glTexCoord2f(0.0f, 0.0f);       //left
	glVertex3f(-0.5, -0.8, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, -1, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1, -1.5, 1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -1.5, 0.5);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

	if (!isTexture)
	{
		glColor3f(1, 1, 0);
	}
	else glColor3f(1, 1, 1);
	texture = loadTexture(textBody2);
	glBegin(GL_TRIANGLES);        //shoe      
	glTexCoord2f(0.5f, 1.0f);       //up
	glVertex3f(0, -2, -2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -1.5, 0.5);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -1.5, 0.5);

	glTexCoord2f(0.0f, 0.0f);         //down
	glVertex3f(1, -2, 1);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0, -2, -2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, -2, 1);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);         //right 
	glVertex3f(1, -1.5, 1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1, -2, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, -2, -2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -1.5, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1, -1.5, 1);   //left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1, -2, 1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, -2, -2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -1.5, 0.5);
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void leftDownLeg(LPCSTR textBody1, LPCSTR textBody2, LPCSTR textJoin1)
{
	glPushMatrix();
	glTranslatef(0.4, -0.05, 0);    //right leg translate to right
	downLeg(textBody1, textBody2, textJoin1);
	glPopMatrix();
}

void rightDownLeg(LPCSTR textBody1, LPCSTR textBody2, LPCSTR textJoin1)
{
	glPushMatrix();
	glTranslatef(-0.4, -0.05, 0);    //right leg translate to right
	downLeg(textBody1, textBody2, textJoin1);
	glPopMatrix();
}

void leg() {
	if (walkUpLeftKnee > 20 && walkLeftKnee > 0.18) {          //walking
		walkLeft = false;
		walkRight = true;
	}
	else if (walkUpRightKnee > 20 && walkRightKnee > 0.18) {
		walkRight = false;
		walkLeft = true;
	}

	glPushMatrix();
	glTranslatef(0, -0.9, 0.2);
	glRotatef(180, 0, 1, 0);
	glScalef(0.8, 1, 1);

	glPushMatrix();                         //move whole left leg
	if (legMoveFront == true && legMoveX < 20) {        //move front
		legMoveX += legMoveSp;
	}
	else if (legMoveBack == true && legMoveX > -20) {     //move back
		legMoveX -= legMoveSp;
	}
	else if (legMoveLeft == true && legMoveY > -5) {        //move left
		legMoveY -= legMoveSp;
	}
	else if (legMoveRight == true && legMoveY < 5) {        //move left
		legMoveY += legMoveSp;
	}

	glTranslatef(0, 0.6, 0);                                //Rotate whole leg
	glRotatef(legMoveX, 1, 0, 0);
	glRotatef(-legMoveY, 0, 0, 1);
	glTranslatef(0, -0.6, 0);
	//////////////////////////////////////////////Left Leg
	glPushMatrix();
	glTranslatef(-0.2, 0, 0);

	glPushMatrix();
	if (walkLeft == true) {                 //move Left up leg
		if (walkUpLeftKnee < 30) {
			walkUpLeftKnee += walkSpeed;
		}
		glTranslatef(0, 0.6, 0);
		glRotatef(walkUpLeftKnee, 1, 0, 0);
		glTranslatef(0, -0.6, 0);
	}
	else if (walkLeft == false) {
		if (walkUpLeftKnee > 0) {
			walkUpLeftKnee -= walkSpeed;
		}
		glTranslatef(0, 0.6, 0);
		glRotatef(walkUpLeftKnee, 1, 0, 0);
		glTranslatef(0, -0.6, 0);
	}
	leftUpLeg(bodyText[changeBody1], bodyText[changeBody2], jointText[changeJoint1]);
	glPopMatrix();

	glPushMatrix();
	if (walkLeft == true) {                   //move Left down leg
		if (walkLeftKnee < 0.3) {
			walkLeftKnee += walkKneeSpeed;
		}
		glTranslatef(0, walkLeftKnee / 8, -walkLeftKnee);
	}
	else if (walkLeft == false) {
		if (walkLeftKnee > 0) {
			walkLeftKnee -= walkKneeSpeed;
		}
		glTranslatef(0, walkLeftKnee / 8, -walkLeftKnee);
	}

	leftDownLeg(bodyText[changeBody1], bodyText[changeBody2], jointText[changeJoint1]);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//////////////////////////////////////////////////////////////////////////////////Right Leg
	glPushMatrix();
	glTranslatef(0.2, 0, 0);

	glPushMatrix();                         //move whole right leg
	glTranslatef(0, 0.6, 0);                //translate x and z
	glRotatef(legMoveX, 1, 0, 0);
	glRotatef(-legMoveY, 0, 0, 1);
	glTranslatef(0, -0.6, 0);

	glPushMatrix();                  //move Right up leg
	if (walkRight == true) {
		if (walkUpRightKnee < 30) {
			walkUpRightKnee += walkSpeed;
		}
		glTranslatef(0, 0.6, 0);
		glRotatef(walkUpRightKnee, 1, 0, 0);
		glTranslatef(0, -0.6, 0);
	}
	else if (walkRight == false) {
		if (walkUpRightKnee > 0) {
			walkUpRightKnee -= walkSpeed;
		}
		glTranslatef(0, 0.6, 0);
		glRotatef(walkUpRightKnee, 1, 0, 0);
		glTranslatef(0, -0.6, 0);
	}

	rightUpLeg(bodyText[changeBody1], bodyText[changeBody2], jointText[changeJoint1]);
	glPopMatrix();

	glPushMatrix();
	if (walkRight == true) {                   //move Right down leg
		if (walkRightKnee < 0.3) {
			walkRightKnee += walkKneeSpeed;
		}
	}
	else if (walkRight == false) {
		if (walkRightKnee > 0) {
			walkRightKnee -= walkKneeSpeed;
		}
	}
	glTranslatef(0, walkRightKnee / 8, -walkRightKnee);

	rightDownLeg(bodyText[changeBody1], bodyText[changeBody2], jointText[changeJoint1]);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void robotWalking() {
	if (walkRight == true || walkLeft == true) {   //walking
		if (walking < 1)
			walking += walkingSp;
		else if (walking > 1) {
			walkRight = false;
			walkLeft = false;
		}
	}
	if (isOrtho)
		glTranslatef(0, 0, walking);
	else if (!isOrtho)
		glTranslatef(0, 0, -walking);
}

void flying() {
	glTranslatef(flyingX, flyingY, 0);
	glTranslatef(0, 0, slideMove);
	glRotatef(sliding, 1, 0, 0);
}

/////////////////////////////////////////Projection
void backGround() {
	if (!isTexture)
	{
		glColor3f(0, 0, 0);
	}
	glPushMatrix();
	glTranslatef(0, 0, -0.5);
	sphereTexture(2, "sky.bmp");
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void projection() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glTranslatef(tx, ty, 0);

	if (isOrtho) {
		glOrtho(-1, 1, -1, 1, -1, 10);
		glRotatef(Ry, 0, 1, 0);

		backGround();
	}
	else {
		gluPerspective(40, 1, -1, 1);
		glFrustum(-1, 1, -1, 1, 1, 3);
		glDisable(GL_DEPTH_TEST);

		backGround();
		glEnable(GL_DEPTH_TEST);
	}
}

void lighting() {
	//Light 0 - white color ambient light
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);

	//glLightfv(GL_LIGHT1, GL_DIFFUSE, amb);
	//glLightfv(GL_LIGHT1, GL_POSITION, posD);
	//glEnable(GL_LIGHT1);

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
	glColor3f(1, 0, 0);
	sphere(0.1);
	glPopMatrix();

	if (isLightOn) {
		glEnable(GL_LIGHTING);
	}
	else {
		glDisable(GL_LIGHTING);
	}
}

void display()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	projection();                           //projection
	lighting();                             //lighting

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, tz);                  //translate z axis
	if (!isOrtho)
		glRotatef(-Ry, 0, 1, 0);             //rotate the object if perspective

	//////////////////////////////////////////////////////
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);

	robotWalking();                            //walking
	flying();                                  //flying
	headAndBody(bodyText[changeBody1], jointText[changeBody1]);
	hand();
	leg();
	glPopMatrix();
	if (sliding == 30) {
		isTurbo = false;
		for (int i = 0; i < sliding; sliding--)
			sliding -= 0.01;
	}
	else if (sliding == -30) {
		isTurbo = false;
		for (int i = 0; i > sliding; sliding++)
			sliding += 0.01;
	}
}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,        //WS = window style
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------