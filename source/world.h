#include <list>
#include "section.h"

class World {
public:
	World();
	void render();
private:
	std::list<Section> sections;
	unsigned int current_section;
	void render_section(unsigned int);
};
