#include "Map.h"

Map::Map(int i)
{
	std::string line;
	std::ifstream myfile(files[i]);
	if (myfile.is_open())
	{
		
		getline(myfile, line);
		tam = std::stoi(line);
		ground = new int* [tam];
		for (size_t i = 0; i < tam; i++)		
			ground[i] = new int[tam];

		int r = -1;
		while (getline(myfile, line))
		{
			r++;
			for (size_t c = 0; c < tam; c++)
			{
				if (line[c] == '1')
					ground[r][c] = 1;
				else 
					ground[r][c] = 0;
			}
		}
		myfile.close();
		border = tam * H / 2.0;
	}

	centers = new glm::vec2*[tam];
	for (size_t i = 0; i < tam; i++)
		centers[i] = new glm::vec2[tam];

	for (size_t r = 0; r < tam; r++)
	{
		for (size_t c = 0; c < tam; c++)
		{
			centers[r][c] = glm::vec2(-border + H/2.0 + c*H, -border + H /2.0 + r*H);
			//std::cout << centers[r][c].x<<" " << centers[r][c].y<<"     ";
		}
		//std::cout<< std::endl;
	}
}

bool Map::collision(glm::vec2 *pos, float radius)
{
	int c = (border + pos->x) / H;
	int r = (border + pos->y) / H;
	//std::cout << r << " " << c << std::endl;
	//std::cout << pos->x + radius << " " << centers[r][c + 1].x - h << std::endl;
	if (c + 1 < tam && ground[r][c+1] == 0) {
		if (pos->x + radius > centers[r][c+1].x - h)
			pos->x = centers[r][c+1].x - h - radius;
	}
	if (c - 1 > -1 && ground[r][c - 1] == 0) {
		if (pos->x - radius < centers[r][c - 1].x + h)
			pos->x = centers[r][c - 1].x + h + radius;
	}
	if (r + 1 < tam && ground[r+1][c] == 0) {
		if (pos->y + radius > centers[r+1][c].y - h)
			pos->y = centers[r+1][c].y - h - radius;
	}
	if (r - 1 > -1 && ground[r-1][c] == 0) {
		if (pos->y - radius < centers[r-1][c].y + h)
			pos->y = centers[r-1][c].y + h + radius;
	}
	
	return false;
}

Map::~Map()
{
	for (size_t i = 0; i < tam; i++)
	{
		delete ground[i];
	}
	delete ground;
}
