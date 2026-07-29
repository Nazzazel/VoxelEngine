#version 330 core




in vec3 v_Color;
in vec2 TexCoord;

uniform vec3 objectColor;
uniform vec3 lightColor;


out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
    //FragColor = vec4(v_Color, 1.0);
    //FragColor = vec4(1.0, 0.5, 0.25, 1.0);
    //FragColor = vec4(lightColor * objectColor, 1.0);

    FragColor = texture(ourTexture,TexCoord) * vec4(v_Color, 1.0);

}
