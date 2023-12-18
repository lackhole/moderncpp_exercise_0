#include <memory>
#include <iostream>
#include <utility>
using namespace std;

#ifdef _MSC_VER
#define MY_FUNC __FUNCSIG__
#else
#define MY_FUNC __PRETTY_FUNCTION__
#endif

int default_constructor_count = 0;
int copy_constructor_count = 0;
int move_constructor_count = 0;
int copy_operate_count = 0;
int move_operate_count = 0;
int destroy_count = 0;

class MyApplication {
public:
    MyApplication() {
        ++default_constructor_count;
        cout << MY_FUNC << '\n';
    }

    MyApplication(const MyApplication&) {
        ++copy_constructor_count;
        cout << MY_FUNC << '\n';
    }

    MyApplication(MyApplication&&) noexcept {
        ++move_constructor_count;
        cout << MY_FUNC << '\n';
    }

    MyApplication operator = (const MyApplication&) {
        ++copy_operate_count;
        cout << MY_FUNC << '\n';
        return *this;
    }

    MyApplication& operator = (MyApplication&&) {
        ++move_operate_count;
        cout << MY_FUNC << '\n';
        return *this;
    }

    ~MyApplication() {
        ++destroy_count;
        cout << MY_FUNC << '\n';
    }
};

void TestUniquePtr() {
    // MyApplication ����
    auto p = std::make_unique<MyApplication>();

    // MyApplication �̵�
    auto p2 = std::move(p);
}

void TestSharedPtr() {
    // MyApplication ����
    auto p = std::make_shared<MyApplication>();

    // ?
    auto p2 = p;

    // p2 �ʱ�ȭ
    p2.reset();

    // ?
    std::weak_ptr<MyApplication> weak_p = p;

    auto lock = weak_p.lock();
    if (lock) {
        std::cout << "Acquired ownership\n";
    }
}

int main() {
    TestUniquePtr();
    std::cout << "�⺻ ������ ȣ�� Ƚ��: " << default_constructor_count << '\n';
    std::cout << "���� ������ ȣ�� Ƚ��: " << copy_constructor_count << '\n';
    std::cout << "�̵� ������ ȣ�� Ƚ��: " << move_constructor_count << '\n';
    std::cout << "���� ���� ������ ȣ�� Ƚ��: " << copy_operate_count << '\n';
    std::cout << "�̵� ���� ������ ȣ�� Ƚ��: " << move_operate_count << '\n';
    std::cout << "�Ҹ��� ȣ�� Ƚ��: " << destroy_count << '\n';

    TestSharedPtr();
    std::cout << "�⺻ ������ ȣ�� Ƚ��: " << default_constructor_count << '\n';
    std::cout << "���� ������ ȣ�� Ƚ��: " << copy_constructor_count << '\n';
    std::cout << "�̵� ������ ȣ�� Ƚ��: " << move_constructor_count << '\n';
    std::cout << "���� ���� ������ ȣ�� Ƚ��: " << copy_operate_count << '\n';
    std::cout << "�̵� ���� ������ ȣ�� Ƚ��: " << move_operate_count << '\n';
    std::cout << "�Ҹ��� ȣ�� Ƚ��: " << destroy_count << '\n';

    return 0;
}


