#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector <int> num, num2;
    int input_num, a, b;
	for (int i = 0; i < 10; i++) {
		cin >> input_num;
		num.push_back(input_num);
	}

    cin >> input_num;

    // sort(num.begin(), num.end());

    if (find(num.begin(), num.end(), input_num) != num.end()) { // 해당 원소를 찾은 경우
        cout << input_num;
    }
    else { // 못찾은경우
    
        vector <int>::iterator iter;
        for (iter = num.begin(); iter != num.end(); ++iter){
            if (*iter - input_num > 0) num2.push_back(*iter - input_num);
            else num2.push_back(0);     
        }
        
        int min_ele = *min_element(num2.begin(), num2.end());
        int max_ele = *max_element(num2.begin(), num2.end());
        int min_val = 10000000;
        iter = num2.begin();
        if (max_ele < 1) cout << "-1"; // 가장 큰 원소가 1보다 작으면 제일 큰 경우
        else { // 주어진 input보다 큰 수 중에서 가장 가까운놈 찾기
            for (iter = num2.begin(); iter != num2.end(); ++iter){
                if (*iter > 0 && *iter < min_val) min_val = *iter; 
            }
            cout << find(num2.begin(), num2.end(), min_val) - num2.begin();
        
        }

     
	}
    
}