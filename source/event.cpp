#include "event.h"

template <typename T>
Event<T>::Event(target t, std::list<T>& p)
{
	targets.push_back(t);
	payload = p;
}
