
#include <gl/glut.h>
#include "utils.h"


namespace GraphUtils
{
	// Definition of colors:
	float diffWhite[] = { 1.0f, 1.0f, 1.0f };
	float ambiWhite[] = { 0.9f, 0.9f, 0.9f };
	float specWhite[] = { 1.0f, 1.0f, 1.0f };

	float diffWhiteh[] = { 1.0f, 1.0f, 1.0f };
	float ambiWhiteh[] = { 0.3f, 0.1f, 0.1f };
	float specWhiteh[] = { 1.0f, 1.0f, 1.0f };

	float diffBlue[] = { 0.0f, 0.0f, 0.6f };
	float ambiBlue[] = { 0.1f, 0.1f, 0.2f };
	float specBlue[] = { 0.2f, 0.2f, 0.8f };

	float diffBlack[] = { 0.3f, 0.3f, 0.3f };
	float ambiBlack[] = { 0.7f, 0.7f, 0.7f };
	float specBlack[] = { 1.0f, 1.0f, 1.0f };

	float diffRed[] = { 0.6f, 0.0f, 0.0f };
	float ambiRed[] = { 0.2f, 0.1f, 0.1f };
	float specRed[] = { 0.8f, 0.2f, 0.2f };

	float diffYellow[] = { 0.9f, 0.9f, 0 };
	float ambiYellow[] = { 0.2f, 0.2f, 0.1f };
	float specYellow[] = { 1.0f, 1.0f, 0.2f };
	float diffYellowb[] = { 0.5f, 0.5f, 0 };
	float ambiYellowb[] = { 0.2f, 0.2f, 0.1f };
	float specYellowb[] = { 1.0f, 1.0f, 0.2f };
	float diffGreen[] = { 0, 0.5f, 0 };
	float ambiGreen[] = { 0.1f, 0.2f, 0.1f };
	float specGreen[] = { 0.2f, 0.7f, 0.2f };

	float diffOrange[] = { 0.9f, 0.2f, 0 };
	float ambiOrange[] = { 0.2f, 0.2f, 0.2f };
	float specOrange[] = { 0.8f, 0.8f, 0.8f };

	float diffLightBlue[] = { 0, 0.6f, 0.9f };
	float ambiLightBlue[] = { 0.2f, 0.2f, 0.2f };
	float specLightBlue[] = { 0.8f, 0.8f, 0.8f };

	float diffViolet[] = { 0.5f, 0, 0.5f };
	float ambiViolet[] = { 0.2f, 0.2f, 0.2f };
	float specViolet[] = { 0.8f, 0.8f, 0.8f };

	// Drawing boardUnit
	void boardUnit(float length, float width, float height)
	{
		glBegin(GL_QUAD_STRIP);
		// YZ, x<0
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-length / 2, -width / 2, -height / 2);
		glVertex3f(-length / 2, -width / 2, height / 2);
		glVertex3f(-length / 2, width / 2, -height / 2);
		glVertex3f(-length / 2, width / 2, height / 2);

		// ZX, y>0
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(length / 2, width / 2, -height / 2);
		glVertex3f(length / 2, width / 2, height / 2);

		// YZ, x>0
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(length / 2, -width / 2, -height / 2);
		glVertex3f(length / 2, -width / 2, height / 2);

		// ZX y<0
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-length / 2, -width / 2, -height / 2);
		glVertex3f(-length / 2, -width / 2, height / 2);
		glEnd();

		glBegin(GL_QUADS);
		// YX, z>0
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-length / 2, -width / 2, height / 2);
		glVertex3f(-length / 2, width / 2, height / 2);
		glVertex3f(length / 2, width / 2, height / 2);
		glVertex3f(length / 2, -width / 2, height / 2);

		// YX, z<0
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(-length / 2, -width / 2, -height / 2);
		glVertex3f(-length / 2, width / 2, -height / 2);
		glVertex3f(length / 2, width / 2, -height / 2);
		glVertex3f(length / 2, -width / 2, -height / 2);
		glEnd();
	}

	// Displays the text string in a specified position using specified font
	void drawString(void *font, const char* text, float x, float y)
	{
		if (!text) // null pointer
			return;
		// Setting position of the text:
		glRasterPos2f(x, y);
		while (*text)
		{
			// Output string character by character:
			glutBitmapCharacter(font, *text);
			text++;
		}
	}
}