#include "camera.h"
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

Camera::Camera() :
	position{{0.0,0.0,4.0}},
	target{{0.0,0.0,-100.0}},
	up{{0,1,0}}
{

}

void Camera::rotate(Player::rotation r)
{
	if (r==Player::left)
	{
		if (up[1] > 0)
			up = std::array<float,3>{-1,0,0};
		else if (up[0] < 0)
			up = std::array<float,3>{0,-1,0};
		else if (up[1] < 0)
			up = std::array<float,3>{1,0,0};
		else if (up[0] > 0)
			up = std::array<float,3>{0,1,0};
	}
	else if (r==Player::right)
	{
		if (up[1] > 0)
			up = std::array<float,3>{1,0,0};
		else if (up[0] < 0)
			up = std::array<float,3>{0,1,0};
		else if (up[1] < 0)
			up = std::array<float,3>{-1,0,0};
		else if (up[0] > 0)
			up = std::array<float,3>{0,-1,0};
	}
}

void Camera::lookAt()
{
	gluLookAt (position[0], position[1], position[2], target[0], target[1], target[2], up[0], up[1], up[2]);
}
