#include <iostream>
#include <thread>

int x = 0;

int main() {
    std::thread th1([]() {
        for (int i = 0; i < 100'000'000; ++i) {
            ++x;
        }
        });

    std::thread th2([]() {
        for (int i = 0; i < 100'000'000; ++i) {
            ++x;
        }
        });

    th1.join();
    th2.join();

    std::cout << x << '\n';

    return 0;
}
