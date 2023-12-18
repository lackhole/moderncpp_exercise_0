#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
constexpr T gcd(T a, T b) {
	if (b == 0) return a;
	else
		return gcd(b, a % b);

}
int main() {
	static_assert(gcd(192, 72)==24, "");
	return 0;
}