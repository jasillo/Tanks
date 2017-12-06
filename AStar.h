#pragma once
#ifndef _ASTAR_H
#define _ASTAR_H
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

struct Node {
	float startCost;
	float TotalCost;
	int X, Y;
	Node *parent;
};

class AStar
{
private:
	int tam;
	int **ground;
	int start_x, start_y;
	int goal_x, goal_y;

	void clearAll();
	void InsertIntoOpenList(int x, int y, float cost, Node *pa);
	bool IsElementExits(int x, int y);
	int MinNode(std::vector<Node*> *nodesList);
	void DeleteElement(std::vector<Node*> *nodesList, int i);
	
	void show();
public:
	std::vector<Node*> openList;
	std::vector<Node*> closeList;
	std::vector<glm::vec2> path;
	AStar();
	void copyGround(int **map, int t);
	~AStar();

	void create(int s_x, int s_y, int g_x, int g_y);
	glm::vec2 next();
};
#endif //_ASTAR_H
