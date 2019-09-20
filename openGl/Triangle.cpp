#include "Triangle.h"
#include "Vertex.h"
#include "Variable.h"

using namespace Rendering;
using namespace Models;

Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

void Triangle::Create()
{


	// buffers of vertex
	unsigned int vbo;


	//Creation & Bind vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//creation list vertices
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(glm::vec3(0.25, -0.25, 0.0),
		glm::vec4(1, 0, 0, 1)));
	vertices.push_back(Vertex(glm::vec3(-0.25, -0.25, 0.0),
		glm::vec4(0, 1, 0, 1)));
	vertices.push_back(Vertex(glm::vec3(0.25, 0.25, 0.0),
		glm::vec4(0, 0, 1, 1)));


	//Generation buffers
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	vbos.push_back(vbo);

	//Mise de la list dans le buffer
	glBufferData(GL_ARRAY_BUFFER, //Type
		sizeof(Vertex) * 3, // Taille
		&vertices[0], // premier element
		GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)0);
	//remise a zero de letat des arrays
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)(offsetof(Vertex, Vertex::color)));
	glBindVertexArray(0);
}

void Rendering::Models::Triangle::update()
{
}

void Rendering::Models::Triangle::draw()
{
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
