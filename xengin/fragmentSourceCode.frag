#version 330 core

#define N 16

struct Material{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

uniform Material material;

struct FlashLight{
	vec3 postion;
	vec3 direction;
	float cutOff;
	float outerCutOff;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
uniform FlashLight flashlight;

struct DirLight{
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform DirLight dirlight;

uniform int n; 

struct PointLight{
	vec3 postion;

	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
uniform PointLight pointlights[N];



out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;



uniform float ratio;

uniform float qiangdu;

uniform vec3 light_color;

//uniform samplerCube skybox;

uniform vec3 viewPos;

vec3 CalcDirLight(DirLight light,vec3 normal,vec3 viewDir);
vec3 CalcPointLight(PointLight light,vec3 normal,vec3 fragPos,vec3 viewDir);
vec3 CalcFlashLight(FlashLight light,vec3 normal,vec3 fragPos,vec3 viewDir);

vec4 getCloud(vec3 worldPos, vec3 cameraPos);




void main()
{
	//FragColor = mix(texture(ourTexture,TexCoord),texture(ourFace,TexCoord),0.2);

	vec3 norm = normalize(Normal);
	vec3 viewDir = normalize(viewPos-FragPos);

	//vec3 result = CalcPointLight(pointlights,norm,FragPos,viewDir);

	vec3 result = CalcDirLight(dirlight,norm,viewDir);

	//vec3 result = CalcFlashLight(flashlight,norm,FragPos,viewDir);

	for(int i=0;i < n;i++){
		result += CalcPointLight(pointlights[i],norm,FragPos,viewDir);
	}


	result += 0.3 * CalcFlashLight(flashlight,norm,FragPos,viewDir);

	

	//vec3 I = normalize(FragPos - viewPos);
	//vec3 R = reflect(I, normalize(Normal));
	
	//vec3 R = refract(I, normalize(Normal), ratio);

	//FragColor = vec4(texture(skybox, R).rgb, 1.0);

	result *= light_color*qiangdu;

	


	FragColor = vec4(result,1.0f);


	
	
} 



vec3 CalcDirLight(DirLight light,vec3 normal,vec3 viewDir)
{
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(normal,lightDir),0.0f);
	vec3 reflectDir = reflect(-lightDir,normal);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
	vec3 ambient = light.ambient * vec3(texture(material.diffuse,TexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,TexCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.specular,TexCoord));
	return (ambient+diffuse+specular);
}


vec3 CalcPointLight(PointLight light,vec3 normal,vec3 fragPos,vec3 viewDir)
{
	vec3 lightDir = normalize(light.postion-FragPos);
	float diff = max(dot(normal,lightDir),0.0f);
	vec3 reflectDir = reflect(-lightDir,normal);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
	//fade
	float fadeDistance = length(light.postion-fragPos);
	float attenuation = 1.0/(light.constant + light.linear*fadeDistance + light.quadratic*(fadeDistance*fadeDistance));
	vec3 ambient = light.ambient * vec3(texture(material.diffuse,TexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,TexCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.specular,TexCoord));
	return (ambient+diffuse+specular)*attenuation;
}


vec3 CalcFlashLight(FlashLight light,vec3 normal,vec3 fragPos,vec3 viewDir)
{
	vec3 lightDir = normalize(light.postion-FragPos);
	float theta = dot(lightDir,normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff)/epsilon,0.0,1.0);
	float diff = max(dot(normal,lightDir),0.0f);
	vec3 reflectDir = reflect(-lightDir,normal);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
	vec3 ambient = light.ambient * vec3(texture(material.diffuse,TexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,TexCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.specular,TexCoord));

	return ambient + diffuse*intensity + specular*intensity;

}




