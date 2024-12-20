#include "viewport.hpp"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_vulkan.h"


namespace emare
{
	viewport::viewport()
		: viewport_initialization_params_(),
		  im_gui_context_(nullptr)
	{
		viewport_initialization_params_.window_name = "Emare";
		window_ = std::make_unique<window>(viewport_initialization_params_);
		//IM_ASSERT(info->Instance != VK_NULL_HANDLE);
		//IM_ASSERT(info->PhysicalDevice != VK_NULL_HANDLE);
		//IM_ASSERT(info->Device != VK_NULL_HANDLE);
		//IM_ASSERT(info->Queue != VK_NULL_HANDLE);
		//IM_ASSERT(info->DescriptorPool != VK_NULL_HANDLE);
		//IM_ASSERT(info->MinImageCount >= 2);
		//IM_ASSERT(info->ImageCount >= info->MinImageCount);
	}

	void viewport::initialize_imgui()
	{
		IMGUI_CHECKVERSION();
		im_gui_context_ = ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		// TODO: setup path for imgui.ini file
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // IF using Docking Branch
		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForVulkan(std::any_cast<GLFWwindow*>(viewport_initialization_params_.window_handle), false);
		ImGui_ImplVulkan_InitInfo vulkan_init_info{};
		ImGui_ImplVulkan_Init(&vulkan_init_info);
		ImGui_ImplVulkan_CreateFontsTexture();
	}

	void viewport::imgui_new_frame(const float delta_time)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DeltaTime = delta_time;
		//io.DisplaySize.x = static_cast<float>(get_width());
		//io.DisplaySize.y = static_cast<float>(get_height());
		ImGui::NewFrame();
	}
}
