#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 10
int main() {
	vector<int> v(N);

	// input 10 numbers in vector(v)
	for (int i = 0; i < N; i++) cin >> v[i];

	int a;
	cin >> a;

	// find a in vector(v)
	auto it = find(v.begin(), v.end(), a);


	int max_ = *max_element(v.begin(), v.end());

	if (it != v.end())
		//cout << it - v.begin() << '\n';
		cout << distance(v.begin(), it);
	else {
		bool found = false;
		int minimum = 1000000;
		int minimum_index = -1;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > a) {
				found = true;
				if (v[i] < minimum) {
					minimum = v[i];
					minimum_index = i;
				}
			}
		}
		if (found)
			cout << minimum_index << '\n';
		else
			cout << "-1\n";
		/*while (a <= max_ ) {
			it = find(v.begin(), v.end(), ++a);
			if (it != v.end())
				break;
		}
		if (it == v.end())
			cout << -1 << '\n';
		else
			cout << it - v.begin() << '\n';*/
	}

	return 0;
}