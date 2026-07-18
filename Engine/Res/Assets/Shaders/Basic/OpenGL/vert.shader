#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Color;

out vec3 v_Color;

uniform mat4 u_Projection;
uniform mat4 u_Model; // <-- Add this uniform
uniform float u_X;
void main()
{
    v_Color = a_Color;
    //gl_Position = u_Projection * vec4(a_Position, 1.0);
   
    // We multiply Projection * Model * Position. 
    // We also temporarily subtract 3.0 from Z so it sits in front of the camera.
    vec4 worldPosition = u_Model * vec4(a_Position, 1.0);
    worldPosition.z -= u_X;

    //gl_Position = u_Projection * vec4(a_Position.xy, a_Position.z - 5, 1.0);
    gl_Position = u_Projection * worldPosition;
}