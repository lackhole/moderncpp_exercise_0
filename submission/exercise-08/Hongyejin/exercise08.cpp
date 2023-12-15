#include <iostream>

using namespace std;

class MyApplication {
public :
	MyApplication() {
		cout << __FUNCSIG__ << endl;
	}
	MyApplication(const MyApplication& a) {
		cout << __FUNCSIG__ << endl;
	}
	~MyApplication() {
		cout << __FUNCSIG__ << endl;
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