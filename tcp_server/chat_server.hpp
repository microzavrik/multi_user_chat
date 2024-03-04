#ifndef chat_server_hpp
#define chat_server_hpp

#include <iostream>
#include <vector>

#include <boost/asio.hpp>

#include "client_session.hpp"
#include "server_log.hpp"

class chat_server
{
public:
	chat_server(boost::asio::io_context& io, const boost::asio::ip::tcp::endpoint& endpoint) 
		: acceptor_(io, endpoint), socket_(io) 
	{
		server_log::log_sucess_notify("Start listing clients");
		do_accept();
	}

private:
	void do_accept();
private:
	boost::asio::ip::tcp::acceptor acceptor_;
	boost::asio::ip::tcp::socket socket_;
	std::vector<std::shared_ptr<client_session>> clients_;
};

#endif