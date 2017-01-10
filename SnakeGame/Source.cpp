#include <stdlib.h>
#include "windows.h"
#include "menu.h"
#include  <GL/glut.h>
#include "stdio.h"


#include "utils.h"
using namespace std;

using namespace GraphUtils;
int t = 60;
const int N = 32, M = 32;
int l;
int tt;
float z = 1;
int key;
static bool paused = false;

float mouseX, mouseY;
float angleX = 0, angleY = 0;
int Scale = 25;
float x, y;
int time = 0;
int ms;
int i, button;
int w = 1024;//Scale*N;
int h = 768;//Scale*M;
bool finish = false;
int dir, num = 2;
int arrBoard[M][N] = {
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2 },
	{ 2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2 },
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
};
struct
{
	int x;
	int y;
}  s[150];

void initialize()
{
	t = 60;
	const int N = 32, M = 32;
	l;
	z = 1;
	mouseX, mouseY;
	angleX = 0, angleY = 0;
	Scale = 25;
	time = 0;
	s[i].x = 10;
	s[i].y = 10;

	x, y;
	i, button;
	w = 1024;//Scale*N;
	h = 768;//Scale*M;
	finish = false;
	dir, num = 2;
	Sleep(ms);
}

class Fruits
{
public:
	int x, y;

	void New()
	{
		x = rand() % (N - 2);
		y = rand() % (M - 2);
	}

	void DrawApple()
	{
		/*glColor3f(0.0,1.0,0.0);
		glRectf(x*Scale,y*Scale,(x+1)*Scale,(y+1)*Scale);*/
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambiRed);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffRed);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specRed);
		glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
		// Writing the current matrix into stack:
		glPushMatrix();
		glTranslatef((m[i].x), (m[i].y), z);
		glutSolidCube(1.0f);
		glPopMatrix();
	}

} m[10];

void on_mouse(int _button, int state, int x, int y)
{
	// Save the current mouse coordinates:
	mouseX = x;
	mouseY = y;
	if ((state == GLUT_UP)) // button up
	{
		button = -1;  // no button is pressed
		return;
	}
	button = _button; // store information about the buttons
	if (finish)
		return;
}
class Fruits2
{
public:
	int x, y;
	void New()
	{
		x = rand() % (N - 2);
		y = rand() % (M - 2);
	}
	void DrawApple()
	{
		for (int i = 0; i < 10; i++) {
			/*glColor3f(0.0,1.0,0.0);
			glRectf(x*Scale,y*Scale,(x+1)*Scale,(y+1)*Scale);*/
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambiOrange);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffOrange);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specOrange);
			glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
			// Writing the current matrix into stack:
			glPushMatrix();
			glTranslatef((m[i].x), (m[i].y), z);
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}
} m2[10];
class Fruits3
{
public:
	int x, y;
	void New()
	{
		x = rand() % (N - 2);
		y = rand() % (M - 2);
	}
	void DrawApple()
	{
		for (int i = 0; i < 10; i++) {
			/*glColor3f(0.0,1.0,0.0);
			glRectf(x*Scale,y*Scale,(x+1)*Scale,(y+1)*Scale);*/
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambiViolet);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffViolet);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specViolet);
			glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
			// Writing the current matrix into stack:
			glPushMatrix();
			glTranslatef((m[i].x), (m[i].y), z);
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}
} m3[10];
class Fruits4
{
public:
	int x, y;
	void New()
	{
		x = rand() % (N - 2);
		y = rand() % (M - 2);
	}
	void DrawApple()
	{
		for (int i = 0; i < 10; i++) {
			/*glColor3f(0.0,1.0,0.0);
			glRectf(x*Scale,y*Scale,(x+1)*Scale,(y+1)*Scale);*/
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambiYellow);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffYellow);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specYellow);
			glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
			// Writing the current matrix into stack:
			glPushMatrix();
			glTranslatef((m[i].x), (m[i].y), z);
			glutSolidCube(1.0f);
			glPopMatrix();
		}
	}
} m4[10];
void DrawSnake()
{
	/* glColor3f(0.0,0.0,1.0);*/
	for (int i = 1; i < 2; i++)
	{/*glRectf(s[i].x*Scale, s[i].y*Scale, (s[i].x+0.9)*Scale, (s[i].y+0.9)*Scale);*/
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambiWhite);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffWhite);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
		// Writing the current matrix into stack:
		glPushMatrix();
		glTranslatef((s[i].x), (s[i].y), z);
		glutSolidCube(1.0f);
		glPopMatrix();
	}
	for (int i = 1; i < num; i++)
	{/*glRectf(s[i].x*Scale, s[i].y*Scale, (s[i].x+0.9)*Scale, (s[i].y+0.9)*Scale);*/
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambiWhiteh);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffWhiteh);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specWhiteh);
		glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
		// Writing the current matrix into stack:
		glPushMatrix();
		glTranslatef((s[i].x), (s[i].y), z);
		glutSolidCube(0.5f);
		glPopMatrix();
	}
}


