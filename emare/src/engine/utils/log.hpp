#pragma once
#include <windows.h>
#include <chrono>
#include <cstdarg>

namespace emare
{
	inline constexpr uint32_t logging_message_length = 1024;

	struct logging_message
	{
		std::chrono::system_clock::time_point time;
		char buffer[logging_message_length];
	};

	inline void log_message(const char* message, ...)
	{
		// TODO: change logging implementation. output debug string is not the way
		logging_message output_message
		{
			.time = std::chrono::system_clock::now()
		};
		va_list args;
		va_start(args, message);
		vsnprintf_s(output_message.buffer, logging_message_length, _TRUNCATE, message, args);
		va_end(args);
		if (const size_t len = strlen(output_message.buffer); len < logging_message_length - 1)
		{
			output_message.buffer[len] = '\n';
			output_message.buffer[len + 1] = '\0';
		}
		OutputDebugStringA(output_message.buffer);
	}
}

#define EMARE_LOG(message, ...) do { emare::log_message(message, ##__VA_ARGS__); } while ((void) 0, 0)
#define EMARE_LOG_ERROR(message, ...) do { emare::log_message(message, ##__VA_ARGS__); } while ((void) 0, 0)
