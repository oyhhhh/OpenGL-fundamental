#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 texCoord;

void main()
{
    mat4 transform = projection * view * model;
	gl_Position = transform * vec4(aPos, 1.0);

	texCoord = vec2(aTexCoord.x, aTexCoord.y);
}