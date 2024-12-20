#include "engine.hpp"
#include <GLFW/glfw3.h>
#include "src/engine/render/renderer.hpp"

namespace emare
{
	std::unique_ptr<engine> g_engine = nullptr;

	engine::engine()
		: is_requested_exit_(false),
		  program_return_value_(0),
		  tick_info_()
	{
	}

	void engine::initialize()
	{
		assert(!g_render, "Renderer should be initialized only once!");
		g_render = std::make_unique<render>();
		g_render->initialize();
		g_render->create_renderer();
		EMARE_LOG("Engine initialized.");
	}

	void engine::request_exit(const int program_return_value)
	{
		is_requested_exit_ = true;
		program_return_value_ = program_return_value;
	}

	void engine::tick()
	{
		// TODO: set delta time correctly!
		tick_info_.delta_time = 0;
		g_render->tick(tick_info_);
	}

	bool engine::pump_messages()
	{
		// TODO: move glfw code to another place. Not the place for library specific code
		glfwPollEvents();
		return true;
	}
}
