//사용자로부터 정수 10개를 입력받아 std::list에 차례대로 저장 합니다
//
//0 에서 10 사이의 정수 2개를 추가로 입력받고 두 정수 중 작은 것을 a, 큰 것을 b 라 하자
//
//단, 조건문(if, 삼항연산자)을 사용해서는 안됩니다
//
//std::list의[a, b) 영역을 지웁니다
//
//std::list 를 출력 한다
//
//for 문을 사용해서는 안됩니다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main() {

	list<int> num_list;

	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		num_list.push_back(temp);
	}

	int a, b;
	cin >> a >> b;

	num_list.erase(find(num_list.begin(), num_list.end(), a), find(num_list.begin(), num_list.end(), b));

	for (auto it : num_list) {
		cout << it << " ";
	}

	return 0;
}