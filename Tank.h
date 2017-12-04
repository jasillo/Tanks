#pragma once
#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include <vector>
#include <iostream>
#include "Map.h"

class Tank
{
private:
	glm::vec2 position;
	float lifePoints;
	float speed;
	float armor;
	std::vector<int> bullets;
	glm::vec2 movement;	
	Map *map;

public:
	Tank(Map *m);
	float DT;
	glm::vec2 direction;
	float angle;
	const float radius = 1.0;

	void pressX(int x);
	void pressZ(int z);
	void realeaseX();
	void realeaseZ();
	float X() { return position.x; };
	float Z() { return position.y; };

	void update();
	void free();

	~Tank();
};

