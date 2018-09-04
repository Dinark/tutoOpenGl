#include "Model.h"
using namespace Rendering;
using namespace Rendering::Models;
/*
ModelController::ModelController()
{
}


ModelController::~ModelController()
{

	std::map<std::string, Model>::iterator it;
	for (it = models.begin(); it != models.end(); ++it)
	{
		//delete VAO and VBOs (if many)
		unsigned int* p = &it->second.vao;
		glDeleteVertexArrays(1, p);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	models.clear();
}



void ModelController::createTriangleModel(const std::string& gameModelName)
{
	unsigned int vao;
	unsigned int vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<Vertex> vertices;//our vertex positions
	vertices.push_back(Vertex(glm::vec3(0.25, -0.25, 0.0),
		glm::vec4(1.0, 0.0, 0.0, 1.0)));
	vertices.push_back(Vertex(glm::vec3(-0.25, -0.25, 0.0),
		glm::vec4(0.0, 1.0, 0.0, 1.0)));
	vertices.push_back(Vertex(glm::vec3(0.25, 0.25, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 1.0)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 3, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)12);


	Model myModel;                            //is allocated on Stack
	myModel.vao = vao;                        //add vao
	myModel.vbos.push_back(vbo);              //add vbo
	models[gameModelName] = myModel;  //add to std::map

}
*/
/*
void ModelController::deleteModel(const std::string& gameModelName)
{
	Model model = models[gameModelName];
	unsigned int p = model.vao;
	glDeleteVertexArrays(1, &p);
	glDeleteBuffers(model.vbos.size(), &model.vbos[0]);
	model.vbos.clear();
	models.erase(gameModelName);

}
*/
/*
unsigned int ModelController::getModelVao(const std::string& gameModelName)
{
	return models.at(gameModelName).vao;
}
*/
/*
#include "Model.h"

#include "Vertex.h"

using namespace Models;

ModelController::ModelController()
{

}

ModelController::~ModelController()
{
	std::map<std::string, Model>::iterator it;
	for (it = models.begin(); it != models.end(); ++it)
	{
		//delete VAO and VBOs (if many)
		unsigned int* p = &it->second.vao;
		glDeleteVertexArrays(1, p);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	models.clear();
}

void ModelController::createTriangleModel(const std::string & name)
{
	//the arrays of vbo
	unsigned int vao;

	// buffers of vertex
	unsigned int vbo;


	//Creation & Bind vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//creation list vertices
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(glm::vec3(0.25, -0.25, 0.0)));
	vertices.push_back(Vertex(glm::vec3(-0.25, -0.25, 0.0)));
	vertices.push_back(Vertex(glm::vec3(0.25, 0.25, 0.0)));


	//Generation buffers
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//Mise de la list dans le buffer
	glBufferData(GL_ARRAY_BUFFER, //Type
		sizeof(Vertex) * 3, // Taille
		&vertices[0], // premier element
		GL_STATIC_DRAW);
	
	//remise a zero de letat des arrays
	glDisableVertexAttribArray(0);

	glVertexAttribPointer(0, //le numero du parametre
		3, // nombre de parametres R G B
		GL_FLOAT, // type de données  
		GL_FALSE, // normalisation ?
		sizeof(Vertex),
		(void*)0) // offet du premier parametre
		;

	Model myModel;
	myModel.vao = vao;
	myModel.vbos.push_back(vbo);
	this->models[name] = myModel;



}

void ModelController::deleteModel(const std::string & name)
{
	Model model = this->models[name];
	unsigned int vaoToErase = model.vao;

	// supprimer vao
	glDeleteVertexArrays(1, &vaoToErase);

	//supprimer les vbos
	glDeleteBuffers(model.vbos.size(), &model.vbos[0]);

	//
	model.vbos.clear();
	this->models.erase(name);


}

unsigned int ModelController::getModelVao(const std::string & name)
{
	return this->models[name].vao;
}
*/

Rendering::Models::Model::Model()
{
}

Rendering::Models::Model::~Model()
{
	this->destroy();
}

void Rendering::Models::Model::draw()
{

}

void Rendering::Models::Model::update()
{
}

void Rendering::Models::Model::setProgram(ProgramGL shaderName)
{
	this->program = shaderName;
}

void Rendering::Models::Model::destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}

GLuint Rendering::Models::Model::getVao() const
{
	return this->vao;
}

const std::vector<GLuint>& Rendering::Models::Model::getVbos() const
{
	return this->vbos;
}
