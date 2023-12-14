#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;



bool compVec(int a, int b) {
	if (abs(a) < abs(b)) {
		return true;
	}
	else if (abs(a) == abs(b)) {
		if (a < b)
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, vector<int>> m;

	/*for (auto& x : v)
		cin >> x; */
	struct compare_abs {
		bool operator()(int a, int b) const {
			return abs(a) < abs(b);
		}
	};

	multimap<int, int, compare_abs> customMap; // compare_abs 를 통해 key값을 변경?한다?

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v[i] = temp;
		m[abs(temp)].push_back(temp);
		customMap.emplace(temp,temp);
	}
	sort(v.begin(), v.end(), compVec);

	/*sort(v.begin(), v.end(), [](const auto& x, const auto& y) {
		return abs(x) < abs(y);
	});*/

	cout << "\n---using vector ----\n";
	for (auto& a : v) cout << a << ' ';
	cout << "\n---using map ----\n";

	for (auto& a : customMap)
		cout << a.first << ' ';
	/*for (auto& a : m) {
		sort(a.second.begin(), a.second.end());
		for (auto& b : a.second)
			cout << b << ' ';
	}*/
	return 0;
}