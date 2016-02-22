///FileName:	UI.h

///Project:		DS-OOP Project

///Author:		Sekou Diaby, Sameer Sapra	

///Date:		April 18, 2014

///Description:	This program is a menu based system which adds students to a college database.

///				This program more specifically keeps tracks of students in an engineering program.

///				This class contains the menus of the program that will be used to navigate.
				
///				The purpose of the class is to act as an interfac between the user and the program.

///				The user will only see and used methods from this class. These methods will call other 

///				methods in other related classes to perform the desired action of the user. This is the 
	
///				class that will mostly make method calls to validate any input entered by the user.

///	

/* -- FILEHEADER COMMENTS -- 

	NAME	:	UI.h

	PURPOSE :	This class is used to handle any request made by the user and to handle any input provided.

*/

/// included files
#include"college.h"

///disables warnings

#pragma warning(disable: 4996)///<#pragma warning used for depricated functions#pragma warning(disable:4996)


/// 

/// \class UI

///

/// \brief The purpose of this class is to handle any request made by the user and to handle any input provided.

/// This comment block is <i>required</i> for all class declarations.  This is the place 

/// where the <b>Class header Comment</b> appears. 

///

/// \author A <i>Sekou Diaby, Sameer Sapra</i>

///

class UI
{

private:

	college* coll ;								///<used to make calls to functions in the college class.
	char file_name[15] ;						///<used to hold the name of the file that the database will be saved to.
	bool displayOutput;							///<used to check if user wants to display output on the screen.

public:

	/* -------------- METHODS --------------- */
	///
	/// \brief Called to instantiate an object of the UI class.
	/// \details <b>Details</b>
	///
	/// This method will create a UI object which will be used to interface with the user. 
	/// The method will instantiate all the attributes of the class to a null value. 
	///
	/// \return Returns nothing since this is a constructor.
	///
	/// 
	UI()
	{
		//Creating an object dynamically.
		coll = new college();

		//File name to write/read all database.
		strcpy ( file_name , "database.txt" ) ;
		displayOutput = true;
	}

	///
	/// \brief Called to destruct an object of the UI class.
	/// \details <b>Details</b>
	///
	/// This method will destruct a created User Interface object that the user used.
	/// The method will free any memory that is used by the object. 
	///
	/// \return Returns nothing since this is a destructor.
	///
	/// 
	~UI()
	{

	}

