#pragma once

#define GLEW_STATIC

#define STB_IMAGE_IMPLEMENTATION



#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imfilebrowser.h"
#include "imgui_layout.h"
#include "light.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
unsigned int myBindTexture(const char* filename, int bindPostion, GLint internalformat, GLenum format);
unsigned int loadCubemap(std::vector<std::string> faces);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void renderQuad();
std::string changefilepath(std::string);

bool check_mouse_state = false;
bool bloom = true;
Camera camera;

std::vector<Model*> ALLMODEL;
std::vector<Shader*> ALLSHADER;



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
float skyboxVertices[] = {
	// positions          
	-1.0f,  1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	-1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f
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
float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
		// positions   // texCoords
		-1.0f,  1.0f,  0.0f, 1.0f,
		-1.0f, -1.0f,  0.0f, 0.0f,
		 1.0f, -1.0f,  1.0f, 0.0f,

		-1.0f,  1.0f,  0.0f, 1.0f,
		 1.0f, -1.0f,  1.0f, 0.0f,
		 1.0f,  1.0f,  1.0f, 1.0f
};

float floorlength = 5000.0f;

float floorVertices[] = {
	// positions          
	-floorlength, 30.0f, -floorlength,
	-floorlength, 30.0f,  floorlength,
	 floorlength, 30.0f,  floorlength,
	 floorlength, 30.0f,  floorlength,
	 floorlength, 30.0f, -floorlength,
	-floorlength, 30.0f, -floorlength,
};



float screenWidth = 1500;
float screenHeight = 1500;

float deltaTime = 0.0f;//与上一帧的时间差
float lastFrame = 0.0f;//记录上一帧的时间
float lastX = screenWidth / 2.0f;//记录指针位置
float lastY = screenHeight / 2.0f;
bool firstMouse = true;

glm::vec3 lightPos(1.2f, 30.0f, 0.0f);
#pragma endregion

float last_f_time = 0.0f;

PointLight pointlights[16]; //定义在栈区




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
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//glfwSetCursorPosCallback(window, mouse_callback);
	//glfwSetScrollCallback(window, scroll_callback);
	glfwSetKeyCallback(window, key_callback);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//------------------------------------------

#pragma endregion

	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

#pragma region Define Shader
	Shader* myShader = new Shader("vertexSourceCode.vert", "fragmentSourceCode.frag");

	Shader* tijiyunShader = new Shader("vtijiyun.vert", "ftijiyun.frag");

	Shader* skyShader = new Shader("skyvertexSourceCode.vert", "skyfragmentSourceCode.frag");

	Shader* liziShader = new Shader("lizivertexSourceCode.vert", "lizifragmentSourceCode.frag");

	Shader* screenShader = new Shader("vscreenshader.vert", "fscreenshader.frag");

	Shader* mobanShader = new Shader("vmoban.vert", "fmoban.frag");

	Shader* lightcubeShader = new Shader("vlightcube.vert", "flightcube.frag");

	Shader* blurShader = new Shader("vblur.vert", "fblur.frag");

	Shader* bloomfinalShader = new Shader("vfinalscreen.vert", "ffinalscreen.frag");

	Shader* pbrShader = new Shader("pbr.vert", "pbr.frag");


#pragma endregion

#pragma region Bind VAO VBO EBO(case)

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

	unsigned int VBOF, VAOF;
	glGenVertexArrays(1, &VAOF);
	glGenBuffers(1, &VBOF);


	glBindVertexArray(VAOF);

	glBindBuffer(GL_ARRAY_BUFFER, VBOF);
	glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);

	
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


#pragma region Bind VAO VBO EBO(skybox)

	unsigned int skyVAO;
	unsigned int skyVBO;

	glGenVertexArrays(1, &skyVAO);
	glGenBuffers(1, &skyVBO); //1 是 缓冲ID

	glBindVertexArray(skyVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyVBO); //GL_ARRAY_BUFFER是唯一的

	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), skyboxVertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);//激活location = 0 号位置
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);



#pragma endregion

