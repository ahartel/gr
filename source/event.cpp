#include "event.h"

Event::Event(type S)
{
	t = S;
}

Event::Event(type S, std::vector<double>& P)
{
	t = S;
	p = P;
}

PosSpeedEvent::PosSpeedEvent(std::array<double,3> x, std::array<double,3> v) : Event(Event::posSpeed)
{
	for (auto xi : x)
		p.push_back(xi);
	for (auto vi : v)
		p.push_back(vi);
}


std::array<double,3> PosSpeedEvent::getX()
{
	std::array<double,3> ret;
	ret[0] = p[0];
	ret[1] = p[1];
	ret[2] = p[2];
	return ret;
}

CollisionEvent::CollisionEvent() : Event(Event::collision)
{
}
