#include "world.h"
#include <list>
#include <GL/freeglut.h>

World::World() : current_section(0) {
	sections.push_back(Section());
}

void World::render() {
	render_section(current_section);
}

void World::render_section(unsigned int section_num) {
	sections.front().render();
}


