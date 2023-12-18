#include <iostream>

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif

using namespace std;

class MyApplication {

public:
    MyApplication() {
        cout << "constructor : " << MY_FUNCTION << endl;
    }

    ~MyApplication() {
        cout << "destructor : " << MY_FUNCTION << endl;
    }

    MyApplication(const MyApplication& m) {
        cout << "copy constructor : " << MY_FUNCTION << endl;
    }

    MyApplication(MyApplication&& m) noexcept {
        cout << "move constructor : " << MY_FUNCTION << endl;
    }

    MyApplication& operator=(const MyApplication&) {
        cout << "copy assignment operator : " << MY_FUNCTION << endl;
        return *this;
    }

    MyApplication& operator=(MyApplication&& m) noexcept {
        cout << "move assignment constructor : " << MY_FUNCTION << endl;
        return *this;
    }

};

int main() {
    MyApplication a;

    MyApplication b = a;
    MyApplication c(a);

    b = c;

}
