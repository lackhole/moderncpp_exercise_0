#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>

using namespace std;

list<int> num_list;
int a, b;

int main()
{
	for (int i = 0; i < 10; i++) {
		int x;
		scanf("%d", &x);

		num_list.push_back(x);
	}

	scanf("%d %d", &a, &b);

	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int idx = -1;

	for (list<int>::iterator iter = num_list.begin(); iter != num_list.end(); iter++) {
		idx++;
		if (a <= idx && idx < b) continue;
		printf("%d ", *iter);
	}

	return 0;
}