사용자로부터 정수 10개를 입력받아 std::vector에 차례대로 저장 합니다

정수 1개를 추가로 입력받고 이를 a 라 하자

std::vector 에 a 가 있다면 해당 위치의 인덱스를 출력합니다

std::vector 에 a 가 없다면 a 보다 크면서 a 와 가장 가까운 원소의 인덱스를 출력합니다

이마저도 없다면 -1 을 출력합니다

a 검색 시 STL 함수를 사용한다. 직접 구현해서는 안됩니다

입력 예
```
40 20 10 30 50 60 80 70 100 90
31
```

출력 예
```
0
```

입력 예 2
```
40 20 10 30 50 60 80 70 100 90
101
```

출력 예 2
```
-1
```
