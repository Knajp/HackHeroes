#include "Logger.hpp"
#ifdef DEBUG
sk::debug::Logger::Logger(std::string name, spdlog::level::level_enum level)
{
	mLogger = spdlog::stdout_color_mt(name);
	mLogger->set_level(level);
	mLogger->set_pattern("%^[%H:%M:%S] %n %l: %v%$");
}

void sk::debug::Logger::trace(const std::string& message) const
{
	mLogger->trace(message.c_str());
}

void sk::debug::Logger::debug(const std::string& message) const
{
	mLogger->debug(message.c_str());
}

void sk::debug::Logger::info(const std::string& message) const
{
	mLogger->info(message.c_str());
}

void sk::debug::Logger::warn(const std::string& message) const
{
	mLogger->warn(message.c_str());
}

void sk::debug::Logger::error(const std::string& message) const
{
	mLogger->error(message.c_str());
}

void sk::debug::Logger::critical(const std::string& message) const
{
	mLogger->critical(message.c_str());
}
#endif