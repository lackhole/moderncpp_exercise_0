#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int x = 0;

int main() {
	// 예제 #1: 지나간 시간을 체크합니다.

	/*
	auto now1 = std::chrono::steady_clock::now();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	auto now2 = std::chrono::steady_clock::now();
	std::chrono::duration dur = now2 - now1;
	
	std::cout << duration_cast<std::chrono::milliseconds>(dur) << std::endl;
	*/
	std::mutex m;

	std::thread th1([&]() {
		std::lock_guard<std::mutex> lck(m);
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