// TCP client using active socket_page59.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1�ܰ�: Ŭ���̾�Ʈ ���α׷��� ������ ���� ���α׷��� IP �ּҿ�
	// �������� ��Ʈ ��ȣ�� �̹� �˰� �ִٰ� �����Ѵ�.
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		// 2�ܰ�: ������ ���� ���α׷��� ����Ű�� �������� �����.
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address), port_num);

		asio::io_service ios;

		// 3�ܰ�: ������ ����� ����.
		asio::ip::tcp::socket sock(ios, ep.protocol());

		// 4�ܰ�: ������ �����Ѵ�.
		sock.connect(ep);

		// ���� ������ 'sock'��
		// ������ ����Ǿ�����
		// �����͸� �ְ���� �� �ִ�.

		
	}	
	catch (system::system_error & e) {
		// asio::ip::address::from_string()��
		// asio::ip::tcp::socket::connect()����
		// ������ ���ٸ� ���⼭ ���ܸ� ������.
		std::cout << "Error occured! Error code = " << e.code() <<
			". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}

