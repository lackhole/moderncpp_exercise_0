#include <thread>
#include <iostream>

int x = 0;

int main() {

	std::thread th1 = std::thread([&]() {//������ �����ҷ��� ĸ�ĺ��� �����´�.
		
		for (int i = 0; i < 100000000; i++) {
			x += 1;
		}
		});
	
	std::thread th2 = std::thread([&]() {//������ �����ҷ��� ĸ�ĺ��� �����´�.

		for (int i = 0; i < 100000000; i++) {
			x += 1;
		}
		});
	
	if (th1.joinable())
		th1.join();
	
	if (th2.joinable())
		th2.join();

	//2���� �ȳ����� ���� ->���ڼ� 
	//
	// 
	//


		std::cout << x << '\n';

	return 0;
}