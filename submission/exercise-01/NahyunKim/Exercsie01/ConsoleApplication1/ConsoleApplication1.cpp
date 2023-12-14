// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <algorithm>


using namespace std;
list<int> arr;
list<int> result;


void solution() {

    int minnum, maxnum;
    int in01, in02;

   for (size_t i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cin >> in01;
    cin >> in02;
    
    minnum = min(in01, in02);
    maxnum = max(in01, in02);

    auto start = std::next(arr.begin(), minnum); 
    auto end = std::next(arr.begin(), maxnum);

    arr.erase(start, end);

    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

}


int main()
{
    
    solution();
   
}
