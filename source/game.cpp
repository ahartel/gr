#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include "game.h"
#include "world.h"
#include "player.h"

using namespace std;

World world;
Player player;
static int win;

void renderFunction() {
	// do  a clearscreen
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode (GL_PROJECTION);
	gluLookAt (-.5, 0.8, 0.0, -1.0, 0.0, -100.0, 0.0, 1.0, 0.0);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-3);

	world.render();
	player.render();

	glFlush();
}

void keyb(unsigned char key, int x, int y) {
	cout << "Pressed key " << key << " on coordinates (" << x << "," << y << ")";
	cout << endl;
	if(key == 'q'){
		cout << "Got q,so quitting " << endl;
		glutDestroyWindow(win);
		exit(0);
	}
	else if (key == ' ') {
		cout << "JUMP" << endl;
		player.init_jump();
	}
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.5, 1.5, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}


int main(int argc, char* argv[]) {
/* Main method - main entry point of application
the freeglut library does the window creation work for us, 
regardless of the platform. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    win = glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
	glutKeyboardFunc(keyb);
	glutReshapeFunc(reshape);

	// define the color we use to clearscreen 
	glClearColor(0.0,0.0,0.0,0.0);

    glutMainLoop();
    return 0;
}
