/*

Authors: Sebastian Cypert
File Name: Shader.hpp
Description:
	Defines the Shader class. This class is responsable for compiling, loading, configuring,
	and interfacing with OpenGL shader language programs.

*/
#ifndef SHADER_H
#define SHADER_H

class Shader{
	public:
		template <unsigned short vertexSize, unsigned short fragmentSize> 
			Shader(unsigned char (&vertexShader)[vertexSize], unsigned char (&fragmentShader)[fragmentSize]);
		~Shader();
		void bind();
		static void unbind();
	
	private:
		unsigned program;

};

#endif