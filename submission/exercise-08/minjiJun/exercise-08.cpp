//
// Created by Minji Jun on 2023/12/15.
//
#include <bits/stdc++.h>
using namespace std;

class MyApplication {

public:
    // default constructor
    MyApplication() { 
        cout << __PRETTY_FUNCTION__ << '\n';
    }
    // copy constructor
    MyApplication(const MyApplication &myapp) { 
        cout << __PRETTY_FUNCTION__ << '\n';
    }
    // copy assignment operator
    MyApplication(MyApplication&& myapp) noexcept {
        cout << __PRETTY_FUNCTION__ << '\n';
    }
    // move constructor
    MyApplication& operator=(const MyApplication& myapp) {
        cout << __PRETTY_FUNCTION__ << '\n';
        return *this;
        
    }
    // move assignment operator
    MyApplication& operator=(MyApplication&& myapp) noexcept{
        cout << __PRETTY_FUNCTION__ << '\n';
        return *this;
    }
    
    ~MyApplication() {
        cout << __PRETTY_FUNCTION__ << '\n';
    }
};

int main() {
    MyApplication a;

    MyApplication b = a;

    return 0;
}