#include "pchDOGE.h"
#include "ImGuiLayer.h"

#include "Core/Application.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"


// TEMPORARY
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace DOGE {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
		//OnAttach();
	}

	void ImGuiLayer::OnAttach()
	{
		// Setup Dear ImGui context
		ImGui::CreateContext();
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnImGuiRender()
	{
	}

	void ImGuiLayer::OnEvent(Event& e)
	{
	}

	void ImGuiLayer::Begin()
	{
	}

	void ImGuiLayer::End()
	{
	}

	void ImGuiLayer::SetDarkThemeColors()
	{
	}

}
