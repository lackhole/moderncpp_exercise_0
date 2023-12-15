#include <iostream>
#include <list>
using namespace std;


int main() {

	list<int> num;
	int input_num, a, b;
	for (int i = 0; i < 10; i++) {
		cin >> input_num;
		num.push_back(input_num);
	}

	cin >> a >> b;

	int start_num = min(a, b);
	int end_num = max(a, b);

	//cout << start_num << end_num;

	list<int>::iterator frontIter = num.begin();
	for (int i = 0; i < start_num; i++) frontIter++;

	list<int>::iterator endIter = num.begin();
	for (int i = 0; i < end_num; i++) endIter++;

	num.erase(frontIter, endIter);

	while (num.size() > 0) {
		cout << num.front() << ' ';
		num.pop_front();
	}



	return 0;
}