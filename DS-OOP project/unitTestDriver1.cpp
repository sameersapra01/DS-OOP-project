/*
FILE        : unitTestDriver1.cpp
PROJECT     : DS-OOP Project
BY          : Sameer sapra & Sekou Diaby
DATE        : 18-04-2014
DESCRIPTION : This unit test is used to test 3 dfifferent functions as normal , boundary and exceptions test. All the tests displays
			  the expected and actual result from the function.
*/



#include"UI.h"

int main()
{

	//Create an object for UI
	UI myUI ;

	//Creates an object for College.
	college mycollege ;
	bool check = 0 ;
	int i = 0 ;

	//Normal Test for first and middle name.	
	for ( i = 0 ; i < 3 ; i++ )
	{
		char first_name[3][20] = {"sameer sapra" , "sekou" , "testing project" } ;
		check = myUI.validate_first_name( first_name[i] , false) ;

		cout << " Test #" << i+1 << " : Normal Test of first and middle name" << endl << endl;
		cout << "   -> Submitting ( " << first_name[i] << " ) as the student first and middle name" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << first_name[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << first_name[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl << endl ;
			cout << "\t--------------------------" << endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << first_name[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << first_name[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl << endl ;
			cout << "\t--------------------------" << endl ;
		}
	}

	
	//Exception test for first and middle name.
	for( i = 0 ; i < 3 ; i++ )
	{
		char first_name[3][20] = {"123sekou" , "sameer123" , "#1 testing project" } ;
		check = myUI.validate_first_name( first_name[i] , false ) ;

		cout << " Test #" << i+1 << " : Exception Test of first and middle name" << endl << endl;
		cout << "   -> Submitting ( " << first_name[i] << " ) as the student first and middle name" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << first_name[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << first_name[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl << endl ;
			cout << "\t--------------------------" << endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << first_name[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << first_name[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl << endl ;
			cout << "\t--------------------------" << endl ;
		}
	}
	
	//Boundary test for first and middle name.
	for( i = 0 ; i < 2 ; i++ )
	{
		char first_name[2][kMAXCHAR] = {"" , "qwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgkmsmsm"} ;

		
		check = myUI.validate_first_name( first_name[i] , false ) ;

		cout << " Test #" << i+1 << " : Normal Test of first and middle name" << endl << endl;
		cout << "   -> Submitting ( " << first_name[i] << " ) as the student first and middle name" << endl << endl ;
		if( check )
		{
			cout << "\t>> Expected Result : ( " << first_name[i] << " )is valid" << endl ;
			cout << "\t>> Actual Result :   ( " << first_name[i] << " )is valid" << endl ;
			cout << " ** TEST PASSED **" << endl << endl ;
			cout << "\t--------------------------" << endl ;
		}
		else
		{
			cout << "\t>> Expected Result : ( " << first_name[i] << " )is invalid" << endl ;
			cout << "\t>> Actual Result : ( " << first_name[i] << " )is invalid" << endl << endl ;
			cout  << " ** TEST FAILED ** " << endl << endl ;
			cout << "\t--------------------------" << endl ;
		}
	}
	

	////Normal test for last name.
	//for( i = 0 ; i < 3 ; i++ )
	//{
	//	char first_name[3][20] = {"sapra", "diaby" , "lastname" } ;
	//	check = myUI.validate_last_name( first_name[i] ) ;
	//	if( check )
	//	{
	//		cout << "CORRRECT" << endl ;
	//		// EXPECTED RESULT.
	//		// RESULT GOT.
	//	} 
	//	else
	//	{
	//		cout << "incorrect" << endl ;
	//	}
	//}


	////Exception test for last name.
	//for( i = 0 ; i < 3 ; i++ )
	//{
	//	char last_name[3][20] = {" " , "sekou123" , "#1 testing project" } ;
	//	check = myUI.validate_last_name( last_name[i] ) ;
	//	if( check )
	//	{
	//		cout << "CORRRECT" << endl ;
	//		// EXPECTED RESULT.
	//		// RESULT GOT.
	//	} 
	//	else
	//	{
	//		cout << "incorrect" << endl ;
	//	}
	//}


	////NORMAL TEST FOR AGE
	//for( i = 0 ; i < 3 ; i++ )
	//{
	//	char age[3][20] = {"20" , "34" , "42" } ;
	//	check = myUI.validate_age( age[i] ) ;
	//	if( check )
	//	{
	//		cout << "CORRRECT" << endl ;
	//		// EXPECTED RESULT.
	//		// RESULT GOT.
	//	} 
	//	else
	//	{
	//		cout << "incorrect" << endl ;
	//	}
	//}

	////EXCEPTION TEST FOR AGE
	//for( i = 0 ; i < 3 ; i++ )
	//{
	//	char age[3][20] = {"-20" , "0" , "200" } ;
	//	check = myUI.validate_age( age[i] ) ;
	//	if( check )
	//	{
	//		cout << "CORRRECT" << endl ;
	//		// EXPECTED RESULT.
	//		// RESULT GOT.
	//	} 
	//	else
	//	{
	//		cout << "incorrect" << endl ;
	//	}
	//}
	return 0 ;
}