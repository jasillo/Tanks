
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <chrono>

#include "Tank.h"
#include "Map.h"
#include "Enemies.h"
#include "Model.h"

GLsizei width = 1000, height = 500;
std::chrono::time_point<std::chrono::system_clock> prev_time, new_time;
float DT;
const GLfloat LightAmbient[4] = { 0.6f, 0.6f, 0.6f, 1.0f };
const GLfloat LightDiffuse[4] = { 1.f, 1.f, 1.f, 1.f };
const GLfloat LightDirection[4] = { -5, 10, 2, 0 };
const float H = 5;
std::vector<glm::vec2> wallsX;
std::vector<glm::vec2> wallsZ;

Map map(0);
Tank player(&map);
std::vector<Enemies> enemies;
float borde;
std::vector<Model*> models;

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	

	glViewport(0, 0, width, height);
	gluPerspective(60, (double)width / height, 1, 100);
	gluLookAt(player.X() - player.direction.x * 4, 4, player.Z()- player.direction.y * 4,
		player.X() + player.direction.x *4, 2, player.Z() + player.direction.y*4,
		0, 1, 0);
	
	//graficar terreno	
	glColor4f(0.25,0.25,0.25, 1);
	glBegin(GL_QUADS);
	glVertex3f(-borde,0, -borde);
	glVertex3f(borde,0, -borde);
	glVertex3f(borde,0 , borde);
	glVertex3f(-borde,0, borde);
	glEnd();
	//graficar paredes
	glColor4f(0.75, 0.75, 0.75, 1);
	for (size_t i = 0; i < wallsX.size(); i++)
	{
		glBegin(GL_QUADS);
		glVertex3f(wallsX[i].x, 0, wallsX[i].y);
		glVertex3f(wallsX[i].x, 0, wallsX[i].y + H);
		glVertex3f(wallsX[i].x, H, wallsX[i].y + H);
		glVertex3f(wallsX[i].x, H, wallsX[i].y);
		glEnd();
	}
	glColor4f(0.65, 0.65, 0.65, 1);
	for (size_t i = 0; i < wallsZ.size(); i++)
	{
		glBegin(GL_QUADS);
		glVertex3f(wallsZ[i].x, 0, wallsZ[i].y);
		glVertex3f(wallsZ[i].x+H, 0, wallsZ[i].y);
		glVertex3f(wallsZ[i].x+H, H, wallsZ[i].y);
		glVertex3f(wallsZ[i].x, H, wallsZ[i].y);
		glEnd();
	}

	//dibujar jugador	
	glPushMatrix();
	glColor4f(1, 1, 1, 1);
	glTranslatef(player.X(),0,player.Z());
	glRotatef(180-player.getAngle(), 0, 1, 0);
	//std::cout << player.getAngle() << std::endl;
	glScalef(0.5, 0.5, 0.5);
	models[0]->draw();
	glPopMatrix();
	
	//glScalef(0.1, 0.1, 0.1);
	

	glutSwapBuffers();
	glFlush();	
}

void initGL() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glLoadIdentity();

	glEnable(GL_COLOR_MATERIAL);
	GLfloat ambientGround[4] = { 0.3,0.3,0.3,1 };
	GLfloat diffuseGround[4] = { 0.5,0.5,0.5,1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientGround);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseGround);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, LightDirection);
	prev_time = std::chrono::system_clock::now();;
	borde = map.tam * H / 2.0;

	bool continius = false;
	for (size_t r = 0; r < map.tam; r++)
	{
		for (size_t c = 0; c < map.tam; c++)
		{
			if (map.ground[r][c] == 0 && !continius) {
				wallsX.push_back(glm::vec2(-map.border + c*H, -map.border + r*H));
				continius = true;
				//std::cout << -map.border + c*H << " " << -map.border + r*H << std::endl;
			}
			else if (map.ground[r][c] == 1 && continius) {
				wallsX.push_back(glm::vec2(-map.border + c*H, -map.border + r*H));
				continius = false;
				//std::cout << -map.border + c*H << " " << -map.border + r*H << std::endl;
			}
				
		}
	}
	continius = false;
	for (size_t c = 0; c < map.tam; c++)
	{
		for (size_t r = 0; r < map.tam; r++)
		{
			if (map.ground[r][c] == 0 && !continius) {
				wallsZ.push_back(glm::vec2(-map.border + c*H, -map.border + r*H));
				continius = true;
			}
			else if (map.ground[r][c] == 1 && continius) {
				wallsZ.push_back(glm::vec2(-map.border + c*H, -map.border + r*H));
				continius = false;
			}				
		}
	}
	models.push_back(Model::getModel("MetalKabuterimon"));
	models.push_back(Model::getModel("AirStrike"));
}

void reshape(GLsizei w, GLsizei h) {
	width = w;
	height = h;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}

void keys(unsigned char key, int x, int y) {
	if (key == 'x') {
		player.free();
		exit(1);
	}	
}

void moveKeys(int key, int x, int y) {

	if (key == GLUT_KEY_UP) {
		player.pressZ(1);
	}
	else if (key == GLUT_KEY_DOWN) {
		player.pressZ(-1);
	}
	else if (key == GLUT_KEY_RIGHT) {
		player.pressX(1);
	}
	else if (key == GLUT_KEY_LEFT) {
		player.pressX(-1);
	}
}

void releaseKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN)
		player.realeaseZ();
	else if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT)
		player.realeaseX();
}

void idle() {
	new_time = std::chrono::system_clock::now();
	DT = (std::chrono::duration<float>(new_time - prev_time).count());
	player.DT = DT;
	prev_time = new_time;
	player.update();
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("MOBILE SUIT TANKS");

	initGL();

	glutIgnoreKeyRepeat(1);

	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keys);	
	glutSpecialFunc(moveKeys);
	glutSpecialUpFunc(releaseKeys);
	glutIdleFunc(idle);

	glutMainLoop();

	return 1;
}