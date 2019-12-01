#include <iostream>
#include <stdlib.h>
#include <list>

#include <GL/glut.h>

#include "fireworks.h"
#include "constants.h"

using namespace std;

vector<fireworks> fireworks_vec;

// initializes GL functions on points and how they are rendered
void init()
{
	// sets point size
	glPointSize(5);

	glEnable(GL_POINT_SMOOTH); // if enabled, draw points with proper filtering. Otherwise, draw aliased points. 
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // specifies a symbolic constant indicating the behavior to be controlled.

	// enable transparency
	glEnable(GL_BLEND); // blend the computed fragment color values with the values in the color buffers. 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // specifies how the red, green, blue, and alpha source blending factors are computed.
}


// called when the window is resized
void handle_resize(int w, int h)
{
	// sets the window
	glViewport(0, 0, w, h);

	// reset the camera
	glLoadIdentity();

	//glOrtho(-LENGTH, LENGTH, -LENGTH, LENGTH, -LENGTH, LENGTH);
	glOrtho(-100, 100, -100, 100, -100, 100);
}


// display loop
void draw()
{

	while (fireworks_vec.size() < 4) {
		fireworks temp;
		fireworks_vec.push_back(temp);
	}

	vector<fireworks>::iterator it;
	for (it = fireworks_vec.begin(); it != fireworks_vec.end(); it++)
	{
		it->draw();
		glColor4f(0, 0, 0, it->get_life_span());

		// removes past particle from being drawn
		glBegin(GL_QUADS);
		glVertex3f(-LENGTH, -LENGTH, 0);
		glVertex3f(LENGTH, -LENGTH, 0);
		glVertex3f(LENGTH, LENGTH, 0);
		glVertex3f(-LENGTH, LENGTH, 0);
		glEnd();
	}

	vector<fireworks>::iterator iter;
	for (iter = fireworks_vec.begin(); iter != fireworks_vec.end(); iter++)
	{
		// remove particle system if life span has ended
		if (iter->get_life_span() >= 1) {
			fireworks_vec.erase(iter);
			break;
		}
	}
	glutSwapBuffers(); // swaps the buffers of the current window if double buffered.
	glutPostRedisplay(); // marks the current window as needing to be redisplayed.
}


int main(int argc, char** argv)
{
	// init GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // inits display mode on double buffer window in RGBA
	glutInitWindowSize(1200, 800); // set the window start size

	// create window
	glutCreateWindow("Firework System");
	init();

	// handlers for drawing particles and window resizes
	glutDisplayFunc(draw); // sets the display callback for the current window.
	glutReshapeFunc(handle_resize); // sets the reshape callback for the current window.

	glutMainLoop(); // calls the display func (draw), never leaves
	return 0; // never reaches
}