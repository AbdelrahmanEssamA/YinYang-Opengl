#include <windows.h>
#include <gl/gl.h>
#include <glut.h> 
#include <vector>
#include <iostream>
using namespace std;
float PI = 3.14159, x, y;
void draw();
void yinYang();
void Set_Information();
void Initialize(int argc, char *argv[]);
int main(int argc, char *argv[]) {
	Initialize(argc, argv);
	return 0;
}
struct point {
	int x, y;
};
vector<point> points;
bool done;
void Initialize(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Window");
	Set_Information();
	glutDisplayFunc(draw);
	glutMainLoop();
}
void Set_Information() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);

}
void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	yinYang();
	glFlush();
}
void yinYang() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float i = PI / 2; i <= 2 * PI - (PI / 2); i += 0.01)
	{
		x = 50 * cos(i);
		y = 50 * sin(i);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	for (float i = 0; i <= 2 * PI; i += 0.01)
	{
		x = 25 * cos(i);
		y = 25 * sin(i) + 25;
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (float i = 0; i <= 2 * PI; i += 0.01)
	{
		x = 25 * cos(i);
		y = 25 * sin(i) - 25;
		glVertex2f(x, y);
	}
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (float i = 0; i <= 2 * PI; i += 0.01)
	{
		x = 5 * cos(i);
		y = 5 * sin(i) + 25;
		glVertex2f(x, y);
	}
	glEnd();
	glColor3f(0.0, 0.0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (float i = 0; i <= 2 * PI; i += 0.01)
	{
		x = 5 * cos(i);
		y = 5 * sin(i) - 25;
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (float i = 0; i <= 2 * PI; i += 0.01)
	{
		x = 50 * cos(i);
		y = 50 * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}
