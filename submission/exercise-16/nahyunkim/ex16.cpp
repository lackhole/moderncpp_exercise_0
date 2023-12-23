#include <thread>
#include <iostream>
#include <atomic>
#include <mutex>
#include <chrono>
std::atomic<int> x1(0);
int x2 = 0;
std::mutex x2_mutex;
int y = 0;
void Async();
void solution1();
void solution2();


int main() {

	//동기일때 연산의 결과가 200,000,000이 나오지 않는다.
	//th1과 th2가 동시에 진행되기 때문에
	std::cout << "Aync:";
	Async();

	//atomic을 통한 해결
	std::cout << "Atomic: ";

	solution1();

	//뮤텍스를 통한 해결
	std::cout << "Mutex: ";

	solution2();

	exit(0);


}

void solution1() { // atomic을 통한 해결
	std::thread th1([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			x1.fetch_add(1, std::memory_order_relaxed);
		}
		});

	std::thread th2([&] {for (int i = 0; i < 100'000'000; ++i) {
		x1.fetch_add(1, std::memory_order_relaxed);
	}});

	th1.join();
	th2.join();

	std::cout << x1 << '\n';
	auto _time = std::chrono::steady_clock::now();
	
	auto time_point = std::chrono::duration_cast<std::chrono::milliseconds>(_time.time_since_epoch());

	std::cout << "atomic time(ms): " << time_point.count() << '\n';

	
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

	
}


void solution2() { // 뮤텍스 활용

	std::thread t1 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
		
			{
				std::lock_guard<std::mutex> lock(x2_mutex);
				x2++;
			}
			
			 
		}
		});

	std::thread t2 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			{
			std::lock_guard<std::mutex> lock(x2_mutex);
			x2++; }
		}
		});

	t1.join();
	t2.join();

	if (t1.joinable()) {
		t1.join();
	}

	if (t2.joinable()) {
		t2.join();
	}
	std::cout << x2 << '\n';
	auto _time = std::chrono::steady_clock::now();

	auto time_point = std::chrono::duration_cast<std::chrono::milliseconds>(_time.time_since_epoch());

	std::cout << "mutex time(ms): " << time_point.count() << '\n';


	
}

