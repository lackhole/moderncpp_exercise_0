// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solution() {

    vector<int> arr;

    for (size_t i = 0; i < 10; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);       

    }

    int num;
    cin >> num;


    auto it = std::find(arr.begin(), arr.end(), num); // n

    if (it != arr.end()) {
    
        std::ptrdiff_t index1 = std::distance(arr.begin(), it);
        cout << index1 << endl;
    }
    else {
      
        auto it2 = std::lower_bound(arr.begin(), arr.end(), num);
        
        if (it2 != arr.end()) {
            std::ptrdiff_t index0 = std::distance(arr.begin(), it2);
            std::cout << index0 << endl;
        }
        else {
            cout << "-1" << endl;
        }
        


    }







}

int main()
{
    solution();
}
