#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>


using namespace std;
/*
* exercise-16.cpp
*
* by jekim
* 2023-12-18
*/
int main() {

	atomic<int> x1(0);
	auto start1 = std::chrono::steady_clock::now();
	thread th1([&]() {
		for (int i = 0; i < 100'000'000; i++) x1++;
		});

	thread th2([&]() {
		for (int i = 0; i < 100'000'000; i++) x1++;
		});

	th1.join();
	th2.join();
	auto end1 = std::chrono::steady_clock::now();

	cout << "Using atomic... x1 :" << x1 << '\n';
	auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
	cout << "Elapsed time: " << dur.count() << "ms\n";
	
	int x2 = 0;
	mutex m;

	auto start2 = std::chrono::steady_clock::now();
	thread th3([&]() {
		for (int i = 0; i < 100'000'000; i++) {
			lock_guard<mutex> lck(m);
			++x2;
		}
		});
	thread th4([&]() {
		for (int i = 0; i < 100'000'000; i++) {
			lock_guard<mutex> lck(m);
			++x2;
		}
		});

	// do something
	th3.join();
	th4.join();

	auto end2 = std::chrono::steady_clock::now();
	cout << "\nUsing mutex... x2 : " << x2 << '\n';
	auto dur2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
	cout << "Elapsed time: " << dur2.count() << "ms\n";


	
	return 0;
}