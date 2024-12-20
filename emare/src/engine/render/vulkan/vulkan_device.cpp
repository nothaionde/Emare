#include "vulkan_device.hpp"

namespace emare
{
	vulkan_device::vulkan_device(const vkb::Instance& vkb_instance, const VkSurfaceKHR vk_surface)
	{
		// We should not use any vkb in constructor need to rewrite this part of code
		vkb::PhysicalDeviceSelector physical_device_selector{vkb_instance};
		const auto physical_device_selector_return = physical_device_selector.set_surface(vk_surface).select();
		if (!physical_device_selector_return)
		{
			EMARE_LOG_ERROR("Failed to select physical device: {}",
			                physical_device_selector_return.error().message().c_str());
		}
		const auto& device = physical_device_selector_return.value();
		const vkb::DeviceBuilder device_builder{device};
		const auto device_return = device_builder.build();
		if (!device_return)
		{
			EMARE_LOG_ERROR("Failed to build physical device: {}",
			                device_return.error().message().c_str());
		}
		vkb_physical_device_ = device_return.value();
		vkb_dispatch_table_ = vkb_physical_device_.make_table();
	}
}
