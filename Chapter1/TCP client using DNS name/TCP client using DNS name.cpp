// TCP client using DNS name.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
	// 1�ܰ�: Ŭ���̾�Ʈ ���α׷��� ������ ���� ���α׷��� DNS �̸���
	// �������� ��Ʈ ��ȣ�� �̹� �˰� ������ ���ڿ��� ���� �ִٰ� �����Ѵ�.
	std::string host = "samplehost.book";
	std::string port_num = "3333";

	// 'resolver'�� 'socket'���� ����Ѵ�.
	asio::io_service ios;

	// �ؼ��Ⱑ ���� ���Ǹ� �����.
	asio::ip::tcp::resolver::query resolver_query(host, port_num,
		asio::ip::tcp::resolver::query::numeric_service);

	// �ؼ��� 'resolver'�� �����.
	asio::ip::tcp::resolver resolver(ios);

	try {
		// 2�ܰ�: DNS �̸��� �ؼ��Ѵ�.
		asio::ip::tcp::resolver::iterator it =
			resolver.resolve(resolver_query);

		// 3�ܰ�: ������ �����Ѵ�.
		asio::ip::tcp::socket sock(ios);

		// 4�ܰ�: asio::connect() �޼����
		// ���������� ����� ������ �� �������� ��ȯ�Ѵ�.
		// � ���������� ������ �� ���ų�,
		// �ٸ� ������ �߻��ϸ� ���ܸ� ������.
		asio::connect(sock, it);

		// ���� ������ 'sock'��
		// ������ ����Ǿ�����
		// �����͸� �ְ� ���� �� �ִ�.
	}
	// asio::ip::tcp::resolver::resolve��
	// asio::ip::tcp::socket::connect()����
	// ������ ���ٸ� ���⼭ ���ܸ� ������.
	catch (system::system_error & e){
		std::cout << "Error occured! Error code = " << e.code() <<
			". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}

