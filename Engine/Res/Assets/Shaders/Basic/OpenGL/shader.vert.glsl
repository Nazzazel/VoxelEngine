#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Color;
layout (location = 2) in vec2 aTexCoord;

out vec3 v_Color;
out vec2 TexCoord;



uniform mat4 u_Projection;
uniform mat4 u_View;
uniform mat4 u_Model;


void main()
{
    v_Color = a_Color;
    TexCoord = aTexCoord;
    //gl_Position = u_Projection * vec4(a_Position, 1.0);

    // We multiply Projection * Model * Position.
    // We also temporarily subtract 3.0 from Z so it sits in front of the camera.
   // vec4 worldPosition = u_Model * vec4(a_Position, 1.0);
    //worldPosition.z -= 3.0f;

    //gl_Position = u_Projection * vec4(a_Position.xy, a_Position.z - 5, 1.0);
    gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0);

    //gl_Position = u_Projection * worldPosition * u_Model * vec4(a_Position, 0.5);
}

//#version 330 core
//layout (location = 0) in vec3 a_Position;
//layout (location = 1) in vec3 a_Color;
////layout (location = 2) in vec2 a_TexCoord;
//
////uniform mat4 u_Model; // <-- Add this uniform
//
//out vec3 v_Color;
////out vec2 TexCoord;
//
//void main()
//{
//
//
//    gl_Position = vec4(a_Position, 1.0);
//    v_Color = a_Color;
//    //TexCoord = a_TexCoord;
//
//}
