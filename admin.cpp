#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<cstdio>
#include<windows.h>
#include "admin.h"
#include "Doctor.h"
#include "Patient.h"
#include "appointment.h"
using namespace std;

//options prototypes
void patient_options();
void doctor_options();
//ends

char* gets(char* str);

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//***************************************************************
// global declaration for stream object, object
//****************************************************************
fstream fp, fp1;
doctor dc;
patient st;
Appointment app;

int credRank;
//***************************************************************
// function to write in file
//****************************************************************

void write_doc()
{
    char ch;
    fp.open("book.dat", ios::out | ios::app);
    do
    {

        dc.create_doc();
        fp.write((char*)&dc, sizeof(doctor));
        cout << "\n\nDo you want to add more record..(y/n?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}

void write_app()
{
    char ch;
    fp.open("apps.dat", ios::out | ios::app);
    do
    {
        app.create_app();
        fp.write((char*)&app, sizeof(Appointment));
        cout << "\n\nDo you want to add more record..(y/n?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}


void write_patient()
{
    char ch;
    fp.open("patient.dat", ios::out | ios::app);
    do
    {
        st.create_patient();
        fp.write((char*)&st, sizeof(patient));
        cout << "\n\ndo you want to add more record..(y/n?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fp.close();
}
//***************************************************************
// function to read specific record from file
//****************************************************************
void display_spb(char n[])
{
    cout << "\nDOCTOR DETAILS\n";
    int flag = 0;
    fp.open("book.dat", ios::in);
    while (fp.read((char*)&dc, sizeof(doctor)))
    {
        if (strcmp(dc.retbno(), n) == 0)
        {
            dc.show_doc();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nDoctor does not exist";

}

void display_spa(char n[])
{
    cout << "\nAPPOINTMENT DETAILS\n";
    int flag = 0;
    fp.open("apps.dat", ios::in);
    while (fp.read((char*)&app, sizeof(Appointment)))
    {
        if (strcmp(app.retappno(), n) == 0)
        {
            app.show_app();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nAppointment does not exist";

}


void display_spp(char n[])
{
    cout << "\nPATIENT DETAILS\n";
    int flag = 0;
    fp.open("patient.dat", ios::in);
    while (fp.read((char*)&st, sizeof(patient)))
    {
        if ((strcmp(st.retadmno(), n) == 0))
        {
            st.show_patient();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nPatient does not exist";

}
//***************************************************************
// function to modify record of file
//****************************************************************
void modify_doc()
{
    char n[6];
    int found = 0;

    cout << "\n\n\tMODIFY DOCTOR RECORD.... ";
    cout << "\n\n\tEnter The ID no. of The Doctor";
    cin >> n;
    fp.open("book.dat", ios::in | ios::out);
    while (fp.read((char*)&dc, sizeof(doctor)) && found == 0)
    {
        if (strcmp(dc.retbno(), n) == 0)
        {
            dc.show_doc();
            cout << "\nEnter The New Details of doctor" << endl;
            dc.modify_doc();
            int pos = -1 * sizeof(dc);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&dc, sizeof(doctor));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";

}

void modify_app()
{
    char n[6];
    int found = 0;

    cout << "\n\n\tMODIFY APPOINTMENT RECORD.... ";
    cout << "\n\n\tEnter The ID no. of The Appointment";
    cin >> n;
    fp.open("apps.dat", ios::in | ios::out);
    while (fp.read((char*)&app, sizeof(Appointment)) && found == 0)
    {
        if (strcmp(app.retappno(), n) == 0)
        {
            app.show_app();
            cout << "\nEnter The New Details of appointment" << endl;
            app.modify_app();
            int pos = -1 * sizeof(app);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&app, sizeof(Appointment));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";

}

void modify_patient()
{
    char n[6];
    int found = 0;

    cout << "\n\n\tMODIFY PATIENT RECORD... ";
    cout << "\n\n\tEnter The admit no. of The patient";
    cin >> n;
    fp.open("patient.dat", ios::in | ios::out);
    while (fp.read((char*)&st, sizeof(patient)) && found == 0)
    {
        if (strcmp(st.retadmno(), n) == 0)
        {
            st.show_patient();
            cout << "\nEnter The New Details of patient" << endl;
            st.modify_patient();
            int pos = -1 * sizeof(st);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&st, sizeof(patient));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";

}
//***************************************************************
// function to delete record of file
//****************************************************************
void delete_patient()
{
    char n[6];
    int flag = 0;

    cout << "\n\n\n\tDELETE PATIENT...";
    cout << "\n\nEnter The admit no. of the Patient You Want To Delete : ";
    cin >> n;
    fp.open("patient.dat", ios::in | ios::out);
    fstream fp;
    fp.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)&st, sizeof(patient)))
    {
        if (strcmp(st.retadmno(), n) != 0)
            fp.write((char*)&st, sizeof(patient));
        else
            flag = 1;
    }
    fp.close();
    fp.close();
    remove("patient.dat");
    rename("Temp.dat", "patient.dat");
    if (flag == 1)
        cout << "\n\n\tRecord Deleted ..";
    else
        cout << "\n\nRecord not found";

}

void delete_doc()
{
    char n[6];

    cout << "\n\n\n\tDELETE DOCTOR ...";
    cout << "\n\nEnter The Doctor no. of the Doctor You Want To Delete : ";
    cin >> n;
    fp.open("book.dat", ios::in | ios::out);
    fstream fp;
    fp.open("Temp3.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)&dc, sizeof(doctor)))
    {
        if (strcmp(dc.retbno(), n) != 0)
        {
            fp.write((char*)&dc, sizeof(doctor));
        }
    }
    fp.close();
    fp.close();
    remove("book.dat");
    rename("Temp3.dat", "book.dat");
    cout << "\n\n\tRecord Deleted ..";
}
//***************************************************************
// function to display all patients list
//****************************************************************
void display_alls()
{

    fp.open("patient.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        return;
    }
    cout << "\n\n\t\tPATIENT LIST\n\n";
    cout << "==================================================================\n"
        ;
    cout << "\tAdmit No." << setw(10) << "Name" << setw(20) << "Password" << setw(20) << "Doctor Issued\n";
    cout << "==================================================================\n"
        ;
    while (fp.read((char*)&st, sizeof(patient)))
    {
        st.report();
    }
    fp.close();
}

//***************************************************************
// function to display Appointment list
//****************************************************************
void display_allapps()
{

    fp.open("apps.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        return;
    }
    cout << "\n\n\t\tAPPOINTMENT LIST\n\n";
    cout << " =========================================================================\n";
    cout << "ID" << setw(20) << "Appointment Name" << setw(25) << "Time\n";
    cout << "=========================================================================\n";
    while (fp.read((char*)&app, sizeof(Appointment)))
    {
        app.report();
    }
    fp.close();
}

//***************************************************************
// function to display Books list
//****************************************************************
void display_allb()
{

    fp.open("book.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        return;
    }
    cout << "\n\n\t\tBook LIST\n\n";
    cout << " =========================================================================\n";
    cout << "DR ID" << setw(20) << "Doctor Name" << setw(25) << "Speciality\n";
    cout << "=========================================================================\n";
    while (fp.read((char*)&dc, sizeof(doctor)))
    {
        dc.report();
    }
    fp.close();
}
//***************************************************************
// function to book issue
//****************************************************************
void book_issue()
{
    char sn[6], bn[6];
    int found = 0, flag = 0;

    cout << "\n\nDOCTOR ISSUE ...";
    cout << "\n\n\tEnter The patient's admit no.";
    cin >> sn;
    fp.open("patient.dat", ios::in | ios::out);
    fp1.open("book.dat", ios::in | ios::out);
    while (fp.read((char*)&st, sizeof(patient)) && found == 0)
    {
        if (strcmp(st.retadmno(), sn) == 0)
        {
            found = 1;
            if (st.rettoken() == 0)
            {
                cout << "\n\n\tEnter the doctor no. ";
                cin >> bn;
                while (fp1.read((char*)&dc, sizeof(doctor)) && flag == 0)
                {
                    if (strcmp(dc.retbno(), bn) == 0)
                    {
                        dc.show_doc();
                        flag = 1;
                        st.addtoken();
                        st.getstbno(dc.retbno());
                        int pos = -1 * sizeof(st);
                        fp.seekp(pos, ios::cur);
                        fp.write((char*)&st, sizeof(patient));
                   }
                }
                if (flag == 0)
                    cout << "Doctor no does not exist";
            }
            else
                cout << "You have not finished pending appointments ";
        }
    }
    if (found == 0)
        cout << "Patient record not exist...";

    fp.close();
    fp1.close();
}
//***************************************************************
// function to deposit book
//****************************************************************
void book_deposit()
{
    char sn[6], bn[6];
    int found = 0, flag = 0, day, fine;

    cout << "\n\nDOCTOR DEPOSIT ...";
    cout << "\n\n\tEnter The patient’s admit no.";
    cin >> sn;
    fp.open("patient.dat", ios::in | ios::out);
    fp1.open("book.dat", ios::in | ios::out);
    while (fp.read((char*)&st, sizeof(patient)) && found == 0)
    {
        if (strcmp(st.retadmno(), sn) == 0)
        {
            found = 1;
            if (st.rettoken() == 1)
            {
                while (fp1.read((char*)&dc, sizeof(doctor)) && flag == 0)
                {
                    if (strcmp(dc.retbno(), st.retstbno()) == 0)
                    {
                        dc.show_doc();
                        flag = 1;
                        cout << "\n\nDoctor deposited in no. of days";
                        cin >> day;
                        if (day > 15)
                        {
                            fine = (day - 15) * 1;
                            cout << "\n\nFine has to deposited Rs. " << fine;
                        }
                        st.resettoken();
                        int pos = -1 * sizeof(st);
                        fp.seekp(pos, ios::cur);
                        fp.write((char*)&st, sizeof(patient));
                        cout << "\n\n\t Doctor deposited successfully";
                    }
                }
                if (flag == 0)
                    cout << "Doctor no does not exist";
            }
            else
                cout << "No Doctor is issued..please check!!";
        }
    }
    if (found == 0)
        cout << "Patient record not exist...";

    fp.close();
    fp1.close();
}

//***************************************************************
// Function to Login User
//****************************************************************

void LoginUser() 
{
    char admitNO[6];
    char name[20];
    char password[20];

    cout << "\nEnter The admit no. ";
    cin >> admitNO;
    cout << "\n\nEnter The Name of The Patient ";
    cin >> name;
    gets(name);
    cout << "\n\nEnter Password ";
    cin >> password;
    
    int flag = 0;
    fp.open("patient.dat", ios::in);
    while (fp.read((char*)&st, sizeof(patient)))
    {
        if ((strcmp(st.retadmno(), admitNO) == 0) && (strcmp(st.retpass(), password) == 0))
        {
            cout << "RIGHT PASSWORD" << endl;
            flag = 1;
            patient_options();
            
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nWrong Password";
}


void LoginDoctor()
{
    char admitNO[6];
    char name[20];
    char password[20];

    cout << "\nEnter The admit no. ";
    cin >> admitNO;
    cout << "\n\nEnter The Name of The Docotr ";
    cin >> name;
    gets(name);
    cout << "\n\nEnter Password ";
    cin >> password;

    int flag = 0;
    fp.open("book.dat", ios::in);
    while (fp.read((char*)&st, sizeof(patient)))
    {
        if ((strcmp(dc.retbno(), admitNO) == 0) && (strcmp(dc.retpass(), password) == 0))
        {
            cout << "RIGHT PASSWORD" << endl;
            flag = 1;
            doctor_options();
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nWrong Password";
}

//***************************************************************
// Function to Register User
//****************************************************************

void RegisterUser()
{
    write_patient();
    
}

void RegisterDoctor()
{
    write_doc();

}

//***************************************************************
// INTRODUCTION FUNCTION
//****************************************************************
void intro()
{

    gotoxy(35, 11);
    cout << "HOSPITAL";
    gotoxy(35, 14);
    cout << "MANAGEMENT";
    gotoxy(35, 17);
    cout << "SYSTEM";
    cout << "\n\nMADE BY : AGHA TALHA ";
    cout << "\n\nROLL NO : 21I-2544";
}
//***************************************************************
// ADMINISTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
    string name, adminName;
    cout << "ADMIN PASS : ";
    cin >> name;

    //FILE HANDLING
    string filename("Admin.txt");

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
    }

    while (input_file >> adminName) {
        
    }
    cout << endl;
    input_file.close();

    //ADMINSHIP WILL BE TAKEN IF ADMIN NAME IS SAME OR NOT. THIS PART CAN BE ADMIN LOCKED BY MAKING A FILE. ASSIGNING AN ADMIN NAME
    //AND ENCRYPTING IT SO THAT NON OTHER CAN OPEN IT

    if (name == adminName)
    {
        int ch2;
        cout << "\n\n\n\tADMINISTRATOR MENU";
        cout << "\n\n\t1.CREATE PATIENT RECORD";
        cout << "\n\n\t2.DISPLAY ALL PATIENT RECORD";
        cout << "\n\n\t3.DISPLAY SPECIFIC PATIENT RECORD ";
        cout << "\n\n\t4.MODIFY PATIENT RECORD";
        cout << "\n\n\t5.DELETE PATIENT RECORD";
        cout << "\n\n\t6.CREATE DOCTOR ";
        cout << "\n\n\t7.DISPLAY ALL DOCTORS ";
        cout << "\n\n\t8.DISPLAY SPECIFIC DOCTOR ";
        cout << "\n\n\t9.MODIFY DOCTOR ";
        cout << "\n\n\t10.DELETE DOCTOR ";
        cout << "\n\n\t11.CREATE APPOINTMENT ";
        cout << "\n\n\t12.DISPLAY ALL APPOINTMENTs ";
        cout << "\n\n\t13.DISPLAY SPECIFIC APPOINTMENT ";
        cout << "\n\n\t14.MODIFY APPOINTMENT ";
        cout << "\n\n\t15.DELETE APPOINTMENT ";
        cout << "\n\n\t16.BACK TO MAIN MENU";
        cout << "\n\n\tPlease Enter Your Choice (1-16) ";
        cin >> ch2;
        switch (ch2)
        {
        case 1:
            write_patient(); break;
        case 2: display_alls(); break;
        case 3:
            char num[6];

            cout << "\n\n\tPlease Enter The Admit No. ";
            cin >> num;
            display_spp(num);
            break;
        case 4: modify_patient(); break;
        case 5: delete_patient(); break;
        case 6:
            write_doc(); break;
        case 7: display_allb(); break;
        case 8: {
            char num[6];

            cout << "\n\n\tPlease Enter The book No. ";
            cin >> num;
            display_spb(num);
            break;
        }
        case 9: modify_doc(); break;
        case 10: delete_doc(); break;
        case 11: write_app(); break;
        case 12: display_allapps(); break;
        case 13: 
            cout << "\n\n\tPlease Enter The Appointment No. ";
            cin >> num;
            display_spa(num); 
            break;
        case 14: modify_app(); break;
        case 15: break;
        case 16: return;
        default:cout << "\a";
        }
        admin_menu();
    }
    else
    {
        cout << "WRONG NAME OR PASSWORD!!" << endl;
    }
    
}
//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main()
{
    char ch;
    intro();
    do
    {

        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. DOCTOR ISSUE";
        cout << "\n\n\t02. DOCTOR DEPOSIT";
        cout << "\n\n\t03. USER REGISTER";
        cout << "\n\n\t04. USER LOGIN";
        cout << "\n\n\t05. DOCTOR REGISTER";
        cout << "\n\n\t06. DOCTOR LOGIN";
        cout << "\n\n\t07. ADMINISTRATOR MENU";
        cout << "\n\n\t";
        cout << "\n\n\tPlease Select Your Option (1-8) ";
        cout << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            book_issue();
            break;
        case '2':book_deposit();
            break;
        case '3':
            cout << "Registering" << endl;
            RegisterUser();
            break;
        case '4':
            cout << "Logging In" << endl;
            LoginUser();
            break;
        case '5':
            cout << "Registering" << endl;
            RegisterDoctor();
            break;
        case '6':
            cout << "Logging In" << endl;
            LoginDoctor();
            break;
        case '7':admin_menu();
            break;
        case '8':exit(0);
        default:cout << "\a";
        }
    } while (ch != '8');
    return 0;
}


void patient_options()
{
    char ch;
    do
    {

        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. BOOK APPOINTMENTS";
        cout << "\n\n\t02. START APPOINTMENTS";
        cout << "\n\n\t03. SHOW APPOINTMENTS";
        cout << "\n\n\t04. CANCEL APPOINTMENT";
        cout << "\n\n\t05. CHANGE ACCOUNT DETAILS";
        cout << "\n\n\t06. LOG OUT";
        cout << "\n\n\t07. DELETE ACCOUNT";
        cout << "\n\n\tPlease Select Your Option (1-6) ";
        cout << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            write_app();
            st.deductBalance(200);
            break;
        case '2':
            char t[50];
            cout << "Enter the time of your appointment." << endl;
            cin >> t;
            char num[6];
            cout << "\n\n\tPlease Enter The Appointment Number";
            cin >> num;
            cout << "APPOINTMENT STARTED WITH DR." << dc.retname() << endl<<endl;

            break;
        case '3':
            char fum[6];
            cout << "\n\n\tPlease Enter The Appointment Number You Want To Attend";
            cin >> fum;
            display_spa(fum);
            break;
        case '4':
            
            st.deductBalance(-200);
            break;
        case '5':
            modify_app();
            break;
        case '6':
            return;
        case '7':
            delete_patient();
            break;
        default:cout << "\a";
        }
    } while (ch != '6');
}


void doctor_options()
{
    char ch;
    do
    {

        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. SHOW APPOINTMENTS";
        cout << "\n\n\t02. END APPOINTMENT";
        cout << "\n\n\t03. DELETE APPOINTMENT";
        cout << "\n\n\t04. LOG OUT";
        cout << "\n\n\t05. DELETE ACCOUNT";
        cout << "\n\n\tPlease Select Your Option (1-5) ";
        cout << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            display_allapps();
            break;
        case '2':
            break;
        case '3':
            display_allapps();
            cout << "\nWhich appointment do you want to cancel" << endl;
            break;
        case '4':
            return;
            break;
        case '5':
            delete_doc();
            break;
        default:cout << "\a";
        }
    } while (ch != '5');
}

