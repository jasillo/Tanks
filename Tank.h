#pragma once
#ifndef _TANK_H
#define _TANK_H

#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include <vector>
#include <iostream>


class Tank
{
private:
	
	float lifePoints;
	float speed;
	float armor;
	std::vector<int> bullets;
	glm::vec2 movement;
	const float pi = 3.141592653589;

public:
	Tank();
	glm::vec2 direction;
	float angle;
	const float radius = 1.0;
	glm::vec2 nextPos;
	glm::vec2 position;

	void pressX(int x);
	void pressZ(int z);
	void realeaseX();
	void realeaseZ();
	float X() { return position.x; };
	float Z() { return position.y; };
	float getAngle();

	void update(float DT);
	void free();

	~Tank();
};

#endif //TANK_H