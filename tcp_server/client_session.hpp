#ifndef client_session_hpp
#define client_session_hpp

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <memory>

#include <boost/asio.hpp>

#include "server_log.hpp"

class client_session : public std::enable_shared_from_this<client_session>
{
public:
	client_session(boost::asio::ip::tcp::socket socket, std::vector<std::shared_ptr<client_session>>& clients)
		: socket_(std::move(socket)), clients_(clients) {}
	void start();                                             // Method to start the client session
	void deliver(const std::string& message);                 // Method to deliver a message to all other clients
private: 
	void do_read();                                           // Method to read messages from the client
	void do_write();                                          // Method to write messages to the client
private:
	boost::asio::ip::tcp::socket socket_;                     // Socket for communication with the client
	std::vector<std::shared_ptr<client_session>>& clients_;   // Reference to the list of active clients
	enum { max_length = 1024 };
	char data_[max_length];
	std::deque<std::string> write_msgs_;                      // Queue for outgoing messages
};


#endif