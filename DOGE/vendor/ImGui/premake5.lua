project "ImGui"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/imgui.cpp",
		"include/imgui.h",
		"include/imgui_demo.cpp",
		"include/imconfig.h",
		"include/imgui_draw.cpp",
		"include/imgui_internal.h",
		"include/imgui_widgets.cpp",
		"include/imstb_rectpack.h",
		"include/imstb_textedit.h",
		"include/imstb_truetype.h",
	}

	includedirs
	{
		"include"
	}

	filter "configurations:Debug"
		defines "ImGui_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "ImGui_RELEASE"
		runtime "Release"
		symbols "On"
