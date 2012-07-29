#include "player.h"
#include <GL/freeglut.h>

void Player::render() {

	// draw something
	glColor3f (1.0, 0.0, 0.0);  /* the current RGB color is red: */
                            /* full red, no green, no blue. */
	glPushMatrix();
	glRotatef(90,0,1,0);
	glutWireTeapot(0.5);
	glPopMatrix();
}

void Player::init_jump() {
	if (!in_jump) {
		in_jump = 1;
		velocity = 30;
	}
}