void Tick()
{
	for (int i = num; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	if (dir == 0) s[0].y += 1;
	if (dir == 1) s[0].x -= 1;
	if (dir == 2) s[0].x += 1;
	if (dir == 3) s[0].y -= 1;

	for (int i = 0; i < 10; i++) {
		if ((s[0].x == m[i].x) && (s[0].y == m[i].y))
		{
			num++; m[i].New();
		}
		else if ((s[0].x == m2[i].x) && (s[0].y == m2[i].y))
		{
			num++; m2[i].New();
		}
		else  if ((s[0].x == m3[i].x) && (s[0].y == m3[i].y))
		{
			num += 2; m3[i].New();
		}
		else  if ((s[0].x == m3[i].x) && (s[0].y == m3[i].y))
		{
			num += 3; m4[i].New();
		}

		if (s[0].x >= N - 1) dir = 1;
		if (s[0].x <= 0) dir = 2;
		if (s[0].y >= M - 1) dir = 3;
		if (s[0].y <= 0) dir = 0;
	}

	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y)  num = i;
}

void DrawField()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arrBoard[i][j] == 1)
			{
				glMaterialfv(GL_FRONT, GL_AMBIENT, ambiGreen);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffGreen);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specGreen);
				glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
				// Writing the current matrix into stack:
				glPushMatrix();
				glTranslatef(i, j, z - 0.5);
				GraphUtils::boardUnit(1, 1, 0.1);
				// Recovery the current matrix from stack:
				glPopMatrix();
			}
			if (arrBoard[i][j] == 0)
			{
				glMaterialfv(GL_FRONT, GL_AMBIENT, ambiGreen);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffGreen);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specGreen);
				glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
				// Writing the current matrix into stack:
				glPushMatrix();
				glTranslatef(i, j, z - 0.5);
				GraphUtils::boardUnit(1, 1, 0.1);
				// Recovery the current matrix from stack:
				glPopMatrix();
			}
			if (arrBoard[i][j] == 2)
			{
				glMaterialfv(GL_FRONT, GL_AMBIENT, ambiOrange);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffYellow);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specOrange);
				glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
				// Writing the current matrix into stack:
				glPushMatrix();
				glTranslatef(i, j, z);
				GraphUtils::boardUnit(1, 1, 1.0);
				// Recovery the current matrix from stack:
				glPopMatrix();
			}
		}
	}
}
void display() {

	char text[128]; // An array of characters. Fill this array according to the state of game
	if (finish)
		sprintf_s(text, "You Won. Time: %d   F2 - Restart game   Esc - Exit", time);
	else  if (l == 1)
		sprintf_s(text, "F2 - Restart game   Esc - Exit    Level   1          Time: %d", time);
	else  if (l == 2)
		sprintf_s(text, "F2 - Restart game   Esc - Exit    Level   2          Time: %d", time);
	else  if (l == 3)
		sprintf_s(text, "F2 - Restart game   Esc - Exit    Level   3          Time: %d", time);
	else  if (l == 4)
		sprintf_s(text, "F2 - Restart game   Esc - Exit    Level   4          Time: %d", time);
	else
		sprintf_s(text, "F2 - Restart game   Esc - Exit                 Time: %d", time);
	// Set the viewing area so that it is able to contain the entire window:
	glViewport(0, 0, w, h);

	// Initialize light source parameters:
	float lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // color of ambient light
	float lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // color of diffuse light 
	float lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };// color of specular light
	float lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };// position of light source

	// Set light source parameters:
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	// Specify clear values for the color buffers:
	glClearColor(0.1, 0.2, 1, 0);
	// Clear buffers using specified color:
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Use orthographic projection to display text:
	glOrtho(0, 1, 0, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1, 1, 0); // yellow text
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.225, 0.89);
	glPopMatrix();

	// Turn the operating mode of the projection matrix:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Specify a viewing frustum into the world coordinate system, 
	// 70: the field of view angle in the y direction,
	// width/height: the field of view in the x direction,
	// 1 and 100: distances from the viewer to the near and far clipping plane: 
	gluPerspective(70, w / h, 1, 100);

	// Enable modelview matrix mode:
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-15, -15, -35);	// camera shifts from the origin to distZ, 

	glRotatef(angleX, 0.0f, 1.0f, 0.0f);  // then turns along the Y axis
	glRotatef(angleY, 1.0f, 0.0f, 0.0f);  // then turns along the X axis
	glEnable(GL_DEPTH_TEST);	// Enable depth buffer

								// Enable light setting mode:
	glEnable(GL_LIGHTING);

	// Set light source #0 (from eight possible sources):
	glEnable(GL_LIGHT0);


	DrawField();

	DrawSnake();
	if (num < 20)
	{
		angleX = 0;
		angleY = 0;
		l = 1;
		t = 60;
		m[i].DrawApple();

	}
	else if (num >= 20 && num <= 60)
	{
		l = 2;
		t = 45;
		angleX = 0;
		angleY = 0;
		for (int j = 0; j < 10; j++)
		{
			m2[j].New();
			m2[j].DrawApple();
		}
	}
	else if (num > 60 && num <= 85)
	{
		l = 3;
		t = 30;
		angleX = 0;
		angleY = 0;
		for (int j = 0; j < 10; j++) {
			m3[i].New();
			m3[j].DrawApple();
		}
	}
	else if (num > 85 && num <= 100)
	{
		if (num == 100)
		{
			finish = true;
			num = 0;
		}
		l = 4;
		t = 20;
		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < 20; i += 2)
			{
				for (int j = 0; j < 20; j += 2)
				{
					angleX = i;
					angleY -= j;
					if (angleX == 20)
					{
						angleX = 0;
						angleY = 0;
					}
				}
			}
			m4[j].DrawApple();
		}
	}

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glFlush();
	glutSwapBuffers();
}
void on_motion(int x, int y)
{
	switch (button)

	{
	case 0:
	{
		break;
	}
	case GLUT_UP:
	{
		break;
	}
	case 2: // right button: scene rotation 
	{
		angleX += x - mouseX;
		angleY += y - mouseY;
		mouseX = x;
		mouseY = y;
		break;
	}
	}
}
void KeyboardEvent(int key, int a, int b)
{
	switch (key)
	{
	case 101: 	dir = 0; break;
	case 102:   dir = 2; break;
	case 100:  dir = 1; break;
	case 103:  dir = 3; break;
	case GLUT_KEY_PAGE_UP:   // move closer
		if (z > 10)
			break;
		z += 0.1;
		break;
	case GLUT_KEY_PAGE_DOWN: // move farther
		z -= 0.1;
		break;
	case GLUT_KEY_F2:   // new game
		initialize();
		break;
	case  GLUT_KEY_HOME:
		Sleep(1000);
		break;
	}
}