#pragma region Bind FrameBuffer
	unsigned int fbo;
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	

	unsigned int frametexture;
	glGenTextures(1, &frametexture);
	glBindTexture(GL_TEXTURE_2D, frametexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, screenHeight, screenWidth, 0, GL_RGB, GL_FLOAT, NULL);//绑定一个暂时还不存在的纹理，大小是整个屏幕（意思就是最后会用整个屏幕作为texture）
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, frametexture, 0);

	unsigned int rbo;
	glGenRenderbuffers(1, &rbo);//渲染缓冲对象附件
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, screenHeight, screenWidth);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	unsigned int quadVAO, quadVBO;
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

#pragma endregion

	//GLuint hdrFBO;
	//glGenFramebuffers(1, &hdrFBO);
	//glBindFramebuffer(GL_FRAMEBUFFER, hdrFBO);
	//GLuint colorBuffers[2];
	//glGenTextures(2, colorBuffers);
	//for (GLuint i = 0; i < 2; i++)
	//{
	//	glBindTexture(GL_TEXTURE_2D, colorBuffers[i]);
	//	glTexImage2D(
	//		GL_TEXTURE_2D, 0, GL_RGB16F, screenWidth, screenHeight, 0, GL_RGB, GL_FLOAT, NULL
	//	);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//	// attach texture to framebuffer
	//	glFramebufferTexture2D(
	//		GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, colorBuffers[i], 0
	//	);
	//}

	//// create and attach depth buffer (renderbuffer)
	//unsigned int rboDepth;
	//glGenRenderbuffers(1, &rboDepth);
	//glBindRenderbuffer(GL_RENDERBUFFER, rboDepth);
	//glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, screenWidth, screenHeight);
	//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth);
	//GLuint attachments[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
	//glDrawBuffers(2, attachments);

	//// ping-pong-framebuffer for blurring
	//unsigned int pingpongFBO[2];
	//unsigned int pingpongColorbuffers[2];
	//glGenFramebuffers(2, pingpongFBO);
	//glGenTextures(2, pingpongColorbuffers);
	//for (unsigned int i = 0; i < 2; i++)
	//{
	//	glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[i]);
	//	glBindTexture(GL_TEXTURE_2D, pingpongColorbuffers[i]);
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, screenWidth, screenHeight, 0, GL_RGBA, GL_FLOAT, NULL);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //clamp to the edge as the blur filter would otherwise sample repeated texture values!
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pingpongColorbuffers[i], 0);
	//	// also check if framebuffers are complete (no need for depth buffer)
	//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	//		std::cout << "Framebuffer not complete!" << std::endl;
	//}



#pragma region loadtexture

	std::vector<std::string> faces
	{
		"C:/Users/11656/source/repos/xengin/xengin/Debug/skybox/right.jpg",
		"C:/Users/11656/source/repos/xengin/xengin/Debug/skybox/left.jpg",
		"C:/Users/11656/source/repos/xengin/xengin/Debug/skybox/top.jpg",
		"C:/Users/11656/source/repos/xengin/xengin/Debug/skybox/bottom.jpg",
		"C:/Users/11656/source/repos/xengin/xengin/Debug/skybox/front.jpg",
		"C:/Users/11656/source/repos/xengin/xengin/Debug/skybox/back.jpg"
	};

	unsigned int cubemapTexture = loadCubemap(faces);

	unsigned int noise_texture = myBindTexture("picture/noise.png", 6, GL_RGBA, GL_RGBA);

#pragma endregion


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


#pragma region set other parameters
	skyShader->use();
	skyShader->setInt("skybox", 0);

	blurShader->use();
	blurShader->setInt("image", 0);

	bloomfinalShader->use();
	bloomfinalShader->setInt("scene", 0);
	bloomfinalShader->setInt("bloomBlur", 1);
	
	screenShader->use();
	screenShader->setInt("screenTexture", 0);

	

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	static float ratio;


	ImGui::FileBrowser fileDialog;

	// (optional) set browser properties
	fileDialog.SetTitle("Open File");
	fileDialog.SetTypeFilters({ ".obj" });

	bool drawflag = false;
	bool show_skybox = false;
	bool dir_light = false;
	bool point_light = false;
	bool flash_light = false;


	glm::vec3 mColor = { 1.0f, 1.0f, 1.0f };
	glm::vec3 mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 mRotation = glm::vec3(0.0f, 0.0f, 0.0f);
	
	float mIntensity = 0.2;

	int frameCounter = 0;

	float exposure = 1.0f;

	int point_light_cnt = 0;
	
	

