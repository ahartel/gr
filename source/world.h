#include <list>
#include "section.h"

class World {
public:
	World();
	void render();
	void advance();

private:
	float position;

	std::list<Section> sections;
	unsigned int current_section;
	void render_section(unsigned int);
};
