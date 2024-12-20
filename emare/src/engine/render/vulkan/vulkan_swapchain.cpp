#include "vulkan_swapchain.hpp"

namespace emare
{
	vulkan_swapchain::vulkan_swapchain(const vkb::Device& vkb_device)
	{
		vkb::SwapchainBuilder swapchain_builder{vkb_device};
		const auto swapchain_builder_return = swapchain_builder.build();
		if (!swapchain_builder_return)
		{
			EMARE_LOG_ERROR("Failed to build swapchain: {}",
				swapchain_builder_return.error().message().c_str());
		}
	}
}
