#pragma once
#ifndef _ENEMIES_H
#define _ENEMIES_H

#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>

class Enemies
{
private:
	float lifePoints;
	float speed;	
	glm::vec2 direction;
	float armor;
	float timer;
	

public:
	float radius = 1.0;
	glm::vec2 position;
	Enemies(int lv, glm::vec2 pos);
	void update(float DT);
	void free();
	~Enemies();
	float X() { return position.x; };
	float Z() { return position.y; };
};

#endif //_ENEMIES_MODEL_H