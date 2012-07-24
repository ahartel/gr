#include "player.h"
#include <GL/freeglut.h>

void Player::render() {

	// draw something
	glColor3f (1.0, 0.0, 0.0);  /* the current RGB color is red: */
                            /* full red, no green, no blue. */
	glutWireTeapot(0.5);
	//glutSolidCone(0.5,0.5,100,100);
}
