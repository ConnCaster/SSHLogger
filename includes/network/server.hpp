#ifndef SSH_LOGGER_SERVER_HPP
#define SSH_LOGGER_SERVER_HPP

#include <boost/asio.hpp>

class Connection{

};

class Server{
public:
    Server(boost::asio::io_context& io_context)
    :m_io_context(io_context),
    m_acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 5000))
    {

    }


private:
    boost::asio::io_context& m_io_context;
    boost::asio::ip::tcp::acceptor m_acceptor;
};

#endif //SSH_LOGGER_SERVER_HPP
