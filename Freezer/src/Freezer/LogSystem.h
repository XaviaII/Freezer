#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Freezer {
	class FREEZER_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define FREEZER_CORE_TRACE(...) ::Freezer::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FREEZER_CORE_INFO(...)  ::Freezer::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FREEZER_CORE_WARN(...)  ::Freezer::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FREEZER_CORE_ERROR(...) ::Freezer::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FREEZER_CORE_FATAL(...) ::Freezer::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define FREEZER_TRACE(...) ::Freezer::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FREEZER_INFO(...)  ::Freezer::Log::GetClientLogger()->info(__VA_ARGS__)
#define FREEZER_WARN(...)  ::Freezer::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FREEZER_ERROR(...) ::Freezer::Log::GetClientLogger()->error(__VA_ARGS__)
#define FREEZER_FATAL(...) ::Freezer::Log::GetClientLogger()->fatal(__VA_ARGS__)
