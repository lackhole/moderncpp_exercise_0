#include <bits/stdc++.h>

using namespace std;
/*
* exercise-08.cpp
* 
* by jekim
* 2023-12-15
*/

class MyApplication {
public:
	MyApplication() {	cout << __FUNCSIG__ << '\n'; }
	MyApplication(const MyApplication& r) { cout << __FUNCSIG__ << '\n'; }
	~MyApplication() { cout << __FUNCSIG__ << '\n'; }
};

int main() {

	MyApplication a;

	MyApplication b = a;

	return 0;
}