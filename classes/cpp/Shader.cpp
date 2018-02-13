/*

Authors: Sebastian Cypert
File Name: Shader.cpp
Description:
	Gives meaning to the Shader class and implements it's functions.
	The class loads in OpenGL shader language, compiles them, binds and unbinds them, 
	and sets arguments for them.

*/

#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <Shader.hpp>

template <unsigned short vertexSize, unsigned short fragmentSize> 
Shader::Shader(unsigned char (&vertexShader)[vertexSize], unsigned char (&fragmentShader)[fragmentSize]){

	program = glCreateProgram();

	short vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexShader, 0);
	glCompileShader(vs);

	int vsCompile;
	glGetShaderiv(vs, GL_COMPILE_STATUS, &vsCompile);
	if(!vsCompile){

		int LogLen;
		glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &LogLen);

		char *infoLog = new char[LogLen + 1];
		glGetShaderInfoLog(vs, LogLen, 0, infoLog);

		std::cerr << "Error compiling vertex shader:" << std::endl << infoLog;
		delete[] infoLog;

		exit(320);
	}

	short fs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(fs, 1, &fragmentShader, 0);
	glCompileShader(fs);

	int fsCompile;
	glGetShaderiv(fs, GL_COMPILE_STATUS, &fsCompile);
	if(!fsCompile){

		int LogLen;
		glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &LogLen);

		char *infoLog = new char[LogLen + 1];
		glGetShaderInfoLog(fs, LogLen, 0, infoLog);

		std::cerr << "Error compiling fragment shader:" << std::endl << infoLog;
		delete[] infoLog;

		exit(321);
	}

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glBindAttribLocation(program, 0, "Vertces");
	glBindAttribLocation(program, 1, "tex_coords");

	glLinkProgram(program);

	int LinkerStatus;
	glGetProgramiv(program, GL_LINK_STATUS, &LinkerStatus);
	if(!LinkerStatus){

		int LogLen;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &LogLen);

		char *infoLog = new char[LogLen + 1];
		glGetProgramInfoLog(program, LogLen, 0, infoLog);

		std::cerr << "Error linking shader program" << std::endl << infoLog;
		delete[] infoLog;

		exit(322);
	}

	glValidateProgram(program);

	int Validation;
	glGetProgramiv(program, GL_VALIDATE_STATUS, &Validation);
	if(!Validation){

		int LogLen;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &LogLen);

		char *infoLog = new char[LogLen + 1];
		glGetProgramInfoLog(program, LogLen, 0, infoLog);

		std::cerr << "Error Validating shader program" << std::endl << infoLog;
		delete[] infoLog;

		exit(323);
	}

}

void Shader::bind(){
	glUseProgram(program);
}

void Shader::unbind(){
	glUseProgram(0);
}

Shader::~Shader(){
	glDeleteProgram(program);
}