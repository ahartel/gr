#include "world.h"
#include <GL/freeglut.h>

World::World() : section(0) {
	render_section(0);
}

void World::render() {
	glColor3f (0.0, 1.0, 1.0);  /* the current RGB color is red: */
	//glutSolidCube(1.);
	draw_pipe_tile();
}

void World::render_section(unsigned int section_num) {

}

void World::draw_pipe_tile() {
	glPushMatrix();
	glTranslatef(-1,0,+1);
	glRotatef(90,0,1,0);
	glRectf(-2.f,0.f,+2.f,+1.f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(+1,0,+1);
	glRotatef(90,0,1,0);
	glRectf(-2.f,0.f,+2.f,+1.f);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90,1,0,0);
	glRectf(-1.f,0.f,+2.f,+1.f);
	glPopMatrix();
}
