#ifndef input_message_hpp
#define input_message_hpp

#include <iostream>
#include <string>

#include "chat_client.hpp"

#include <termcolor.hpp>

void input_thread(chat_client& client)
{
	std::string message;
	while (true)
	{
		std::cout << termcolor::green << "[FOR SERVER]: ";
		std::getline(std::cin, message);
		client.send_message(message);
		std::cout << termcolor::white << "[INFO] Message send!" << std::endl;
	}
}

#endif