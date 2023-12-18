#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>



int main() {
	namespace chrono = std::chrono;

	//std::atomic<int> x1 = 0;
	int x1 = 0;
	std::mutex m;

	auto now1 = std::chrono::steady_clock::now();

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

	if (th1.joinable()) {
		th1.join();
	}
	if (th2.joinable()) {
		th2.join();
	}
	auto now2 = std::chrono::steady_clock::now();
	auto dt = chrono::duration_cast<chrono::microseconds>(now2 - now1);

	std::cout << x1 << '\n';
	std::cout << dt.count()<<"mili" << '\n';

	return 0;
}