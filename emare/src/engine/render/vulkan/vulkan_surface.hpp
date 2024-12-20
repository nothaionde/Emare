#pragma once
#include <VkBootstrap.h>

namespace emare
{
	class vulkan_surface
	{
	public:
		explicit vulkan_surface(VkInstance vk_instance);

		VkSurfaceKHR get_vk_surface() const
		{
			return vk_surface_khr_;
		}

	private:
		VkSurfaceKHR vk_surface_khr_{VK_NULL_HANDLE};
	};
}
