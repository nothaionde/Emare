#pragma once
#include <src/engine/render/gpu_api_interface.hpp>
#include "vulkan_instance.hpp"
#include "vulkan_surface.hpp"
#include "vulkan_device.hpp"
#include "vulkan_swapchain.hpp"

namespace emare
{
	// TODO: parse here program name, maybe preferable version and other renderer related things like version ect.
	class vulkan_rendering_api final : public gpu_api
	{
	public:
		bool is_api_supported() override;
		bool initialize_graphics_context() override;
		bool set_device_event_handler() override;
		bool initialize_graphics_device() override;
		bool configure_pipeline_cache() override;

	private:
		std::unique_ptr<vulkan_instance> p_instance_;
		std::unique_ptr<vulkan_surface> p_surface_;
		std::unique_ptr<vulkan_device> p_device_;
		std::unique_ptr<vulkan_swapchain> p_swapchain_;
	};
}
