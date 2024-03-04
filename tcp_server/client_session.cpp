#include "client_session.hpp"

void client_session::start()
{
	do_read();
}

void client_session::deliver(const std::string& message)
{
	server_log::log_info("Delivering message: " + message);

	bool write_in_progress = !write_msgs_.empty();
	write_msgs_.push_back(message);

	if (!write_in_progress)
		do_write();
}

void client_session::do_read()
{
	auto self(shared_from_this());
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
		[this, self](boost::system::error_code ec, size_t length)
		{
			if (!ec)
			{
				std::string message(data_, length);
				server_log::log_info("Received message: " + message);

				for (auto& client : clients_)
				{
					if (client != shared_from_this())
						client->deliver(message);
				}
			}
			else
			{
				// Error handling: client disconnected
				auto remove_user_it = std::find(clients_.begin(), clients_.end(), shared_from_this());
				if (remove_user_it != clients_.end())
				{
					clients_.erase(remove_user_it);
					server_log::log_info("Client disconnected");
				}
			}
			do_read();
		});
}


void client_session::do_write()
{
	auto self(shared_from_this());

	boost::asio::async_write(socket_, boost::asio::buffer(write_msgs_.front()),
		[this, self](boost::system::error_code ec, size_t length)
		{
			if (!ec)
			{
				write_msgs_.pop_front();
				if (!write_msgs_.empty())
					do_write();
			}
		});
}