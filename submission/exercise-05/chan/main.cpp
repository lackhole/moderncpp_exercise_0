#include <iostream>
#include <vector>
#include <unordered_map>

//Hash 알고리즘

using namespace std;

int n, m;

int main()
{
	cin >> n;

	unordered_map<int, int> my_map;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		auto it = my_map.find(x);
		if (it != my_map.end()) {
			it->second += 1;
		}
		else { // not found
			my_map.emplace(x, 1);
		}
	}

	cin >> m;
	vector <int> v(m);
	for (auto& x : v) {
		cin >> x;
	}

	for (const auto& x : v) {
		auto it = my_map.find(x);
		if (it != my_map.end()) {
			cout << it->second << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	
	return 0;
}