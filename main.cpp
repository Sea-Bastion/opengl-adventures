/*

Authors: Sebastian Cypert
Name: opengl game

	it is the starting point for the opengl game program
	initalizes glfw and opens a window as well as in charge of running render functions
*/



#include <iostream>
#include <GL/glew.h>
#include <mesh.hpp>
#include <GLFW/glfw3.h>
#include <AL/alc.h>
#include <AL/al.h>
#include <glm/glm.hpp>
#include <window_exception.hpp>

GLFWwindow *window;

//--------------------------starting function-----------------------
int main(int argc, char **argv){

	//ready glfw for use
	if(!glfwInit()){
		std::cerr << "failed to initalize glfw" << std::endl;
		return 300;
	}

	//make the window
	window = glfwCreateWindow(800, 600, "window", 0, 0);
	if (!window){
		std::cerr << "failed to open window" << std::endl;
		return 301;
	}

	//ready window for opengl
	glfwMakeContextCurrent(window);
	if (!glewInit()){
		std::cerr << "failed to initalize opengl\n make sure you have the opengl drivers installed" << std::endl;
		return 302;
	}
	glEnable(GL_TEXTURE_2D);

	//make meshes
	glm::dvec2 size(.375, .5);
	glm::dvec3 pos(0,0,0);
	mesh square = mesh(size, pos);

	//-------------------------------------render loop--------------------------------
	while (!glfwWindowShouldClose(window)){

		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		square.render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();

}