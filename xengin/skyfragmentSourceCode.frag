#version 330 core
out vec4 FragColor;
#define bottom 13   // �Ʋ�ײ�
#define top 20      // �Ʋ㶥��
#define width 40     // �Ʋ� xz ���귶Χ [-width, width]


#define baseBright  vec3(1.26,1.25,1.29)    // ������ɫ -- ����
#define baseDark    vec3(0.31,0.31,0.32)    // ������ɫ -- ����
#define lightBright vec3(1.29, 1.17, 1.05)  // ������ɫ -- ����
#define lightDark   vec3(0.7,0.75,0.8)      // ������ɫ -- ����





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
    vec3 direction = normalize(worldPos - cameraPos);   // �������߷���
    vec3 step = direction * 0.25;   // ����
    vec4 colorSum = vec4(0);        // ���۵���ɫ
    vec3 point = cameraPos;         // �����������ʼ����

    // ���������Ʋ��£���������ʼ���ƶ����Ʋ�ײ� bottom
    if(point.y<bottom) {
        point += direction * (abs(bottom - cameraPos.y) / abs(direction.y));
    }
    // ���������Ʋ��ϣ���������ʼ���ƶ����Ʋ㶥�� top
    if(top<point.y) {
        point += direction * (abs(cameraPos.y - top) / abs(direction.y));
    }

    // ���Ŀ�������ڵ����Ʋ����������
    float len1 = length(point - cameraPos);     // �Ʋ㵽�۾���
    float len2 = length(worldPos - cameraPos);  // Ŀ�����ص��۾���
    if(len2<len1) {
        return vec4(0);
    }

    // ray marching
    for(int i=0; i<100; i++) {
        point += step;
        if(bottom>point.y || point.y>top || -width>point.x || point.x>width || -width>point.z || point.z>width) {
            break;
        }

        // ����
        float density = getDensity(noisetex, point);                // ��ǰ�����ܶ�
        vec3 L = normalize(lightPos - point);                       // ��Դ����
        float lightDensity = getDensity(noisetex, point + L);       // ���Դ�������һ�� ��ȡ�ܶ�
        float delta = clamp(density - lightDensity, 0.0, 1.0);      // ���β����ܶȲ�

        // ����͸����
        density *= 0.5;

        // ��ɫ����
        vec3 base = mix(baseBright, baseDark, density) * density;   // ������ɫ
        vec3 light = mix(lightDark, lightBright, delta);            // ���ն���ɫӰ��

        // ���
        vec4 color = vec4(base*light, density);                     // ��ǰ���������ɫ
        colorSum = color * (1.0 - colorSum.a) + colorSum;           // ���ۻ�����ɫ���
    }

    return colorSum;
}

float getDensity(sampler2D noisetex, vec3 pos) {
    // �߶�˥��
    float mid = (bottom + top) / 2.0;
    float h = top - bottom;
    float weight = 1.0 - 2.0 * abs(mid - pos.y) / h;
    weight = pow(weight, 0.5);

    // ��������ͼ
    vec2 coord = pos.xz * 0.0025;
    float noise = texture2D(noisetex, coord).x;
	noise += texture2D(noisetex, coord*3.5).x / 3.5;
	noise += texture2D(noisetex, coord*12.25).x / 12.25;
	noise += texture2D(noisetex, coord*42.87).x / 42.87;	
	noise /= 1.4472;
    noise *= weight;

    // �ض�
    if(noise<0.4) {
        noise = 0;
    }

    return noise;
}
