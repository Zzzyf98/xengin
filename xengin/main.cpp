#pragma once

#define GLEW_STATIC

#define STB_IMAGE_IMPLEMENTATION



#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Camera.h"
#include "Model.h"

		 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
unsigned int myBindTexture(const char* filename, int bindPostion, GLint internalformat, GLenum format);

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

#pragma region ModelData

float vertics[] = {
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,0.0f, 1.0f
};

glm::vec3 cubePositions[] = {
	  glm::vec3(0.0f,  0.0f,  0.0f),
	  glm::vec3(2.0f,  5.0f, -15.0f),
	  glm::vec3(-1.5f, -2.2f, -2.5f),
	  glm::vec3(-3.8f, -2.0f, -12.3f),
	  glm::vec3(2.4f, -0.4f, -3.5f),
	  glm::vec3(-1.7f,  3.0f, -7.5f),
	  glm::vec3(1.3f, -2.0f, -2.5f),
	  glm::vec3(1.5f,  2.0f, -2.5f),
	  glm::vec3(1.5f,  0.2f, -1.5f),
	  glm::vec3(-1.3f,  1.0f, -1.5f)
};

float screenWidth = 1500;
float screenHeight = 1500;

float deltaTime = 0.0f;//与上一帧的时间差
float lastFrame = 0.0f;//记录上一帧的时间
float lastX = screenWidth / 2.0f;//记录指针位置
float lastY = screenHeight / 2.0f;
bool firstMouse = true;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
#pragma endregion






int main() {
#pragma region create window
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//------------------------------------------
		//create window
		GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "openglwindow", NULL, NULL);

		if (window == NULL) {
			std::cout << "open window fail" << std::endl;
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		//------------------------------------------
		//init glew
		glewExperimental = true;
		if (glewInit() != GLEW_OK) {
			std::cout << "init glew fail" << std::endl;
			glfwTerminate();
			return -1;
		}
		glViewport(0, 0, screenWidth, screenHeight);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetScrollCallback(window, scroll_callback);
	
		glEnable(GL_DEPTH_TEST);
		//------------------------------------------

	#pragma endregion

	Shader* myShader = new Shader("vertexSourceCode.vert", "fragmentSourceCode.frag");

	Shader* lightShader = new Shader("LightvertexSourceCode.vert", "LightfragmentSourceCode.frag");

#pragma region Bind VAO VBO EBO

	unsigned int VAO;
	unsigned int VBO;
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO); //1 是 缓冲ID
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //GL_ARRAY_BUFFER是唯一的

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertics), vertics, GL_STATIC_DRAW);//VBO内容：全是数据顶点
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); //VAO内容：告诉你几个为一组
	glEnableVertexAttribArray(0);//激活location = 0 号位置
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//激活location = 1 号位置
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);//激活location = 2 号位置

	




#pragma endregion


	unsigned int texture_container2 = myBindTexture("container2.png", 0, GL_RGBA, GL_RGBA);
	unsigned int texture_container2_specular = myBindTexture("container2_specular.png", 1, GL_RGBA, GL_RGBA);



#pragma region MVP

	//----------------MVP Matrix-------------------------------------------
	//和vertexShader定义的变量名字最好相同，不然看的累

	glm::mat4 model; //（模型的变换矩阵）Model
	unsigned int modelLoc = glGetUniformLocation(myShader->ID, "model");

	glm::mat4 view; //，（摄像头位置矩阵）View
	unsigned int viewLoc = glGetUniformLocation(myShader->ID, "view");

	glm::mat4 projection; //（摄像头看法矩阵）Projection
	unsigned int projectionLoc = glGetUniformLocation(myShader->ID, "projection");
	
	//----------------MVP Matrix------------------------------------------

#pragma endregion

	
	Model ourModel("C:/Users/11656/source/repos/xengin/xengin/Debug/model/nanosuit.obj");

	while (!glfwWindowShouldClose(window)) {


		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		view = camera.GetViewMatrix();
		projection = glm::perspective(glm::radians(camera.Zoom), screenWidth / screenHeight, 0.1f, 100.0f);


		myShader->use();

		ourModel.Draw(*myShader);

		glBindVertexArray(VAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_container2);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture_container2_specular);




		glm::mat4 cubeModel = glm::mat4(1.0f);
		myShader->setMat4("model", cubeModel);
		myShader->setMat4("view", view);
		myShader->setMat4("projection", projection);

		
		myShader->setVec3("viewPos", camera.Position);
		
		
		

		myShader->setVec3("flashlight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
		myShader->setVec3("flashlight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
		myShader->setVec3("flashlight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
		myShader->setVec3("flashlight.postion", camera.Position);
		myShader->setVec3("flashlight.direction", camera.Front);
		myShader->setFloat("flashlight.cutOff", glm::cos(glm::radians(12.5f)));
		myShader->setFloat("flashlight.outerCutOff", glm::cos(glm::radians(17.5f)));


		myShader->setVec3("dirlight.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
		myShader->setVec3("dirlight.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
		myShader->setVec3("dirlight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
		myShader->setVec3("dirlight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));


		myShader->setVec3("pointlights.postion", lightPos);
		myShader->setVec3("pointlights.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
		myShader->setVec3("pointlights.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
		myShader->setVec3("pointlights.specular", glm::vec3(1.0f, 1.0f, 1.0f));
		myShader->setFloat("pointlights.constant", 1.0f);
		myShader->setFloat("pointlights.linear", 0.09f);
		myShader->setFloat("pointlights.quadratic", 0.032f);



	
		//以后贴图都要在material中设置了
		//先active通道，再bind textureid，最后设置fragment 通道开启数
		myShader->setInt("material.diffuse", 0);//设置texture只要输入通道数int类型即可
		myShader->setInt("material.specular", 1);
		myShader->setFloat("material.shininess", 32.0f);

		
		
	
		
		for (unsigned int i = 0; i < 10; i++) {
			glm::mat4 temp;
			temp = glm::translate(temp, cubePositions[i]);
			float angle = 20.0f * i;
			temp = glm::rotate(temp, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			myShader->setMat4("model", temp);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		
		myShader->setMat4("model", glm::mat4(1.0f));
		
		
		lightShader->use();
		glm::mat4 lightModel = glm::mat4(1.0f);
		lightModel = glm::translate(lightModel, lightPos);
		lightModel = glm::scale(lightModel, glm::vec3(0.2f));//x,y,z都缩小为0.2倍
		lightShader->setMat4("model", lightModel);
		lightShader->setMat4("view", view);
		lightShader->setMat4("projection", projection);
		glDrawArrays(GL_TRIANGLES, 0, 36);



		



		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	//------------------------------------------
	glfwTerminate();
	return 0;
}


// bind texture to postion n
unsigned int myBindTexture(const char* filename, int bindPostion, GLint internalformat, GLenum format)
{
	unsigned int myTexture;
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
	glGenTextures(1, &myTexture);
	glActiveTexture(GL_TEXTURE0 + bindPostion);
	glBindTexture(GL_TEXTURE_2D, myTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);

	return myTexture;
}




void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)//叉积出右向量
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);

}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}





void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}