#include <iostream>
#include <string>
#include <boost/asio.hpp>
using namespace std;

using boost::asio::ip::tcp;

namespace asio = boost::asio;

int main(){

    asio::io_context io;

    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 5000));

    while(true){
        tcp::socket socket(io);

        acceptor.accept(socket);

        asio::streambuf request;
        asio::read_until(socket, request, "\r\n\r\n");

        string body = "<h1>Hello from Boost.Asio</h1>";

        string response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: " + to_string(body.size()) + "\r\n"
            "Connection: close\r\n"
            "\r\n"+
            body;

        asio::write(socket, asio::buffer(response));
    }

    return 0;
}