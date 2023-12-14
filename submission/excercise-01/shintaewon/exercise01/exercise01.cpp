#include <iostream>
#include <list>

using namespace std;

int main()
{
	//리스트 선언
	list<int> num_list;

	int temp;

	//뒤쪽으로 요소 추가하기
	for (int i = 0; i < 10; i++) {
		cin >> temp;
		num_list.push_back(temp);
	}


}
