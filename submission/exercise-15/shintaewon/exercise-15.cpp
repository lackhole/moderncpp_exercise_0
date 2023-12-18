#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    atomic<int> x1 = 0;
    mutex mtx;
    int x2 = 0;

    // atomic ���
    auto start1 = steady_clock::now();
    thread th1([&]() {
        for (int i = 0; i < 100'000'000; ++i) {
            ++x1;
        }
        });
    thread th2([&]() {
        for (int i = 0; i < 100'000'000; ++i) {
            ++x1;
        }
        });

    th1.join();
    th2.join();

    auto end1 = steady_clock::now();
    duration<double> elapsed1 = end1 - start1;

    cout << "x1: " << x1 << '\n';
    cout << "Atomic �ɸ� �ð�: " << elapsed1.count() << "��\n";

    //mutex ���
    auto start2 = steady_clock::now();
    thread th3([&]() {
        for (int i = 0; i < 100'000'000; ++i) {
            lock_guard<mutex> lock(mtx);
            ++x2;
        }
        });
    thread th4([&]() {
        for (int i = 0; i < 100'000'000; ++i) {
            lock_guard<mutex> lock(mtx);
            ++x2;
        }
        });

    th3.join();
    th4.join();

    auto end2 = steady_clock::now();
    duration<double> elapsed2 = end2 - start2;

    cout << "x2: " << x2 << '\n';
    cout << "Mutex �ɸ� �ð�: " << elapsed2.count() << "��\n";

    return 0;
}
