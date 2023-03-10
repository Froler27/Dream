#version 430 core

void main(void)
{
    const vec4 vertices[3] = vec4[3](
        vec4(0.25, -0.25, 0.5, 1.0),
        vec4(-0.25, -0.25, 0.5, 1.0),
        vec4(0.25, 0.25, 0.5, 1.0));
    const vec4 vertices2[3] = vec4[3](
        vec4(0, -1, 0.5, 1.0),
        vec4(-1, 0, 0.5, 1.0),
        vec4(0, 0, 0.5, 1.0));
    gl_Position = vertices[gl_VertexID];
}