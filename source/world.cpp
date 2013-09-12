#include "world.h"
#include <list>
#include <GL/freeglut.h>

World::World() : current_section(0),position(0) {
	sections.push_back(Section());
}

void World::render() {
	render_section(current_section);
}

void World::render_section(unsigned int section_num) {
	glPushMatrix();
	glTranslatef(0,0,position);
	sections.front().render();
	glPopMatrix();
}

void World::advance()
{
	position += 0.01;
}

