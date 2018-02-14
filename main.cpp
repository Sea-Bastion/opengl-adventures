/*

Authors: Sebastian Cypert
Name: opengl game

	it is the starting point for the opengl game program
	initalizes glfw and opens a window as well as in charge of running render functions
*/



#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <Mesh.hpp>
#include <GLFW/glfw3.h>
#include <AL/alc.h>
#include <AL/al.h>
#include <glm/glm.hpp>

GLFWwindow *window;


//--------------------------starting function-----------------------
int main(int argc, char **argv){

	//ready glfw for use
	if(!glfwInit()){
		std::cerr << "failed to initalize glfw" << std::endl;
		return 300;
	}

	

	//make the window
	glfwWindowHint(GLFW_RESIZABLE, false);
	window = glfwCreateWindow(800, 600, "window", 0, 0);
	if (!window){
		std::cerr << "failed to open window" << std::endl;
		return 301;
	}

	//ready window for opengl
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	if (glewInit()){
		std::cerr << "failed to initalize opengl\n make sure you have the opengl drivers installed" << std::endl;
		return 302;
	}
	glEnable(GL_TEXTURE_2D);

	std::ifstream vs("shaders/entity.vs.glsl");
	std::stringstream vsBuffer;
	vsBuffer << vs.rdbuf();

	std::ifstream fs("shaders/lit.fl.glsl");
	std::stringstream fsBuffer;
	fsBuffer << fs.rdbuf();

	Shader shader(vsBuffer.str(), fsBuffer.str()); 
	
	//make meshes
	glm::dvec2 size(.375, .5);
	glm::dvec3 pos(0,0,0);
	Mesh square(size, pos, shader);

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