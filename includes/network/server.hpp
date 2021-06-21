#ifndef SSH_LOGGER_SERVER_HPP
#define SSH_LOGGER_SERVER_HPP

#include <boost/asio.hpp>
#include <iostream>

#include <network/connection.hpp>
#include <msgpack.hpp>

using tcp = boost::asio::ip::tcp;

class Server{
public:
    Server(boost::asio::io_context& io_context, uint16_t port);
    ~Server() {
      std::cout << "Server dtor\n";
    };

private:
    void do_accept();

private:
    boost::asio::io_context& m_io_context;
    boost::asio::ip::tcp::acceptor m_acceptor;
};

#endif //SSH_LOGGER_SERVER_HPP
