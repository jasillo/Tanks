#pragma once
#include <glm\glm.hpp>
class Enemies
{
private:
	float lifePoints;
	float speed;
	glm::vec3 position;
	glm::vec3 direction;
	float armor;
	float timer;

public:
	Enemies(int lv);
	void update();
	~Enemies();
};

