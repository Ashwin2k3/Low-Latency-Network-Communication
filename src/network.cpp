#include "network.hpp"
#include <iostream>

NetworkManager::NetworkManager(const std::string& host, unsigned short port)
    : io_context_(), acceptor_(io_context_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), socket_(io_context_) {}

void NetworkManager::start() {
    do_accept();
    io_context_.run();
}

void NetworkManager::stop() {
    io_context_.stop();
}

void NetworkManager::do_accept() {
    acceptor_.async_accept(socket_, [this](const boost::system::error_code& error) {
        if (!error) {
            do_read();
        }
    });
}

void NetworkManager::do_read() {
    auto buffer = std::make_shared<boost::asio::streambuf>();
    boost::asio::async_read_until(socket_, *buffer, "\n",
        [this, buffer](const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (!error) {
                // Process data
                std::istream is(buffer.get());
                std::string data;
                std::getline(is, data);
                std::cout << "Received: " << data << std::endl;
                do_write(data); // Echo back
            }
        });
}

void NetworkManager::do_write(const std::string& message) {
    boost::asio::async_write(socket_, boost::asio::buffer(message + "\n"),
        [this](const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (!error) {
                do_read();
            }
        });
}

