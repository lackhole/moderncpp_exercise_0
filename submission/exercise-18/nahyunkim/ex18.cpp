#include <thread>
#include <iostream>
#include <atomic>
#include <mutex>
#include <chrono>

int x2 = 0;
std::mutex x2_mutex;
std::condition_variable cv; // mutex의 소유권을 가지는 변수


void solution2();


int main() {


	std::cout << "Mutex: ";

	solution2();

	exit(0);


}



void solution2() {

	std::thread t1 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {

			{
				std::lock_guard<std::mutex> lock(x2_mutex);
				x2++;
			}

			cv.notify_all();

		}
		});

	std::thread t2 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			{
				std::lock_guard<std::mutex> lock(x2_mutex);
				x2++; 
			}
			cv.notify_all();
		}
		});

	//x2가 2억이 되기 전까지는 sleep
	std::thread t3 = std::thread([&] {

		//객체 생성하지만 소유권은 아직 가지지 않는다.
		std::unique_lock<std::mutex> lck(x2_mutex);

		//lck는 소유권 획득을 시도하면 획득할때까지 무한 대기한다.
		cv.wait(lck, [&]() {  //람다함수
			return x2 == 200'000'000; // 리턴값이 1이 될때 notification이 생성이된다.
			});


	});

	t1.join();
	t2.join();
	t3.join();

	if (t1.joinable()) {
		t1.join();
	}

	if (t2.joinable()) {
		t2.join();
	}
	if (t3.joinable()) {
		t3.join();
	}
	std::cout << x2 << '\n';
	auto _time = std::chrono::steady_clock::now();

	auto time_point = std::chrono::duration_cast<std::chrono::milliseconds>(_time.time_since_epoch());

	std::cout << "mutex time(ms): " << time_point.count() << '\n';



}
