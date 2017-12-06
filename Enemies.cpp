#include "Enemies.h"



Enemies::Enemies(int lv, Map *m, glm::vec2 pos)
{
	lifePoints = 500 + lv * 25.0;
	speed = 3 + lv * 0.25;
	armor = 100 + lv * 10;
	map = m;
	position.x = -map->border + pos.x * map->H + map->h;
	position.y = -map->border + pos.y * map->H + map->h;
}

void Enemies::update(float DT)
{

}

void Enemies::free()
{
	map = nullptr;
}

Enemies::~Enemies()
{
}
