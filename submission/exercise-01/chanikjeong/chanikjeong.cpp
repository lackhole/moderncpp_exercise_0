#include <iostream>

#include <list>
using namespace std;


int main() {

	list<int> ls;
	int i = 10;
	while (i--){		
		int k;
		cin >> k;
		ls.push_back(k);
	}
	int a, b;
	cin >> a >> b;
	list<int>::iterator it1, it2;
	it1 = it2=ls.begin();
	advance(it1, a);
	advance(it2, b);
	ls.erase(it1, it2);
	
	
	while (!ls.empty()) {
		cout << ls.front()<<" ";
		ls.pop_front();
		
	}


	return 0;
}
