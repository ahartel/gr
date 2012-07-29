#include <list>
#include <tuple>

class Section {
public:
	Section();
	void render();
private:
	typedef std::tuple<bool,bool,bool,bool> pipeTile;
	std::list<std::tuple<bool,bool,bool,bool>> subsections;
	void draw_pipe_tile();
};
