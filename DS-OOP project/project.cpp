/*
FILE        : project.cpp
PROJECT     : DS-OOP Project
BY          : Sameer sapra & Sekou Diaby
DATE        : 18-04-2014
DESCRIPTION : This main test harness creates object for UI and College class. College class main UI which shows user to select 
			  his option , what to do.
*/
#include"UI.h"


int main()
{

	//Instantiating an object for UI class.
	UI myUI ;

	//Instantiating an object for College class.
	college mycollege ;


	myUI.main_menu() ;
	return 0 ;
}
