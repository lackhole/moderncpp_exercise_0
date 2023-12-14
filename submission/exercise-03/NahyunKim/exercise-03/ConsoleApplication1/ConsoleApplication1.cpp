
#include <iostream>

using namespace std;

template<typename x1,typename x2>
constexpr x2 gcd(x1 a, x2 b) {

    if (a % b) {
        return gcd(b, (a % b));
    }
    else {
        return b;
    }

}


int main()
{

    int a, b;
    cin >> a;
    cin >> b;
    const int num =gcd(a, b);

    cout << num << endl;
   

}
