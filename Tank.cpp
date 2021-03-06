#include "Tank.h"



Tank::Tank()
{
	lifePoints = 500;
	speed = 7.0;
	armor = 1.0;
	position = glm::vec2(0, 0);
	movement = glm::vec2(0, 0);
	direction = glm::vec2(0, 1);	
	//map = m;
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

void Tank::update(float DT)
{
	angle += DT * movement.x;
	direction = glm::rotate(glm::vec2(0, -1), angle);
	position += speed * DT * direction * movement.y;	
}

void Tank::free()
{
	//map = nullptr;
}

Tank::~Tank()
{
}
