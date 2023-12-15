#include <iostream>

using namespace std;

class MyApplication {

public:
    MyApplication() {
        cout << "constructor : " << __FUNCSIG__ << endl;
    }

    ~MyApplication() {
        cout << "destructor : " << __FUNCSIG__ << endl;
    }

    MyApplication(const MyApplication& m) {
        cout << "copy constructor : " << __FUNCSIG__ << endl;
    }

    MyApplication(MyApplication&& m) noexcept {
        cout << "move constructor : " << __FUNCSIG__ << endl;
    }

    MyApplication& operator=(const MyApplication&) {
        cout << "copy assignment operator : " << __FUNCSIG__ << endl;
        return *this;
    }

    MyApplication& operator=(MyApplication&& m) noexcept {
        cout << "move assignment constructor : " << __FUNCSIG__ << endl;
        return *this;
    }

};

int main() {
    MyApplication a;

    MyApplication b = a;
    MyApplication c(a);

    b = c;

}