	///
	/// \brief Called to display a menu to the user.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user is running the program. It will 
	///	display a list of menu options to the user to choose from. This function will 
	/// make calls to other functions depending on that choice of the user.
	/// This function will keep looping until the user chooses to exit.
	///
	/// \return Returns nothing.
	///
	void main_menu ( void )
	{

		//User's main menu option.
		int choice = 0 ;		

		//True till user press 8 and save's all database to the file.
		while(choice != 8 )
		{
			printf("\n\t\t\t\tCONESTOGA COLLEGE\n" ) ;
			printf("\n\t\t\tENGINEERING DEPARTMENT DATABASE\n\n\n" ) ;
			printf("1. ADD STUDENT.\t\t\t\t\t" ) ;
			printf("2. DELETE STUDENT.\n\n" ) ;
			printf("3. DELETE ENTIRE STUDENT DATABASE.\t\t" ) ;
			printf("4. SEARCH STUDENT.\n\n" ) ;
			printf("5. DISPLAY ENTIRE STUDENT DATABASE.\t\t" ) ;
			printf("6. LOAD DATABASE FROM FILE.\n\n" ) ;
			printf("7. ADD RANDOM VALUE FOR TESTING.\t\t" ) ;
			printf("8. EXIT.\n\n") ;
			printf("What would you like to do?\n\n\n") ;

			//User input the choice.
			choice = getch() ;

			switch( choice )
			{
			case '1':					// For Add Student.

				coll->ClearScreen() ;	// Calling function of college class to clear sceen to get rid of previous output.
				add_student() ;			// Calling its own add student function which will call to another add student function of college class. 
				coll->ClearScreen() ;
				break ;

			case '2':					// For Deleting a student.

				coll->ClearScreen() ;
				delete_Student() ;		// Calling it's own function which will call delete student function of college class 
										// to delete a particaular student.
				coll->ClearScreen() ;
				break ;

			case '3':					// For To delete all database from memory.  

				coll->ClearScreen() ;
				delete_database() ;		// Calling its own function.
				coll->ClearScreen() ;
				break ;

			case '4':					// To search a student.

				coll->ClearScreen() ;	
				search_student() ;		// Calling its own function.
				coll->ClearScreen() ;
				break ;
			case '5':					//To display all student's information stored in memory/file.

				coll->ClearScreen() ;
				display_database() ;	//Calling its own function.
				coll->ClearScreen() ;
				break ;

			case '6':					// To load database from a file.
				coll->ClearScreen() ;
				coll->load_from_file(file_name);	
				break ;

			case '7':					//To create random database for studnent.	

				coll->ClearScreen() ;
				create_fake_data() ;	// Calling its own function , which will call college function to process further.
				coll->ClearScreen() ;
				break ;

			case '8':					// To exit and save all database in a file mentioned in default constructor.					

				cout << "\t ***You Are Out Of The Program***"<< endl ;
				cout << "\t ***All changes have been saved to File***" << endl ;

				save_in_database( file_name ) ;		//Calling its own function which will call college function to save all database in file.
				choice = 8 ;						//To end while loop of main menu.
				break ;

			default:					//If user enter any other option. 
					
				cout << "( ERROR - Choose A Valid Option... )"<< endl ;
				
				while( 1 )						//True till user presses any key.
				{
					cout << "Press Any Key To Continue." << endl ;
					getch() ;
					break ;
				}
				coll->ClearScreen() ;
			}
		}
	}

