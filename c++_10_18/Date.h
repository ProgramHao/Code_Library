#pragma once

#include<iostream>
#include<assert.h>
using namespace std;


// һ�����׿���������Щ�������-����Щ��������������������
class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	// ��Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline(����)
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))//����Ķ�����29��
		{
			day += 1;
		}

		return day;
	}

	// �����Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline(����)
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool CheckDate()
	{
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day > 0 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// �����Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		/*if (!CheckDate())
		{
			Print();
			cout << "�չ�������ڷǷ�" << endl;
		}*/

		assert(CheckDate());
	}

	void Print();

	//�Ƚϲ�����
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	Date operator+(int day);
	Date& operator+=(int day);

	// ++d1;
	// d1++;
	// ֱ�Ӱ��������أ��޷�����
	// ���⴦��ʹ���������֣�����++��������һ��int������ǰ�ù��ɺ������ؽ�������
	Date& operator++(); // ǰ��
	Date operator++(int); // ����


		// d1 - 100
	Date operator-(int day) const;
	Date& operator-=(int day);

	Date& operator--(); // ǰ��
	Date operator--(int); // ����

	// d1 - d2 �������
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};
