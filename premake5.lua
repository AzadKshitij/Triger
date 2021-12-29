include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Triger"
	architecture "x86_64"
	startproject "Tridor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Triger/vendor/Box2D"
	include "Triger/vendor/GLFW"
	include "Triger/vendor/Glad"
	include "Triger/vendor/ImGui"
	include "Triger/vendor/yaml-cpp"


group ""

include "Triger"
include "Sandbox"
include "Tridor"
