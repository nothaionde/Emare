#include "application.hpp"

#include <windows.h>
#include <src/engine/engine/engine.hpp>

namespace emare
{
	void application::initialize()
	{
		assert(!g_engine, "Engine should be initialized only once!");
		g_engine = std::make_unique<engine>();
		g_engine->initialize();
		EMARE_LOG("Application initialized.");
	}

	int application::run()
	{
		do
		{
			g_engine->pump_messages();
			g_engine->tick();
		}
		while (!g_engine->requested_exit());
		return g_engine->get_return_value();
	}
}