	///
	/// \brief Called to add a new student into the database.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a the user choose to add a new student. It will 
	/// initialize of the data members of the student that is going to be added. The 
	/// method itself has its own menu options for the user to choose which data member to set.
	/// The user will then be asked to enter input for all the fields of the student object. 
	/// Once the input is received from the console, the method makes calls to other methods 
	/// to validate the input. after validation, the methods make a call to a function in the college class
	/// with the attributes to the data members of the object.
	///
	/// \return Returns nothing.
	///
	void add_student()
	{
		// Local data members .

		char first_name[kMaxSize] = "";			// To store user's input first name and validate it.
		char last_name[kMaxSize] = "";			// To store user's input last name and validate it.
		char age[kMaxSize] = "" ;				// To store user's input age and validate it.
		int age_int = 0 ;					// Store's user's input age in integer.

		char gender[kMaxSize] = "" ;				// Store's user's input of gender.
		char email[kMaxSize] = "" ;				// Store's user's email input.
		char program_name[kMaxSize] = "" ;		// Store's user's program name input.
		char program_type[kMaxSize] = "" ;		// Store's user's program type input.
		char student_number[kMaxSize] = "" ;		// Store's user's student number.


		char check_all_input[8] = "" ;		// Used to check if user has input all correct information in all 8 fields of student.
		int stud_number = 0 ;				
		int check = 0 ;						// Used in while loop of each student field to check for valid input.
		int loop1 = 0 ;
		int select = 0 ;					// Gets user choice for student menu.
		int length = 0 ;					
		int done = 0 ;
		int check_range = 0 ;
		int count_correct_fields = 0 ;
		int prog_type = 0 ;
		int i = 0 ;

		bool ret = 0 ;

		//Student menu and true till done is 1.

		while( done != 1 )
		{
			cout << "\n\t\tENTER STUDENT INFORMATION" << endl << endl ;
			printf("1. Student's First Name.") ;
			printf("\t\t2. Student's Last Name.\n\n") ;
			printf("3. Student's Age.") ;
			printf("\t\t\t4. Student's Gender\n\n") ;
			printf("5. Student Number.") ;
			printf("\t\t\t6. Program Type.\n\n") ;
			printf("7. Program Name" ) ;
			printf("\t\t\t\t8. Email Address\n\n" ) ;
			printf("9. DONE\n") ;

			// User enters menu option.
			select = getch() ;
			switch( select )
			{

			case '1':					// For student first name.

				coll->ClearScreen() ;

				//True till input validation is true.
				while( check == 0 )
				{
					check_all_input[0] = '0' ;
					ret = 0 ;
					cout << "Enter Your First And Middle Name : " ;

					gets( ( first_name ) ) ;							// Getting user input.
					
					ret = validate_first_name( first_name , true ) ;			// Calling its function to validate the user input.
					
					//If validation is true.
					if( ret )
					{
						check = 1 ;					// Dont ask user again for first name.
						check_all_input[0] = '1' ;	// User has input something.
					}
					else
					{
						check = 0 ;					// Ask again for user input.
						check_all_input[0] = '0';	// User has enetred something in first name. 
					}
				}// End of while loop.

				check = 0 ;
				coll->ClearScreen() ;
				break ;

			case '2':					// For last name.
				coll->ClearScreen() ;

				//True till check is 1.
				while( check == 0 )
				{
					ret = 0 ;
					cout << "Enter Your Last Name : " ;
					gets( last_name ) ;							// User enters last name.

					ret  = validate_last_name( last_name , true ) ;	// Calling its own function to validate the user input.
					
					// If validation is true.
					if( ret )
					{
						check  = 1 ;							// Dont ask user again for last name.
						check_all_input[1] = '1' ;				// User has enetred somthing in last name.
					}
					else
					{
						check = 0 ;								// Ask again for last name from the user.
						check_all_input[1] = '0' ;				// user has enetred somthing in last name.
					}
				}	// End of while loop.

				check = 0 ;
				coll->ClearScreen() ;
				break ;

			case '3':					// For age.
				coll->ClearScreen() ;

				//True till check is 1.
				while( check == 0 )
				{
					ret = 0 ;
					check_all_input[2] = '0' ;				// If user has not entered anything in age .
					cout << "Enter Your Age : " ;
					
					gets( age ) ;							// User input the age.

					ret = validate_age( age , true) ;				// Calling its own function to validate the suer input.
					
					//If validation is true.
					if( ret )
					{
						check = 1 ;						//Dont ask user again for age.
						check_all_input[2] = '1' ;
						
					}
					else
					{
						check = 0 ;					// Ask again from the user for age.
						check_all_input[2] = '0' ;
					}
					
				}		// End of while loop.

				check = 0 ;
				coll->ClearScreen() ;
				break ;

			case '4':					// For gender.
				coll->ClearScreen() ;
				
				//True till check is 1.

				while( check == 0 )
				{
					//local variables.
					int flag1 = 0 ;
					int gen = 0 ;
					
					cout << "Choose Your Gender : " <<endl ;
					cout << "\t\t\t1.  Male" << endl ;
					cout << "\t\t\t2.  Female" << endl ;
					gen = getch() ;							// user enters the option.
					check_all_input[3] = '0' ;
					flag1 = validate_gender( gen , true ) ;		// Calls its own function to validate the user input.


					// If user has selected 1 from menu.
					if( flag1 == 1 )
					{
						strcpy ( gender , "Male" ) ;
						check = 1 ;							// Don't ask user for gender.
						check_all_input[3] = '1' ;			// User has opted something for gender.
					}
					else
					{
						//If user has selected 1 from menu.
						if ( flag1 == 2 )
						{
							strcpy ( gender , "Female" ) ;
							check = 1 ;						// Dont ask for user for gender again.
							check_all_input[3] = '1' ;		// User has enetered something.
						}
						else
						{
							check = 0 ;						// Ask again from user for gender.
							check_all_input[3] = '0' ;	
						}
					}
				}		// End of while loop.

				check = 0 ;
				coll->ClearScreen() ;
				break ;
			case '5':
				coll->ClearScreen() ;

				// True till check is 1.
				while( check == 0 )
				{
					ret = 0 ;
					cout << "Enter Your Student Number : " ;
					gets( student_number ) ;							// user input the student number.

					check_all_input[4] = '0' ;

					ret = validate_student_number( student_number , true) ;	// Calling its own function to validate the user input.

					//If validation is true.
					if( ret )
					{
						// Convert it into integer.
						stud_number = atoi( student_number ) ;
			
						if( stud_number > 0 )
						{
							check = 1 ;								//Dont ask for student number again.
							check_all_input[4] = '1' ;				// User has input something.
						}
						else
						{
							check = 0 ;								// Ask again for student number.
							check_all_input[4] = '0' ;
						}
					}
					else
					{
						check = 0 ;									//Ask again for user input.
						check_all_input[4] = '0' ;
					}
				}		// End of while loop.

				check = 0 ;
				coll->ClearScreen() ;
				break ;
			case '6':			// For program type.

				coll->ClearScreen() ;

				// True till check is 1.
				while( check == 0 )
				{
					int flag = 0 ;

					cout << "Choose Your Program Type : \n" ;
					cout << "\t\t\t1. FULL TIME" << endl ;
					cout << "\t\t\t2. PART TIME" << endl ;

					check_all_input[5] = '0' ;

					// Get the user choice.
					prog_type = getch () ;
					
					flag = validate_program_type( prog_type , true) ;			// Calling the  function to validate the user input.
		
					// If user pressed 1.
					if ( flag == 1 )
					{
						strcpy( program_type , "FULL TIME" ) ;
						check = 1 ;								// Dont ask again.
						check_all_input[5] = '1' ;
					}
					else
					{
						//If user pressed 2
						if( flag == 2 )
						{
							strcpy( program_type , "PART TIME" ) ;
							check = 1 ;								// Dont ask for program type again.
							check_all_input[5] = '1' ;				// User has input somthing.
						}
						else
						{
							//Ask again.
							check = 0 ;
							check_all_input[5] = '0' ;
						}
					}
				}// End of while loop.

				coll->ClearScreen() ;
				check = 0 ;
				break ;

			case '7':			// For program name.

				coll->ClearScreen() ;
				
				// True till check is 1. 
				while( check == 0 ) 
				{
					ret = 0 ;

					check_all_input[6] = '0' ;

					cout << "Enter Program Name : " ;
					gets( program_name ) ;								// User Enters the program name.
					
					ret = validate_program_name( program_name , true ) ;		// Calling function to validate user input.
					 

					//If validation is true.
					if( ret )
					{
						check = 1 ;					// Dont ask for program name again.
						check_all_input[6] = '1' ;	// User has input something.
					}
					else
					{
						//Ask again.
						check = 0 ;
						check_all_input[6] = '0' ;
					}
					
				}		// End of while loop.
				check = 0 ;
				coll->ClearScreen() ;
				break ;

			case '8':				// For email address.

				coll->ClearScreen() ;
				
				// True till check is 1.
				while( check == 0 )
				{
					cout << "Enter Email Address : " ;
					gets( email ) ;							// User enter the email address.

					// User cannot input a space in beginning.
					if( email[0] == ' ' )
					{
						cout << "\t\t( ERROR - Don't Put A Space in begining... )" << endl ;
						continue ;
					}

					// Gets the length of the email.
					length = strlen( email ) ;

					// If user has entered nothing.
					if( length <= 0 )
					{
						cout << "\t\t( ERROR - Dont Leave The Field Blank... )" << endl ;
						continue ;
					}
					else
					{ 
						// Calling validation function.
						if( is_email_valid(email) )
						{
							check  = 1 ;						// Dont ask for email again.
							check_all_input[7] = '1' ;			// User has entered somthing.				
						}
						else
						{
							cout << "\t\t\t( ERROR - " << email << "is : INVALID... )" << endl ; 
						}
					
					}
				}	//End of while loop.
				check = 0 ;
				coll->ClearScreen() ;
				break ;

			case '9':		// If user is done with all the fields.
				
				// Check whether user has input something in all fields.
				for( loop1 = 0 ; loop1 < 8 ; loop1++ )
				{
					if( check_all_input[loop1] != '1' )
					{
						cout << "\t(ERROR - You Did Not Input All The Fields... )" << endl ;
						
						// true till user press any key.
						while(1)
						{
							cout << "Press Any Key To Continue" << endl ;
							getch();
							break ;
						}
						break ;
					}
				}

				// If user has input in all the fields then don't ask again for the fields.
				if( loop1 == 8 )
				{
					done = 1 ;
					coll->addstudent(first_name , last_name , age_int , gender , stud_number , email , program_name , program_type );
				}

				// Else process from start to input all fields.
				else
				{
					done = 0 ;
				}
				coll->ClearScreen() ;
				break ;
			default:

				// True till user enters any key.
				while( 1 )
				{
					cout << "\n( ERROR - Enter a valid option... )" << endl ;
					cout << "Press Any Key To Continue" << endl ;
					getch() ;
					break ;
				}
				coll->ClearScreen() ;
			}
			
		}
	}

