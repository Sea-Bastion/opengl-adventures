/*

Authors: Sebastian Cypert
Name: opengl game

	it is the starting point for the opengl game program
	initalizes glfw and opens a window as well as in charge of running render functions
*/



#include <iostream>
#include <GL/glew.h>
#include <Mesh.hpp>
#include <GLFW/glfw3.h>
#include <AL/alc.h>
#include <AL/al.h>
#include <glm/glm.hpp>

GLFWwindow *window;
const GLFWvidmode *monitor = glfwGetVideoMode(glfwGetPrimaryMonitor());

//--------------------------starting function-----------------------
int main(int argc, char **argv){

	//ready glfw for use
	if(!glfwInit()){
		std::cerr << "failed to initalize glfw" << std::endl;
		return 300;
	}

	

	//make the window
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_RED_BITS, monitor->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, monitor->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, monitor->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, monitor->refreshRate);
	window = glfwCreateWindow(800, 600, "window", glfwGetPrimaryMonitor(), 0);
	if (!window){
		std::cerr << "failed to open window" << std::endl;
		return 301;
	}

	//ready window for opengl
	glfwMakeContextCurrent(window);
	if (glewInit()){
		std::cerr << "failed to initalize opengl\n make sure you have the opengl drivers installed" << std::endl;
		return 302;
	}
	glEnable(GL_TEXTURE_2D);

	//make meshes
	glm::dvec2 size(.375, .5);
	glm::dvec3 pos(0,0,0);
	Mesh square = Mesh(size, pos);

	//-------------------------------------render loop--------------------------------
	while (!glfwWindowShouldClose(window)){

		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		//resizes meshes when window is resized
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		square.render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();

}