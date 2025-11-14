#version 330

out vec4 fragColor;
in vec3 vColor;

void main()
{
	fragColor = vec4(vColor);
}