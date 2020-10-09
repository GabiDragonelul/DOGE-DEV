workspace "DOGE DEV"
	language "C++"
	architecture "x64"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project DOGE
	location "DOGE"
	kind "StaticLib"
	cppdialect "17"

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
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "RELEASE" }
		symbols "On"

project "Game"
	location "Game"
	language "C++17"
	kind "ConsoleApp"

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
		"DOGE/src",
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "RELEASE" }
		symbols "On"




