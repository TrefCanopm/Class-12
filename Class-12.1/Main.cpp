#include <iostream>
#include <map>

using namespace std;

typedef multimap<int, float> Mul;
typedef multimap<int, float> ::iterator it;

Mul Mmap(int n)
{
	Mul m;
	for (int i = 0; i < n; i++)
	{
		m.insert(make_pair(i, rand() % 100));
	}
	return m;
}

void Print(Mul m)
{
	it iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->second << endl;
	}
	cout << "--------------------------------------" << endl;
}

Mul MapM(Mul m)
{
	it iter;
	float mn = 100;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (mn > iter->second)
			mn = iter->second;
	}
	cout << "Enter the number to put the item on" << endl;
	int n;
	cin >> n;
	m.emplace(n, mn);
	return m;
}

Mul MapS(Mul m)
{
	it iter;
	Mul m1;
	float s = 0, ms;
	int n, n1 = 0;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		s += iter->second;
		n = iter->first + 1;
	}
	s = s / n;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (s > iter->second)
		{
			ms = iter->second;
			m1.insert(make_pair(n1, ms));
			n1++;
		}
	}
	return m1;
}

Mul MapMax(Mul m)
{
	it iter;
	float mx = 0;
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
	Mul m;
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