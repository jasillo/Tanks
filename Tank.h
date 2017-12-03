#pragma once
#include <glm\glm.hpp>
#include <vector>
#include <iostream>

class Tank
{
private:
	glm::vec3 position;
	float lifePoints;
	float speed;
	float armor;
	std::vector<int> bullets;
	glm::vec3 movement;

public:
	Tank();
	Tank(int lv);
	float DT;

	void pressX(int x);
	void pressZ(int z);
	void realeaseX();
	void realeaseZ();
	float X() { return position.x; };
	float Z() { return position.z; };

	void update();

	~Tank();
};

