#include "network/connection.hpp"

void Connection::do_start() {
    do_read();
}

void Connection::do_read() {
    m_socket.async_read_some(boost::asio::buffer(m_data),
         [self = shared_from_this()](const boost::system::error_code &error,
                                     std::size_t bytes_transferred) {
             if (!error) {
                 std::string recv_msg{self->m_data.begin(), self->m_data.begin() + bytes_transferred};
                 std::cout << "Received from client: " << recv_msg.data() << std::endl;
                 self->m_socket.async_write_some(boost::asio::buffer(recv_msg),
                                           [self](
                                                   const boost::system::error_code &error,
                                                   std::size_t bytes_transferred) {
                                           });
             } else {
                 std::cerr << "[ERROR] Reading failed. Connection is closed." << std::endl;
                 return;
             }
             self->do_read();
         });
}