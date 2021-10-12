#pragma once
#include "allmyheadfile.h"
#include "Shader.h"




struct PointLight {
public:
	glm::vec3 ambient = glm::vec3(0.1f, 0.1f, 0.1f);
	glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
	glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
	
	float constant = 1.0f;
	float linear = 0.09f;
	float quadratic = 0.032;

	glm::vec3 postion = glm::vec3(0.0f, 2.0f, 0.0f);
};

















//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
//glm::vec3 flashlight_specular = glm::vec3(1.0f, 1.0f, 1.0f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
//glm::vec3 flashlight_ambient = glm::vec3(0.1f, 0.1f, 0.1f);
