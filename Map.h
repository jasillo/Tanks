#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
	const float H = 5.0;

public:
	int **ground;
	int tam;
	float border;
	Map(int i);
	~Map();
};

