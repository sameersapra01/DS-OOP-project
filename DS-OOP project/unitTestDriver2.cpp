/*
FILE        : unitTestDriver2.cpp
PROJECT     : DS-OOP Project
BY          : Sameer sapra & Sekou Diaby
DATE        : 18-04-2014
DESCRIPTION : This unit test is used to test 3 dfifferent functions as normal , boundary and exceptions test. All the tests displays
			  the expected and actual result from the function.
*/


#include"UI.h"

int main()
{
	//Creates an object for UI.
	UI myUI ;

	//Create an ibject for College.
	college mycollege ;

	bool check = 0 ;
	int i = 0 ;

	//Normal Test
	for( i = 0 ; i < 3 ; i++ )
	{
		char student_number[3][10] = {"1896" , "2222" , "45689" } ;

		check = myUI.validate_student_number( student_number[i] , false ) ;

		cout << " Test #" << i+1 << " : Normal Test of student number" << endl << endl;
		cout << "   -> Submitting ( " << student_number[i] << " ) as the student number" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << student_number[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << student_number[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl  ;
			cout << "\t----------------------"<< endl <<endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << student_number[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << student_number[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl << endl ;
			cout << "\t----------------------"<< endl <<endl ;
		}
	}

	//Exception test.
	for( i = 0 ; i < 3 ; i++ )
	{
		char student_number[3][10] = {"ssc56" , "0.2" , "-2262" } ;
		check = myUI.validate_student_number( student_number[i] , false ) ;

		cout << " Test #" << i+1 << " : Exception Test of student number" << endl << endl;
		cout << "   -> Submitting ( " << student_number[i] << " ) as the student number" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << student_number[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << student_number[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl << endl ;
			cout << "\t----------------------"<< endl <<endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << student_number[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << student_number[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl << endl ;
			cout << "\t----------------------"<< endl <<endl ;
		}
	}

	//Boundary test.
	for( i = 0 ; i < 2 ; i++ )
	{
		char student_number[3][10] = {"0" , "1111111" } ;
		check = myUI.validate_student_number( student_number[i] , false ) ;

		cout << " Test #" << i+1 << " : Boundary Test of student number" << endl << endl;
		cout << "   -> Submitting ( " << student_number[i] << " ) as the student number" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << student_number[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << student_number[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl << endl ;
			cout << "\t----------------------"<< endl <<endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << student_number[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << student_number[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl << endl ;
			cout << "\t----------------------"<< endl <<endl ;
		}
	}
	return  0 ;
}