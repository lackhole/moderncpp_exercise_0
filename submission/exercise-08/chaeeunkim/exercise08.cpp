#include <typeinfo>
#include <iostream>
using namespace std;

class MyApplication {
public:
	MyApplication() {
		cout << __FUNCSIG__ << endl;
	}
	MyApplication(const MyApplication& other) {
		cout << __FUNCSIG__ << endl;
	}
	MyApplication(MyApplication&& other) noexcept {
		cout << __FUNCSIG__ << endl;
	}

	MyApplication& operator=(const MyApplication& other) {
		cout << __FUNCSIG__ << endl;
	}
	MyApplication& operator=(MyApplication&& other) noexcept {
		cout << __FUNCSIG__ << endl;
	}

	~MyApplication() {
		cout << __FUNCSIG__ << endl;
	}
};

int main() {
	MyApplication a;
	MyApplication b = a;
}