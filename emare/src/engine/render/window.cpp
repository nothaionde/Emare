#include "window.hpp"

#include "viewport.hpp"
#include "GLFW/glfw3.h"

namespace emare
{
	window::window(viewport_initialization_params& initialization_params)
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		// TODO: after adding fullscreen of windowed or borderless need to recheck window creation
		initialization_params.window_handle = glfwCreateWindow(initialization_params.width,
		                                                       initialization_params.height,
		                                                       initialization_params.window_name,
		                                                       initialization_params.window_mode ==
		                                                       viewport_window_mode_windowed
			                                                       ? nullptr
			                                                       : std::any_cast<GLFWmonitor*>(
				                                                       initialization_params.monitor_for_full_screen),
		                                                       initialization_params.window_to_share_resources_with.
		                                                       has_value()
			                                                       ? std::any_cast<GLFWwindow*>(
				                                                       initialization_params.
				                                                       window_to_share_resources_with)
			                                                       : nullptr
		);
	}

	void window::update()
	{
	}
}
