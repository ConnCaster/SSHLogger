#ifndef SSH_LOGGER_CONNECTION_HPP
#define SSH_LOGGER_CONNECTION_HPP

#include <iostream>
#include <memory>
#include <boost/asio.hpp>

class Connection : public std::enable_shared_from_this<Connection> {
public:
    Connection(boost::asio::ip::tcp::socket socket)
            : m_socket(std::move(socket)) {
    }

    void do_start();

private:

    void do_read();

private:
    boost::asio::ip::tcp::socket m_socket;
    std::array<uint8_t, 20> m_data;
};

#endif //SSH_LOGGER_CONNECTION_HPP
