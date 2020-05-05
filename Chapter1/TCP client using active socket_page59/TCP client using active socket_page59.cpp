// TCP client using active socket_page59.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1단계: 클라이언트 프로그램이 연결할 서버 프로그램의 IP 주소와
	// 프로토콜 포트 번호를 이미 알고 있다고 가정한다.
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		// 2단계: 연결할 서버 프로그램을 가리키는 종료점을 만든다.
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address), port_num);

		asio::io_service ios;

		// 3단계: 소켓을 만들고 연다.
		asio::ip::tcp::socket sock(ios, ep.protocol());

		// 4단계: 소켓을 연결한다.
		sock.connect(ep);

		// 이제 소켓인 'sock'은
		// 서버와 연결되었으며
		// 데이터를 주고받을 수 있다.

		
	}	
	catch (system::system_error & e) {
		// asio::ip::address::from_string()과
		// asio::ip::tcp::socket::connect()에서
		// 오류가 난다면 여기서 예외를 던진다.
		std::cout << "Error occured! Error code = " << e.code() <<
			". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}

