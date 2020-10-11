#pragma once

#include "spdlog/logger.h"

namespace DOGE
{
	class Logger
	{
	public:
		Logger();
		~Logger();
	private:
		std::shared_ptr<spdlog::logger>  m_Logger;
	};
}


