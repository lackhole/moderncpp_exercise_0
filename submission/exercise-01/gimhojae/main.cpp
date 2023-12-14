#include <iostream>
#include <list>

using namespace std;

int main(void) {
  list<int> li;
  int a, b;

  for (int i = 0; i < 10; i++) {
    int n;
    cin >> n;
    li.push_back(n);
  }

  cin >> a >> b;

  int temp = a;
  a = min(a, b);
  b = max(temp, b);

  auto itr_1 = li.begin();
  auto itr_2 = li.begin();
  advance(itr_1, a);
  advance(itr_2, b);
  li.erase(itr_1, itr_2);

  for (const auto& i : li) {
    cout << i << ' ';
  }
 }