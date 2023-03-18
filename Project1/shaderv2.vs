#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 normalTransform;

out vec3 fragPos;
out vec3 normal;
out vec2 texCoord;

void main()
{
    mat4 transform = projection * view * model;
	gl_Position = transform * vec4(aPos, 1.0);

	normal = vec3(normalTransform * vec4(aNormal, 0.0));
	texCoord = aTexCoord;
    fragPos = vec3(model * vec4(aPos, 1.0)); //�����������м���
	
}