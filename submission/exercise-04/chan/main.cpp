#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num;
vector <int> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), [](int a, int b) {
		return abs(a) < abs(b);
	});

	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";
	
	return 0;
}