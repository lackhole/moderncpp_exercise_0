#include <iostream>
#include <memory>

class MyBaseClass {
    public:
        virtual void Hello() {
            std::cout << "This is Base" << "\n";
        }
        // °¡»ó ¼Ò¸êÀÚ
        virtual ~MyBaseClass() = default; 
};

class MyDerivedClass : public MyBaseClass {
    public:
        void Hello() override {
            std::cout << "This is Derived" << "\n";
        }
};

int main() {
    std::unique_ptr<MyBaseClass> p = std::make_unique<MyDerivedClass>();
    p->Hello();

    return 0;
}