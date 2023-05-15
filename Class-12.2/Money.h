#pragma once

#include <iostream>

using namespace std;

class Money
{
	long rubles;
	int kopecks;
public:
	Money();
	Money(long r, int k);
	Money(const Money&);
	long GetMoneyR();
	int GetMoneyK();
	void SetMoney(long r, int k);
	Money& operator = (const Money&);
	Money& operator * (const Money&);
	Money& operator --();
	Money& operator --(int);
	friend std::ostream& operator << (std::ostream& out, const Money&);
	friend std::istream& operator >> (std::istream& in, Money&);
	bool operator == (const Money&);
	bool operator != (const Money&);
	bool operator < (const Money&);
	~Money() {};
};