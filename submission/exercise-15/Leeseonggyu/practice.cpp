#include <iostream>
#include <thread>

int x = 0;

int main() {

	std::thread th1([&]() {
		for (int i = 0; i < 100000000; ++i) {
			x ++;
		}
		});
	std::thread th2([&]() {
		for (int i = 0; i < 100000000; ++i) {
			x ++;
		}
		});

	if (th1.joinable()) {
		th1.join();
	}
	if (th2.joinable()) {
		th2.join();
	}

	std::cout << x << '\n';

	return 0;
}