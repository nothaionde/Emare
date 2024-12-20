#pragma once
#include "VkBootstrap.h"

namespace emare
{
	class vulkan_swapchain
	{
	public:
		explicit vulkan_swapchain(const vkb::Device& vkb_device);
	private:
		vkb::Swapchain vkb_swapchain_;
	};
}
