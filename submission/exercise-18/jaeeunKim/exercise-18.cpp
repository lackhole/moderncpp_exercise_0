#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
/*
* exercise-18.cpp
*
* by jekim
* 2023-12-18
*/
int main() {
	int x = 0;
	mutex m;
	condition_variable cv;

	thread th1([&]() {
		for (int i = 0; i < 100'000'000; i++) {
			unique_lock<mutex> lck(m);
			++x;
			lck.unlock();
		}
		cv.notify_one();
	});
	thread th2([&]() {
		for (int i = 0; i < 100'000'000; i++) {
			unique_lock<mutex> lck(m);
			++x;
			lck.unlock();
		}
		cv.notify_one();
		});


	thread th3([&]() {
		// wait until x becomes 200'000'000
		unique_lock<mutex> lck(m);
		cv.wait(lck, [&]() {
			return x == 200'000'000;
		});
		cout << x << '\n';
		lck.unlock();
	});


	th1.join();
	th2.join();
	th3.join();
	return 0;
}