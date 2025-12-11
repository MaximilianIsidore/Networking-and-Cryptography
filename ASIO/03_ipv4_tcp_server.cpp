#include <iostream>
#include <boost/asio.hpp>

using namespace std;
namespace asio = boost::asio;

int main(){
    asio::io_context io;

    asio::ip::tcp::acceptor acceptor(io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 8080));
    cout<<"Server Listening on IPV4 port 8080\n";

    asio::ip::tcp::socket socket(io);
    acceptor.accept(socket);

    std::string msg = "Hello\n";

    asio::write(socket, asio::buffer(msg));
    return 0;
}