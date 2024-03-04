#include "chat_server.hpp"

int main()
{
	try
	{
		boost::asio::io_context io_context;
		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 8888);
		chat_server server(io_context, endpoint);
		io_context.run();
	}
	catch (std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}