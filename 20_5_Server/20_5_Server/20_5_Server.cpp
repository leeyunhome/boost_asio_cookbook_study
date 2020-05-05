// 20_5_Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Examples are based on
//https://www.boost.org/doc/libs/1_68_0/doc/html/boost_asio/examples.html#boost_asio.examples.iostreams

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
	try
	{
		boost::asio::io_service io_service;

		tcp::endpoint endpoint(tcp::v4(), 13);
		tcp::acceptor acceptor(io_service, endpoint);

		std::cout << "Server started" << std::endl;

		for (;;)
		{
			const std::string message_to_send = "Hello From Server";

			boost::asio::ip::tcp::iostream stream;

			std::cout << "check 1" << std::endl;

			boost::system::error_code ec;
			acceptor.accept(*stream.rdbuf(), ec);

			std::cout << "check 2" << std::endl;

			if (!ec) // TODO: How to take care of multiple clients? Multi-threading?
			{
				// recieve message from client
				std::string line;
				std::getline(stream, line);
				std::cout << line << std::endl;

				// send message to client
				stream << message_to_send;
				stream << std::endl;	// send std::endl to end getline of client
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

