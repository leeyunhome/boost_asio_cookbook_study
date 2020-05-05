// TCP Server page67.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 대기열에서 기다릴 연결 요청의 최대 수
	const int BACKLOG_SIZE = 30;

	// 1단계: 서버 프로그램이 사용할 프로토콜 포트 번호를
	// 이미 알고 있다고 가정한다.
	unsigned short port_num = 3333;

	// 2단계: 서버의 종료점을 만든다.
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);

	asio::io_service ios;

	try {
		// 3단계: 수용자 소켓을 인스턴스화하고 연다.
		asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

		// 4단계: 수용자 소켓을 서버 종료점에 바인딩한다.
		acceptor.bind(ep);

		// 5단계: 들어오는 연결 요청이 있는지 듣기 시작한다.
		acceptor.listen(BACKLOG_SIZE);

		// 6단계: 능동 소켓을 생성한다.
		asio::ip::tcp::socket sock(ios);

		// 7단계: 연결 요청을 처리하고
		// 능동 소켓을 클라이언트에 연결한다.
		acceptor.accept(sock);

		// 이 시점에서 'sock' 소켓은 클라이언트에 연결되어 있다.
		// 클라이언트에게 데이터를 전송하고 받을 수 있다.
	}
	catch (system::system_error & e) {
		std::cout << "Error occured! Error code = " << e.code() <<
			". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}