#pragma endregion

	while (!glfwWindowShouldClose(window)) {
		
		if (check_mouse_state) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glfwSetCursorPosCallback(window, mouse_callback);
			glfwSetScrollCallback(window, scroll_callback);
		}
		else {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			glfwSetCursorPosCallback(window,NULL);
			glfwSetScrollCallback(window, NULL);
		}

		
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		processInput(window);



		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		//glBindFramebuffer(GL_FRAMEBUFFER, hdrFBO);
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glm::mat4 temp = glm::mat4(1.0);
		view = camera.GetViewMatrix();
		projection = glm::perspective(glm::radians(camera.Zoom), screenWidth / screenHeight, 0.1f, 100.0f);

		
		glStencilMask(0x00);


		tijiyunShader->use();
		frameCounter++;
		if (frameCounter == INT_MAX)
		{
			frameCounter = 0;
		}
		tijiyunShader->setInt("frameCounter", frameCounter);
		glActiveTexture(GL_TEXTURE6);
		glBindTexture(GL_TEXTURE_2D, noise_texture);
		tijiyunShader->setInt("noisetex", 6);
		tijiyunShader->setVec3("lightPos", lightPos);
		
		tijiyunShader->setMat4("model", temp);
		tijiyunShader->setMat4("view", view);
		tijiyunShader->setMat4("projection", projection);
		tijiyunShader->setVec3("viewPos", camera.Position);
		//std::cout << "x:" << camera.Position.x << "y:" << camera.Position.y << "z:" << camera.Position.z << std::endl;
		glBindVertexArray(VAOF);
		glDrawArrays(GL_TRIANGLES, 0, 6);




#pragma region setmyshader
		
		if (drawflag) {
			
			
			for (int i = 0; i < ALLMODEL.size(); i++) {
				pbrShader->use();//myShader
				glStencilFunc(GL_ALWAYS, 1, 0xFF);
				glStencilMask(0xFF);
				ALLMODEL[i]->setShader(ALLSHADER[i], view, projection, camera.Position, camera.Front, mColor,mIntensity,ratio, pointlights,point_light_cnt);
				ALLMODEL[i]->Draw(*pbrShader);//myShader

				glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
				glStencilMask(0x00);
				//glDisable(GL_DEPTH_TEST);
				mobanShader->use();
				float scale = 1.1;
				temp = glm::mat4(1.0f);
				temp = glm::translate(temp, ALLMODEL[i]->modelPosition);
				temp = glm::rotate(temp, glm::radians(ALLMODEL[i]->modelRotation.x), glm::vec3(1.0, 0.0, 0.0));
				temp = glm::rotate(temp, glm::radians(ALLMODEL[i]->modelRotation.y), glm::vec3(0.0, 1.0, 0.0));
				temp = glm::rotate(temp, glm::radians(ALLMODEL[i]->modelRotation.z), glm::vec3(0.0, 0.0, 1.0));
				temp = glm::scale(temp, ALLMODEL[i]->modelScale);
				
				mobanShader->setMat4("model", temp);
				mobanShader->setMat4("view", view);
				mobanShader->setMat4("projection", projection);
				ALLMODEL[i]->Draw(*mobanShader);
				glStencilMask(0xFF);
				glStencilFunc(GL_ALWAYS, 0, 0xFF);
				glEnable(GL_DEPTH_TEST);

			}
			lightcubeShader->use();
			lightcubeShader->setMat4("projection", projection);
			lightcubeShader->setMat4("view", view);
			glBindVertexArray(VAO);
			for (int i = 0; i < point_light_cnt; i++) {
				glm::mat4 tempcube = glm::mat4(1.0f);

				tempcube = glm::translate(tempcube, pointlights[i].postion);
				tempcube = glm::scale(tempcube, glm::vec3(0.2f)); // Make it a smaller cube
				lightcubeShader->setMat4("model", tempcube);
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}


			
		}