	///
	/// \brief Called to search the database that contains the students.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user wants to search for a student in the database.
	///	The method will call the accessor for the database/map in the college class and receive the 
	///	address of the map for access. Than the function will call a method from the college class. 
	///
	/// \return Returns nothing.
	///
	void search_student()
	{
		map<int,student> *v1 ;

		//Getting the map from the college class.
		v1 = coll->get_map() ;

		//Calling function of college class to search for a student.
		coll->searchstudent( v1 ) ;
	}

	///
	/// \brief Called to delete a student from the database that contains the students.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user wants to delete a student in the database.
	///	The method will call the accessor for the database/map in the college class and receive the 
	///	address of the map for access. Than the function will call a method from the college class to
	///	to delete a student from the received database. 
	///
	/// \return Returns nothing.
	///
	void delete_Student() 
	{
		map<int , student> *v2 ;

		//Getting map from the college class.
		v2 = coll->get_map() ;

		//Calling fuction of college class to delete a student.
		coll->delete_student( v2 ) ;
	}

	///
	/// \brief Called to delete all students from the database that contains the students.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user wants to delete all students in the database.
	///	The method will call the accessor for the database/map in the college class and receive the 
	///	address of the map for access. Than the function will call a method from the college class to
	///	to delete the received database. 
	///
	/// \return Returns nothing.
	///
	void delete_database()
	{
		map<int , student> *v3 ;

		//getting map from the college class.
		v3 = coll->get_map() ;

		//Calling function of college class to delete an entire database.
		coll->delete_entire_database(v3) ;
	}

