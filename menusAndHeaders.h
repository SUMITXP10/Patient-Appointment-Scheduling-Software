#include<stdio.h>
#include <iostream>
#ifndef MENUSANDHEADERS_H
#define MENUSANDHEADERS_H
using namespace std;
void mainManu()
{
    cout << "\t\t*****************************************************************************************************************************************\n\n";
    cout << "\n\t\t\t\t\t\t\t\t***PATIENT APPOINTMENT SCHEDULING SYSTEM***\n\n\n\n";
    cout << "\t\t*****************************************************************************************************************************************\n\n";
    cout << "\n\t\t\t\t [ 1 ] PATIENT\n\t\t\t\t [ 2 ] DOCTOR\n\t\t\t\t [ 3 ] RECEPTIONIST\n\t\t\t\t [ 4 ] EXIT\n\n\n\n";
    cout << "\t\t*****************************************************************************************************************************************\n\n";
    cout << " Enter your choice : ";
}
void patientMenu()
{
    cout << "\t\t*****************************************************************************************************************************************\n\n";

    cout << "\n\t\t\t\t[ 1 ] MAKE AN APPOINTMENT\n";    //done
    cout << "\t\t\t\t[ 2 ] DISPLAY DOCTORS SCHEDULE\n";  //done
    cout << "\t\t\t\t[ 3 ] SEARCH DOCTOR NAME\n";      //done
    cout << "\t\t\t\t[ 4 ] SERACH AVAILABLE DOCTORS\n"; //done
    cout << "\t\t\t\t[ 8 ] RETURN TO USER INTERFACE\n"; // done
    cout << "\t\t\t\t[ 9 ] EXIT\n\n";                   //done
    cout << "\t\t*****************************************************************************************************************************************\n\n";

    cout << "What would you like to do? : ";
}
void doctorMenu()
{
    cout << "\t\t*****************************************************************************************************************************************\n\n";

    cout << "\n\t\t\t\t[ 1 ] DISPLAY ALL PATIENT APPOINTMENTS\n"; //done
    cout << "\t\t\t\t[ 2 ] SEARCH PATIENT NAME\n";                // done
    cout << "\t\t\t\t[ 3 ] SEARCH PATIENT BY ID\n";               // done
    cout << "\t\t\t\t[ 4 ] UPDATE SCHEDULE\n";                    //done
    cout << "\t\t\t\t[ 8 ] RETURN TO USER INTERFACE\n";           // done
    cout << "\t\t\t\t[ 9 ] EXIT\n\n";                             //done
    cout << "\t\t*****************************************************************************************************************************************\n\n";

    cout << "What would you like to do? : ";
}
void recMenu()
{
    cout << "\t\t*****************************************************************************************************************************************\n\n";

    cout << "\n\t\t\t\t[ 1 ] DISPLAY ALL PATIENT'S LIST\n"; //done
    cout << "\t\t\t\t[ 2 ] DISPLAY ALL DOCTOR'S LIST\n";       //done
    cout << "\t\t\t\t[ 3 ] SEARCH DOCTOR'S NAME\n";        //done
    cout << "\t\t\t\t[ 4 ] SERACH AVAILABLE DOCTORS\n";   //done
    cout << "\t\t\t\t[ 5 ] SORT ALL PATIENT'S LIST BY FIRST NAME\n";
    cout << "\t\t\t\t[ 6 ] UPDATE PATIENT'S PHONE NUMBER\n"; //done
    cout << "\t\t\t\t[ 7 ] DELETE PATIENT'S RECORD\n";        //done
    cout << "\t\t\t\t[ 8 ] RETURN TO USER INTERFACE\n";     // done
    cout << "\t\t\t\t[ 9 ] EXIT\n\n";                       // done
    cout << "\t\t*****************************************************************************************************************************************\n\n";

    cout << "What would you like to do? : ";
}
void doctorTableHeaders()
{
    cout << "\nThese are the avilable date and dcotors\n\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";

    cout << "\nDOCTOR NAME\t\t  SCHEDULE ID\t\t\t DAY\t\tSTART TIME\tEND TIME\tSTATUS\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void doctorInfoTableHeaders()
{
    cout << " DOCTOR'S ID"
         << "\t"
         << "DOCTOR'S NAME"
         << "\t\t"
         << "GENDER"
         << "\t\t"
         << "DAY OF BIRTH"
         << "\t\t"
         << "PHONE NO."
         << "\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void patientBookingTableHeaders()
{
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "PATIENT'S ID\t"
         << "PATIENT'S NAME\t"
         << "DOCTOR'S NAME\t"
         << "APPOINTMENT DAY\t"
         << "APPOINTMENT TIME\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void patientInfoTableHeaders()
{
    // patientInfoTableHeaders();
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "PATIENT'S ID"
         << "\t"
         << "PATIENT'S NAME"
         << "\t\t"
         << "GENDER"
         << "\t\t"
         << "DAY OF BIRTH"
         << "\t\t"
         << "PHONE NO."
         << "\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
}
#endif
