#pragma once
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



class patient
{
	char admno[6];
	char name[20];
	char stbno[6];
	char pass[20];
	int token;
	int balance = 2000;

public:
	void create_patient()
	{
		cout << "\nNEW PATIENT ENTRY...\n";
		cout << "\nEnter The admit no. ";
		cin >> admno;
		cout << "\n\nEnter The Name of The Patient ";
		cin >> name;
		cout << "\n\nEnter Password ";
		cin >> pass;
		gets(name);
		token = 0;
		stbno[0] = '/0';
		cout << "\n\Patient Record Created..";
	}

	int	deductBalance(int bal)
	{
		balance -= bal;
		return balance;
	}

	bool compare_patient(char _admitNo[], char _name[], char _pass[])
	{
		if (admno == _admitNo && name == _name && pass == _pass)
		{

			return true;
		}
		else
		{
			false;
		}
	}

	void show_patient()
	{
		cout << "\nAdmit no. : " << admno;
		cout << "\Patient Name : ";
		puts(name);
		cout << "Password : ";
		puts(pass);

		cout << "\nNo of Book issued : " << token;
		if (token == 1)
			cout << "\nBook No " << stbno;
	}
	void modify_patient()
	{
		cout << "\nAdmit no. : " << admno;
		cout << "\nModify Patient Name : ";
		cin >> name;
		gets(name);
		cout << "\nModify Patient Password : ";
		cin >> pass;
		gets(pass);
	}
	char* retadmno()
	{
		return admno;
	}

	char* retpass()
	{
		return pass;
	}

	char* retstbno()
	{
		return stbno;
	}
	int rettoken()
	{
		return token;
	}
	void addtoken()
	{
		token = 1;
	}
	void resettoken()
	{
		token = 0;
	}
	void getstbno(char t[])
	{
		strcpy_s(stbno, t);
	}
	void report()
	{
		cout << "\t" << admno << setw(20) << name << setw(20) << pass << setw(10) << token << endl;
	}





};