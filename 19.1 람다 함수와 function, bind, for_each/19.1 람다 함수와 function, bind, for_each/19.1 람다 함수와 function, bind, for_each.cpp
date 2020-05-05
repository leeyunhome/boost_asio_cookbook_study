// 19.1 람다 함수와 function, bind, for_each.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye " << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello " << s << endl;
	}
};

int main()
{
	// lambda-introducer
	// lambda-parameter-declaration
	// lambda-return-type-clause
	// compound-statement
	auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };

	func(123);

	[](const int& i) -> void { cout << "Hello, World!" << endl; }(1234);

	{
		string name = "JackJack";
		[&]() {std::cout << name << endl; }();
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []() -> int { return 1; }() << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	std::function<void()>func4 = std::bind(func3, 456);
	func4();

	// https://en.cppreference.com/w/cpp/utility/functional/placeholders
	{
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(string("World"));

		auto f2 = std::bind(&goodbye, std::placeholders::_1);

		f2(string("World"));
	}
}

