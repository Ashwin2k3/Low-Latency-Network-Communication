#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <boost/asio.hpp>

class NetworkManager {
public:
    NetworkManager(const std::string& host, unsigned short port);
    void start();
    void stop();

private:
    void do_accept();
    void do_read();
    void do_write(const std::string& message);

    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::ip::tcp::socket socket_;
    std::string message_;
};

#endif // NETWORK_HPP

