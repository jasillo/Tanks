#include "AStar.h"

void AStar::clearAll()
{
	for (size_t i = 0; i < openList.size(); i++)	
		delete openList[i];

	for (size_t i = 0; i < closeList.size(); i++)
		delete closeList[i];
	
	openList.erase(openList.begin(), openList.begin() + openList.size());
	closeList.erase(closeList.begin(), closeList.begin() + closeList.size());
}

void AStar::InsertIntoOpenList(int x, int y, float cost, Node * pa)
{
	//node must be inside the boundary of the map
	if (x <tam && y<tam && x>=0 && y>=0 && !IsElementExits(x, y))
	{
		//the tile must be ground tile, so it will be passable
		if (ground[y][x] == 1)
		{
			openList.push_back(new struct Node());
			openList.back()->startCost = cost;
			openList.back()->TotalCost = cost + abs(x - goal_x) + abs(y - goal_y);
			openList.back()->X = x;
			openList.back()->Y = y;
			openList.back()->parent = pa;
		}		
	}
}

bool AStar::IsElementExits(int x, int y)
{
	for (int i = 0; i<openList.size(); i++)
	{
		if (openList[i]->X == x && openList[i]->Y == y)
		{
			return true;
		}
	}
	for (int i = 0; i<closeList.size(); i++)
	{
		if (closeList[i]->X == x && closeList[i]->Y == y)
		{
			return true;
		}
	}
	return false;
}

int AStar::MinNode(std::vector<Node*> *nodesList)
{	
	int i = 0;
	if (nodesList->size() == 1)
		return 0;
	for (int j = 1; j<nodesList->size(); j++)
	{
		if (nodesList->at(j)->TotalCost < nodesList->at(i)->TotalCost)
			i = j;
	}
	//std::cout << nodesList->size() << " " << i << std::endl;
	return i;
}

void AStar::DeleteElement(std::vector<Node*> *nodesList, int i)
{
	nodesList->erase(nodesList->begin() + i);
}

void AStar::show()
{
	for (size_t i = 0; i < path.size(); i++)
	{
		std::cout << path[i].x << "," << path[i].y << std::endl;
	}
}

AStar::AStar()
{
}

void AStar::copyGround(int **map, int t)
{
	ground = map;
	tam = t;
}


AStar::~AStar()
{
	ground = nullptr;
}

void AStar::create(int s_x,int s_y, int g_x, int g_y)
{	
	path.clear();
	std::cout << s_x <<","<< s_y<<"    " << g_x<<"," << g_y << std::endl;
	
	start_x = s_x;
	start_y = s_y;
	goal_x = g_x;
	goal_y = g_y;
	
	//add the start node to the closed list	
	closeList.push_back(new struct Node());
	closeList.back()->X = start_x;
	closeList.back()->Y = start_y;
	closeList.back()->TotalCost = 0;
	closeList.back()->startCost = 0;
	closeList.back()->parent = nullptr;
	
	int i = 0;
	while (!(closeList[i]->X == goal_x && closeList[i]->Y == goal_y) )
	{
		//take all the neighboring passable nodes and add them to the OpenList
		InsertIntoOpenList(closeList[i]->X + 1, closeList[i]->Y, closeList[i]->startCost + 1, closeList[i]);
		//InsertIntoOpenList(closeList[i]->X + 1, closeList[i]->Y + 1, closeList[i]->startCost + 1, closeList[i]);
		InsertIntoOpenList(closeList[i]->X, closeList[i]->Y + 1, closeList[i]->startCost + 1, closeList[i]);
		//InsertIntoOpenList(closeList[i]->X - 1, closeList[i]->Y + 1, closeList[i]->startCost + 1, closeList[i]);
		InsertIntoOpenList(closeList[i]->X - 1, closeList[i]->Y, closeList[i]->startCost + 1, closeList[i]);
		//InsertIntoOpenList(closeList[i]->X - 1, closeList[i]->Y - 1, closeList[i]->startCost + 1, closeList[i]);
		InsertIntoOpenList(closeList[i]->X, closeList[i]->Y - 1, closeList[i]->startCost + 1, closeList[i]);
		//InsertIntoOpenList(closeList[i]->X + 1, closeList[i]->Y - 1, closeList[i]->startCost + 1, closeList[i]);
		//find the min node
		DeleteElement(&closeList, i);
		i = MinNode(&openList);
		closeList.push_back(openList[i]);
		DeleteElement(&openList, i);
		i = MinNode(&closeList);
	}
	
	Node* temp = closeList[i];
	while (temp != nullptr)
	{
		path.push_back(glm::vec2(temp->X,temp->Y));
		temp = temp->parent;
	}
	clearAll();
	//show();
}

glm::vec2 AStar::next()
{
	std::cout << path.size()<<std::endl;
	if (path.size() == 0)
		return glm::vec2(0, 0);
	glm::vec2 temp = path.back();
	path.pop_back();
	return temp;
}
