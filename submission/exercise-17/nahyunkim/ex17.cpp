#include <thread>
#include <iostream>
#include <atomic>
#include <mutex>
#include <chrono>
std::atomic<int> x1(0);

int y = 0;
static long min = 999'999'999;
template <typename T>
void solution1(T a);
std::memory_order omin;

const char* memory_order_to_string(std::memory_order order) {
	switch (order) {
	case std::memory_order_relaxed:
		return "memory_order_relaxed";
	case std::memory_order_consume:
		return "memory_order_consume";
	case std::memory_order_acquire:
		return "memory_order_acquire";
	case std::memory_order_release:
		return "memory_order_release";
	case std::memory_order_acq_rel:
		return "memory_order_acq_rel";
	case std::memory_order_seq_cst:
		return "memory_order_seq_cst";
	default:
		return "unknown_memory_order";
	}
}

int main() {
	
	//memory_order_relaxed
	std::cout << "memory order relaxed\n";
	solution1<std::memory_order>(std::memory_order_relaxed);

	//memory_order_consum
	std::cout << "memory order consume\n";
	solution1<std::memory_order>(std::memory_order_consume);

	//memory_order_acquire
	std::cout << "memory order acquire\n";
	solution1<std::memory_order>(std::memory_order_acquire);

	//memory_order_release
	std::cout << "memory order release\n";
	solution1<std::memory_order>(std::memory_order_release);

	//memory_order_acq_rel
	std::cout << "memory order acq rel\n";
	solution1<std::memory_order>(std::memory_order_acq_rel);

	//memory_order_seq_cst
	std::cout << "memory order seq cst\n";
	solution1<std::memory_order>(std::memory_order_seq_cst);



	std::cout << " The fastest Memory Order: " << memory_order_to_string(omin) << '\n';



	exit(0);


}

template <typename T>
void solution1(T a) { // atomic을 통한 해결
	std::thread th1([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			x1.fetch_add(1, a);
		}
		});

	std::thread th2([&] {for (int i = 0; i < 100'000'000; ++i) {
		x1.fetch_add(1, a);
	}});

	th1.join();
	th2.join();

	std::cout << x1 << '\n';
	auto _time = std::chrono::steady_clock::now();

	auto time_point = std::chrono::duration_cast<std::chrono::milliseconds>(_time.time_since_epoch());

	if (min > time_point.count()) {
		min = time_point.count();
		omin = a;
	}
	std::cout << "atomic time(ms): " << time_point.count() << '\n';

	x1 = 0;

}


