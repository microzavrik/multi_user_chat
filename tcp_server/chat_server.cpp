#include "chat_server.hpp"

void chat_server::do_accept()
{
	acceptor_.async_accept(socket_,
		[this](boost::system::error_code ec)
		{
			if (!ec)
			{
				std::shared_ptr<client_session> new_client = std::make_shared<client_session>(std::move(socket_), clients_);
				new_client->start();
				clients_.push_back(new_client);
				server_log::log_info("New client connected | Total online: " + std::to_string(clients_.size()));			
			}
			do_accept();
		});
}