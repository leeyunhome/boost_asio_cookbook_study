// IPv4 UDP Server Program_page54.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1�ܰ�: ���� ���α׷��� ����� �������� ��Ʈ ��ȣ�� 
	// �̹� �˰� �ִٰ� �����Ѵ�.
	unsigned short port_num = 3333;

	// 2�ܰ�: �������� �����.
	asio::ip::udp::endpoint ep(asio::ip::address_v4::any(), port_num);

	// 'socket' Ŭ���� �����ڿ��� ����Ѵ�.
	asio::io_service ios;

	// 3�ܰ�: ������ ����� ����.
	asio::ip::udp::socket sock(ios, ep.protocol());

	boost::system::error_code ec;

	// 4�ܰ�: ������ �������� ���ε��Ѵ�.
	sock.bind(ep, ec);

	// ������ �ִٸ� ó���Ѵ�.
	if (ec)
	{
		// ������ ���ε����� ���ߴ�. ������ �ߴ��Ѵ�.
		std::cout << "Failed to bind the socket" <<
			"Error code = " << ec.value() << " . Message: " <<
			ec.message();

		return ec.value();
	}

	return 0;
}