	///
	/// \brief Called to display all students from the database that contains the students.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user wants to display all students in the database.
	///	The method will call the accessor for the database/map in the college class and receive the 
	///	address of the map for access. Than the function will call a method from the college class to
	///	to display the received database. 
	///
	/// \return Returns nothing.
	///
	void display_database()
	{
		map<int ,student> *v4 ;
		//Getting map from the college.
		v4 = coll->get_map() ;

		//Calling function of college to display entire dataabse. 
		coll->display_entire_database( v4 ) ;
	}

	///
	/// \brief Called to save the database that contains the students into a file.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user wants to exit which will automatically save to a file.
	///	The method will call the accessor for the database/map in the college class and receive the 
	///	address of the map for access. Than the function will call a method from the college class to
	///	to save the received database to a file. 
	///
	/// \return Returns nothing.
	///
	void save_in_database(char *filename) 
	{
		map<int,student> v5;
		//Getting map from the college class.
		v5 = *(coll->get_map() );

		//Calling college class function to save database to file.
		coll->saveToDatabase(v5 , filename) ;
	}

	///
	/// \brief Called to generate random data for a student object.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user wants to generate a desired amount of random students 
	/// that have random data in their fields. It will ask the user to input the number of data and 
	/// and will loop that number times by calling a function that generates a random student at a time.
	/// After, the method will call add student with the specific fields provided. 
	///
	/// \return Returns nothing.
	///
	void create_fake_data()
	{
		// Local variables. 
		int number_of_data = 0 ;
		int loop1 = 0 ;
		int length = 0 ;
		char fake_data[50] = "" ;
		cout << "Enter The Number of Random Data" << endl ;
		
		gets( fake_data ) ;							//Getting the number of random data.

		length = strlen( fake_data ) ;
		for ( loop1 = 0 ;  loop1 < length  ; loop1++ )
		{
			if( isdigit( fake_data[loop1] ) == 0 )
			{
				cout << "Input Only Digits" << endl ;
				break ; 
			}
		}
		//changing character into a number
		number_of_data = atoi ( fake_data ) ;
		//calling function to create random object 
		loop1 = 0;
		
		while ( loop1 < number_of_data)
		{
			student randomStudent ;
			//getting the random student that is created
			randomStudent = coll->randomStudentcreator() ;
			// adding the student to the map container
			coll->addstudent(randomStudent.get_fname(), randomStudent.get_lname(), randomStudent.get_age(), randomStudent.get_gender(),
							randomStudent.get_student_number(), randomStudent.get_email(),randomStudent.get_program_name(), 
							randomStudent.get_program_type());
			loop1 ++;
		}
	}

