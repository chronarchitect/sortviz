#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

static int random_seed = 0;

void setup() {   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); }

void display()
{
	srandom(random_seed);
	float arr[200];
	for ( int i = 0; i < 200; i++){
		arr[i] = (float)(random() % 200)/100; 
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);
	for (float i = -1; i < 1; i+=0.01){
		glRectf(i, arr[(int)(i*100) + 100] -1, i+0.005, -1.0f);
		glutSwapBuffers();
	}
}

int main(int argc, char *argv[])
{
	random_seed = random();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutCreateWindow("Hello World");

	setup();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
