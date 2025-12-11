#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

int main(){

    boost::asio::io_context io;

    boost::asio::ip::tcp::resolver resolver(io);
    auto endpoints = resolver.resolve("google.com", "80");

    boost::asio::ip::tcp::socket socket(io);
    boost::asio::connect(socket,endpoints);

    std::cout << "Connected!" << std::endl;
    return 0;
}