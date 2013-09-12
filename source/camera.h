#include <array>
#include "player.h"

class Camera {
public:
	Camera();
	void lookAt();
	void rotate(Player::rotation r);

private:
	std::array<float,3> position;
	std::array<float,3> target;
	std::array<float,3> up;
};
