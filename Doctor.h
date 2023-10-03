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

class doctor
{
	char bno[6];
	char bname[50];
	char pass[20];
	char aname[20];
	int money = 2000;
public:
	void create_doc()
	{
		cout << "\nNEW DOCTOR ENTRY...\n";
		cout << "\nEnter The Doctor no.";
		cin >> bno;
		cout << "\n\nEnter The Name of The Doctor ";
		cin >> bname;
		gets(bname);

		cout << "\n\nEnter The Password ";
		cin >> pass;
		gets(pass);

		cout << "\n\nEnter The Speciality Name ";
		cin >> aname;
		gets(aname);

		cout << "\n\n\nAccount Created..";
	}
	void show_doc()
	{
		cout << "\nDoctor no. : " << bno;
		cout << "\nDoctor Name : ";
		puts(bname);
		cout << "Doctor Speciality Name : ";
		puts(aname);
	}
	void modify_doc()
	{
		cout << "\nDoctor no. : " << bno;
		cout << "\nModify Doctor Name : ";
		cin >> bname;
		gets(bname);
		cout << "\nModify Doctor Password : ";
		cin >> pass;
		gets(pass);
		cout << "\nModify Speciality of Doctor : ";
		cin >> aname;
		gets(aname);
	}
	char* retbno()
	{
		return bno;
	}

	char* retpass()
	{
		return pass;
	}
	char* retname()
	{
		return bname;
	}


	void report()
	{
		cout << bno << setw(30) << bname << setw(30) << aname << endl;
	}

}; //class ends here
