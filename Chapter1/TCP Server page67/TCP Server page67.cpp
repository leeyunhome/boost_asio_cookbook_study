// TCP Server page67.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// ��⿭���� ��ٸ� ���� ��û�� �ִ� ��
	const int BACKLOG_SIZE = 30;

	// 1�ܰ�: ���� ���α׷��� ����� �������� ��Ʈ ��ȣ��
	// �̹� �˰� �ִٰ� �����Ѵ�.
	unsigned short port_num = 3333;

	// 2�ܰ�: ������ �������� �����.
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);

	asio::io_service ios;

	try {
		// 3�ܰ�: ������ ������ �ν��Ͻ�ȭ�ϰ� ����.
		asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

		// 4�ܰ�: ������ ������ ���� �������� ���ε��Ѵ�.
		acceptor.bind(ep);

		// 5�ܰ�: ������ ���� ��û�� �ִ��� ��� �����Ѵ�.
		acceptor.listen(BACKLOG_SIZE);

		// 6�ܰ�: �ɵ� ������ �����Ѵ�.
		asio::ip::tcp::socket sock(ios);

		// 7�ܰ�: ���� ��û�� ó���ϰ�
		// �ɵ� ������ Ŭ���̾�Ʈ�� �����Ѵ�.
		acceptor.accept(sock);

		// �� �������� 'sock' ������ Ŭ���̾�Ʈ�� ����Ǿ� �ִ�.
		// Ŭ���̾�Ʈ���� �����͸� �����ϰ� ���� �� �ִ�.
	}
	catch (system::system_error & e) {
		std::cout << "Error occured! Error code = " << e.code() <<
			". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}
