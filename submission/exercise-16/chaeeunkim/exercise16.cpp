#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>
using namespace std;

int main() {
	namespace chrono = std::chrono;

	// Use std::atomic
	std::atomic<int> x1 = 0;

	// 시간 측정
	auto t1 = chrono::steady_clock::now();
	std::thread th1 = thread([&]() {
		for (int i = 0; i < 100000000; i++) {
			x1.fetch_add(1);  //x1 += 1;
		}
	});

	std::thread th2 = thread([&]() {
		for (int i = 0; i < 100000000; i++) {
			x1.fetch_add(1);  //x1 += 1;
		}
	});
	auto t2 = chrono::steady_clock::now();
	
	// do something
	if (th1.joinable()) {
		th1.join();
	}

	if (th2.joinable()) {
		th2.join();
	}

	std::cout << x1 << '\n';
	auto dt1 = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	std::cout << "걸린 시간: " << dt1.count() << '\n';

	// Use std::mutex
	int x2 = 0;
	std::mutex m;

	// 시간 측정
	auto t3 = chrono::steady_clock::now();
	std::thread th3 = thread([&]() {
		for (int i = 0; i < 100000000; i++) {
			std::lock_guard<std::mutex> lck(m);
			x2 += 1;
		}
	});
	std::thread th4 = thread([&]() {
		for (int i = 0; i < 100000000; i++) {
			std::lock_guard<std::mutex> lck(m);
			x2 += 1;
		}
	});
	auto t4 = chrono::steady_clock::now();

	// do something
	if (th3.joinable()) {
		th3.join();
	}

	if (th4.joinable()) {
		th4.join();
	}

	std::cout << x2 << '\n';
	auto dt2 = chrono::duration_cast<chrono::microseconds>(t4 - t3);
	std::cout << "걸린 시간: " << dt2.count() << '\n';

	return 0;
}