#include <iostream>
#include "client.hpp"

int main(){

    boost::asio::io_context ios;
//    boost::asio::signal_set signals(ios, SIGINT, SIGTERM);
//    signals.async_wait(
//            [&](boost::system::error_code ec, int sig_number)
//            {
//                std::cout << "EXIT";
//                ios.stop();
//                return 0;
//            });
    Client client{ios, std::string{"127.0.0.1"}, std::string{"5000"}};
    client.do_start();

    return 0;
}