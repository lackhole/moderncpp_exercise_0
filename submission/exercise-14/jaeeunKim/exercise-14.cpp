#include <iostream>
#include <memory>
#include <utility>
/*
* exercise-14.cpp
*
* by jekim
* 2023-12-18
*/
using namespace std;

class MyBaseClass {
public:
    virtual void Hello() {
        cout << "This is Base\n";
    }
};

class MyDerivedClass :public MyBaseClass {
public:
    void Hello() {
        cout << "This is Derived\n";
    }
};

int main() {
    unique_ptr<MyBaseClass> p = make_unique<MyDerivedClass>();
    p->Hello();
    return 0;
}