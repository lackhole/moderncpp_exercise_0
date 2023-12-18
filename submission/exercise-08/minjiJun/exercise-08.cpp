//
// Created by Minji Jun on 2023/12/15.
//
#include <iostream>

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif

using namespace std;

class MyApplication {

public:
    // default constructor
    MyApplication() { 
        cout << MY_FUNCTION << '\n';
    }
    // copy constructor
    MyApplication(const MyApplication &myapp) { 
        cout << MY_FUNCTION << '\n';
    }
    // copy assignment operator
    MyApplication(MyApplication&& myapp) noexcept {
        cout << MY_FUNCTION << '\n';
    }
    // move constructor
    MyApplication& operator=(const MyApplication& myapp) {
        cout << MY_FUNCTION << '\n';
        return *this;
        
    }
    // move assignment operator
    MyApplication& operator=(MyApplication&& myapp) noexcept{
        cout << MY_FUNCTION << '\n';
        return *this;
    }
    
    ~MyApplication() {
        cout << MY_FUNCTION << '\n';
    }
};

int main() {
    MyApplication a;

    MyApplication b = a;

    return 0;
}
