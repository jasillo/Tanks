#pragma once
#ifndef _MODEL_H
#define _MODEL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <map>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <GL/glut.h>


class Model {
public:
	Model(const std::string filename);

	void draw() const;

	static Model *getModel(std::string name);

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	std::vector<unsigned int> vertexIndices;
	std::vector<unsigned int> uvIndices;
	std::vector<unsigned int> normalIndices;

	static std::map<std::string, Model *> models;
};


#endif //_MODEL_H
