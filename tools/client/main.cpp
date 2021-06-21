#include <iostream>
#include "client.hpp"

int main(){

    boost::asio::io_context ios;
    Client client{ios, std::string{"127.0.0.1"}, std::string{"5000"}};
    client.do_start();

    return 0;
}