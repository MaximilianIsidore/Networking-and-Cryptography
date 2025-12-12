#include <iostream>
#include <boost/asio.hpp>
#include <string>
using namespace std;

namespace asio = boost::asio;
using boost::asio::ip::tcp;

int main(){

    asio::io_context  io;

    tcp::resolver resolver(io);
    tcp::socket socket(io);

    auto endpoint = resolver.resolve("example.com", "80");

    asio::connect(socket, endpoint);

    string request = 
        "GET / HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "Connection: close\r\n"
        "\r\n";

    asio::write(socket, asio::buffer(request));

    asio::streambuf response;
    boost::system::error_code ec;

    while(true){
        size_t bytes = socket.read_some(response.prepare(1024), ec);
        response.commit(bytes);
        cout<<&response;

        if(ec == boost::asio::error::eof)
            break;
        if(ec)
            throw boost::system::system_error(ec);
    }

    return 0;
}