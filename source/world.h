#include <list>
#include "section.h"

class World {
public:
	World();
	void render();
private:
	std::list<Section> sections;
	unsigned int section;
	void render_section(unsigned int);
	void draw_pipe_tile();
};
