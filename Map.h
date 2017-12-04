#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct NODE {
	int StartCost; 
	int TotalCost; 
	int X, Y; 
	int ParentX, ParentY; //parent	x, y
};

class Map
{
private:
	int **ground;
	int tam;
	const std::vector< std::string> files = {"mapa1.txt", "mapa2.txt"};

public:
	Map(int i);
	~Map();
};