	///
	/// \brief Called to validate that the email provided by the user is in the right format.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered an email input. 
	///	The method will validate the email by using regular expression class.
	/// The methods brings in as a parameter the string email to be tested.
	///
	/// \return Returns a boolean value that will determine if the email was valid.
	///
	bool is_email_valid(const std::string& email)
    {
		// define a regular expression
		const std::tr1::regex pattern
		("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
     
		// try to match the string with the regular expression
		return std::tr1::regex_match(email, pattern);
    }

	///
	/// \brief Called to validate that the first name provided by the user is in the right format.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered a first name input. 
	///	The method will validate the first name through a series of if and else statements.
	/// The methods brings in as a parameter the char* first name to be tested.
	///
	/// \return Returns a boolean value that will determine if the first name was valid.
	///
	bool validate_first_name( char *fname, bool displayOutput)							///<used to check if user wants to display output on the screen. ) 
	{
		//local data members.
		int length = 0 ;
		int loop1  = 0 ;

		length = strlen( fname ) ;		//Gets the length of the first name.
					
		if( length <= 0 )					//If user inputs nothing.
		{
			if ( displayOutput)
			{
				printf("\t\t\t( ERROR - Don't Leave Any Field Blank... )\n") ;
			}
			return 0 ;
		}

		if( fname[0] == ' ' )			// User cannot input a space in begining.
		{
			if (displayOutput)
			{
				cout << "\t\t\t( ERROR - Don't Put A Space in begining... )" << endl ;
			}
				return 0 ;
		}


		//Input validation of first name starts.
		for( loop1 = 0 ; loop1 < length ; loop1++ )
		{

			//Only letters and space is allowed.
			if( ( isalpha( fname[ loop1 ] ) == 0 ) )
			{
				if( fname[loop1] == ' ' )
				{
					continue ;
				}
				else
				{
					if (displayOutput )
					{
						cout << "\t\t\t( ERROR - Enter Only Alphabets And Space... )" << endl ; 
					}
					break ;
				}
			}
		}

		// If user's input is valid.
		if( loop1 == length ) 
		{
			return 1 ;
		}
		else
		{
			return 0 ;
		}
	}

	///
	/// \brief Called to validate that the last name provided by the user is in the right format.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered a last name input. 
	///	The method will validate the last name through a series of if and else statements.
	/// The methods brings in as a parameter the char* last name to be tested.
	///
	/// \return Returns a boolean value that will determine if the last name was valid.
	///
	bool validate_last_name( char *last_name, bool displayOutput )
	{
		int length = 0 ;
		int loop1  = 0 ;
		
		length = strlen( last_name ) ;			// Gets the length of the last name.

		// If user enters nothing.
		if( length <= 0 )
		{
			if (displayOutput)
			{
				printf("\t\t\t( ERROR - Don't Leave Any Field Blank... )\n") ;
			}
			return 0 ;
		}

		//User cannot input space in begining.
		if( last_name[0] == ' ' )
		{
			if (displayOutput)
			{
				cout << "\t\t\t( ERROR - Don't Put A Space in begining... )" << endl ;
			}
			return 0 ;
		}
					
		// Validation starts.
		for( loop1 = 0 ; loop1 < length ; loop1++ )
		{
			// Only letters are allowed.
			if( isalpha( last_name[loop1] ) == 0 )
			{
				if (displayOutput)
				{
					cout << "\t\t\t( ERROR - Enter Only Alphabets... )" << endl ;
				}
				return 0 ;
				break ;
			}
		}
		//If user enters correct last name.
		if( loop1 == length )
		{
			return 1 ;
		}
		return 0;
	}

	///
	/// \brief Called to validate that the age provided by the user is in the right range.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered an age input. 
	///	The method will validate the age through a series of if and else statements.
	/// The methods brings in as a parameter the char* age to be tested. This will be 
	/// converted to an int before it is set.
	///
	/// \return Returns a boolean value that will determine if the age was valid.
	///
	bool validate_age( char *age, bool displayOutput )
	{
		int length = 0 ;
		int loop1 = 0 ;
		int age_int = 0 ;

		length = strlen( age ) ;				// Length of the string.

		// If user does not input anything.
		if( length <= 0 )
		{
			if (displayOutput)
			{
				printf("\t\t( ERROR - Don't Leave Any Field Blank... )\n") ;
			}
			return 0 ;
		}

		//User cannot input a space in begining.
		if( age[0] == ' ' )
		{
			if (displayOutput)
			{
				cout << "\t\t( ERROR - Don't Put A Space in begining... )" << endl ;
			}
			return 0 ;
		}

		// Validation starts.
		for( loop1 = 0 ; loop1 < length ; loop1++ )
		{
			//Only digits are allowed.

			if( isdigit( age[loop1] ) == 0 )
			{
				if (displayOutput)
				{
					cout << "\t\t( ERROR - Input Only Digits... )" << endl ;
				}
				return  0 ;				
				break ;
							
			}
		}

		// If only digits are there in age then convert it into integer.
		if( loop1 == length )
		{
			
			// Convert Age in integer.
			age_int = atoi( age ) ;

			//Age cannot be less than 15 and greater than kMaxSize.
			if( ( age_int <= 15 ) || ( age_int >= 100 ) )
			{
				if (displayOutput)
				{
					cout << "(ERROR - Enter age in range... ) " << endl ;
				}
				return  0 ;
			}
			else
			{
				return 1;
			}
		}
		return 0;
	}

	///
	/// \brief Called to validate that the gender provided by the user is in the right range.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered a gender input. 
	///	The method will validate the gender through a series of if and else statements.
	/// The methods brings in as a parameter an int gender to be tested. each integer 
	/// represents a specific gender to set. 
	///
	/// \return Returns an int value that will determine if the age was valid.
	///
	int validate_gender( int gender, bool displayOutput )
	{
		if( gender == '1' )
		{
			return 1 ;
		}
		else
		{
			if( gender == '2' )
			{
				return 2 ;
			}
			else
			{
				if (displayOutput)
				{
					cout << "\t\t\t( ERROR - Choose Correct Option... )" << endl << endl ;
				}
				return 0 ;
			}
		}
	}

	///
	/// \brief Called to validate that the student number provided by the user is in the right range.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered a student number input. 
	///	The method will validate the number through a series of if and else statements.
	/// The methods brings in as a parameter a char* that contains the number to be tested. 
	///
	/// \return Returns an bool value that will determine if the number was valid.
	///
	bool validate_student_number( char *student_number, bool displayOutput ) 
	{
		int length = 0 ;
		int loop1  = 0 ;
		int stud_number = 0 ;

		length = strlen( student_number ) ;		// Gets the length of the string.
				
		// If user enters nothing. 
		if( length <= 0 )
		{
			if (student_number)
			{
				printf("\t\t\t( ERROR - Don't Leave Any Field Blank... )\n") ;
			}
			return  0 ;
		}
		if ( length > 7)
		{
			if (displayOutput)
			{
				printf("\t\t\t( ERROR - Input only 7 digits... )\n") ;
			}
			return  0 ;
		}
		if ( *student_number == '0' ) 
		{
			if (displayOutput)
			{
				printf("\t\t\t( ERROR - No student starts with a zero... )\n") ;
			}
			return  0 ;
		}

		// User cannot input space in begining.
		if( student_number[0] == ' ' )
		{
			if (displayOutput)
			{
				cout << "\t\t\t( ERROR - Don't Put A Space in begining... )" << endl ;
			}
			return 0 ;
		}

		//Validation starts.
		for( loop1 = 0 ; loop1 < length ; loop1++ )
		{

			// Only digits are allowed.
			if( isdigit( student_number[loop1] ) == 0 )
			{
				if (displayOutput)
				{
					cout <<"\t\t\t( ERROR - Enter only digits... )" << endl ;
				}
				break ;

			} // Ask for student number again.
		}

		// If there are only digits in student number. 
		if( loop1 == length )
		{
			return 1 ;
		}
		else
		{
			return  0 ;
		}
	}

	///
	/// \brief Called to validate that the program type provided by the user is in the right range.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered an int for the program type. 
	///	The method will validate the integer through a series of if and else statements.
	/// The methods brings in as a parameter an int to be tested. each integer 
	/// represents a specific program type to set. 
	///
	/// \return Returns an int value that will determine if the program type was valid.
	///
	int validate_program_type( int prog_type, bool displayOutput )
	{
		if( prog_type == '1' )
		{
			return 1 ;
		}
		else
		{
			if( prog_type == '2' )
			{
				return 2 ;
			}
			else
			{
				if (displayOutput)
				{
					cout << "\t\t\t( ERROR - Choose Correct Option... )" << endl << endl ;
				}
				return 0 ;
			}
		}
	}

	///
	/// \brief Called to validate that the program nmae provided by the user is in the right format.
	/// \details <b>Details</b>
	///
	///	This method is called whenever a user has entered a program name input. 
	///	The method will validate the name of the program through a series of if and else statements.
	/// The methods brings in as a parameter a char* to be tested.
	///
	/// \return Returns a bool value that will determine if the program_name was valid.
	///
	bool validate_program_name( char *program_name, bool displayOutput )
	{
		int length = 0 ;
		int loop1 = 0 ;
		length = strlen ( program_name ) ;		// Gets the length of the program name.
					
		// User cannot input space in begining.
		if( program_name[0] == ' ' )
		{
			if ( displayOutput)
			{
				cout << "\t\t\t( ERROR - Don't Put A Space in begining... )" << endl ;
			}
			return 0 ;
		}

		// If user has entered nothing.
		if( length <= 0 ) 
		{
			if (displayOutput)
			{
				cout <<"\t\t\t( ERROR - Don't Leave The Field Blank... )" << endl ;
			}
			return  0 ;
		}
		else
		{

			// Validation starts.
			for( loop1 = 0 ; loop1 < length ; loop1++ )
			{
				// Only letters and space is allowed. 
				if( ( isalpha( program_name[ loop1 ] ) == 0 ) )
				{
					if( program_name[loop1] == ' ' )
					{
						continue ;
					}
					else
					{
						if (displayOutput)
						{
							cout << "\t\t\t( ERROR - Enter Only Alphabets And Space... )" << endl ; 
						}
						return  0 ;
						break ;
					}
				}
			}

			// If user input valid program name.
			if( loop1 == length )
			{
				return  1 ;
			}
			
		}
		return 0 ;
	}
};
