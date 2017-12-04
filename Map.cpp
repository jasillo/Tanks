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
	}
}


Map::~Map()
{
	for (size_t i = 0; i < tam; i++)
	{
		delete ground[i];
	}
	delete ground;
}
