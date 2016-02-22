///FileName:	student.h

///Project:		DS-OOP Project

///Author:		Sekou Diaby, Sameer Sapra	

///Date:		April 18, 2014

///Description:	This program is a menu based system which adds students to a college database.

///				This program more specifically keeps tracks of students in an engineering program.
				
///				The student's attributes are entered by the receptionist at the college's reception

///				through menu options. The purpose of this class is to create a student object that 

///				has multiple attributes such as age, gender, name etc. The class will allow the 

///				students to have a unique student number that will differentitate one from another. 

///				The class will allow the student to set his or her name, gender, email, program information
				
///				and will allow the user to retrieve it when it is needed.

///	

/* -- FILEHEADER COMMENTS -- 

	NAME	:	student.h

	PURPOSE :	This class is used to handle the instantiation or creation of a student object with specific attributes.

*/


/// included files
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <map>
#include <regex>
#include <sstream>
#include <conio.h>
#include <vector>
#include <new.h>
#include <fstream>
#include <iostream>
using namespace std ;
#define kMaxSize 255

///disables warnings

#pragma warning(disable: 4996)///<#pragma warning used for depricated functions


/// 

/// \class student

///

/// \brief The purpose of this class is to handle the creation of a student object.

/// This comment block is <i>required</i> for all class declarations.  This is the place 

/// where the <b>Class header Comment</b> appears. 

///

/// \author A <i>Sekou Diaby, Sameer Sapra</i>

///

class student
{
private:
	char first_name[kMaxSize] ;					///<used to hold the first name of the student
	char last_name[kMaxSize] ;					///<used to hold the last name of the student
	char gender[kMaxSize] ;						///<used to hold the gender of the student
	char email[kMaxSize] ;						///<used to hold the email of the student
	char program_name[kMaxSize] ;				///<used to hold the name of the program that the student is enrolled in.
	char program_type[kMaxSize] ;				///<used to see if the student is enrolled Full time or Part time

	int  student_number ;						///<used to hold the uniquely identifying number of the student
	int  age ;									///<used to hold the age of the student
	bool displayOutput;							///<used to check if user wants to display output on the screen.
	
public:

	/* -------------- METHODS --------------- */
	///
	/// \brief Called to instantiate an object of the student class or create a student.
	/// \details <b>Details</b>
	///
	/// This method will create a student object with specific attributes and unique student 
	/// number. The method will instantiate all the attributes to a null value so that 
	/// the student will be able to insert their own information.
	///
	/// \return Returns nothing since this is a constructor.
	///
	/// 
	student::student(void)
	{
		/// initializing the data attributes of the student object.
		for ( int i = 0; i < kMaxSize; i ++)
		{
			first_name[i] = '\0';
			last_name[i] = '\0';
			gender[i] = '\0';
			email[i] = '\0';
			program_name [i] = '\0';
			if ( i < 10)
			{
				program_type[i] = '\0';
			}
			student_number = 0 ;
			age = 0;
			displayOutput = true;
		}
	}

	///
	/// \brief Called to destruct an object of the student class.
	/// \details <b>Details</b>
	///
	/// This method will destruct a created student object with specific attributes and unique student 
	/// number. The method will free any memory that is used by the object. 
	///
	/// \return Returns nothing since this is a destructor.
	///
	/// 
	student::~student()
	{
	}

	///
	/// \brief Called to set the first name of the student.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter the character array that will be 
	/// set as the student's first name. The method will just set the private data member 
	/// of the student first name in the class with the first name provided as a parameter.
	///
	/// \return Returns nothing.
	/// 
	void set_fname(char fname[])
	{
		strcpy( first_name , fname ) ;
	}

	///
	/// \brief Called to set the last name of the student.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter the character array that will be 
	/// set as the student's last name. The method will just set the private data member last name 
	/// of the student in the class with the last name provided as a parameter.
	///
	/// \return Returns nothing.
	///
	void set_lname( char lname[] )
	{
		strcpy ( last_name , lname ) ;
	}

