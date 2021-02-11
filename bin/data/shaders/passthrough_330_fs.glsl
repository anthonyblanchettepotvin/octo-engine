#version 330

uniform sampler2D image;

in vec2 surface_texcoord;

out vec4 fragment_color;

void main()
{
  vec4 texture_sample = texture(image, surface_texcoord);

  fragment_color = texture_sample;
}
