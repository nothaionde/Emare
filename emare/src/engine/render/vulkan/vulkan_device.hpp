#pragma once
#include <VkBootstrap.h>

namespace emare
{
	class vulkan_device
	{
	public:
		explicit vulkan_device(const vkb::Instance& vkb_instance, VkSurfaceKHR vk_surface);
		vkb::Device get_vkb_device() const
		{
			return vkb_physical_device_;
		}
	private:
		vkb::Device vkb_physical_device_;
		vkb::DispatchTable vkb_dispatch_table_;
	};
}