#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>  //해시 map 사용
#include <numeric>
using namespace std;

int main() {
	int a, b, N;
	cin >> a >> b >> N;

	vector<int> A(N);
	vector<int> B(N);

	
	iota(A.begin(), A.end(), a);
	iota(B.begin(), B.end(), b);
	
	auto res=inner_product(A.begin(), A.end(), B.begin(), 0);

	cout << res;
	return 0;
}
