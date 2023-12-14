#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS 

int main()
{
	vector<int> v(10); 

	for (int i = 0; i < 10; i++)
	{
		int in;
		cin >> in; 
		v[i] = in; 
	}

	int find_num;
	cin >> find_num; 

	auto it = find(v.begin(), v.end(), find_num); 

	if (it == v.end()) // 못찾음용
	{
		v.push_back(find_num); 

		sort(v.begin(), v.end()); 
		auto it = find(v.begin(), v.end(), find_num);
		it++; 
		cout << *it;
	}
	else
	{
		cout << *it; 
	}


}
