//#version 330 core
////layout (location = 0) in vec4 a_Vertex; // <vec2 pos, vec2 tex>
//
//layout(location = 0) in vec2 a_Position;
////layout (location = 1) in vec2 aTexCoord;
//
////out vec2 TexCoords;
//
//uniform mat4 u_Projection;
//
//void main()
//{
//    gl_Position = vec4(a_Position, 0.0, 1.0);
//    //gl_Position = u_Projection * vec4(a_Position, 0.0, 1.0);
//    //TexCoords = aTexCoord;
//}


#version 330 core
//layout (location = 0) in vec4 vertex; // <vec2 pos, vec2 tex>

layout(location = 0) in vec2 a_Position;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoords;

uniform mat4 u_Projection;
//out vec4 v_DebugColor;


void main()
{
    //gl_Position = vec4(a_Position, 0.0, 1.0);

    gl_Position = u_Projection * vec4(a_Position.xy, 0.0, 1.0);
    //v_DebugColor = vec4(u_Projection[0][0], u_Projection[1][1], u_Projection[2][2], 1.0);
    TexCoords = aTexCoord;
}
