///FileName:	college.h

///Project:		DS-OOP Project

///Author:		Sekou Diaby, Sameer Sapra	

///Date:		April 18, 2014

///Description:	This program is a menu based system which adds students to a college database.

///				This program more specifically keeps tracks of students in an engineering program.

///				This class contains all the methods that the user interface will call. This class 

///				will handle all actions with the database such as adding, deleting and searching for a 

///				student. It will also handle all actions that involve displaying and deleting the database.

///						

///	

/* -- FILEHEADER COMMENTS -- 

	NAME	:	college.h

	PURPOSE :	This class is used to handle all actions involved with the college such as adding and deleting students.

*/

/// include files 
#include"student.h"

#define kMAXROWS		55
#define kMAXCOLUMNS		100
#define kMAXCHAR		256

class college
{
private:
	map<int , student> info ;					///<used to store all the new students in the database.
	bool displayOutput;							///<used to check if user wants to display output on the screen.
public:

	/* -------------- METHODS --------------- */
	///
	/// \brief Called to instantiate an object of the college class.
	/// \details <b>Details</b>
	///
	/// This method will create a college object which will be used to access all the class functions. 
	/// The method will instantiate all if any attributes of the class to a null value. 
	///
	/// \return Returns nothing since this is a constructor.
	///
	/// 
	college()
	{
		displayOutput = true;
	}

	///
	/// \brief Called to destruct an object of the college class.
	/// \details <b>Details</b>
	///
	/// This method will destruct a college object which is used to access all the class functions. 
	/// \return Returns nothing since this is a destructor.
	///
	///
	~college()
	{
	}


	///
	/// \brief Called to add a new student into the database by setting attributes of a student object.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a the user choose to add a new student. It will 
	/// initialize of the data members of the student that is going to be added.
	/// this function is called after input validation is done.
	/// The method is brings all the attributes of the student object and calls
	///	setters to set those attributes for the student object.
	///
	/// \return Returns nothing.
	///
	void addstudent( char first_name[],char last_name[],int age_int,char gender[]			
					, int std_number,char email[] , char program_name[],char program_type[] )
	{
		
		// Creates an object for student.
		student std1;

		ClearScreen() ;
		

		// Set all the arguments to the student data members.
		std1.set_fname( first_name ) ;
		std1.set_lname( last_name ) ;
		std1.set_age( age_int ) ;
		std1.set_gender( gender ) ;
		std1.set_studentnumber( std_number ) ;
		std1.set_email( email ) ;
		std1.set_program_type( program_type ) ;
		std1.set_program_name( program_name ) ;

		// Insert the student number as a key and object in second.
		info.insert(make_pair( std_number , std1 ) ) ;
		cout << "\n\tStudent's Information is Added In The Database." << endl ;

		// Show the above message for a second.
	}


	
	///
	/// \brief Called to clear the screen.
	/// \details <b>Details</b>
	///
	///	This method clear an ammount of rows and columns.
	///
	/// \return Returns nothing.
	///
	void college::ClearScreen()
	{
		SetPos(0,0) ;

		for( int i = 1 ; i <= kMAXROWS ; i++ )
		{
			for( int j = 1 ; j < kMAXCOLUMNS ;j++ )
			{
				printf(" " ) ;
			}
			printf("\n") ;
		}
		SetPos(0,0) ;
	}

	///
	/// \brief Called to set the position of the cursor after the screen is cleared..
	/// \details <b>Details</b>
	///
	///	This method sets the cursor back to a specific position.
	/// This position is received as parameters x, y.
	/// \return Returns nothing.
	///
	void college::SetPos( int x, int y )
	{
		static HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE) ;