#pragma endregion



		if (show_skybox) {
			glDepthFunc(GL_LEQUAL); //使得skybox永远在最后显示
			skyShader->use();
			glActiveTexture(GL_TEXTURE6);
			glBindTexture(GL_TEXTURE_2D, noise_texture);
			skyShader->setInt("noisetex", 6);
			skyShader->setVec3("lightPos", lightPos);
			skyShader->setVec3("viewPos", camera.Position);

			glm::mat4 viewskybox = glm::mat4(glm::mat3(camera.GetViewMatrix()));//观察矩阵转换为3x3矩阵（移除位移），再将其转换回4x4矩阵
			skyShader->setMat4("view", viewskybox);
			skyShader->setMat4("projection", projection);

			glBindVertexArray(skyVAO);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
			glDepthFunc(GL_LESS);
		}

		

#pragma region hold on
		//tijiyunShader->use();
		//glm::mat4 lightModel = glm::mat4(1.0f);
		//lightModel = glm::translate(lightModel, lightPos);
		//lightModel = glm::scale(lightModel, glm::vec3(0.2f));//x,y,z都缩小为0.2倍
		//tijiyunShader->setMat4("model", lightModel);
		//tijiyunShader->setMat4("view", view);
		//tijiyunShader->setMat4("projection", projection);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		//glDepthFunc(GL_LEQUAL);
		// 
		// 
		// 


		//if (show_demo_window)
		//	ImGui::ShowDemoWindow(&show_demo_window);
		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.

		//if (ImGui::Begin("dummy window"))
		//{
		//	// open file dialog when user clicks this button
		//	if (ImGui::Button("open file dialog"))
		//		fileDialog.Open();
		//}
		//ImGui::End();

		//fileDialog.Display();

		//if (fileDialog.HasSelected())
		//{
		//	std::string filename = fileDialog.GetSelected().string();
		//	std::string usename = changefilepath(filename);
		//	std::cout << "Selected filename" << usename << std::endl;
		//	drawflag = true;
		//	ourModel->loadModel(usename);
		//	fileDialog.ClearSelected();
		//}

		//{
		//	//static float f = 0.0f;
		//	static int counter = 0;

		//	ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		//	ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		//	ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		//	ImGui::Checkbox("Another Window", &show_another_window);

		//	ImGui::SliderFloat("x", &transmodel.x, -5.0f, 5.0f);
		//	ImGui::SliderFloat("y", &transmodel.y, -10.0f, 0.0f);
		//	ImGui::SliderFloat("z", &transmodel.z, -30.0f, -20.0f);
		//	ImGui::SliderFloat("ratio", &ratio, 0.0f, 1.0f);   // Edit 1 float using a slider from 0.0f to 1.0f
		//	ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

		//	if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
		//		counter++;
		//	ImGui::SameLine();
		//	ImGui::Text("counter = %d", counter);

		//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		//	ImGui::End();
		//}

		//if (show_another_window)
		//{
		//	ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		//	ImGui::Text("Hello from another window!");
		//	if (ImGui::Button("Close Me"))
		//		show_another_window = false;
		//	ImGui::End();
		//}

#pragma endregion
		//glBindFramebuffer(GL_FRAMEBUFFER, 0);

