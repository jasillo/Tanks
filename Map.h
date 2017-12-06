#pragma once
#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <glm\vec2.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Tank.h"
//#include "Enemies.h"


struct Node {
	int StartCost; 
	int TotalCost; 
	int X, Y; 
	int ParentX, ParentY; //parent	x, y
};



class Map
{
private:		
	const std::vector< std::string> files = {"mapa1.txt", "mapa2.txt"};
	int getWord(std::string *s);
	int level;

public:
	const float H = 5.0;
	const float h = H / 2.0;
	int **ground;
	glm::vec2 **centers;
	int tam;
	float border;
	std::vector<glm::vec2> initialPos;
	Tank *player;
	//std::vector<Enemies *>enemies;
	
	glm::vec2 randomPos();
	void update(float DT);	
	
	Map(int i, int lv);
	bool collision(glm::vec2 *pos, float radius);
	~Map();
};

#endif //_MAP_H