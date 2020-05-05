// server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1단계: 서버 프로그램이 사용할 프로토콜 포트 번호를
	// 이미 알고 있다고 가정한다.
	unsigned short port_num = 3333;

	// 2단계: 호스트에서 쓸 수 있는 모든 IP 주소를 나타내는
	// 특별한 asio::ip::address 클래스 객체를 만든다.
	// 서버가 IPv6로 동작한다고 가정한다.
	asio::ip::address ip_address = asio::ip::address_v6::any();

	// 3단계
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	// 4단계
	// 종료점을 만들었으므로 서버 프로그램이
	// 들어오는 연결 요청을 들을
	// IP주소와 포트 번호를 명시하는 데 쓰일 수 있다.

	return 0;
}

