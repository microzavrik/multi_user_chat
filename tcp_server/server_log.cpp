#include "server_log.hpp"


void server_log::log_warning(const std::string& message)
{
	print_log("WARNING", message, color_t::yellow);
}

void server_log::log_info(const std::string& message)
{
	print_log("INFO", message, color_t::white);
}

void server_log::log_error(const std::string& message)
{
	print_log("ERROR", message, color_t::red);
}

void server_log::log_sucess_notify(const std::string& message)
{
	print_log("SUCCESS", message, color_t::green);
}

void server_log::print_log(const std::string& log_type, const std::string& message, const color_t& color)
{
	std::time_t now = std::time(nullptr);
	std::tm* local_time = std::localtime(&now);

	switch (color)
	{
	case color_t::red:
		std::cout << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] ";
		std::cout << termcolor::red << "[" << log_type << "] " << message << termcolor::reset << std::endl;
		break;
	case color_t::yellow:
		std::cout << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] ";
		std::cout << termcolor::yellow << "[" << log_type << "] " << message << termcolor::reset << std::endl;
		break;
	case color_t::white:
		std::cout << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] ";
		std::cout << termcolor::white << "[" << log_type << "] " << message << termcolor::reset << std::endl;
		break;
	case color_t::green:
		std::cout << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] ";
		std::cout << termcolor::green << "[" << log_type << "] " << message << termcolor::reset << std::endl;
		break;
	default:
		std::cout << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] ";
		std::cout << termcolor::yellow << "[" << log_type << "] " << "Undefined log" << termcolor::reset << std::endl;
		break;
	}
}