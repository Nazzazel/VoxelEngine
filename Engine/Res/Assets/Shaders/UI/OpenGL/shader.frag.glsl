//#version 330 core
////in vec2 TexCoords;
//out vec4 color;
//
////uniform sampler2D text;
//uniform vec3 textColor;
//
//void main()
//{
//    // Sample the red channel from FreeType's single-channel bitmap and use it as alpha
//    //vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
//    color = vec4(textColor, 1.0) * sampled;
//    //color = vec4(1.0, 0.0, 0.0, 1.0);
//}


//#version 330 core
//in vec2 TexCoords;
//out vec4 color;
//
//uniform sampler2D text;
//uniform vec3 textColor;
//
//void main()
//{
//    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
//    color = vec4(textColor, 1.0) * sampled;
//}

#version 330 core
in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D textTexture;
uniform vec3 textColor;

void main()
{
    // Sample the red channel for font coverage, use it as alpha
    //vec4 sampled = vec4(1.0, 1.0, 1.0, texture(textTexture, TexCoords).r);
    //FragColor = vec4(textColor, 1.0) * sampled;

    FragColor = vec4(testColor, 1.0); // Renders a solid color
}