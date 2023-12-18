#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
	int x1 = 0;
	std::mutex m;

	std::thread th1([&]() {
		for (int i = 0; i < 100'000'000; ++i) {
			std::lock_guard<std::mutex> lck(m);
			x1 += 1;
		}
	});
	std::thread th2([&]() {
		for (int i = 0; i < 100'000'000; ++i) {
			std::lock_guard<std::mutex> lck(m);
			x1 += 1;
		}
	});

	if (th1.joinable()) { th1.join(); }
	if (th2.joinable()) { th2.join(); }

	std::cout << x1 << '\n';

	return 0;
}
