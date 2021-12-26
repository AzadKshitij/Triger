/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Sandbox
//   License     : https://opensource.org/licenses/MIT
//   File        : FlatColor.glsl
//   Created On  : 11/11/2020
//   Updated On  : 11/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
// Flat Color Shader

#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

void main()
{
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
	color = u_Color;
}