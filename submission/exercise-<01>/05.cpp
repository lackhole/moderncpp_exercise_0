#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>  //해시 map 사용
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	unordered_map<int, int> m1;
	while (n--) {
		int k;
		cin >> k;
		auto it = m1.find(k);
		if (it != m1.end()) {
			it->second += 1;
		}
		else { //못찾음
			m1.emplace(k, 1);
		}
	}
	int m;
	cin >> m;
	vector<int> B;
	while (m--) {
		int k;
		cin >> k;
		B.push_back(k);
	}
	
	for (const auto& x: B) {
		auto it = m1.find(x);
		if (it != m1.end()) {
			cout << it->second << " ";
		}
		else {
			cout << 0<< " ";
		}
	}

	return 0;
}
