#pragma once
#include<fstream>
#include<string>
#include<cstring>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<cstdio>
#include<windows.h>
char* gets(char* str);
using namespace std;

char* gets(char* str)
{
	return nullptr;
}

#pragma region MAIN CLASS OPERATIONS

//***************************************************************
// CLASS USED IN PROJECT
//****************************************************************


#pragma endregion

class Date
{
public:
	int day, month, year;

public:

	Date(int day_val = 0, int _month = 0, int _year = 0) {
		day = day_val;
		month = _month;
		year = _year;
	}


	int operator-(Date _date2)
	{
		int year_val, month_val, day_val;
		year_val = abs(_date2.year - this->year);
		month_val = abs(_date2.month - this->month);
		day_val = abs(_date2.day - this->day);
		day_val = day_val + (month_val * 30) + (year_val * 365);
		return day_val;
	}
};




