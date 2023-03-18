#version 330 core

in vec2 texCoord;

uniform sampler2D texture_normal;
uniform vec3 color;
uniform bool chooseColor;

out vec4 FragColor;

void main()
{
    FragColor = chooseColor? vec4(color, 1.0) : texture(texture_normal, texCoord);
}
