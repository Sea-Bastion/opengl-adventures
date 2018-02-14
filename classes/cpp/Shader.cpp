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
#include <string>
#include <GL/glew.h>
#include <Shader.hpp>

Shader::Shader(std::string vertexShader, std::string fragmentShader){

	program = glCreateProgram();

	short vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	short fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

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

	glDeleteShader(vs);
	glDeleteShader(fs);

}

unsigned Shader::compileShader(GLenum type, std::string& source){

	unsigned id = glCreateShader(type);

	const char* src = source.c_str();
	const int size = source.size();
	glShaderSource(id, 1, &src, &size);
	glCompileShader(id);

	int Compile;
	glGetShaderiv(id, GL_COMPILE_STATUS, &Compile);
	if(!Compile){

		int LogLen;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &LogLen);

		char *infoLog = new char[LogLen + 1];
		glGetShaderInfoLog(id, LogLen, 0, infoLog);

		std::cerr << "Error compiling shader:" << std::endl << infoLog;
		delete[] infoLog;

		exit(320);
	}

	return id;
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