#include "client.hpp"

void Client::do_start() {
    boost::asio::ip::tcp::resolver resolver(m_ios);
    auto endpoits = resolver.resolve(m_ip, std::string{m_port});
    boost::system::error_code ec;
    boost::asio::connect(m_socket, endpoits, ec);
    if (ec) {
        std::cerr << "[ERROR] Connection refused";
        return;
    }
    do_handle();
}

void Client::do_handle() {
    while (true) {
        std::cout << "Enter message: ";
        std::string msg;
        std::cin >> msg;
        boost::system::error_code ec;
        boost::asio::write(m_socket, boost::asio::buffer(msg),ec);
        if (ec) {
            std::cerr << "[ERROR] Write failed";
            return;
        }
        boost::asio::read(m_socket, boost::asio::buffer(msg),ec);
        if (ec) {
            std::cerr << "[ERROR] Read failed";
            return;
        }
        else std::cout << "From server: " << msg.data() << std::endl;
    }
}
