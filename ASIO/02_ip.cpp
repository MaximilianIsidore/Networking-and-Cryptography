#include <iostream>
#include <boost/asio.hpp>
using namespace std;
namespace asio = boost::asio;

int main(){

    asio::io_context io;

    // IPv4 endpoint: 0.0.0.0:8080
    boost::asio::ip::tcp::endpoint ep4(asio::ip::address_v4::any(), 8080);
    // IPv6 endpoint: [::]:8080
    boost::asio::ip::tcp::endpoint ep6(asio::ip::address_v6::any(), 8080);

    cout<<"IPV4 "<<ep4<<endl;
    cout<<"IPV6 "<<ep6<<endl;
    return 0;
}