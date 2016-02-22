
#include"college.h"

#pragma warning(disable:4996)

	void college::add_student( char first_name[],char last_name[],int age_int,char gender[]			
					, int std_number,char email[] , char program_name[],char program_type[] )
	{
		
		student std1;

		ClearScreen() ;
		
		std1.set_fname( first_name ) ;
		std1.set_lname( last_name ) ;
		std1.set_age( age_int ) ;
		std1.set_gender( gender ) ;
		std1.set_studentnumber( std_number ) ;
		std1.set_email( email ) ;
		std1.set_program_type( program_type ) ;
		std1.set_program_name( program_name ) ;
		info.insert(make_pair( std_number , std1 ) ) ;
		cout << "\n\tStudent's Information is Added In The Database." << endl ;
		Sleep( 1000 ) ;
	}

	void college::ClearScreen()
	{
		SetPos(0,0) ;
		for( int i = 1 ; i <= 55 ; i++ )
		{
			for( int j = 1 ; j < 80 ;j++ )
			{
				printf(" " ) ;
			}
			printf("\n") ;
		}
		SetPos(0,0) ;
	}

	void college::SetPos( int x, int y )
	{
		static HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE) ;

		COORD pos = {y,x} ;
		SetConsoleCursorPosition(hout,pos ) ;  //	Sets the Coordinate position.
	}


	void college::searchstudent(map<int , student > *v)
	{
		char std_number[10] = "" ;
		int stud_number     = 0 ;
	
		map<int,student>::iterator i = v->begin() ;

		if( (v->size()) == 0 )
		{
			cout << "( ERROR - Database Is Empty Right Now... )" << endl ;
		}
		else
		{
			printf( "Enter student number to display student's information : ") ;
			fgets( std_number , 9 , stdin ) ;
			stud_number = atoi( std_number ) ;
			i = v->find( stud_number ) ;
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

	void college::delete_student(map<int , student> *v2) 
	{
		char std_number[10] = "" ;
		int stud_number     = 0 ;
		int out = 0 ;
		printf( "Enter student number to delete student's information\n") ;
		
		fgets( std_number , 9 , stdin ) ;
		
		stud_number = atoi( std_number ) ;
		map<int, student>::iterator it;
		it = v2->find( stud_number ) ;
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

	void college::delete_entire_database( map<int,student> *v4)
	{
		v4->clear() ;
		printf("\n\tEntire Database is deleted.\n") ;
		while( 1)
		{
			printf("Press Any Key To Continue.\n") ;
			getch() ;
			break ;
		}
	}

	void college::display_entire_database( map< int , student > *v1)
	{
		if( ( v1->size() ) == 0 )
		{
			printf("( ERROR - Database Contains Nothing To Display...)\n") ;
		}
		else
		{
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

	void college::set_map(map<int , student> v)
	{
		info = v;
	}

	void college::saveToDatabase ( map<int, student> v, char* fileName)
	{
		map<int, student>::iterator it = v.begin();
		fstream output;
		output.open( fileName, ios::out ) ; 
		if ( !output ) 
		{
			cout << "Sorry ... Couldn't open <database> for output\n" ; 
			
		}
		else 
		{
			for ( it = v.begin() ; it != v.end() ; it++ )
			{
				output << (it->second).get_student_number() << endl ;
				output << (it->second).get_fname() << endl ;
				output << (it->second).get_lname() << endl ;
				output << (it->second).get_age() << endl ;
				output << (it->second).get_gender() << endl ;
				output << (it->second).get_program_type() << endl ;
				output << (it->second).get_program_name() << endl ;
				output << (it->second).get_email() << endl <<endl ;
			}
			output.close() ;
		}
	}

	void college::load_from_file( char file_name[] )
	{
		student s ;
		ifstream file;
		string buffer;
		file.open(file_name , std::ifstream::in);
		if(file.is_open())
		{
			while ( getline(file,buffer) )							//Takes the student number from the file.
			{
				s.set_studentnumber(atoi((char*)buffer.c_str())) ;		 

				getline(file,buffer) ;								//Takes the first name from the file.
				s.set_fname((char*)buffer.c_str()) ;

				getline(file,buffer) ;								//Takes the last name from the file->
				s.set_lname((char*)buffer.c_str()) ;

				getline(file,buffer) ;								//Takes the age from the file->
				s.set_age(atoi((char*)buffer.c_str())) ;

				getline(file,buffer) ;								//Takes the gender from the file.
				s.set_gender((char*)buffer.c_str()) ;

				getline(file,buffer) ;								//Takes the program type from the file.
				s.set_program_type((char*)buffer.c_str()) ;

				getline(file,buffer) ;
				s.set_program_name((char*)buffer.c_str()) ;		//Takes the program name from the file.

				getline(file,buffer) ;								//Takes the email from the file.
				s.set_email((char*)buffer.c_str()) ;

				getline(file,buffer) ;								//Takee the blank line which separate each student.

				info.insert(make_pair(s.get_student_number(), s) ) ;
			}
		}
		else
		{
			printf("No such file exists.\n");
			printf("First store data to file.\n");
		}
	}

	map<int , student>* college::get_map()
	{
		return &info ;
	}

	student college::randomStudentcreator( void )
	{
		// random object/student data members
		char randomletter = ' ';
		student *randomStudent = new student;
		char first_name[100] = {"\0"};
		char last_name[100] = {"\0"} ;
		char gender[100] = "\0" ;
		char email[100] = {"\0"} ;
		char program_name[100] = {"\0"};
		char program_type[10] = {"\0"};
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
		length = (rand() % 2000000 + 9999999 );
		student_number = length;

		// randomizing student number
		length = (rand() % 99 + 1);
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
