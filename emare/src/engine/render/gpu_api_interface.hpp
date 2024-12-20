#pragma once

namespace emare
{
	enum api : std::uint8_t
	{
		headless,
		vulkan,
		direct_x,
		open_gl
	};

	class gpu_api
	{
	public:
		static std::unique_ptr<gpu_api> get_gpu_api(api api = vulkan);
		virtual ~gpu_api() = default;
		virtual bool is_api_supported() = 0;
		virtual bool initialize_graphics_context() = 0;
		virtual bool set_device_event_handler() = 0;
		virtual bool initialize_graphics_device() = 0;
		virtual bool configure_pipeline_cache() = 0;

	private:
		inline static api api_;
	};
}
