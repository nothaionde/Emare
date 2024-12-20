#include "vulkan_surface.hpp"
#include <GLFW/glfw3.h>

#include "src/engine/render/renderer.hpp"

namespace emare
{
	vulkan_surface::vulkan_surface(const VkInstance vk_instance)
	{
		if (const auto result = glfwCreateWindowSurface(vk_instance,
		                                                std::any_cast<GLFWwindow*>(g_render->get_window_handle()),
		                                                nullptr, &vk_surface_khr_); result != VK_SUCCESS)
		{
			EMARE_LOG_ERROR("Vulkan surface creation failed! {}", result);
		}
	}
}
