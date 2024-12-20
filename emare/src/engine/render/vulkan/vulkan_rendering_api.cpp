#include "vulkan_rendering_api.hpp"

#include "VkBootstrap.h"

namespace emare
{
	bool vulkan_rendering_api::is_api_supported()
	{
		// TODO: Is there better way to check if vulkan is supported?
		vkb::InstanceBuilder builder;
		if (const auto instance_return = builder.set_app_name("Emare")
		                                        .build(); !instance_return)
		{
			return false;
		}
		return true;
	}

	bool vulkan_rendering_api::initialize_graphics_context()
	{
		p_instance_ = std::make_unique<vulkan_instance>();
		p_surface_ = std::make_unique<vulkan_surface>(p_instance_->get_vk_instance());
		p_device_ = std::make_unique<vulkan_device>(p_instance_->get_vkb_instance(), p_surface_->get_vk_surface());
		p_swapchain_ = std::make_unique<vulkan_swapchain>(p_device_->get_vkb_device());
		return true;
	}

	bool vulkan_rendering_api::set_device_event_handler()
	{
		return true;
	}

	bool vulkan_rendering_api::initialize_graphics_device()
	{
		return true;
	}

	bool vulkan_rendering_api::configure_pipeline_cache()
	{
		return true;
	}
}
