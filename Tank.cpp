#include "Tank.h"



Tank::Tank()
{
	lifePoints = 500;
	speed = 7.0;
	armor = 1.0;
	position = glm::vec2(0, 0);
	movement = glm::vec2(0, 0);
	direction = glm::vec2(0, 1);
	DT = 0.1;
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

void Tank::update()
{
	direction = glm::rotate(direction, 2.0f*DT*movement.x );
	position += speed * DT * direction * movement.y;
}

Tank::~Tank()
{
}
