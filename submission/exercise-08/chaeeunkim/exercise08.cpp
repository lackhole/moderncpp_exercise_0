#include <typeinfo>
#include <iostream>
using namespace std;

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif 


class MyApplication {
public:
	MyApplication() {
		cout << MY_FUNCTION << endl;
	}
	MyApplication(const MyApplication& other) {
		cout << MY_FUNCTION << endl;
	}
	MyApplication(MyApplication&& other) noexcept {
		cout << MY_FUNCTION << endl;
	}

	MyApplication& operator=(const MyApplication& other) {
		cout << MY_FUNCTION << endl;
		return *this;
	}
	MyApplication& operator=(MyApplication&& other) noexcept {
		cout << MY_FUNCTION << endl;
		return *this;
	}

	~MyApplication() {
		cout << MY_FUNCTION << endl;
	}
};

int main() {
	MyApplication a;
	MyApplication b = a;

	return 0;
}
