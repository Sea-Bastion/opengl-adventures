/*

Authors: Sebastian Cypert
File Name: Sprite.hpp
Description:
	Defines the Sprite class. the Sprite class is responsable for loading in textures
	and interfacing with the texture. these textures can be plastered on to a Mesh class
	to be rendered on the screen.

*/
#ifndef SPRITE_H
#define SPRITE_H

#include <string>

class Sprite{
	public:
		Sprite(std::string filepath);
		~Sprite();
		void bind(int sampler = 0);
		static void unbind();
	private:
		unsigned id;
};

#endif