#include "Enemies.h"



Enemies::Enemies(int lv, Map *m)
{
	lifePoints = 500 + lv * 25.0;
	speed = 3 + lv * 0.25;
	armor = 100 + lv * 10;
	map = m;
}

void Enemies::update()
{
}

void Enemies::free()
{
	map = nullptr;
}

Enemies::~Enemies()
{
}
