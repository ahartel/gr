#include "player.h"
#include <GL/freeglut.h>
#include <iostream>
#include "point.hpp"

using namespace std;

Player::Player() :
	timestep(0.001),
	gravity{{0,1,0}},
	gravity_constant(-9.81),
	initial_velocity(4.0),
	initial_jump_height(0.1),
	initial_height(-1.0),
	height{{0,initial_height,0}},
	orientation_z(0),
	trans_rot(0)
{

}

void Player::rotate(rotation r)
{
	if (r==left)
	{
		if (gravity[1] > 0)
			gravity = std::array<double,3>{-1,0,0};
		else if (gravity[0] < 0)
			gravity = std::array<double,3>{0,-1,0};
		else if (gravity[1] < 0)
			gravity = std::array<double,3>{1,0,0};
		else if (gravity[0] > 0)
			gravity = std::array<double,3>{0,1,0};

		orientation_z -= 90;
		if (orientation_z <= -360)
			orientation_z = 0;
	}
	else if (r==right)
	{
		if (gravity[1] > 0)
			gravity = std::array<double,3>{1,0,0};
		else if (gravity[0] < 0)
			gravity = std::array<double,3>{0,1,0};
		else if (gravity[1] < 0)
			gravity = std::array<double,3>{-1,0,0};
		else if (gravity[0] > 0)
			gravity = std::array<double,3>{0,-1,0};

		orientation_z += 90;
		if (orientation_z >= 360)
			orientation_z = 0;
	}
	height = vector_scale(initial_height,gravity);
	cout << orientation_z << endl;
}

void Player::render() {

	// draw something
	glColor3f (1.0, 0.0, 0.0);  /* the current RGB color is red: */
                            /* full red, no green, no blue. */
	glPushMatrix();
	jump_mutex.lock();
	glRotatef(trans_rot,0.0,0.0,-1.0);
	glTranslatef(height[0],height[1],height[2]);
	glRotatef(orientation_z,0.0,0.0,-1.0);
	jump_mutex.unlock();
	glutWireTeapot(0.5);
	glPopMatrix();
}

void Player::init_jump() {
	jump_mutex.lock();
	if (!in_jump) {
		in_jump = 1;
		velocity = vector_scale(initial_velocity,gravity);
		height = vector_scale(initial_height+initial_jump_height,gravity);
	}
	jump_mutex.unlock();
}

PosSpeedEvent* Player::advance() {
	jump_mutex.lock();
	if (in_jump) {
		if (vector_sp(height,gravity)-initial_height > 1e-3) {
			height = vector_add(height, vector_scale(timestep, velocity));
			velocity = vector_add(velocity,vector_scale(gravity_constant*timestep,gravity));
		}
		else {
			height = vector_scale(initial_height,gravity);
			velocity = std::array<double,3>{0,0,0};
			in_jump = 0;
		}
	}
	jump_mutex.unlock();
	return new PosSpeedEvent(height,velocity);
}

