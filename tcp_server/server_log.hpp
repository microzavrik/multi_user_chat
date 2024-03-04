#ifndef server_log_hpp
#define server_log_hpp

#include <iomanip>
#include <ctime>

#include <termcolor.hpp>

#include "color_t.hpp"

class server_log
{
public:
	static void log_warning(const std::string& message);
	static void log_info(const std::string& message);
	static void log_error(const std::string& message);
	static void log_sucess_notify(const std::string& message);
private:
	static void print_log(const std::string& log_type, const std::string& message, const color_t& color);
};

#endif