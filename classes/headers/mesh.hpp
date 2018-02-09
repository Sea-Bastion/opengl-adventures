#ifndef MESH_H
#define MESH_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <GLFW/glfw3.h>

class mesh{
	public:
		mesh(GLFWwindow *window, glm::ivec2 size, glm::bvec3 pos);
		void render();
		void setPos(glm::bvec3 pos);
		void setPosRel(glm::bvec3 pos);

	private:
		glm::ivec3 pos;
		glm::ivec2 size;
		int Vid, Iid; // vertex id, indices id

		
};

#endif