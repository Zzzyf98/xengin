#version 330 core
out vec4 FragColor;

//in vec3 ourColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D ourTexture;
uniform sampler2D ourFace;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	FragColor = mix(texture(ourTexture,TexCoord),texture(ourFace,TexCoord),0.2);
    FragColor = FragColor * vec4(objectColor*lightColor,1.0f);
	float ambientStrength = 0.15;
	vec3 ambient = ambientStrength*lightColor;
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos-FragPos);
	float diff = max(dot(norm,lightDir),0.0f);
	vec3 diffuse = diff*lightColor;
	float specularStrength = 5.0f;
	vec3 viewDir = normalize(viewPos-FragPos);
	vec3 reflectDir = reflect(-lightDir,norm);

	float spec = pow(max(dot(viewDir,reflectDir),0.0),32);//angle < 90
	vec3 specular = specularStrength * spec * lightColor;

	vec3 result = (ambient+diffuse+specular)*objectColor;
	FragColor *= vec4(result,1.0f);
} 