		COORD pos = {y,x} ;
		SetConsoleCursorPosition(hout,pos ) ;  //	Sets the Coordinate position.
	}

	///
	/// \brief Called to search a student in the database.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a the user choose to search a student. It recieves 
	/// a database as an input parameter that will be searched. The search is done 
	/// by the student's number. Once the search is completed, the information is displayed.
	///
	/// \return Returns nothing.
	///
	void college::searchstudent(map<int , student > *v)
	{
		// local data memebers.
		char std_number[10] = "" ;
		int stud_number     = 0 ;
	
		// iterator is at begin of map.
		map<int,student>::iterator i = v->begin() ;

		// if size of map is 0.
		if( (v->size()) == 0 )
		{
			cout << "( ERROR - Database Is Empty Right Now... )" << endl ;
		}
		else
		{
			printf( "Enter student number to display student's information : ") ;
			
			fgets( std_number , 9 , stdin ) ;		// User enter the student number to search for.
			stud_number = atoi( std_number ) ;		// Convert it into integer.
			i = v->find( stud_number ) ;			// Find the student number in the map.
			
			// Find till end of map.
			if( i != v->end() )
			{
				ClearScreen() ;
				cout << "Student Information is : " << endl ; 
				cout << "\t\tStudent Number : "	    << (i->first) << endl ;
				cout << "\t\tFirst name is : "    << (i->second).get_fname() << endl ;
				cout << "\t\tLast name is : "     << (i->second).get_lname() << endl ;
				cout << "\t\tAge is : "           << (i->second).get_age() << endl ;
				cout << "\t\tGender is : "        << (i->second).get_gender() << endl ;
				cout << "\t\tProgram name : "     << (i->second).get_program_name() << endl ;
				cout << "\t\tProgram Type is : "  << (i->second).get_program_type() << endl ;
				cout << "\t\tEmail Address : "    << (i->second).get_email() << endl ;
				cout << "\t-------------------------"<< endl << endl ;
			}

			// If there is no user input's student number in map.
			if( i == v->end())
			{
				printf("( ERROR - Not Found In Database... )\n") ;
			}
		}
			
		printf("Press Any Key To Continue.\n") ;
		while(1)
		{
			getch() ;
			break ;
		}
	}

	
	///
	/// \brief Called to delete a student in the database.
	/// \details <b>Details</b>
	///
	///	This method is called whenever the user choose to delete a student. It receives 
	/// a database as an input parameter that will be searched. The search is done 
	/// by the student's number. Once the search is completed, the student's data is deleted.
	///
	/// \return Returns nothing.
	///
	void college::delete_student(map<int , student> *v2) 
	{
		//Local data members.

		char std_number[10] = "" ;
		int stud_number     = 0 ;
		int out = 0 ;
		
		printf( "Enter student number to delete student's information\n") ;
		fgets( std_number , 9 , stdin ) ;					// Enter a student number to delete student.
		
		stud_number = atoi( std_number ) ;
		map<int, student>::iterator it = v2->begin() ;

		it = v2->find( stud_number ) ;		// find the student number in the map.

		// if there is no such student number in map.
		if( it == v2->end() )
		{
			printf("( ERROR - The Mentioned Student Number Does not Exist... )\n\n") ;
			printf("Press Any Key To Continue.\n") ;
			while(1)
			{
				getch() ;
				break ;
			}
		}
		else
		{
			// Erase the student form map.
			v2->erase( it ) ;
			printf("Student Deleted From The Database\n" ) ;
			printf("Press Any key to continue\n") ;
			while( 1 )
			{
				getch() ;
				break ;
			}
		}
	}

	
	///
	/// \brief Called to delete an entire database.
	/// \details <b>Details</b>
	///
	///	This method is called whenever the user choose to delete an entire database. It receives 
	/// a database as an input parameter that will be deleted. 
	///
	/// \return Returns nothing.
	///
	void college::delete_entire_database( map<int,student> *v4)
	{
		//Delete the entire map.
		v4->clear() ;
		printf("\n\tEntire Database is deleted.\n") ;
		while( 1 )
		{
			printf("Press Any Key To Continue.\n") ;
			getch() ;
			break ;
		}
	}

	
	///
	/// \brief Called to display all items in the database.
	/// \details <b>Details</b>
	///
	///	This method is called whenever the user choose to display a databese. It receives 
	/// a database as an input parameter that will be displayed. Once received, the databased
	/// is traversed and all items are displayed one by one.
	///
	/// \return Returns nothing.
	///
	void college::display_entire_database( map< int , student > *v1)
	{
		// Check if the size is not 0.
		if( ( v1->size() ) == 0 )
		{
			printf("( ERROR - Database Contains Nothing To Display...)\n") ;
		}
		else
		{
			// Iteration used to display each student in map.
			for( map<int, student > ::iterator i = v1->begin() ; i != v1->end() ; i++ )
			{
				cout << "STUDENT INFORMATION IS :" << endl << endl ;
				cout << "\t\tStudent Number is : "   << (i->first) << endl ;
				cout << "\t\tFirst name is : "       << (i->second).get_fname() << endl ;
				cout << "\t\tLast name is : "        << (i->second).get_lname() << endl ;
				cout << "\t\tAge is : "              << (i->second).get_age() << endl ;
				cout << "\t\tGender is : "           << (i->second).get_gender() << endl ;
				cout << "\t\tProgram type is : "     << (i->second).get_program_type() << endl ;
				cout << "\t\tProgram Name is : "     << (i->second).get_program_name() << endl ;
				cout << "\t\tEmail is : "            << (i->second).get_email() << endl ;
				cout << "\t----------------------------" << endl ;
			}
		}

		while( 1 ) 
		{
			printf("Press Enter Any Key To continue.\n") ;
			getch() ;
			break ;
		}

	}

	
	///
	/// \brief Called to save a database to a file.
	/// \details <b>Details</b>
	///
	///	This method is called whenever the user choose to exit the program. It receives 
	/// a database as an input parameter that will be saved to a file, and char* that 
	///	contains the name of the output file that the databse will be saved to. The program creates and
	/// opens a text file for writing and outputs all the fields of the objects in the database into
	///  the text file. Once done, the file is closed.
	///
	/// \return Returns nothing.
	///
	void college::saveToDatabase ( map<int, student> v, char* fileName)
	{

		//iterator set to begin of the map.
		map<int, student>::iterator it = v.begin();
		fstream output;

		// Opening the file as text.
		output.open( fileName, ios::out ) ; 
		
		// if cannot open file.
		if ( !output ) 
		{
			cout << "Sorry ... Couldn't open <database> for output\n" ; 
			
		}
		else 
		{
			// write the all fields of student from map to file.
			for ( it = v.begin() ; it != v.end() ; it++ )
			{
				output << (it->second).get_student_number() << endl ;		// writes the student number.	
				output << (it->second).get_fname() << endl ;				// write the fisrt and middle name of the student.
				output << (it->second).get_lname() << endl ;				// writes the last name of the student.
				output << (it->second).get_age() << endl ;					// writes the age of the student.
				output << (it->second).get_gender() << endl ;				// writes the gender of the student.
				output << (it->second).get_program_type() << endl ;			// writes the program type of student.
				output << (it->second).get_program_name() << endl ;			// writes the program name od the student.
				output << (it->second).get_email() << endl <<endl ;			// writes the email of the student and 
																			// each student is separated by blank line.
			}
			output.close() ;			// closing the file.
		}
	}

	///
	/// \brief Called to laod a database from a file.
	/// \details <b>Details</b>
	///
	///	This method is called whenever the user choose to laod the database from a file. It receives a 
	/// char* that	contains the name of the input file that the databse will be laoded from. The program 
	/// opens a text file for reading and reads all the fields of the objects in the database in
	/// from the text file. Once done, the file is closed.
	///
	/// \return Returns nothing.
	///
	void college::load_from_file( char file_name[] )
	{
		// student object to call mutators of student class.
		student s ;
		ifstream file;
		string buffer;

		//opening file to read all students.
		file.open(file_name , std::ifstream::in);
		
		if(file.is_open())
		{
			while ( getline(file,buffer) )							// Takes the student number from the file.
			{
				s.set_studentnumber(atoi((char*)buffer.c_str())) ;  // sets the student number using mutator of student.

				getline(file,buffer) ;								// Takes the first name from the file.
				s.set_fname((char*)buffer.c_str()) ;				// sets the first name using mutator of student class.

				getline(file,buffer) ;								// Takes the last name from the file.
				s.set_lname((char*)buffer.c_str()) ;				// sets the last name using mutator of student class.

				getline(file,buffer) ;								// Takes the age from the file.
				s.set_age(atoi((char*)buffer.c_str())) ;			// sets the age using mutator of student class.

				getline(file,buffer) ;								// Takes the gender from the file.
				s.set_gender((char*)buffer.c_str()) ;				// sets the gender using mutator of student class.

				getline(file,buffer) ;								// Takes the program type from the file.
				s.set_program_type((char*)buffer.c_str()) ;			// sets the program type using mutator of student class.

				getline(file,buffer) ;								// Takes the program name from the file.
				s.set_program_name((char*)buffer.c_str()) ;		    // sets the program name using mutator of student class.

				getline(file,buffer) ;								// Takes the email from the file.
				s.set_email((char*)buffer.c_str()) ;				// sets the email using mutator of student class.

				getline(file,buffer) ;								//Takes the blank line which separate each student.

				info.insert(make_pair(s.get_student_number(), s) ); // insert the student number as key and object into the map.
			}
		}
		else
		{
			printf("No such file exists.%s \n") ;
		}
	}

	///
	/// \brief Called to get the address database.
	/// \details <b>Details</b>
	///
	/// This methods accesses the map container in the private data members and returns its address.
	///
	/// \return Returns a map * that holds all the items in the database.
	/// 
	map<int , student>* college::get_map()
	{
		return &info ;
	}


		
	/// \brief Called to generate random data for a student object.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user wants to generate a desired amount of random students 
	/// that have random data in their fields. it will generate random data for all the 
	///	fields of the object.
	/// After, the method will call add student with the specific fields provided. 
	///
	/// \return Returns the student object created..
	///
	student college::randomStudentcreator( void )
	{
		// random object/student data members
		char randomletter = ' ';
		student *randomStudent = new student;
		char first_name[kMAXCHAR] = {"\0"};
		char last_name[kMAXCHAR] = {"\0"} ;
		char gender[kMAXCHAR] = "\0" ;
		char email[kMAXCHAR] = {"\0"} ;
		char program_name[kMAXCHAR] = {"\0"};
		char program_type[kMAXCHAR] = {"\0"};
		int  student_number = 0;
		int  age = 0,  i = 0, length = 0;
//		srand(time(NULL));
		length = (rand() % 30 + 4);

		//randomizing the first name of the student.
		for ( i = 0; i < length; i++)
		{
			if ( i == 0)
			{
				// randomize first letter of first name in upper Case
				randomletter = "BCDFGHJKLMNPQRSTVWXYZ"[rand () % 26];
				first_name[i] = randomletter;
				
			}
			// if previous character is a vowel
			else if ( first_name[i-1] == 'a' ||  first_name[i-1] == 'e' ||  first_name[i-1] == 'i' ||   first_name[i-1] == 'o' ||  first_name[i-1] == 'u')
			{
				// add a 
				randomletter = "bcdfghjklmnpqrstvwxyz"[rand () % 21];
				first_name[i] = randomletter;
				
			}
			else 
			{
				randomletter = "aeiou"[rand () % 5];
				first_name[i] = randomletter;
				
			}
		}
		if ( strcmp ( first_name, "") == 0)
		{
			// harcoded value if unexpected error occurs
			strcpy( first_name, "Sameer");
		}
		if ( first_name[0] == '\0')
		{
			// harcoded value if unexpected error occurs
			strcpy( first_name, "Sameer");
		}

		length = (rand() % 20 + 4);
		//randomizing last name of the student
		for ( i = 0; i < length; i++)
		{
			if ( i == 0)
			{
				// randomize first letter of first name in upper Case
				randomletter = "BCDFGHJKLMNPQRSTVWXYZ"[rand () % 26];
				last_name[i] = randomletter;
			}
			// if previous character is a vowel
			else if ( first_name[i-1] == 'a' ||  first_name[i-1] == 'e' ||  first_name[i-1] == 'i' ||   first_name[i-1] == 'o' ||  first_name[i-1] == 'u')
			{
				randomletter = "bcdfghjklmnpqrstvwxyz"[rand () % 21];
				last_name[i] = randomletter;
			}
			else
			{
				randomletter = "aeiou"[rand () % 5];
				last_name[i] = randomletter;
			}
		}
		if ( strcmp ( last_name, "") == 0)
		{
			// harcoded value if unexpected error occurs
			strcpy( last_name, "Diaby");
		}
		if ( last_name[0] == '\0')
		{
			// harcoded value if unexpected error occurs
			strcpy( last_name, "Sameer");
		}

		//randomize gender 
		length = (rand() % 2 + 1);
		if ( length == 1)
		{
			strcpy(gender, "Male");
		}
		else
		{
			strcpy(gender, "Female");
		}

		//randomizing the first part of the email
		length = (rand() % 10 + 3);
		for ( i = 0; i < length; i++)
		{
			randomletter = "abcdefghijklmnopqrstuvwxyz0123456789"[rand () % 36];
			email[i] = randomletter;
		}
		// inserting @ character
		email[i] = '@';
		//randomizing the second part of the email
		int length2 = (rand() % 7 + 3);
		int i2 = i+1;
		for (  i2 = (i+1) ; i2 < length + length2; i2++)
		{
			// if the number of characters after @ is inputed 
			if ( i2 == length2 + length)
			{
				break;
			}
			randomletter = "abcdefghijklmnopqrstuvwxyz"[rand () % 26];
			email[i2] = randomletter;
		}
		//inserting dot
		email[i2] = '.';
		// randomizing the extension of the email
		int length3 = (rand() % 3 + 2);
		int i3 = i2 + 1;
		for (  i3 ; i3 < length+ length2 + length3; i3++)
		{
			//if number of characters after . has been reached
			if ( i3 == length3 + length2)
			{
				break;
			}
			randomletter = "abcdefghijklmnopqrstuvwxyz"[rand () % 26];
			email[i3] = randomletter;
		}

		//Randomizing program name 
		length = (rand () % 50 + 3);
		for (  i = 0 ; i < length; i++)
		{
			//if this is the first letter of the program name
			if ( i == 0 )
			{
				randomletter = "ABCDFEGHIJKLMNOPQRSTUVWXYZ"[rand () % 26];
				program_name [i] = randomletter;
			}
			else if ( program_name[i-1] == 'a' ||  program_name[i-1] == 'e' ||  program_name[i-1] == 'i' ||   program_name[i-1] == 'o' ||  program_name[i-1] == 'u')
			{
				randomletter = "bcdfghjklmnpqrstvwxyz"[rand () % 21];
				program_name[i] = randomletter;
			}
			else
			{
				randomletter = "aeiou"[rand () % 5];
				program_name [i] = randomletter;
			}
		}
		if( strcmp (program_name, "") == 0 )
		{
			strcpy( program_name, "Software Engineering");
		}
		if ( program_name[0] == '\0')
		{
			// harcoded value if unexpected error occurs
			strcpy( program_name, "Software Engineering");
		}

		//randomize program type 
		length = (rand() % 2 + 1);
		if ( length == 1)
		{
			strcpy(program_type, "Full Time");
		}
		else
		{
			strcpy(program_type, "Part Time");
		}
		// randomizing the student number 
		length = (rand() % 200000 + 999999 );
		student_number = length;

		// randomizing age number
		length = (rand() % 80 + 15 ) ;
		age = length;

		//setting data members of random object
		randomStudent->set_fname(first_name);
		randomStudent->set_lname(last_name);
		randomStudent->set_gender(gender);
		randomStudent->set_email(email);
		randomStudent->set_program_name(program_name);
		randomStudent->set_program_type(program_type);
		randomStudent->set_age(age);
		randomStudent->set_studentnumber(student_number);
		
		return *randomStudent;
	}


};


