// IPv4 TCP Server Program_page54.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);

	// 'acceptor' Ŭ���� �����ڿ��� ����Ѵ�.
	asio::io_service ios;

	// 3�ܰ�: ������ ������ ����� ����.
	asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

	boost::system::error_code ec;

	// 4�ܰ�: ������ ������ ���ε��Ѵ�.
	acceptor.bind(ep, ec);

	// ������ �ִٸ� ó���Ѵ�.
	if (ec)
	{
		// ������ ������ ���ε����� ���ߴ�. ������ �ߴ��Ѵ�.
		std::cout << "Failed to bind the acceptor socket." <<
			"Error code = " << ec.value() << ". Message: " <<
			ec.message();

		return ec.value();
	}
	
	return 0;
}

