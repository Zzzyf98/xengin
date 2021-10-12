#version 330 core
out vec4 FragColor;
#define bottom 13   // 云层底部
#define top 20      // 云层顶部
#define width 40     // 云层 xz 坐标范围 [-width, width]


#define baseBright  vec3(1.26,1.25,1.29)    // 基础颜色 -- 亮部
#define baseDark    vec3(0.31,0.31,0.32)    // 基础颜色 -- 暗部
#define lightBright vec3(1.29, 1.17, 1.05)  // 光照颜色 -- 亮部
#define lightDark   vec3(0.7,0.75,0.8)      // 光照颜色 -- 暗部





in vec3 FragPos;
uniform sampler2D noisetex;

uniform vec3 viewPos;

uniform vec3 lightPos;

vec4 getCloud(sampler2D noisetex,vec3 worldPos, vec3 cameraPos,vec3 lightPos);

float getDensity(sampler2D noisetex, vec3 pos);

in vec3 TexCoords;
uniform samplerCube skybox;

void main()
{
    FragColor = texture(skybox,TexCoords);



    //vec4 cloud = getCloud(noisetex,FragPos, viewPos,lightPos);


	//FragColor.rgb = FragColor.rgb*(1.0 - cloud.a) + cloud.rgb; 

} 



vec4 getCloud(sampler2D noisetex, vec3 worldPos, vec3 cameraPos, vec3 lightPos) {
    vec3 direction = normalize(worldPos - cameraPos);   // 视线射线方向
    vec3 step = direction * 0.25;   // 步长
    vec4 colorSum = vec4(0);        // 积累的颜色
    vec3 point = cameraPos;         // 从相机出发开始测试

    // 如果相机在云层下，将测试起始点移动到云层底部 bottom
    if(point.y<bottom) {
        point += direction * (abs(bottom - cameraPos.y) / abs(direction.y));
    }
    // 如果相机在云层上，将测试起始点移动到云层顶部 top
    if(top<point.y) {
        point += direction * (abs(cameraPos.y - top) / abs(direction.y));
    }

    // 如果目标像素遮挡了云层则放弃测试
    float len1 = length(point - cameraPos);     // 云层到眼距离
    float len2 = length(worldPos - cameraPos);  // 目标像素到眼距离
    if(len2<len1) {
        return vec4(0);
    }

    // ray marching
    for(int i=0; i<100; i++) {
        point += step;
        if(bottom>point.y || point.y>top || -width>point.x || point.x>width || -width>point.z || point.z>width) {
            break;
        }

        // 采样
        float density = getDensity(noisetex, point);                // 当前点云密度
        vec3 L = normalize(lightPos - point);                       // 光源方向
        float lightDensity = getDensity(noisetex, point + L);       // 向光源方向采样一次 获取密度
        float delta = clamp(density - lightDensity, 0.0, 1.0);      // 两次采样密度差

        // 控制透明度
        density *= 0.5;

        // 颜色计算
        vec3 base = mix(baseBright, baseDark, density) * density;   // 基础颜色
        vec3 light = mix(lightDark, lightBright, delta);            // 光照对颜色影响

        // 混合
        vec4 color = vec4(base*light, density);                     // 当前点的最终颜色
        colorSum = color * (1.0 - colorSum.a) + colorSum;           // 与累积的颜色混合
    }

    return colorSum;
}

float getDensity(sampler2D noisetex, vec3 pos) {
    // 高度衰减
    float mid = (bottom + top) / 2.0;
    float h = top - bottom;
    float weight = 1.0 - 2.0 * abs(mid - pos.y) / h;
    weight = pow(weight, 0.5);

    // 采样噪声图
    vec2 coord = pos.xz * 0.0025;
    float noise = texture2D(noisetex, coord).x;
	noise += texture2D(noisetex, coord*3.5).x / 3.5;
	noise += texture2D(noisetex, coord*12.25).x / 12.25;
	noise += texture2D(noisetex, coord*42.87).x / 42.87;	
	noise /= 1.4472;
    noise *= weight;

    // 截断
    if(noise<0.4) {
        noise = 0;
    }

    return noise;
}
