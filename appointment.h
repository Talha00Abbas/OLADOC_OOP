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

class Appointment
{
	char appno[6];
	char appname[50];


public:
	char time[50];
	void create_app()
	{
		cout << "\nNEW APPOINTMENT ENTRY...\n";
		cout << "\nEnter The Appointment no.";
		cin >> appno;
		cout << "\n\nEnter The Name of The Appointment ";
		cin >> appname;
		gets(appname);
		cout << "\n\nEnter The Time of The Appointment ";
		cin >> time;
		gets(time);

		cout << "\n\n\Appointment Created..";
	}
	void show_app()
	{
		cout << "\nAppointment no : " << appno;
		cout << "\Appointment Name : ";
		puts(appname);
		cout << "\Appointment Name : ";
		puts(time);
	}
	void modify_app()
	{
		cout << "\Appointment no. : " << appno;
		cout << "\nModify Appointment Name : ";
		cin >> appname;
		gets(appname);
		cout << "\nModify Appointment Name : ";
		cin >> time;
		gets(time);

	}
	char* retappno()
	{
		return appno;
	}

	char* rettime()
	{
		return time;
	}

	void report()
	{
		cout << appno << setw(30) << appname << setw(30) << time << endl;
	}

	void doctor_options()
	{
		char ch;
		do
		{

			cout << "\n\n\n\tMAIN MENU";
			cout << "\n\n\t01. SHOW APPOINTMENTS";
			cout << "\n\n\t02. START APPOINTMENT";
			cout << "\n\n\t03. DELETE APPOINTMENT";
			cout << "\n\n\t04. LOG OUT";
			cout << "\n\n\t05. DELETE ACCOUNT";
			cout << "\n\n\tPlease Select Your Option (1-5) ";
			cout << endl;
			cin >> ch;
			switch (ch)
			{
			case '1':

				break;
			case '2':
				break;
			case '3':
				cout << "Registering" << endl;

				break;
			case '4':
				cout << "Logging In" << endl;

				break;
			case '5':
				cout << "Registering" << endl;

				break;
			default:cout << "\a";
			}
		} while (ch != '5');
	}

}; //class ends here
