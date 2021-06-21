#include <iostream>
#include <boost/asio.hpp>
#include <msgpack.hpp>

class Client {
public:
    Client(boost::asio::io_context &ios, std::string ip, std::string port)
            : m_ios(ios), m_ip(ip), m_port(port), m_socket(ios) {}

    void do_start();

private:

    void do_handle();

private:
    boost::asio::io_context &m_ios;
    boost::asio::ip::tcp::socket m_socket;
    const std::string m_ip;
    const std::string m_port;
};