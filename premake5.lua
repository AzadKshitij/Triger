include "./vendor/premake/premake_customization/solution_items.lua"

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

-- Include directories relative to root folder (solution directory)

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Triger/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Triger/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Triger/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Triger/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Triger/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Triger/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Triger/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Triger/vendor/Box2D/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Triger/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Triger/vendor/Box2D"
	include "Triger/vendor/GLFW"
	include "Triger/vendor/Glad"
	include "Triger/vendor/ImGui"
	include "Triger/vendor/yaml-cpp"


group ""

include "Triger"
include "Tridor"