	///
	/// \brief Called to set the age of the student.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter an int that will be 
	/// set as the student's age. The method will just set the private data member age, 
	/// of the student in the class with the age provided as a parameter.
	///
	/// \return Returns nothing.
	///
	void set_age( int a )
	{
		age = a ;
	}

	///
	/// \brief Called to set the gender of the student.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter a character of arrays that will be 
	/// set as the student's gender. The gender can only be set to be either a male or female.
	///	The method will just set the private data member gender, 
	/// of the student in the class with the gender provided as a parameter.
	///
	/// \return Returns nothing.
	///
	void set_gender( char gen[] )
	{
		strcpy( gender , gen ) ;
	}

	///
	/// \brief Called to set the unique number of the student.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter an int that will be 
	/// set as the student's number. 
	///	The method will just set the private data member student number, 
	/// of the student in the class with the number provided as a parameter.
	///
	/// \return Returns nothing.
	///
	void set_studentnumber( int std_number )
	{
		student_number = std_number ;
	}

	///
	/// \brief Called to set the contact email of the student.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter the character array that will be 
	/// set as the student's email. The method will just set the private data member email
	/// of the student in the class with the string provided as a parameter.
	///
	/// \return Returns nothing.
	///
	void set_email( char e_mail[] )
	{
		strcpy ( email , e_mail ) ;
	}

	///
	/// \brief Called to set the name of the program that the student is enrolled in.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter the character array that will be 
	/// set as the student's program name. The method will just set the private data member program name, 
	/// of the student in the class with the string provided as a parameter.
	///
	/// \return Returns nothing.
	///	
	void set_program_name( char prog_name[])
	{
		strcpy( program_name , prog_name ) ;
	}
	
	///
	/// \brief Called to set the type of the program that the student is enrolled in, which is Full or Part time.
	/// \details <b>Details</b>
	///
	/// This method will bring in as a parameter the character array that will be 
	/// set as the student's program type. The method will just set the private data member program type, 
	/// of the student in the class with the string provided as a parameter.
	///
	/// \return Returns nothing.
	///	
	void set_program_type( char prog_type[] )
	{
		strcpy( program_type , prog_type ) ;
	}

	///
	/// \brief Called to get the first name of the student.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's first name. 
	/// The method will just get the private data member, first name of the student in the class.
	///
	/// \return Returns the first name of the student.
	/// 
	char* get_fname( void )
	{
		return first_name ;
	}

	///
	/// \brief Called to get the last name of the student.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's last name. 
	/// The method will just get the private data member last name, of the student in the class.
	///
	/// \return Returns the last name of the student.
	/// 
	char* get_lname()
	{
		return last_name ;
	}

	///
	/// \brief Called to get the age of the student.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's age. 
	/// The method will just get the private data member age, of the student in the class.
	///
	/// \return Returns the age of the student.
	/// 
	int get_age()
	{
		return age ;
	}

	///
	/// \brief Called to get the unique number of the student.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's number. 
	/// The method will just get/access the private data member student number, of the student in the class.
	///
	/// \return Returns the unique number of the student.
	///
	int get_student_number()
	{
		return student_number ;
	}

	///
	/// \brief Called to get the gender of the student.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's gender. 
	/// The method will just get the private data member gender, of the student in the class.
	///
	/// \return Returns the gender of the student.
	///
	char* get_gender()
	{
		return gender ;
	}

	///
	/// \brief Called to get the name of the student program.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's program name. 
	/// The method will just get the private data member program_name, of the student in the class.
	///
	/// \return Returns the name of the progrma of the student.
	///
	char* get_program_name()
	{
		return program_name ;
	}

	///
	/// \brief Called to get the typr of program that the student is enrolled in.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's program type. 
	/// The method will just get the private data member program_type, of the student in the class.
	///
	/// \return Returns the type of program of the student.
	///
	char* get_program_type()
	{
		return program_type ;
	}

	///
	/// \brief Called to get the email of the student.
	/// \details <b>Details</b>
	///
	/// This method will return the private member attribute that is student's email. 
	/// The method will just get the private data member email, of the student in the class.
	///
	/// \return Returns the email of the student.
	///
	char* get_email()
	{
		return email ;
	}

} ;


