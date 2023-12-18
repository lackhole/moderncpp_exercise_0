#include <iostream>
#include <memory>

class MyBaseClass {
public:
	virtual void Hello() {
		//std::cout << "This is Base"<<std::endl;
		//std::endl은 개행 + flush  기능이 있기 떄문에 느리다.
		// 그렇기 때문에 std::cout << "This is Base\n" 이 훨씬 더 빠르다
		std::cout << "This is Base\n";
	}

	virtual ~MyBaseClass()=default;

};

class MyDerivedClass :public MyBaseClass {
	virtual void Hello() { // 그냥쓰면 override가 아니다.
		std::cout << "This is Derived\n";
	}
};

int main() {
	// new가 아닌 스마트 포인터로 구현한 인스턴스화
	std::unique_ptr<MyBaseClass> p = std::make_unique<MyDerivedClass>();
	p->Hello();

	p->MyBaseClass::Hello();



	return 0;

}
