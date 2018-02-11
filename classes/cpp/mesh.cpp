/*

Authors: Sebastian Cypert
File Name: mesh.cpp
Desciption:
	gives meaning to the mesh class and describes all it functions

*/
#include <GL/glew.h>
#include <mesh.hpp>
#include <GL/glut.h>

mesh::mesh(glm::dvec2 size, glm::dvec3 pos)
{

	/*

		positioning will be done with the vector shader but that is not
		implemented yet so everything will be rendered at 0,0 aka
		the middle of the window
	
	*/

	const double *Coords = new double[12]{
		-size.x,	 size.y, 	pos.z, //top left

		 size.x,	 size.y, 	pos.z, //top right

		-size.x,	-size.y, 	pos.z, //bottom left

		 size.x,	-size.y, 	pos.z  //bottom right
	};

	
	glGenBuffers(12, &Vid);
	glBindBuffer(GL_ARRAY_BUFFER, Vid);
	glBufferData(GL_ARRAY_BUFFER, 12, Coords, GL_STATIC_DRAW);

	glGenBuffers(8, &Iid);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Vid);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 8, indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[] Coords;
}

mesh::~mesh()
{
	delete[] indices;
}
