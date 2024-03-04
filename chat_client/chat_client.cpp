#include "chat_client.hpp"

chat_client::chat_client(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint)
    : socket_(io_context) {
    socket_.connect(endpoint);
}

void chat_client::start()
{
    do_read();
}

void chat_client::send_message(const std::string& message)
{
    boost::asio::write(socket_, boost::asio::buffer(message));
}

void chat_client::do_read()
{
    socket_.async_read_some(boost::asio::buffer(data_),
        [this](boost::system::error_code ec, size_t length)
        {
            if (!ec)
            {
                std::cout << "Received message from server: " << std::string(data_.begin(), data_.begin() + length)
                    << std::endl;
                do_read();
            }
        });
}