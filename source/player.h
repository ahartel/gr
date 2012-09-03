#include <mutex>

class Player {
public:
	Player();
	void render();
	void init_jump();
	void calculate_height();
	void lookAt();
private:
	bool in_jump;
	float velocity;
	float height;
	std::mutex jump_mutex;

	float timestep;
	float gravity;
};
