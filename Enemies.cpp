#include "Enemies.h"



Enemies::Enemies(int lv, glm::vec2 pos)
{
	lifePoints = 500 + lv * 25.0;
	speed = 3 + lv * 0.25;
	armor = 100 + lv * 10;	
	position = pos;
	direction = glm::vec2(1,0);
}

void Enemies::update(float DT, glm::vec2 player, float border, float H, float h)
{
	//angle += DT * movement.x;
	//direction = glm::rotate(glm::vec2(0, -1), 100);

	if (state == 0) { //busqueda
		int c1 = (border + position.x) / H;
		int r1 = (border + position.y) / H;
		int c2 = (border + player.x) / H;
		int r2 = (border + player.y) / H;
		//std::cout << c1 << "," << r1 << " " << c2 << "," << r2 << std::endl;
		finder.create(c1,r1,c2,r2);
		dir = finder.next();
		direction = (glm::vec2(-border + H *dir.x, -border + H *dir.y)) - position;
		state = 1;
	}
	else if (state == 1) { //seguimiento
		if (glm::distance(player, position) < 10) {
			state = 2;
			return;
		}
			
		int c = (border + position.x) / H;
		int r = (border + position.y) / H;

		if (c == dir.x && r == dir.y) {
			dir = finder.next();
			if (finder.path.size() == 0) {
				state = 0;
				return;
			}
			//std::cout << dir.x << "," << dir.y << std::endl;
			direction = glm::normalize((glm::vec2(-border + H *dir.x+h, -border + H *dir.y+h)) - position);
			//std::cout << direction.x << "," << direction.y << std::endl;
		}			

		position += speed * DT * direction;
	}
	else if (state == 2) { //ataque estando detenido
		if (glm::distance(player, position) >= 10)
			state = 0;
	}
	
}

void Enemies::free()
{
	
}

Enemies::~Enemies()
{
}
