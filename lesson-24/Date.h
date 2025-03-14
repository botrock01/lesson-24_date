#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
public:
	//--------- ������������ �� ����������� ---------
	Date(); // �� ������������� - ������� ����
	Date(int year, int month, int day); // � ����������� - ������ ����	

	bool isLeapYear()const; //�������� �� ���������� ��
	int monthDays()const; //ʳ������ ��� �� ������
	void nextDate(); // �������� ����
	void prevDate(); // ��������� ����

	//--------- �������� ---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;

	void showDate()const;
	bool valid()const; // �������� ���� �� ����������

	//--------- ��������� ��в������ ---------
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- ��������� �����Ϊ��� ---------	
	Date& operator += (int days); // ������ days ��� �� ����
	Date& operator -= (int days); // ������ days �� �� ����
	Date& operator += (float months); // ������ months ������ �� ����
	Date& operator -= (float months); // ������ months ����� �� ����
	Date& operator += (long years); // ������ years ���� �� ����
	Date& operator -= (long years); // ������ years ���� �� ����


	Date& operator -- ();
	Date operator -- (int);
	Date& operator ++ ();
	Date operator ++ (int);

	friend Date operator + (int days, const Date& a);
	friend Date operator - (int days, const Date& a);

	friend Date operator + (float months, const Date& a);
	friend Date operator - (float months, const Date& a);

	friend Date operator + (long years, const Date& a);
	friend Date operator - (long years, const Date& a);


	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);

	Date operator + (int days)const&;
	Date operator - (int days)const&;
	Date operator + (float months)const&;
	Date operator - (float months)const&;
	Date operator + (long years)const&;
	Date operator - (long years)const&;


};
