// server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1�ܰ�: ���� ���α׷��� ����� �������� ��Ʈ ��ȣ��
	// �̹� �˰� �ִٰ� �����Ѵ�.
	unsigned short port_num = 3333;

	// 2�ܰ�: ȣ��Ʈ���� �� �� �ִ� ��� IP �ּҸ� ��Ÿ����
	// Ư���� asio::ip::address Ŭ���� ��ü�� �����.
	// ������ IPv6�� �����Ѵٰ� �����Ѵ�.
	asio::ip::address ip_address = asio::ip::address_v6::any();

	// 3�ܰ�
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	// 4�ܰ�
	// �������� ��������Ƿ� ���� ���α׷���
	// ������ ���� ��û�� ����
	// IP�ּҿ� ��Ʈ ��ȣ�� ����ϴ� �� ���� �� �ִ�.

	return 0;
}

