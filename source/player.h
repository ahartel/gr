#pragma once

#include <mutex>
#include <array>

class Player {
public:
	Player();
	void render();
	void init_jump();
	void calculate_height();

	enum rotation {left,right};
	void rotate(rotation r);

private:
	bool in_jump;
	bool in_transition;
	std::mutex jump_mutex;

	float timestep;
	float orientation_z;
	float trans_rot;
	float gravity_constant;
	float initial_velocity;
	float initial_height;
	float initial_jump_height;

	std::array<float,3> gravity;
	std::array<float,3> velocity;
	std::array<float,3> height;
};
