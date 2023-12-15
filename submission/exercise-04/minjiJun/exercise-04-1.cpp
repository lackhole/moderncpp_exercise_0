#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare_abs(int a, int b) {
    // compare abs integer value
    return abs(a) < abs(b);
}

int main() {
    int N, input_num;
    cin >> N;

    vector<int> num;
    for (int i = 0; i < N; i++) {
        cin >> input_num;
        num.push_back(input_num);
    }

    // sort given vector
    sort(num.begin(), num.end(), compare_abs);

    for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter) {
        cout << *iter <<' ';
    }
    


}


