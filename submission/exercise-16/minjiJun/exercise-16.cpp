#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

int main() {

    std::atomic<int> x1 = {0};

    // Use std::atomic
    auto time1 = std::chrono::steady_clock::now();

    // 시간 측정
    std::thread th1 = std::thread([&]() {
        for (int i = 0; i < 100'000'000; i++) {
            x1 += 1;
        }
    });
    std::thread th2 = std::thread([&]() {
        for (int i = 0; i < 100'000'000; i++) {
            x1.fetch_add(1);
        }
    });

    if (th1.joinable())
        th1.join();
        
    if (th2.joinable())
        th2.join();

    auto time2 = std::chrono::steady_clock::now();

    auto interval1 = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1);
    

    std::cout << x1 << '\n';
    std::cout << "걸린 시간: " << interval1.count() << "ms\n";

    std::mutex mtx;
    int x2 = 0;

    auto time3 = std::chrono::steady_clock::now();

    std::thread th3 = std::thread([&]() {
        for (int i = 0; i < 100'000'000; i++) {
            mtx.lock();
            x2 += 1;
            mtx.unlock();
        }
    });

    std::thread th4 = std::thread([&]() {
        for (int i = 0; i < 100'000'000; i++) {
            mtx.lock();
            x2 += 1;
            mtx.unlock();
        }
    });

    if (th3.joinable())
        th3.join();
        
    if (th4.joinable())
        th4.join();

    auto time4 = std::chrono::steady_clock::now();
    auto interval2 = std::chrono::duration_cast<std::chrono::milliseconds>(time4 - time3);
    
    // // do something
    
    std::cout << x2 << '\n';
    std::cout << "걸린 시간: " << interval2.count() << "ms\n";

    return 0;
}