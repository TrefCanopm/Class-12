#include "Money.h"
#include <iostream>

using namespace std;
Money::Money()
{
	rubles = 0;
	kopecks = 0;
}
Money::Money(long r, int k)
{
	rubles = r;
	if (k < 100)
	{
		kopecks = k;
	}
	else
	{
		rubles = rubles + k / 100;
		kopecks = k % 100;
	}
}
Money::Money(const Money& m)
{
	rubles = m.rubles;
	kopecks = m.kopecks;
}

long Money::GetMoneyR()
{
	return rubles;
}
int Money::GetMoneyK()
{
	return kopecks;
}

void Money::SetMoney(long r, int k)
{
	rubles = r;
	kopecks = k;
}

Money& Money::operator = (const Money& m)
{
	rubles = m.rubles;
	kopecks = m.kopecks;
	return *this;
}
Money& Money::operator * (const Money& m)
{
	int M;
	M = (rubles * 100 + kopecks) * (m.rubles * 100 + m.kopecks);
	rubles = M / 100;
	kopecks = M % 100;
	return *this;
}
Money& Money::operator -- ()
{
	kopecks = kopecks - 1;
	return *this;
}
Money& Money::operator--(int)
{
	kopecks = kopecks - 1;
	return *this;
}


ostream& operator << (ostream& out, const Money& p)
{
	return(out << p.rubles << ", " << p.kopecks);
}
istream& operator >> (istream& in, Money& p)
{
	in >> p.rubles;
	in >> p.kopecks;
	return in;
}

bool Money::operator!=(const Money& m)
{
	if (this->rubles != m.rubles)
	{
		return 1;
	}
	else
	{
		if (this->kopecks != m.kopecks)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
bool Money::operator==(const Money& m)
{
	if (this->rubles == m.rubles)
	{
		if (this->kopecks == m.kopecks)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

bool Money:: operator <(const Money& m)
{
	if (this->rubles < m.rubles)
	{
		return 1;
	}
	else
	{
		if (this->rubles == m.rubles)
		{
			if (this->kopecks < m.kopecks)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
}