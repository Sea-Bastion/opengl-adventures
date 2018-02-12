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