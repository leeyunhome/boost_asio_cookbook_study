// Chapter1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1�ܰ�: Ŭ���̾�Ʈ ���α׷��� ������ ���� ���α׷��� IP �ּҿ�
	// �������� ��Ʈ ��ȣ�� �̹� �˰� �ִٰ� �����Ѵ�.
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	// IP �ּҸ� �м��ϴ� ���� �߻��� �� �ִ� ���� ������ �����ϴ� �� ���δ�.
	boost::system::error_code ec;

	// 2�ܰ�: IP �������� ������ ���� ���� �ּ� ������ ����Ѵ�.
	asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ec);

	if (ec.value() != 0)
	{
		// �˰� �ִ� IP�ּҰ� ��ȿ���� �ʴ�. ������ �ߴ��Ѵ�.
		std::cout << "Failed to parse the IP address. Error code = " <<
			ec.value() << ". Message: " << ec.message();
		return ec.value();
	}

	// 3�ܰ� 
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	// 4�ܰ�: �������� �غ� ������.
	// ����Ϸ��� Ư�� ������ ��Ÿ���� �� ���� �� �ִ�.

	return 0;
}
