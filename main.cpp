/*

Authors: Sebastian Cypert
File Name: main.cpp
 Description:
	it is the starting point for the opengl adventures program
	initalizes glfw and opens a window as well as in charge of running render functions
*/


#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <window_exception.hpp>

void render();

//--------------------------starting function-----------------------
int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800,600);
	glutCreateWindow("window");

	glutDisplayFunc(render);
	glutMainLoop();

}

void render(){

	glClear(GL_COLOR_BUFFER_BIT);

	glRectf(-.5,.5,.5,-.5);

	glutSwapBuffers();

}