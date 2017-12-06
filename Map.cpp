#include "Map.h"

int Map::getWord(std::string * s)
{
	int pos;
	//eliminar espacios en blanco al inicio, trim
	for (pos = 0; pos < s->size() && s->at(pos) == ' '; ++pos) {};
	*s = s->substr(pos);
	if (s->empty())
		return 0;
	//obtencion de la primera palabra
	for (pos = 0; pos < s->size() && s->at(pos) != ' '; ++pos) {};
	std::string word = s->substr(0, pos);
	*s = s->substr(pos);
	return std::stoi(word);
}

void Map::createEnemie(float DT)
{
	enemiesTime += DT;
		
	if (enemiesTime > 2.0) {
		if (enemies.size() < maxEnemies) {
			enemies.push_back(new Enemies(level, enemiePos));
			enemies.back()->finder.copyGround(ground, tam);
		}		
		enemiesTime = 0;
		return;
		//std::cout << "creado" << std::endl;
	}
	else if (enemiesTime > 1.5) {
		enemiePos = randomPos();
	}
}

glm::vec2 Map::randomPos()
{
	int i = rand() % 8;
	return initialPos[i];
}

void Map::update(float DT)
{
	createEnemie(DT);
	//actualizar player
	player->update(DT);
	collisionBorder(&player->position, player->radius);	
	collision(&player->position, player->radius);
	//actualizar enemigos
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i]->update(DT, player->position,border, H, h);
		collisionBorder(&enemies[i]->position, enemies[i]->radius);		
		collision(&enemies[i]->position, enemies[i]->radius);
	}
}

Map::Map(int i, int lv)
{
	level = lv;
	srand(time(NULL));
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
		for (size_t r = 0; r < tam; r++)
		{
			getline(myfile, line);
			for (size_t c = 0; c < tam; c++)
			{
				if (line[c] == '1')
					ground[r][c] = 1;
				else
					ground[r][c] = 0;
			}
		}
		border = tam * H / 2.0;
		
		for (size_t i = 0; i < 8; i++)
		{
			getline(myfile, line);
			float x = -border + H*getWord(&line) + h;
			float y = -border + H*getWord(&line) + h;
			initialPos.push_back(glm::vec2(x,y));
		}

		myfile.close();
	}

	centers = new glm::vec2*[tam];
	for (size_t i = 0; i < tam; i++)
		centers[i] = new glm::vec2[tam];

	for (size_t r = 0; r < tam; r++)
		for (size_t c = 0; c < tam; c++)
			centers[r][c] = glm::vec2(-border + H/2.0 + c*H, -border + H /2.0 + r*H);

	player = new Tank();
	enemiesTime = 0;
	enemiePos = randomPos();
	finder.copyGround(ground, tam);
}

bool Map::collision(glm::vec2 *pos, float radius)
{
	int c = (border + pos->x) / H;
	int r = (border + pos->y) / H;
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

void Map::collisionBorder(glm::vec2 * pos, float radius)
{
	if (pos->x - radius < -border)
		pos->x = -border + radius;
	if (pos->x + radius > border)
		pos->x = border - radius;
	if (pos->y - radius < -border)
		pos->y = -border + radius;
	if (pos->y + radius > border)
		pos->y = border - radius;
}

Map::~Map()
{
	for (size_t i = 0; i < tam; i++)
	{
		delete ground[i];
	}
	delete ground;
}
