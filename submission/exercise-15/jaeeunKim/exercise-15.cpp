#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
/*
* exercise-15.cpp
*
* by jekim
* 2023-12-18
*/
int x = 0;
int main() {
	thread th1([&]() {
		for (int i = 0; i < 100'000'000; i++) ++x;
	});
	thread th2([&]() {
		for (int i = 0; i < 100'000'000; i++) ++x;
	});

	// do something
	if(th1.joinable())
		th1.join();
	if(th2.joinable())
		th2.join();
	cout << x << '\n';
	return 0;
}