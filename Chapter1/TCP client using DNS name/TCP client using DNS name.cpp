// TCP client using DNS name.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1단계: 클라이언트 프로그램이 연결할 서버 프로그램의 DNS 이름과
	// 프로토콜 포트 번호를 이미 알고 있으며 문자열로 갖고 있다고 가정한다.
	std::string host = "samplehost.book";
	std::string port_num = "3333";

	// 'resolver'와 'socket'에서 사용한다.
	asio::io_service ios;

	// 해석기가 던질 질의를 만든다.
	asio::ip::tcp::resolver::query resolver_query(host, port_num,
		asio::ip::tcp::resolver::query::numeric_service);

	// 해석기 'resolver'를 만든다.
	asio::ip::tcp::resolver resolver(ios);

	try {
		// 2단계: DNS 이름을 해석한다.
		asio::ip::tcp::resolver::iterator it =
			resolver.resolve(resolver_query);

		// 3단계: 소켓을 생성한다.
		asio::ip::tcp::socket sock(ios);

		// 4단계: asio::connect() 메서드는
		// 성공적으로 연결될 때까지 각 종료점을 순환한다.
		// 어떤 종료점과도 연결할 수 없거나,
		// 다른 오류가 발생하면 예외를 던진다.
		asio::connect(sock, it);

		// 이제 소켓인 'sock'은
		// 서버와 연결되었으며
		// 데이터를 주고 받을 수 있다.
	}
	// asio::ip::tcp::resolver::resolve와
	// asio::ip::tcp::socket::connect()에서
	// 오류가 난다면 여기서 예외를 던진다.
	catch (system::system_error & e){
		std::cout << "Error occured! Error code = " << e.code() <<
			". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}

