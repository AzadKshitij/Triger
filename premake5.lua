workspace "Triger"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Triger/vendor/GLFW/include"
IncludeDir["Glad"] = "Triger/vendor/Glad/include"
IncludeDir["ImGui"] = "Triger/vendor/ImGui"
IncludeDir["glm"] = "Triger/vendor/glm"

group "Dependencies"
	include "Triger/vendor/GLFW"
	include "Triger/vendor/Glad"
	include "Triger/vendor/ImGui"

group ""


project "Triger"

	location "Triger"
	-- kind "SharedLib"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "trpch.h"
	pchsource "Triger/src/trpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS",
			"TR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		

	filter "configurations:Debug"
		defines "TR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TR_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Triger/vendor/spdlog/include",
		"Triger/src",
		"Triger/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Triger"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS"
		}
		-- postbuildcommands
		-- {
		-- 	("{COPY} ../bin/" .. outputdir .. "/Triger/Triger.dll" .. " ../bin/" .. outputdir .. "/%{prj.name}")
		-- }

	filter "configurations:Debug"
		defines "TR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TR_DIST"
		runtime "Release"
		optimize "on"