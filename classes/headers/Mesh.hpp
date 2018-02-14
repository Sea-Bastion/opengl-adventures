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
#include <Sprite.hpp>
#include <Shader.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <GLFW/glfw3.h>

class Mesh{
	public:
		Mesh(glm::dvec2 size, glm::dvec3 pos, Shader shader);
		Mesh(glm::dvec2 size, glm::dvec3 pos, Shader shader, Sprite texture);
		virtual ~Mesh();
		void render();
		void setTexture(Sprite texture);
		void setPos(glm::dvec3 pos);
		void setPosRel(glm::dvec3 pos); //set position relative to current position
		void setSize(glm::dvec2);

	private:
		glm::ivec3 pos;
		glm::ivec2 size;
		unsigned Vid, Iid, Tid; // vertex id, indices id
		Sprite *Texture;
		const unsigned char indices[6]{
			0,1,2,
			1,2,3
		};
		const unsigned char TexCoords[8]{
			0,0,
			1,0,
			0,1,
			1,1
		};

		
};

#endif