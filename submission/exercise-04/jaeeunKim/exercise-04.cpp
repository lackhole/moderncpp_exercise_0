#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
bool compVec(int a, int b) {
	if (abs(a) < abs(b)) {
		if (a < b) return true;
		else false;
	}
	else return false;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, vector<int>> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v[i] = temp;
		m[abs(temp)].push_back(temp);
	}
	sort(v.begin(), v.end(), compVec);
	//sort(m.begin(), m.end(), compMap);
	cout << "\n---using vector ----\n";
	for (auto& a : v) cout << a << ' ';
	cout << "\n---using map ----\n";
	for (auto& a : m) {
		sort(a.second.begin(), a.second.end());
		for (auto& b : a.second)
			cout << b << ' ';

	}
	return 0;
}