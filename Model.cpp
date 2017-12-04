#include "Model.h"

Model::Model(const std::string filename) {
	char buffer[100];
	memset(buffer, 0, 100);
	std::ifstream file(filename);
	if (file.bad()) {
		return;
	}
	while (true) {
		std::string lineHeader;
		//file >> lineHeader;
		file >> buffer;
		lineHeader = buffer;
		if (file.eof())
			break;
		if (lineHeader == "v") {
			glm::vec3 vertex;
			file >> vertex.x >> vertex.y >> vertex.z;
			vertices.push_back(vertex);
		}
		else if (lineHeader == "vt") {
			glm::vec2 uv;
			file >> uv.x >> uv.y;
			uvs.push_back(uv);
		}
		else if (lineHeader == "vn") {
			glm::vec3 normal;
			file >> normal.x >> normal.y >> normal.z;
			normals.push_back(normal);
		}
		else if (lineHeader == "f") {
			std::string vertex;
			for (int i = 0; i < 3; ++i) {
				memset(buffer, 0, 100);
				file >> buffer;
				vertex = buffer;
				//file >> vertex;
				unsigned int v, uv, normal;
				//sscanf(vertex.c_str(), "%d/%d/%d", &v, &uv, &normal);
				//sscanf(vertex.c_str(), "%d/%d", &v, &uv);
				sscanf(vertex.c_str(), "%d//%d", &v, &uv);
				//std::cout << v << " " << uv << std::endl;
				vertexIndices.push_back(v - 1);
				uvIndices.push_back(uv - 1);
				//normalIndices.push_back(normal - 1);
			}
		}
	}
}

void Model::draw() const {
	glBegin(GL_TRIANGLES);
	for (std::size_t i = 0; i < vertexIndices.size(); ++i) {
		const glm::vec3 &vertex = vertices[vertexIndices[i]];
		//const glm::vec3 &normal = normals[normalIndices[i]];
		glVertex3f(vertex.x, vertex.y, vertex.z);
		//glNormal3f(normal.x, normal.y, normal.z);
	}
	glEnd();
}


Model *Model::getModel(std::string name) {
	if (models.find(name) == models.end())
		return models[name] = new Model("models/" + name + ".obj");
	return models[name];
}


std::map<std::string, Model *> Model::models;