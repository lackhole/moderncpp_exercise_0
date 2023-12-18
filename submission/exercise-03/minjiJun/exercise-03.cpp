#include <iostream>
using namespace std;

constexpr int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

template<int a, int b, int r = a % b>
struct gcd_2 {
    static constexpr int value = gcd_2<b, r>::value;
};

template<int a, int b>
struct gcd_2<a, b, 0> {
    static constexpr int value = b;
};

int main() {
    
    cout << GCD(24, 36);

}
