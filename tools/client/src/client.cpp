#include "client.hpp"

void Client::do_start() {
    boost::asio::ip::tcp::resolver resolver(m_ios);
    auto endpoits = resolver.resolve(m_ip, std::string{m_port});
    boost::system::error_code ec;
    boost::asio::connect(m_socket, endpoits, ec);
    if (ec) {
        std::cerr << "Connection error";
        return;
    }
    do_handle();
}

void Client::do_handle() {
    std::array<uint8_t, 10> data{};
    while (true) {
        std::cout << "Enter message: ";
        std::string msg;
        std::cin >> msg;
        boost::system::error_code ec;
        boost::asio::write(m_socket, boost::asio::buffer(msg, msg.size()), boost::asio::transfer_all(), ec);
        if (ec) {
            std::cerr << "Write error";
            return;
        }
        boost::asio::read(m_socket, boost::asio::buffer(data),boost::asio::transfer_at_least(0), ec);
        if (ec) {
            std::cerr << "Read error";
            return;
        }
        else std::cout << "From server: " << data.data() << std::endl;
    }

}
