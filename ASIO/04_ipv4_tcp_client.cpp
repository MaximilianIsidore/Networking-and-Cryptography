#include <iostream>
#include <boost/asio.hpp>
#include <array>
#include <string>
using namespace std;
namespace asio = boost::asio;


int main(){
    asio::io_context io;

    asio::ip::tcp::resolver resolver(io);
    auto endpoint = resolver.resolve("example.com", "80");

    asio::ip::tcp::socket socket(io);
    asio::connect(socket, endpoint);

    std::array<char, 128> buf;
    size_t len = socket.read_some(asio::buffer(buf));

    cout<<"Recieved "<<std::string(buf.data(), len)<<"\n";
    return 0;
}