#pragma region framebuffer

		//// 2. blur bright fragments with two-pass Gaussian Blur 
		//// --------------------------------------------------
		//bool horizontal = true, first_iteration = true;
		//unsigned int amount = 5;
		//blurShader->use();
		//for (unsigned int i = 0; i < amount; i++)
		//{
		//	glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[horizontal]);
		//	blurShader->setInt("horizontal", horizontal);
		//	glBindTexture(GL_TEXTURE_2D, first_iteration ? colorBuffers[1] : pingpongColorbuffers[!horizontal]);  // bind texture of other framebuffer (or scene if first iteration)
		//	renderQuad();
		//	horizontal = !horizontal;
		//	if (first_iteration)
		//		first_iteration = false;
		//}
		//glBindFramebuffer(GL_FRAMEBUFFER, 0);


		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//bloomfinalShader->use();
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, colorBuffers[0]);
		//glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, pingpongColorbuffers[!horizontal]);
		//bloomfinalShader->setInt("bloom", bloom);
		//bloomfinalShader->setFloat("exposure", exposure);
		//renderQuad();

		//std::cout << "bloom: " << (bloom ? "on" : "off") << "| exposure: " << exposure << std::endl;


		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glDisable(GL_DEPTH_TEST);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set clear color to white (not really necessary actually, since we won't be able to see behind the quad anyways)
		glClear(GL_COLOR_BUFFER_BIT);
		screenShader->use();
		screenShader->setFloat("exposure", exposure);
		glBindVertexArray(quadVAO);
		glBindTexture(GL_TEXTURE_2D, frametexture);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		
#pragma endregion
		
#pragma region imgui
		std::string mCurrentFile;
		{
			ImGui::Begin("Properties");
			if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen))
			{

				if (ImGui::Button("Open..."))
				{
					fileDialog.Open();
				}
				ImGui::SameLine(0, 5.0f);
				ImGui::Text(mCurrentFile.c_str());
			}
			if (ImGui::CollapsingHeader("Light"))
			{
				ImGui::ColorPicker3("LightColor", (float*)&mColor, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
				ImGui::SliderFloat("xx", &lightPos.x, -5.0f, 5.0f);
				ImGui::SliderFloat("yy", &lightPos.y, -5.0f, 5.0f);
				ImGui::SliderFloat("zz", &lightPos.z, -5.0f, 5.0f);
				ImGui::Separator();
				ImGui::SliderFloat("Light intensity", &mIntensity, 0.0f,1.0f);
				if (ImGui::Button("Add a Pointlight")) {
					point_light_cnt++;

				}

				
				
				for (int i = 0; i < point_light_cnt; i++) {

					std::string point_light_postion = "LAmb" + std::to_string(i);
					nimgui::draw_vec3_position(point_light_postion, pointlights[i].postion, 5.0f);
				}
				

			}

			if (ImGui::CollapsingHeader("Model"))
			{
				for (int i = 0; i < ALLMODEL.size(); i++) {
					float t = 1.0;
					ImGui::Separator();
					ImGui::Text("Position");
					ImGui::Separator();
					std::string tpos = "P" + std::to_string(i);
					nimgui::draw_vec3_position(tpos, ALLMODEL[i]->modelPosition, 80.0f);
					ImGui::Separator();
					std::string trot = "R" + std::to_string(i);
					nimgui::draw_vec3_position(trot, ALLMODEL[i]->modelRotation, 180.0f);
					ImGui::Separator();
					std::string tsca = "S" + std::to_string(i);
					nimgui::draw_vec3_position(tsca, ALLMODEL[i]->modelScale, 2.0f);
				
					ImGui::Separator();
				}
				
			}
			
			

			ImGui::Checkbox("show skybox", &show_skybox);

			ImGui::SliderFloat("exposure", &exposure, 0.0f, 2.0f);
			

			ImGui::End();

			fileDialog.Display();
			if (fileDialog.HasSelected())
			{
				auto file_path = fileDialog.GetSelected().string();
				mCurrentFile = file_path.substr(file_path.find_last_of("/\\") + 1);

				std::string usename = changefilepath(file_path);
				std::cout << "Selected filename" << usename << std::endl;
				drawflag = true;
				Model* ourModel = new Model;
				ourModel->loadModel(usename);
				ALLMODEL.push_back(ourModel);
				Shader* tempShader = new Shader("vertexSourceCode.vert", "fragmentSourceCode.frag");
				ALLSHADER.push_back(tempShader);
				fileDialog.ClearSelected();
			}

		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

#pragma endregion

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	//------------------------------------------
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

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
	if (!data) {
		std::cout << "load texture fail" << std::endl;
	}
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
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
		

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_F && action == GLFW_PRESS)
	{
		if (check_mouse_state)
			check_mouse_state = false;
		else if (!check_mouse_state)
			check_mouse_state = true;

		
	}
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


unsigned int loadCubemap(std::vector<std::string> faces)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height, nrComponents;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrComponents, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
			stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


	return textureID;
}


std::string changefilepath(std::string filename)
{
	std::string usename = "";
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] == '\\') usename += "/";
		else usename += filename[i];
	}
	return usename;
}


// renderQuad() renders a 1x1 XY quad in NDC
// -----------------------------------------
unsigned int QUADVAO = 0;
unsigned int QUADVBO;
void renderQuad()
{
	if (QUADVAO == 0)
	{
		float quadVertices[] = {
			// positions        // texture Coords
			-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
			 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		};
		// setup plane VAO
		glGenVertexArrays(1, &QUADVAO);
		glGenBuffers(1, &QUADVBO);
		glBindVertexArray(QUADVAO);
		glBindBuffer(GL_ARRAY_BUFFER, QUADVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	}
	glBindVertexArray(QUADVAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}
