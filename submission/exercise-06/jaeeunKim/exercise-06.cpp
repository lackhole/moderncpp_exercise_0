#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, N;
	cin >> a >> b >> N;
	vector<int> aa(N), bb(N);
	for_each(aa.begin(), aa.end(), [&a](auto& x) {
		x = a++;
		});

	/*for_each(bb.begin(), bb.end(), [&b](auto& x) {
		x = b++;
		});*/
	iota(bb.begin(), bb.end(), b);

	int ans = 0;
	cout << inner_product(aa.begin(), aa.end(), bb.begin(), 0);
	
	return 0;
}