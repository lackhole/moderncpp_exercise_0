#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<int> v(10);

int main()
{
	for (int i = 0; i < 10; i++) scanf("%d", &v[i]);

	int a;
	scanf("%d", &a);

	vector<int>::iterator it = find(v.begin(), v.end(), a);

	int chk = INF;
	int idx = -1;

	if (it == v.end()) {
		for (int i = 0; i < 10; i++) {
			if (a > v[i]) continue;
			if (chk > v[i]) {
				chk = v[i];
				idx = i;
			}
		}
		if (chk == INF) printf("-1");
		else printf("%d", idx);
	}
	else printf("%d", it - v.begin());

	return 0;
}