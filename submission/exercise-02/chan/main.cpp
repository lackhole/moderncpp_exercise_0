#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a;
vector <int> v;

int main()
{
	for (int i = 0; i < 10; i++) {
		cin >> n;
		v.push_back(n);
	}
	cin >> a;

	auto hi = upper_bound(v.begin(), v.end(), a);

	if (find(v.begin(), v.end(), a) != v.end()){
		cout << find(v.begin(), v.end(), a) - v.begin() << "\n";	
	}
	else if (find(v.begin(), v.end(), a) == v.end()) {

		cout << hi - v.begin() << "\n";
		if (find(v.begin(), v.end(), a) != v.end()) {
			cout << -1 << "\n";
		}
		
	}
		
	
	return 0;
}