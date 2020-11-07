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
group "Dependencies"
	include "Triger/vendor/GLFW"
	include "Triger/vendor/Glad"
	include "Triger/vendor/ImGui"

group ""


project "Triger"

	location "Triger"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "trpch.h"
	pchsource "Triger/src/trpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS",
			"TR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		

	filter "configurations:Debug"
		defines "TR_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "TR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TR_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Triger/src"
	}

	links
	{
		"Triger"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOWS"
		}
		postbuildcommands
		{
			("{COPY} ../bin/" .. outputdir .. "/Triger/Triger.dll" .. " ../bin/" .. outputdir .. "/%{prj.name}")
		}

	filter "configurations:Debug"
		defines "TR_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "TR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TR_DIST"
		buildoptions "/MD"
		optimize "On"