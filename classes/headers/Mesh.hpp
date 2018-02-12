/*

Authors: Sebastian Cypert
File Name: mesh.hpp
Description:
	Defines the mesh class. the mesh class is for rendering any object.
	you can attach hitboxs textures and shaders to it to give it more pazazz
	or just leave it as an ugly white square.

*/
#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <GLFW/glfw3.h>

class Mesh{
	public:
		Mesh(glm::dvec2 size, glm::dvec3 pos);
		virtual ~Mesh();
		void render();
		void setPos(glm::dvec3 pos);
		void setPosRel(glm::dvec3 pos); //set position relative to current position
		void setSize(glm::dvec2);

	private:
		glm::ivec3 pos;
		glm::ivec2 size;
		unsigned Vid, Iid; // vertex id, indices id
		const unsigned short indices[6]{
			0,1,2,
			1,2,3
		};

		
};

#endif