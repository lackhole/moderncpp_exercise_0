#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int i = 10;
	
	while (i--) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	int a;
	cin >> a;
	
	//vector<int>::iterator it;
	if (find(v.begin(), v.end(), a) != v.end()) {
		int idx = find(v.begin(), v.end(), a) - v.begin(); //인덱스 
		cout << idx;
	}
	else {
		
		int idx = -1;
		vector<int>::iterator it;
		// Commented by yonggyulee: cannot find check
		// find_if(v.begin(), v.end(),check(a) );
		
		if (it == v.end()) {
			cout << idx;
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == *it)
				{
					idx = i;
					break;
				}
			}
			cout << idx;
		}
		
	}
	

	
	

	return 0;
}
