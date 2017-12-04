#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <glm\vec2.hpp>

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

public:
	const float H = 5.0;
	const float h = H / 2.0;
	int **ground;
	glm::vec2 **centers;
	int tam;
	float border;

	Map(int i);
	bool collision(glm::vec2 *pos, float radius);
	~Map();
};

