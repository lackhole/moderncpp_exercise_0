//
// Created by Minji Jun on 2023/12/15.
//
#include <bits/stdc++.h>
using namespace std;

class MyApplication {
private:
    char name;
public:
    MyApplication() {
        this-> name = 'a';
        cout << __PRETTY_FUNCTION__  << '\n';
    }
    MyApplication(const MyApplication &myapp) {
        this->name = myapp.name;
        cout << __PRETTY_FUNCTION__ << '\n';
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