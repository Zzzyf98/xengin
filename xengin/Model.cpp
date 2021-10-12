#include "Model.h"



Model::Model( bool gamma) : gammaCorrection(gamma)
{
}

void Model::Draw(Shader& shader)
{
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		meshes[i].Draw(shader);
	}
}

void Model::loadModel(std::string const& path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << std::endl;
		return;
	}
	else
	{
		std::cout << "import success" << std::endl;
	}
	directory = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void Model::setShader(Shader* myShader,glm::mat4 view,glm::mat4 projection,glm::vec3 cameraPosition, glm::vec3 cameraFront,glm::vec3 mColor,float mIntensity,float ratio,struct PointLight pointlights[],int point_light_cnt)
{
	myShader->use();

	glm::mat4 temp;
	
	temp = glm::translate(temp, modelPosition);
	temp = glm::rotate(temp, glm::radians(modelRotation.x), glm::vec3(1.0, 0.0, 0.0));
	temp = glm::rotate(temp, glm::radians(modelRotation.y), glm::vec3(0.0, 1.0, 0.0));
	temp = glm::rotate(temp, glm::radians(modelRotation.z), glm::vec3(0.0, 0.0, 1.0));
	temp = glm::scale(temp, modelScale);

	myShader->setMat4("model", temp);
	myShader->setMat4("view", view);
	myShader->setMat4("projection", projection);

	myShader->setVec3("viewPos", cameraPosition);

	myShader->setVec3("light_color", mColor);
	myShader->setFloat("qiangdu", mIntensity);


	myShader->setVec3("flashlight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
	myShader->setVec3("flashlight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
	myShader->setVec3("flashlight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
	myShader->setVec3("flashlight.postion", cameraPosition);
	myShader->setVec3("flashlight.direction", cameraFront);
	myShader->setFloat("flashlight.cutOff", glm::cos(glm::radians(12.5f)));
	myShader->setFloat("flashlight.outerCutOff", glm::cos(glm::radians(17.5f)));




	myShader->setVec3("dirlight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
	myShader->setVec3("dirlight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
	myShader->setVec3("dirlight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
	myShader->setVec3("dirlight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));


	//for (int i = 0; i < dir_light_cnt; i++) {
	//	myShader->setVec3("dirlight[i].ambient", DirLight[i].ambient);
	//	myShader->setVec3("dirlight[i].diffuse", DirLight[i].diffuse);
	//	myShader->setVec3("dirlight[i].specular", DirLight[i].specular);
	//	myShader->setVec3("dirlight[i].direction", DirLight[i].direction);
	//}

	myShader->setInt("n", point_light_cnt);

	for (int i = 0; i < point_light_cnt; i++) {
		std::string temp = "pointlights[";
		temp += char('0' + i);
		temp += "].ambient";
		//std::cout << temp << std::endl;
		myShader->setVec3(temp, pointlights[i].ambient);
		temp = "pointlights[";
		temp += char('0' + i);
		temp += "].diffuse";
		myShader->setVec3(temp, pointlights[i].diffuse);
		temp = "pointlights[";
		temp += char('0' + i);
		temp += "].specular";
		myShader->setVec3(temp, pointlights[i].specular);
		temp = "pointlights[";
		temp += char('0' + i);
		temp += "].postion";
		myShader->setVec3(temp, pointlights[i].postion);
		temp = "pointlights[";
		temp += char('0' + i);
		temp += "].constant";
		myShader->setFloat(temp, pointlights[i].constant);
		temp = "pointlights[";
		temp += char('0' + i);
		temp += "].linear";
		myShader->setFloat(temp, pointlights[i].linear);
		temp = "pointlights[";
		temp += char('0' + i);
		temp += "].quadratic";
		myShader->setFloat(temp, pointlights[i].quadratic);

	}

	//myShader->setVec3("pointlights.postion", lightPos);
	//myShader->setVec3("pointlights.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
	//myShader->setVec3("pointlights.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
	//myShader->setVec3("pointlights.specular", glm::vec3(1.0f, 1.0f, 1.0f));
	//myShader->setFloat("pointlights.constant", 1.0f);
	//myShader->setFloat("pointlights.linear", 0.09f);
	//myShader->setFloat("pointlights.quadratic", 0.032f);




	//以后贴图都要在material中设置了
	//先active通道，再bind textureid，最后设置fragment 通道开启数
	myShader->setInt("material.diffuse", 0);//设置texture只要输入通道数int类型即可
	myShader->setInt("material.specular", 1);
	//myShader->setInt("skybox", 0);
	
	myShader->setFloat("material.shininess", 32.0f);
	myShader->setFloat("ratio", ratio);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	//遍历node中的mesh
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	//遍历其他node
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		glm::vec3 vector;
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Postion = vector;

		if (mesh->HasNormals())
		{
			vector.x = mesh->mNormals[i].x;
			vector.y = mesh->mNormals[i].y;
			vector.z = mesh->mNormals[i].z;
			vertex.Normal = vector;
		}

		if (mesh->mTextureCoords[0])
		{
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
		{
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}

		vertices.push_back(vertex);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}

	}
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	// 1. diffuse maps
	std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
	textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
	// 2. specular maps
	std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
	textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	// 3. normal maps
	std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
	textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
	// 4. height maps
	std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
	textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());


	return Mesh(vertices,indices,textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
	std::vector<Texture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		//check if texture was loaded before
		bool skip = false;
		for (unsigned int j = 0; j < textures_loaded.size(); j++)
		{
			if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
			{
				textures.push_back(textures_loaded[j]);
				skip = true;
				break;
			}
		}
		if (!skip)
		{
			Texture texture;
			texture.id = TextureFromFile(str.C_Str(), this->directory);
			texture.type = typeName;
			texture.path = str.C_Str();
			textures.push_back(texture);
			textures_loaded.push_back(texture);
		}
	}
	return textures;
}

unsigned int Model::TextureFromFile(const char* path, const std::string& directory, bool gamma)
{
	std::string filename = std::string(path);
	filename = directory + '/' + filename;
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;

	return 0;
}
