#include "network/server.hpp"

Server::Server(boost::asio::io_context &io_context, uint16_t port)
        : m_io_context(io_context),
          m_acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
          {}

void Server::do_start() {
    do_accept();
}

void Server::do_accept() {
    m_acceptor.async_accept([this](const boost::system::error_code& err, tcp::socket socket){
        if (!err) {
            std::cout << "accepted" << std::endl;
        }
        do_accept();
    });
}



