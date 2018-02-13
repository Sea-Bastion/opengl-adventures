/*

Authors: Sebastian Cypert
File Name: Sprite.cpp
Description:
	gives meaning to the Sprite class
	this class is for loading in texture so that they can be attacked to 
	meshes and rendered into the project

*/
#include <iostream>
#include <stdlib.h>
#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <Sprite.hpp>

//--------------------------------init---------------------------------
Sprite::Sprite(std::string filepath){

	//make and ready buffer
	glGenBuffers(1, &id);
	glBindBuffer(GL_TEXTURE_2D, id);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//load image into buffer
	int width, height;
	unsigned char *image = SOIL_load_image(filepath.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);


}

//---------------------------bind------------------------------
void Sprite::bind(int sampler){

	//check for valid sampler
	if (0 <= sampler && sampler <= 31){
		glActiveTexture(GL_TEXTURE0 + sampler);
		glBindTexture(GL_TEXTURE_2D, id);

	} else{
		std::cerr << "invalid sampler id," << std::endl <<
			"please report this to the developer asap" << std::endl;
		exit(310);
	}
}

//-------------------------------unbind-----------------------------
void Sprite::unbind(){
	glBindTexture(GL_TEXTURE_2D, 0);
}

//-------------------------------del----------------------------
Sprite::~Sprite(){
	glDeleteBuffers(1, &id);
}