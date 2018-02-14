/*

Authors: Sebastian Cypert
File Name: Shader.hpp
Description:
	Defines the Shader class. This class is responsable for compiling, loading, configuring,
	and interfacing with OpenGL shader language programs.

*/
#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader{
	public:
		Shader(std::string vertexShader, std::string fragmentShader);
		~Shader();
		void bind();
		static void unbind();
	
	private:
		unsigned program;
		static unsigned compileShader(GLenum type, std::string& source);

};

#endif