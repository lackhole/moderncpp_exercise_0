#include <iostream>
#include <list>
#include <algorithm>
#include <limits>

int main() {
    std::list<int> mylist;

    // 사용자로부터 10개의 정수 입력받아 std::list에 저장
    std::cout << "정수 10개를 입력하세요:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        mylist.push_back(num);
    }

    // 0부터 10사이의 정수 2개를 입력받아 작은 것을 a, 큰 것을 b로 설정
    int a, b;
    std::cout << "0부터 10사이의 정수 2개를 입력하세요:" << std::endl;

    // 사용자로부터 입력받은 값이 0부터 10 사이의 값이 될 때까지 반복
    while (!(std::cin >> a >> b) || (a < 0 || a > 10) || (b < 0 || b > 10)) {
        std::cin.clear(); // 입력 버퍼를 지워 에러 상태를 제거
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼를 비우고 개행 문자를 무시
        std::cout << "잘못된 범위입니다. 0부터 10 사이의 정수를 다시 입력하세요." << std::endl;
    }

    // a와 b 중 작은 값과 큰 값 설정
    int small = (a + b - std::abs(a - b)) / 2;
    int large = (a + b + std::abs(a - b)) / 2;

    // [small:large) 영역을 std::list에서 제거
    auto it_start = std::find(mylist.begin(), mylist.end(), small+1);

    // 수정된 부분: it_start에서 시작하도록 변경
    auto it_end = std::find(it_start, mylist.end(), large);

    if (it_start != mylist.end() && it_end != mylist.end()) {
        mylist.erase(it_start, std::next(it_end)); // [small:large) 범위 삭제
    } else {
        std::cout << "입력된 값 중 일부가 리스트에 없습니다." << std::endl;
        return 1; // 오류 코드 반환
    }

    // 결과 출력
    std::cout << "삭제 후 리스트:" << std::endl;
    for (const auto& num : mylist) {
        std::cout << num << " ";
    }

    return 0;
}