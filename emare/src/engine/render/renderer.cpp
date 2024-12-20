#include "renderer.hpp"

#include "gpu_api_interface.hpp"
#include "vulkan/vulkan_rendering_api.hpp"

namespace emare
{
	std::unique_ptr<render> g_render = nullptr;

	render::render()
		: requested_exit_(false),
		  return_value_(0)
	{
	}

	void render::initialize()
	{
		viewport_ = std::make_unique<viewport>();
		gpu_api_ = gpu_api::get_gpu_api();
		const bool is_supported = gpu_api_->is_api_supported();
		assert(is_supported);
		gpu_api_->initialize_graphics_context();
		gpu_api_->set_device_event_handler();
		gpu_api_->initialize_graphics_device();
		gpu_api_->configure_pipeline_cache();
		viewport_->initialize_imgui();
		EMARE_LOG("Renderer initialized.");
	}

	void render::tick(const info tick_info) const
	{
		viewport_->imgui_new_frame(tick_info.delta_time);
		//viewport_->begin_frame();
		//viewport_->draw_imgui();
		//viewport_->imgui_end_frame();
		//viewport_->end_frame();
	}

	void render::request_exit(int program_return_value)
	{
		requested_exit_ = true;
		return_value_ = program_return_value;
	}

	void render::create_renderer()
	{

	}
}
