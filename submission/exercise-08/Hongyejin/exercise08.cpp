#include <iostream>

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif

using namespace std;

class MyApplication {
public :
	MyApplication() { // �⺻ ������
		cout << "print : " << MY_FUNCTION << endl;
	}
	MyApplication(const MyApplication&) {
		cout << "print : " << MY_FUNCTION << endl;
	}
	MyApplication(MyApplication&&) {
		cout << "print : " << MY_FUNCTION << endl;
	}
	MyApplication& operator=(const MyApplication&) { // ���� ���� ������
		cout << "print : " << MY_FUNCTION << endl;
		return *this;
	}
	MyApplication& operator=(MyApplication&&) noexcept {
		cout << "print : " << MY_FUNCTION << endl;
		return *this;
	}
	~MyApplication() {
		cout << "delete : " << MY_FUNCTION << endl;
	}
};

int main()
{
	// print : MyApplication::MyApplication()
	MyApplication a;

	// print : MyApplication::MyApplication(const MyApplication&)
	MyApplication b = a;


	return 0;
}
