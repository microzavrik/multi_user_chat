#ifndef chat_client_hpp
#define chat_client_hpp

#include <iostream>
#include <array>

#include <boost/asio.hpp>

class chat_client
{
public:
	chat_client(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint);
	void start();
	void send_message(const std::string& message);
private:
	void do_read();
private:
	enum { max_length = 1024 };
	boost::asio::ip::tcp::socket socket_;
	std::array<char, max_length> data_;
};


#endif