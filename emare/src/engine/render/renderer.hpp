#pragma once
#include "gpu_api_interface.hpp"
#include "viewport.hpp"
#include "backends/imgui_impl_glfw.h"
#include "GLFW/glfw3.h"
#include "src/engine/engine/engine.hpp"

namespace emare
{
	extern std::unique_ptr<class render> g_render;

	class render
	{
	public:
		render();
		void initialize();
		void tick(info tick_info) const;
		void request_exit(int program_return_value = 0);
		void create_renderer();
		std::any get_window_handle() const
		{
			return viewport_->get_window_handle();
		}

	private:
		std::unique_ptr<viewport> viewport_;
		std::unique_ptr<gpu_api> gpu_api_;
		bool requested_exit_;
		int return_value_;
	};
}
