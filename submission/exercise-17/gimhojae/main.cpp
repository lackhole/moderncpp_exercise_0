#include <mutex>
#include <thread>
#include <iostream>


int main() {
    int x=0;
    bool wakeup = false;
    std::mutex m;
    std::condition_variable cv;

    std::thread th1([&]() {for (int i = 0; i < 100000000; i++) { std::unique_lock<std::mutex> lck(m); x++; }});
    std::thread th2([&]() {for (int i = 0; i < 100000000; i++) { std::unique_lock<std::mutex> lck(m); x++; }});
    if (th1.joinable() && th2.joinable()) {
        th1.join(); th2.join();
        wakeup = true;
    }
    std::thread th3([&]() {
        // wait until x becomes 200'000'000
        std::unique_lock<std::mutex> lck(m);
        cv.wait(lck, [&]() { return wakeup; });
        std::cout << x << '\n';
        });
    if (th3.joinable()) {
        th3.join();
    }
    return 0;
}