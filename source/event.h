#include <list>

template <typename T>
class Event
{
	public:
		enum target { camera,player,world };
		Event(target t, std::list<T>& p);

	private:
		std::list<target> targets;
		std::list<T> payload;
};

