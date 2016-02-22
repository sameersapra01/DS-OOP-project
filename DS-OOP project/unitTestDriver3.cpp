/*
FILE        : unitTestDriver3.cpp
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

	//Creates an object for College class.
	college mycollege ;
	student std1 ;
	bool check = 0 ;
	int i = 0 ;

	//Normal Test for age.
	for( i = 0 ; i < 3 ; i++ )
	{
		char age[3][10] = { "19" , "22" , "33" } ;

		check = myUI.validate_age( age[i] , false ) ;

		cout << " Test #" << i+1 << " : Normal Test of age" << endl << endl;
		cout << "   -> Submitting ( " << age[i] << " ) as the age" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << age[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << age[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl ;
			cout << "\t-------------------------" << endl << endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << age[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << age[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl ;
			cout << "\t-------------------------" << endl << endl ;
		}
	}

	//Exception test for age.
	for( i = 0 ; i < 3 ; i++ )
	{
		char age[3][10] = {"ssc56" , "0.2" , "-22" } ;
		check = myUI.validate_age( age[i] , false ) ;

		cout << " Test #" << i+1 << " : Exception Test of student age" << endl << endl;
		cout << "   -> Submitting ( " << age[i] << " ) as the student age" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << age[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << age[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl ;
			cout << "\t-------------------------" << endl << endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << age[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << age[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl ;
			cout << "\t-------------------------" << endl << endl ;
		}
	}

	//Boundary test for age.
	for( i = 0 ; i < 2 ; i++ )
	{
		char age[3][10] = {"0" , "100" } ;
		check = myUI.validate_age( age[i] , false) ;

		cout << " Test #" << i+1 << " : Boundary Test of student age" << endl << endl;
		cout << "   -> Submitting ( " << age[i] << " ) as the student age" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << age[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << age[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl ;
			cout << "\t-------------------------" << endl << endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << age[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << age[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl ;
			cout << "\t-------------------------" << endl << endl ;
		}
	}
	return  0 ;
}