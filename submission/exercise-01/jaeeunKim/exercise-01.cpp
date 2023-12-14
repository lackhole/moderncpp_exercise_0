#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	list<int> lst;
	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		lst.push_back(temp);
	}
	int a, b;
	cin >> a >> b;
	int max_ = max(a, b);
	int min_ = min(a, b);
	int cnt = 0;
	auto it = lst.begin();
	while (cnt < min_) {
		it++;
		cnt++;
	}
	cnt = 0;
	while (cnt < max_ - min_) {
		it = lst.erase(it);
		cnt++;
	}

	for (auto& a : lst)
		cout << a << ' ';
}