#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

int x = 0;

int main() {
	std::mutex m;
	std::thread th1([&]() {
		for (int i = 0; i < 1'000'00; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			m.lock();
			x++;
			std::cout << 'A' << '\n';
			m.unlock();
		}

		});
	std::thread th2([&]() {
		for (int i = 0; i < 1'000'00; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			m.lock();
			x++;
			std::cout << 'B' << '\n';
			m.unlock();
		}
		});

	// do something
	th1.join();
	th2.join();
	std::cout << x << '\n';

	return 0;
}