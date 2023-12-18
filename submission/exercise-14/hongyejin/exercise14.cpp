#include <iostream>

using namespace std;

class MyBaseClass {
public :
	virtual void Hello() {
		cout << "This is Base\n";
	}

	virtual ~MyBaseClass() = default;
};

class MyDerivedClass : public MyBaseClass {
public :
	void Hello() override {
		cout << "This is Derived\n";
	}
};

int main()
{
	// ptr = unique_ptr<MyDerivedClass>
	unique_ptr<MyDerivedClass> ptr = make_unique<MyDerivedClass>();

	ptr->Hello();

	return 0;
}