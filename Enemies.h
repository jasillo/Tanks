#pragma once
#include <glm\glm.hpp>
#include "Map.h"

class Enemies
{
private:
	float lifePoints;
	float speed;
	glm::vec3 position;
	glm::vec3 direction;
	float armor;
	float timer;
	Map *map;

public:
	Enemies(int lv, Map *m);
	void update();
	void free();
	~Enemies();
};

