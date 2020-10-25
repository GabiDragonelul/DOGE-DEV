workspace "DOGE DEV"
	architecture "x64"
	configurations { "Debug", "Release" }
	
	startproject "Game"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["GLFW"] = "DOGE/vendor/GLFW/include"
IncludeDirs["Glad"] = "DOGE/vendor/Glad/include"
IncludeDirs["ImGui"] = "DOGE/vendor/ImGui/include"

include "DOGE/vendor/GLFW"
include "DOGE/vendor/Glad"
include "DOGE/vendor/ImGui"

project "DOGE"
	location "DOGE"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pchDOGE.h"
	pchsource "%{prj.name}/src/pchDOGE.cpp"

	files
	{
		"%{prj.name}/src/**.cpp", 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/vendor/spdlog/include/**.h",
		"%{prj.name}/vendor/spdlog/include/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.ImGui}",
		"%{IncludeDirs.Glad}",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"DOGE_PLATFORM_WINDOWS"
		}

	links
	{
		"GLFW",
		"opengl32.lib",
		"Glad",
		"ImGui",
	}

	filter "configurations:Debug"
		defines "DOGE_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "DOGE_RELEASE"
		runtime "Release"
		symbols "On"

project "Game"
	kind "ConsoleApp"
	location "Game"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp", 
		"%{prj.name}/src/**.h",
	}

	includedirs
	{
		"%{prj.name}/src",
		"DOGE/vendor/spdlog/include",
		"DOGE/src",
	}

	links
	{
		"DOGE",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"DOGE_WINDOWS"
		}

	filter "configurations:Debug"
		defines "Game_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "Game_RELEASE"
		runtime "Release"
		symbols "On"