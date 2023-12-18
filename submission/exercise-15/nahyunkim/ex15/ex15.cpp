#include <thread>
#include <iostream>
int y=0;
void Async();

int main() {

	//동기일때 연산의 결과가 200,000,000이 나오지 않는다.
	//th1과 th2가 동시에 진행되기 때문에
	Async();
			
}


void Async() {
	std::thread t1 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			++y;
		}
		});

	std::thread t2 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			++y;
		}
		});

	t1.join();
	t2.join(); // 메인 쓰레드 전에 t1,t2 쓰레드를 종료시키지않는다.

	if (t1.joinable()) {
		t1.join();
	}

	if (t2.joinable()) {
		t2.join();
	}

	std::cout << y << '\n';

	exit(0);
}


