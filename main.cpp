/*

Authors: Sebastian Cypert
Name: opengl game

	it is the starting point for the opengl game program
	initalizes glfw and opens a window as well as in charge of running render functions
*/



#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <AL/alc.h>
#include <AL/al.h>
#include <window_exception.hpp>

GLFWwindow *window;

//--------------------------starting function-----------------------
int main(int argc, char **argv){

	if(!glfwInit()){
		std::cerr << "failed to initalize glfw" << std::endl;
		return 666;
	}

	window = glfwCreateWindow(800, 600, "window", 0, 0);
	if (!window){
		std::cerr << "failed to open window" << std::endl;
	}

	glfwMakeContextCurrent(window);
	glEnable(GL_TEXTURE_2D);

	while (!glfwWindowShouldClose(window)){
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwTerminate();

}