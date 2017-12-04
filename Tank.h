#pragma once
#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include <vector>
#include <iostream>

class Tank
{
private:
	glm::vec2 position;
	float lifePoints;
	float speed;
	float armor;
	std::vector<int> bullets;
	glm::vec2 movement;
	glm::vec2 direction;

public:
	Tank();
	float DT;

	void pressX(int x);
	void pressZ(int z);
	void realeaseX();
	void realeaseZ();
	float X() { return position.x; };
	float Z() { return position.y; };

	void update();

	~Tank();
};

