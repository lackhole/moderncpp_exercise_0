#include <iostream>

using namespace std;

class MyApplication {
public:
	MyApplication() {
		cout << __func__ << "\n";
	};

	MyApplication(const MyApplication& a) {
		cout << __func__ << "\n";
	};
	~MyApplication() {
		cout << __func__ << "\n";
	};

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