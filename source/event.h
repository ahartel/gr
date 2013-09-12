#pragma once

#include <vector>
#include <array>

class Event
{
	public:
		enum type { posSpeed,collision };
		Event(type t);
		Event(type s, std::vector<double>& p);
		type getType() { return t; };

	protected:
		type t;
		std::vector<double> p;
};


class PosSpeedEvent : public Event
{
	public:
		PosSpeedEvent(std::array<double,3> x, std::array<double,3> v);
		std::array<double,3> getX();

};

class CollisionEvent : public Event
{
	public:
		CollisionEvent();

};
