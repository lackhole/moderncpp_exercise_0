#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int soinsu(int a, int b) {
	int c = 0;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {

	/*두 상수표현식(constexpr) 자연수 a, b 가 주어졌을때, 
	이들의 최대공약수를 컴파일 시간에 구하는 로직을 작성하세요
	constexpr 함수 / 템플릿 특수화 두 방법 모두로 구현합니다*/

	static_assert(soinsu(192, 72) == 24, "");

	return 0;
}