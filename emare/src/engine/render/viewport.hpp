#pragma once
#include <any>

#include "window.hpp"
#include "imgui.h"

namespace emare
{
	enum viewport_window_mode : uint8_t
	{
		viewport_window_mode_windowed,
		viewport_window_mode_borderless,
		viewport_window_mode_fullscreen
	};

	struct viewport_initialization_params
	{
		int32_t width = 800;
		int32_t height = 600;
		const char* window_name;
		viewport_window_mode window_mode = viewport_window_mode_windowed;
		std::any window_handle = nullptr;
		std::any monitor_for_full_screen;
		std::any window_to_share_resources_with;
	};

	class viewport
	{
	public:
		viewport();
		void initialize_imgui();
		void imgui_new_frame(float delta_time);
		std::any get_window_handle()
		{
			return viewport_initialization_params_.window_handle;
		}
	private:
		viewport_initialization_params viewport_initialization_params_;
		std::unique_ptr<window> window_;
		ImGuiContext* im_gui_context_;
	};
}
