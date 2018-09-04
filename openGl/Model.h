#pragma once

#include <vector>
#include <map>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "Vertex.h"
#include "Variable.h"

#include "IGameObject.h"
namespace Rendering
{ 
	namespace Models
	{ 

		class Model : public IGameObject
		{

			

		public:
			Model();
			~Model();

			virtual void draw() override;
			virtual void update() override;
			virtual void setProgram(ProgramGL shaderName) override;
			virtual void destroy() override;

			virtual GLuint getVao() const override;
			virtual const std::vector<GLuint>& getVbos() const override;
		protected:
			GLVAO vao;
			std::vector<GLVBO> vbos;
			ProgramGL program;

		};


		class ModelController
		{
		public:
			ModelController();
			~ModelController();
			void createTriangleModel(const std::string& name);
			void deleteModel(const std::string& name);

			GLVAO getModelVao(const std::string& name);

		private:
			std::map<std::string, Model> models;


		};

	}
}
