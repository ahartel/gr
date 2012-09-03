#include "player.h"
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

Player::Player() : timestep(0.001), gravity(9.81) {

}

void Player::render() {

	// draw something
	glColor3f (1.0, 0.0, 0.0);  /* the current RGB color is red: */
                            /* full red, no green, no blue. */
	glPushMatrix();
	glRotatef(90,0,1,0);
	jump_mutex.lock();
	glTranslatef(0,height,0);
	jump_mutex.unlock();
	glutWireTeapot(0.5);
	glPopMatrix();
}

void Player::init_jump() {
	jump_mutex.lock();
	if (!in_jump) {
		in_jump = 1;
		velocity = 4.0;
		height = 0.01;
	}
	jump_mutex.unlock();
}

void Player::calculate_height() {
	jump_mutex.lock();
	if (in_jump) {
		if (height > 0.0) {
			cout << "greater" << endl;
			height += velocity * timestep;
			velocity = velocity - (gravity * timestep);
		}
		else {
			height = 0;
			velocity = 0;
			in_jump = 0;
		}
		cout << height << "," << velocity << endl;
	}
	jump_mutex.unlock();
}

void Player::lookAt() {
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 1.2, 0.0, -1.0, 0.0, -100.0, 0.0, 1.0, 0.0);
	//gluLookAt (-.5, 0.8, 0.0, -1.0, 0.0, -100.0, 0.0, 1.0, 0.0);
}
