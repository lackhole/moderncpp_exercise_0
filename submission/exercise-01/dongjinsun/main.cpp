#include <iostream>
#include <algorithm>
#include <list>

std::list<int>::iterator iter_plus(std::list<int>::iterator iter, int n);

int main() {
	int temp[10];
	for (int i = 0; i < 10; i++) {
		std::cin >> temp[i];
	}
	std::list<int> lst;
	for (const auto& x : temp) {
		lst.push_back(x);
	}
	int temp2[2];

	for (int i = 0; i < 2; i++) {
		std::cin >> temp2[i];
	}
	std::sort(temp2, temp2+2);
	std::list<int>::iterator iter = lst.begin();
	std::list<int>::iterator iter1 = iter_plus(iter,temp2[0] );
	std::list<int>::iterator iter2 = iter_plus(iter1, temp2[1]-temp2[0]);

	lst.erase(iter1, iter2);

	for(auto const& i: lst) {
		std::cout << i << " ";
	}

	return 0;
}


std::list<int>::iterator iter_plus(std::list<int>::iterator iter, int n) {
	if (n == 0) {
		return iter;
	}
	else 

		return iter_plus(++iter, n - 1);
}
