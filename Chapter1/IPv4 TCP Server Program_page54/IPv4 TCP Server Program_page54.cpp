// IPv4 TCP Server Program_page54.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1단계: 서버 프로그램이 사용할 프로토콜 포트 번호를
	// 이미 알고 있다고 가정한다.
	unsigned short port_num = 3333;

	// 2단계: 종료점을 만든다.
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);

	// 'acceptor' 클래스 생성자에서 사용한다.
	asio::io_service ios;

	// 3단계: 수용자 소켓을 만들고 연다.
	asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

	boost::system::error_code ec;

	// 4단계: 수용자 소켓을 바인딩한다.
	acceptor.bind(ep, ec);

	// 오류가 있다면 처리한다.
	if (ec)
	{
		// 수용자 소켓을 바인딩하지 못했다. 실행을 중단한다.
		std::cout << "Failed to bind the acceptor socket." <<
			"Error code = " << ec.value() << ". Message: " <<
			ec.message();

		return ec.value();
	}
	
	return 0;
}

