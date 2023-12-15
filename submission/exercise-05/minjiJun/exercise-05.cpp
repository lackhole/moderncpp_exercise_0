#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, input_num;

    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        cin >> input_num;
        A.push_back(input_num);
    }

    cin>> M;
    vector<int> B;
    for (int i = 0; i < M; i++) {
        cin >> input_num;
        B.push_back(input_num);

        cout << count(A.begin(), A.end(), input_num) <<' ';
    }

    



}