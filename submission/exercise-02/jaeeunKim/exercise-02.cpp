#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 10
int main() {
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int a;
	cin >> a;
	auto it = find(v.begin(), v.end(), a);
	int max_ = *max_element(v.begin(), v.end());
	if (it != v.end())
		cout << it - v.begin() << '\n';
	else {
		while (a <= max_ ) {
			it = find(v.begin(), v.end(), ++a);
			if (it != v.end())
				break;
		}
		if (it == v.end())
			cout << -1 << '\n';
		else
			cout << it - v.begin() << '\n';
	}

	return 0;
}