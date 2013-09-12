#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <thread>

#include "game.h"
#include "world.h"
#include "player.h"
#include "camera.h"
#include <unistd.h>

using namespace std;

World world;
Player player;
Camera camera;
static int win;

void renderFunction() {
	// do  a clearscreen
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

	camera.lookAt();
	world.render();
	player.render();

	glutSwapBuffers();
}

void keyb(unsigned char key, int x, int y) {
	cout << "Pressed key " << key << " on coordinates (" << x << "," << y << ")";
	cout << endl;
	if(key == 'q'){
		cout << "Got q, quitting." << endl;
		glutDestroyWindow(win);
		exit(0);
	}
	else if(key == 'a'){
		cout << "Got a, rotating left." << endl;
		player.rotate(Player::left);
		camera.rotate(Player::left);
	}
	else if(key == 'd'){
		cout << "Got d, rotating right." << endl;
		player.rotate(Player::right);
		camera.rotate(Player::right);
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

void render()
{
	glutPostRedisplay();
}

void evolve_physics()
{
	while (true) {
		player.calculate_height();
		//world.advance();
		usleep(1000);
	}
}

int main(int argc, char* argv[]) {
/* Main method - main entry point of application
the freeglut library does the window creation work for us, 
regardless of the platform. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    win = glutCreateWindow("gr");
    glutDisplayFunc(renderFunction);
	glutKeyboardFunc(keyb);
	glutReshapeFunc(reshape);
	glutIdleFunc(render);

	// define the color we use to clearscreen 
	glClearColor(0.0,0.0,0.0,0.0);

	std::thread t(evolve_physics);
    glutMainLoop();

    return 0;
}
