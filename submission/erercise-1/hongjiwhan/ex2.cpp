#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;

	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int a;
	cin >> a;
	
	int result = upper_bound(v.begin(), v.end(), a) - v.begin();
	if (result >= v.size()) {
		cout << -1 << "\n";
	}
	else {
		cout << result << "\n";
	}

	return 0;
}