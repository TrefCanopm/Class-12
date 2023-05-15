#include <iostream>
#include <map>
#include "Money.h"

using namespace std;

typedef multimap<int, Money> Mult;
typedef multimap<int, Money> :: iterator it;

Mult Mmap(int n)
{
	Mult m;

	for (int i = 0; i < n; i++)
	{
		Money M(rand() % 100, rand() % 100);
		m.insert(make_pair(i, M));
	}

	return m;
}

void Print(Mult m)
{
	it iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		Money M;
		M = iter->second;
		cout << M << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

Mult MapM(Mult m)
{
	Money mn(100, 99);
	it iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second < mn)
			mn = iter->second;
	}
	cout << "Enter the number to put the item on" << endl;
	int n;
	cin >> n;
	m.emplace(n, mn);
	return m;
}

Mult MapS(Mult m)
{
	it iter;
	Mult m1;
	int s = 0;
	int n = 0, n1 = 0;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		s = s + iter->second.GetMoneyR() * 100 + iter->second.GetMoneyK();
		n = iter->first + 1;
	}
	s = s / n;
	Money M(s / 100, s & 100);
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second < M)
		{
			m1.insert(make_pair(n1, iter->second));
			n1++;
		}
	}
	return m1;
}

Mult MapMax(Mult m)
{
	int M;
	it iter;
	Money mx(0, 0);
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (mx < iter->second)
			mx = iter->second;
	}
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		iter->second = iter->second * mx;
	}
	return m;
}

int main()
{
	Mult m;
	cout << "Enter the size of the container" << endl;
	int n;
	cin >> n;
	m = Mmap(n);
	Print(m);
	m = MapM(m);
	Print(m);
	m = MapS(m);
	Print(m);
	m = MapMax(m);
	Print(m);
}