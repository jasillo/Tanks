#include "Enemies.h"



Enemies::Enemies(int lv)
{
	lifePoints = 500 + lv * 25.0;
	speed = 3 + lv * 0.25;
	armor = 100 + lv * 10;
}

void Enemies::update()
{
}

Enemies::~Enemies()
{
}
