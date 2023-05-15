#include <iostream>
#include <map>
using namespace std;

template <class T>
class Plenty
{
	multimap<int, T> plenty;
	typename multimap<int, T>::iterator it;
	int len;
public:
	Plenty();
	Plenty(int);

	void Print();
	Plenty& MapMn();
	Plenty& MapS();
	Plenty& MapMax();

	~Plenty() {};
};

template <class T>
Plenty<T>::Plenty()
{
	len = 0;
}

template <class T>
Plenty<T>::Plenty(int n)
{
	len = n;
	for (int i = 0; i < n; i++)
	{
		plenty.insert(make_pair(i, rand() % 100));
	}
}

template<class T>
void Plenty<T>::Print()
{
	for (it = plenty.begin(); it != plenty.end(); it++)
	{
		cout << it->second << endl;
	}
	cout << "----------------------------------------------" << endl;
}

template<class T>
Plenty<T>& Plenty<T>::MapMn()
{
	T mn = 100;
	for (it = plenty.begin(); it != plenty.end(); it++)
	{
		if (mn > it->second)
			mn = it->second;
	}
	cout << "Enter the number to put the item on" << endl;
	int n;
	cin >> n;
	plenty.emplace(n, mn);
	len++;
	return *this;
}

template <class T>
Plenty<T>& Plenty<T>::MapS()
{
	multimap<int, T> multi;
	T s = 0;
	int n, n1 = 0;
	for (it = plenty.begin(); it != plenty.end();it++)
	{
		s += it->second;
		n = it->first + 1;
	}
	s = s / n;
	for (it = plenty.begin(); it != plenty.end(); it++)
	{
		if (it->second < s)
		{
			multi.insert(make_pair(n1, it->second));
			n1++;
		}
	}
	this->plenty = multi;
	return *this;
}

template<class T>
Plenty<T>& Plenty<T>::MapMax()
{
	T mx = 0;
	for (it = plenty.begin(); it != plenty.end(); it++)
	{
		if (mx < it->second)
			mx = it->second;
	}
	for (it = plenty.begin(); it != plenty.end(); it++)
		it->second = it->second * mx;
	return *this;
}

int main()
{
	cout << "Enter the size of the container" << endl;
	int n;
	cin >> n;
	Plenty<int> P(n);
	P.Print();
	P.MapMn();
	P.Print();
	P.MapS();
	P.Print();
	P.MapMax();
	P.Print();
}