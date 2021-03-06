/*

Authors: Sebastian Cypert
File Name: mesh.cpp
Desciption:
	gives meaning to the Mesh class and describes all it functions. 
	Mesh class it responsable for rendering squares on the screen which shaders,
	textures, and hitboxs can be attached to.

*/
#include <Mesh.hpp>
#include <Sprite.hpp>
#include <Shader.hpp>
#include <GL/glut.h>

Mesh::Mesh(glm::dvec2 size, glm::dvec3 pos, Shader shader)
{

	//*(this->shader) = shader;

	/*

		positioning will be done with the vector shader but that is not
		implemented yet so everything will be rendered at 0,0 aka
		the middle of the window
	
	*/

	const double Coords[12]{
		-size.x,	 size.y, 	pos.z, //top left

		 size.x,	 size.y, 	pos.z, //top right

		-size.x,	-size.y, 	pos.z, //bottom left

		 size.x,	-size.y, 	pos.z  //bottom right
	};

	
	glGenBuffers(1, &Vid);
	glBindBuffer(GL_ARRAY_BUFFER, Vid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Coords), Coords, GL_STATIC_DRAW);

	glGenBuffers(1, &Iid);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Iid);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Mesh::Mesh(glm::dvec2 size, glm::dvec3 pos, Shader shader, Sprite texture):Mesh(size, pos, shader){
	setTexture(texture);
}

void Mesh::setTexture(Sprite texture){

	Texture = &texture;

	glGenBuffers(1, &Tid);
	glBindBuffer(GL_ARRAY_BUFFER, Tid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TexCoords), TexCoords, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::render(){

	//shader->bind();
	if(Tid) Texture->bind();

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, Vid);
	glVertexAttribPointer(0, 3, GL_DOUBLE, false, 0, 0);

	if(Tid){
		glBindBuffer(GL_ARRAY_BUFFER, Tid);
		glVertexAttribPointer(1, 2, GL_UNSIGNED_BYTE, false, 0, 0);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Iid);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	if(Tid) Texture->unbind();
	//shader->unbind();
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &Iid);
	glDeleteBuffers(1, &Vid);
	if(!Tid) glDeleteBuffers(1, &Tid);
}
