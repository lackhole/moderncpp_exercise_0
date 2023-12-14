#include <iostream>
#include <list>
using namespace std;

int main() {

	std::list<int> list;

	int num;
	for (int i = 0; i < 10; i++) {
		std::cin >> num;
		list.push_back(num);
	}

	int arr[2];
	cin >> arr[0] >> arr[1];

	int a = min(arr[0], arr[1]);
	int b = max(arr[0], arr[1]);

	std::list<int>::iterator begin = list.begin();
	std::list<int>::iterator end = list.begin();
	std::advance(begin, a);
	std::advance(end, b);

	list.erase(begin, end);


	for (auto i = list.begin(); i != list.end(); i++) {
		cout << *i << " ";
	}

}