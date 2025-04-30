#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include"windows.h"
#include"person.h"
#include"schedule.h"
#include"doctor.h"
#include"patient.h"
#include"appointment.h"
#include"receptionist.h"
#include"menusAndHeaders.h"
using namespace std ;
int main( )
{
int choice , user , i = 6 , isPatient = 1 , isDoctor = 2 , isReceptionist = 3 ;
string id , firstName , lastName , gender , dateOfBirth , phoneNumber , day , startTime , endTime , status ;
List schudele ;
Patient p ;
PatientList patient ;
DoctorList doctor ;
fstream file , file2 , file3 ;
AppointmentList *appointment = new AppointmentList( ) ;
file.open( "patient.txt" ) ;
file2.open( "doctor_list.txt" ) ;
file3.open( "doctor_schedule.txt" ) ;
while ( getline( file , id , '\n' ) )                                                                                                         // Reading Patient Data From File
{
file >> id >> firstName >> lastName >> gender >> dateOfBirth >> phoneNumber ;
patient.InsertNode( id , firstName , lastName , gender , dateOfBirth , phoneNumber ) ;
}
while ( getline( file3 , id , '\n' ) )
{
file3 >> id >> day >> startTime >> endTime >> status ;
schudele.InsertNode( id , day , startTime , endTime , status ) ;
}
while ( getline( file2 , id , '\n' ) )                                                                                                        // Reading Doctor Data From File
{
file2 >> id >> firstName >> lastName >> gender >> dateOfBirth >> phoneNumber ;
doctor.InsertNode( schudele , i , id , firstName , lastName , gender , dateOfBirth , phoneNumber ) ;
}
do
{
mainManu( ) ;
cin >> user ;
do
{
if( user == isPatient )
{
patientMenu( ) ;
cin >> choice ;
}
else if( user == isDoctor )
{
doctorMenu( ) ; 
cin >> choice ;
}
else if( user == isReceptionist )
{
recMenu( ) ;
cin >> choice ;
}
else if( user == 4 )
{
Sleep( 1000 ) ;
cout << "\n\t\t\tTHANK YOU FOR USING THIS PROGRAM !!!\n\n" ;
Sleep( 2000 ) ;
return 0 ;
}
else
cout << "\nSORRY , THIS OPTION IS NOT AVILABLE .\n" ;
switch( choice )                                                                                                                              // cout << "12 ) Exit\n\n" ;
{
case 1 :                                                                                                                                      //New Record
        int index ;
        Schedule *s ;
		if ( user == isPatient )
        {
        doctorTableHeaders( ) ; 
        doctor.displaySchedul( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        cout << "\nPlease write the appointment id : " ;
        cin >> id ;
        Doctor *d = doctor.findNode( id , index ) ;
        if( d != NULL )
        {
        s = d -> schedule[ index ] ;
        p.setPatientInfo( ) ;
        patient.InsertNode( p.getId( ) , p.getFirstName( ) , p.getLastName( ) , p.getGender( ) , p.getDateOfBirth( ) , p.getPhoneNumber( ) ) ;
        appointment -> InsertNode( &p , d , s ) ;
        cout << "\n" ;
        Sleep( 500 ) ;                                                                                                                        // Sleep( 2000 ) ;                         
        cout << "\nBOOKED SUCCESSFULLY\n" ;
        cout << "\nYOUR BOOKING INFORMATION\n\n\n" ;
        patientBookingTableHeaders( ) ;                                                                                                       // sleep( 1000 ) ;
        appointment -> displayAppointments( ) ;
        Sleep( 2000 ) ;
        }
        else
        cout << "\nSORRY , THE APPOINTMENT YOU CHOOSE IS BOOKED OR NOT AVALIABLE" << endl ;
        break ;
        }                                                                                                                                     //}
		else if( user == isDoctor )
        {
        patientBookingTableHeaders( ) ;
        if( appointment != NULL )
        {
        appointment -> displayAppointments( ) ;
        }
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        if( user == isReceptionist )                                                                                                          // Add else
        {
        patient.displayList( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        break ;
case 2 :                                                                                                                                      //Display All Records
        int pos ;
		if( user == isPatient )
        {
        Sleep( 500 ) ;
        doctorTableHeaders( ) ;
        doctor.displaySchedul( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        if( user == isDoctor )
        {
        cout << "\n\n" << "Enter Patient First Name : " ;
        cin >> firstName ;
        cout << "\n\n" ;
        Sleep( 500 ) ;
        patientInfoTableHeaders( ) ;
        patient.searchPatientInfoByName( firstName ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        if( user == isReceptionist )
        {
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        doctorInfoTableHeaders( ) ;
        doctor.displayList( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        break ;
case 3 :
        int pos1 ;
        int pos2 ;
		if( user == isPatient )
        {
        cout << "\n" << "Please enter the doctor first name : " ;
        cin >> firstName ;
        Sleep( 500 ) ;
        doctorTableHeaders( ) ;
        doctor.findByFirstName( firstName ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        if( user == isDoctor )
        {
        cout << "\n\n" << "Enter Patient ID : " ;
        cin >> id ;
        Sleep( 500 ) ; 
        patientInfoTableHeaders( ) ;
        patient.searchPatientInfoById( id ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        if( user == isReceptionist )
        {
        cout << "\nPlesae enter the doctor first name : " ;
        cin >> firstName ;
        Sleep( 500 ) ;
        doctorTableHeaders( ) ;
        doctor.searchDoctorInfoByName( firstName ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        break ;
case 4 :
        if( ( user == isPatient ) || ( user == isReceptionist ) )
        {
        Sleep( 500 ) ;
        doctorTableHeaders( ) ;
        doctor.findAvialableDoctor( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        if( user == isDoctor )
        {
        Sleep( 500 ) ;
        cout << "\nFILL IN YOUR SCHDEULE INFORMATION\n" ;
        cout << "\nEnter your first name : " ;
        cin >> firstName ;
        Doctor *d = doctor.getDoctor( firstName ) ;
        Schedule s ;
        if( d )
        {
        s.getdata( ) ;
        doctor.getDoctor( firstName ) -> updateSchduel( &s ) ;
        doctorTableHeaders( ) ;
        doctor.findByFirstName( firstName ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        }
        Sleep( 2000 ) ;
        }
        break ;
case 5 :
        if( user == isReceptionist )
        {
        cout << "\n//////////////////////// BEFORE SORTING//////////////////////////\n" ;
        cout << "\nThe Patient list Before Sorting in Asending order\n\n" ;
        Sleep( 500 ) ;
        patientInfoTableHeaders( ) ;
        patient.displayList( ) ;
        Sleep( 3000 ) ;
        patient.insertionSort( ) ;
        cout << "\n//////////////////////// AFTER SORTING//////////////////////////\n" ;
        cout << "\nThe Patient list After Sorting in Asending order\n\n";
        Sleep( 500 ) ;
        patientInfoTableHeaders( ) ;
        patient.displayList( ) ;
        Sleep( 3000 );
        }
        break ;
case 6 :
        if( user == isReceptionist )
        {
        Sleep( 500 ) ;
        patientInfoTableHeaders( ) ;
        patient.displayList( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        cout << "\nPlease enter the patiten Id : " ;
        cin >> id ;
        cout << "\nPlease enter the new phone number : " ;
        cin >> phoneNumber ;
        patient.findNode( id , phoneNumber ) ;
        Sleep( 500 ) ;
        patientInfoTableHeaders( ) ;
        patient.displayList( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        break ;
case 7 :
        if( user == isReceptionist )
        {
        Sleep( 500 ) ;
        patientInfoTableHeaders( ) ;
        patient.displayList( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        cout << "\nPlease enter the patiten Id : " ;
        cin >> id ;
        patient.deleteNode( id ) ;
        patientInfoTableHeaders( ) ;
        patient.displayList( ) ;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n" ;
        Sleep( 2000 ) ;
        }
        break ;
case 8 :
        cout << "\nRETURNING TO THE MAIN INTERFACE\n" ;
        Sleep( 1000 ) ;
        break ;
case 9 :                                                                                                                                      //exit
        system( "cls" ) ;
        cout << "\n\t\t\tTHANK YOU FOR USING THIS PROGRAM !!!\n\n" ;
        Sleep( 2000 ) ;
        return 0 ;
        break ;
        }
        } while ( choice != 8 ) ;
        } while ( choice != 9 ) ;
}
