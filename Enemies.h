#pragma once
#ifndef _ENEMIES_H
#define _ENEMIES_H

#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>

#include "AStar.h"

class Enemies
{
private:
	float lifePoints;
	float speed;	
	glm::vec2 direction;
	glm::vec2 dir;
	float armor;
	float timer;

public:
	float radius = 1.0;
	glm::vec2 position;
	int state = 2; //0 buesqueda, 1 seguimiento, 2 ataque
	AStar finder;

	Enemies(int lv, glm::vec2 pos);
	void update(float DT, glm::vec2 player, float border, float H, float h);
	void free();
	~Enemies();
	float X() { return position.x; };
	float Z() { return position.y; };
};

#endif //_ENEMIES_MODEL_H