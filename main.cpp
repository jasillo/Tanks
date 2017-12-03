
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <chrono>

GLsizei width = 1000, height = 500;
std::chrono::time_point<std::chrono::system_clock> prev_time, new_time;
const GLfloat LightAmbient[4] = { 0.6f, 0.6f, 0.6f, 1.0f };
const GLfloat LightDiffuse[4] = { 1.f, 1.f, 1.f, 1.f };
const GLfloat LightDirection[4] = { -5, 10, 2, 0 };

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	new_time = std::chrono::system_clock::now();
	float delta_time = (std::chrono::duration<float>(new_time - prev_time).count()); //DDDD

	glViewport(0, 0, width, height);
	gluPerspective(60, (double)width / height, 1, 100);
	//gluLookAt(0, 25, 25, 0, 0, 0, 0, 1, 0);	

	glutSwapBuffers();
	glFlush();

	prev_time = new_time;
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
	if (key == 'r') {
		//newGame();
	}	
}

void moveKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		
	}
	else if (key == GLUT_KEY_DOWN) {
		
	}
	else if (key == GLUT_KEY_RIGHT) {
		
	}
	else if (key == GLUT_KEY_LEFT) {
		
	}
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
	glutIdleFunc([]() {
		glutPostRedisplay();
	});

	glutMainLoop();

	return 1;
}