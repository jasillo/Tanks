#pragma once
#ifndef _ENEMIES_H
#define _ENEMIES_H

#include <glm\glm.hpp>
#include "Map.h"

class Enemies
{
private:
	float lifePoints;
	float speed;
	glm::vec2 position;
	glm::vec2 direction;
	float armor;
	float timer;
	Map *map;
	float radius = 1.0;

public:
	Enemies(int lv, Map *m, glm::vec2 pos);
	void update(float DT);
	void free();
	~Enemies();
	float X() { return position.x; };
	float Z() { return position.y; };
};

#endif //_ENEMIES_MODEL_H