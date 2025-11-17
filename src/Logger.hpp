#pragma once
#ifdef DEBUG
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

namespace sk
{
	namespace debug
	{
		class Logger
		{
		public:
			Logger() = default;
			Logger(std::string name, spdlog::level::level_enum level);

			void trace(const std::string& message) const;
			void debug(const std::string& message) const;
			void info(const std::string& message) const;
			void warn(const std::string& message) const;
			void error(const std::string& message) const;
			void critical(const std::string& message) const;

		private:
			std::shared_ptr<spdlog::logger> mLogger;
		};
	}
}
#endif