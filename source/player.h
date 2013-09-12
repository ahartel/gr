#pragma once

#include <mutex>
#include <array>
#include "event.h"

class Player {
public:
	Player();
	void render();
	void init_jump();
	PosSpeedEvent* advance();

	enum rotation {left,right};
	void rotate(rotation r);

private:
	bool in_jump;
	bool in_transition;
	std::mutex jump_mutex;

	double timestep;
	double orientation_z;
	double trans_rot;
	double gravity_constant;
	double initial_velocity;
	double initial_height;
	double initial_jump_height;

	std::array<double,3> gravity;
	std::array<double,3> velocity;
	std::array<double,3> height;
};