void on_keyboard(unsigned char key, int x, int y)
{
	// Handling events from the keyboard:
	if (key == 27)
		exit(0);
}
int tick = 0;
void timer(int = 0)
{
	if (finish == true)
	{
		char text[128];
		sprintf(text, "Game Over.Your time: %d     F2 - Restart game    Esc - Exit", time);
		glClearColor(1.0f, 2.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSetWindowTitle("YOU WON");

		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 1, 0, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glColor3f(1, 1, 0);
		drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.03, 0.55);
		glPopMatrix();
	}
	tick++;
	if (tick >= 16) // the next second
	{
		if (!finish)  // seconds grows up if the game not over
			time++;
		tick = 0;     // reset counter
	}
	display();
	Tick();
	glutTimerFunc(t, timer, 0);
}

int main(int argc, char **argv) {
	menu b;
	int k = b.c;
	switch (k) {
	case 1:
	{
		//srand(time(0));
		for (int i = 0; i < 10; i++)
		{
			m[i].New();
			s[i].x = 10;
			s[i].y = 10;
		}
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1024, 768);
		glutCreateWindow("The Hardest Snake Game EVER !!");
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glutDisplayFunc(display);
		glutSpecialFunc(KeyboardEvent);
		glutKeyboardFunc(on_keyboard);
		glutTimerFunc(t, timer, 0);
		glutMouseFunc(on_mouse);
		glutMotionFunc(on_motion);
		/*MenuInit();*/
		glutMainLoop();
	}
	case 2:
		exit(0);
	}
}
