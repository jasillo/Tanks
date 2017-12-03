#include "Tank.h"



Tank::Tank()
{
	lifePoints = 500;
	speed = 1.0;
	armor = 1.0;
	position = glm::vec3(0, 0, 0);
	movement = glm::vec3(0, 0, 0);
	DT = 0.1;
}

Tank::Tank(int lv)
{

}

void Tank::realeaseX()
{
	movement.x = 0;
}

void Tank::realeaseZ()
{
	movement.z = 0;
}

void Tank::pressZ(int z)
{
	movement.z = z;
}

void Tank::pressX(int x)
{
	movement.x = x;
}

void Tank::update()
{
	position += speed * DT * movement;	
	//std::cout << speed << " " << DT << " " << movement.x << " " << movement.z << std::endl;
}

Tank::~Tank()
{
}
