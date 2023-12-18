#include <iostream>
#include <thread>
using namespace std;

int x = 0;

int main() {

	std::thread th1 = thread([&]() {
		for (int i = 0; i < 100000000; i++) {
			x += 1;
		}
	});

	std::thread th2 = thread([&]() {
		for (int i = 0; i < 100000000; i++) {
			x += 1;
		}
	});

	if (th1.joinable()) {
		th1.join();
	}

	if (th2.joinable()) {
		th2.join();
	}

	cout << x << '\n';

}