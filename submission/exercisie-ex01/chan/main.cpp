#include <iostream>
#include <list>

using namespace std;

list<int> lst;
int n, a, b;

int main()
{

	for (int i = 0; i < 10; i++) {
		cin >> n;
		lst.push_back(n);
	}
	cin >> a >> b;

	
	list<int>::iterator iter = lst.begin();
	list<int>::iterator iter2 = lst.begin();

	for (int i = 0; i < a-1; i++) {
		iter++;
	}
	for (int i = a; i < b-1; i++) {
		iter2++;
	}

	lst.erase(iter, iter2);

	for (list<int>::iterator itera = lst.begin(); itera != lst.end(); itera++) {
		cout << *itera << endl;
	}
	cout << "\n";


	return 0;
}