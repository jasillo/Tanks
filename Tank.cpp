#include "Tank.h"



Tank::Tank(Map *m)
{
	lifePoints = 500;
	speed = 7.0;
	armor = 1.0;
	position = glm::vec2(0, 0);
	movement = glm::vec2(0, 0);
	direction = glm::vec2(0, 1);
	DT = 0.05;
	map = m;
	angle = 0;
}

void Tank::pressX(int x)
{
	movement.x = x;
}

void Tank::realeaseX()
{
	movement.x = 0;
}

void Tank::pressZ(int z)
{
	movement.y = z;
}

void Tank::realeaseZ()
{
	movement.y = 0;
}

float Tank::getAngle()
{
	return angle * 180 / pi;
}

void Tank::update()
{
	angle += DT * movement.x;
	direction = glm::rotate(glm::vec2(0,-1), angle );
	position += speed * DT * direction * movement.y;

	if (position.x - radius < -map->border)
		position.x = -map->border + radius;
	if (position.x + radius > map->border)
		position.x = map->border - radius;
	if (position.y - radius < -map->border)
		position.y = -map->border + radius;
	if (position.y + radius > map->border)
		position.y = map->border - radius;
	
	map->collision(&position, radius);
	
}

void Tank::free()
{
	map = nullptr;
}

Tank::~Tank()
{
}
