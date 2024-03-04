#include "chat_client.hpp"
#include "input_message.hpp"

#include <thread>

int main()
{
	try
	{
		boost::asio::io_context io_context;
		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8888);
		chat_client client(io_context, endpoint);
		client.start();
		
		std::thread thread_input(input_thread, std::ref(client));

		io_context.run();

		thread_input.join();
	}
	catch (std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}