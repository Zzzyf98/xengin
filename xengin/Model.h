#pragma once



#include "Mesh.h"

#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "allmyheadfile.h"
#include "Shader.h"
#include "light.h"
#include "string.h"

class Model
{
public:
	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	bool gammaCorrection;
	Model(bool gama = false);
	void Draw(Shader& shader);
	void loadModel(std::string const& path);
	glm::vec3 modelPosition = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 modelRotation = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 modelScale = glm::vec3(1.0, 1.0, 1.0);
	
	void setShader(Shader* myShader, glm::mat4 view, glm::mat4 projection, glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 mColor, float mIntensity,float ratio, PointLight pointlights[], int point_light_cnt);
private:
	

	
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typename);
	unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma=false);
	
};

