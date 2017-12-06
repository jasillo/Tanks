#include "Enemies.h"



Enemies::Enemies(int lv, glm::vec2 pos)
{
	lifePoints = 500 + lv * 25.0;
	speed = 3 + lv * 0.25;
	armor = 100 + lv * 10;	
	position = pos;
	direction = glm::vec2(1,0);
}

void Enemies::update(float DT)
{
	//angle += DT * movement.x;
	//direction = glm::rotate(glm::vec2(0, -1), 100);
	position += speed * DT * direction;
}

void Enemies::free()
{
	
}

Enemies::~Enemies()
{
}
