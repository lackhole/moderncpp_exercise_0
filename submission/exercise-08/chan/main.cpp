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
		//cout << __func__ << "\n";
		cout << MY_FUNCTION << "\n";
	}

	MyApplication(const MyApplication&) {
		//cout << __func__ << "\n";
		cout << MY_FUNCTION << "\n";
	}
	MyApplication(MyApplication&&) noexcept {
		cout << MY_FUNCTION << "\n";
	}

	MyApplication& operator = (const MyApplication&) {
		cout << MY_FUNCTION << "\n";
		return *this;
	}
	MyApplication& operator = (MyApplication&&) noexcept {
		cout << MY_FUNCTION << "\n";
		return *this;
	}

	~MyApplication() {
		cout << MY_FUNCTION << "\n";
	}

};

int main()
{
	//print: MyApplication::MyApplication()
	MyApplication a;

	//print: MyApplication::MyApplication(const MyApplication&)
	MyApplication b = a;

	//print: MyApplication::MyApplication() (b destroyed)
	//print: MyApplication::MyApplication() (a destroyed)
	
	return 0;
}