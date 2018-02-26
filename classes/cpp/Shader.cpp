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

unsigned compileShader(GLenum type, std::string& source);

Shader::Shader(std::string vertexShader, std::string fragmentShader){

	program = glCreateProgram();

	vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

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

unsigned compileShader(GLenum type, std::string& source){

	unsigned id = glCreateShader(type);

	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int Compile;
	glGetShaderiv(id, GL_COMPILE_STATUS, &Compile);
	if(!Compile){

		int LogLen;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &LogLen);

		char *infoLog = new char[LogLen + 1];
		glGetShaderInfoLog(id, LogLen, 0, infoLog);

		std::cerr << "Error compiling " << ((type == GL_VERTEX_SHADER)?"vertex":"fragment") 
			<< " shader:" << std::endl << infoLog;
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
	glDetachShader(program, vs);
	glDetachShader(program, fs);
	glDeleteShader(vs);
	glDeleteShader(fs);
	glDeleteProgram(program);
}