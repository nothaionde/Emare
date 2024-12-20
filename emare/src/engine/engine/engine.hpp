#pragma once

namespace emare
{
	extern std::unique_ptr<class engine> g_engine;

	struct info
	{
		float delta_time;
	};
	class engine
	{
	public:
		engine();
		void initialize();
		void request_exit(int program_return_value = 0);
		bool requested_exit() const { return is_requested_exit_; }
		int get_return_value() const { return program_return_value_; }
		void tick();
		bool pump_messages();

	private:
		bool is_requested_exit_;
		int program_return_value_;
		info tick_info_;
	};
}
