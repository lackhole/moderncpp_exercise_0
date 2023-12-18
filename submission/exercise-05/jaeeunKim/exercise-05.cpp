#include <iostream>
#include <vector>

using namespace std;
int num[100000] = { 0 };
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		num[a[i]]++;
	}

	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];

	for (auto& x : b) {
		cout << num[x] << ' ';
	}
	return 0;
}
