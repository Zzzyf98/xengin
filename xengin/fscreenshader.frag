#version 330 core
layout (location = 0) out vec4 FragColor;
//layout (location = 1) out vec4 BrightColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;
uniform float exposure;

void main()
{ 
    const float gamma = 1.0;//2.2
    vec3 hdrColor = texture(screenTexture, TexCoords).rgb;


    // 曝光色调映射
    vec3 mapped = vec3(1.0) - exp(-hdrColor * exposure);
    // Gamma校正 
    mapped = pow(mapped, vec3(1.0 / gamma));

    FragColor = vec4(mapped, 1.0);

//    float brightness = dot(FragColor.rgb, vec3(0.2126, 0.7152, 0.0722));
//    if(brightness > 1.0)
//        BrightColor = vec4(FragColor.rgb, 1.0);
   
}