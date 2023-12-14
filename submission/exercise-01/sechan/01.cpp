#include <iostream>
#include <list>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS 

int main()
{
	list<int>l;
	int cnt = 0; 
	while (cnt != 10)
	{
		int a;
		cin >> a;
		l.push_back(a);
		cnt++; 
	}

	int in[2]; 
	cin >> in[0] >> in[1];

	int a = min(in[0], in[1]); 
	int b = max(in[0], in[1]);

	list<int>::iterator f_it = next(l.begin(), a); 
	list<int>::iterator b_it = next(l.begin(), b);
	
	l.erase(f_it, b_it); 
	list<int>::iterator it = l.begin(); 

	while (it != l.end())
	{
		cout << *it << " "; 
		it++; 
	}
}
