class LIB
{
	string lib_name;
	string librarian_name;
	string username;
	string password;

	int book_count,stud_count;

	struct booknode
	{
		string name;
		string author;
		float price;
		int quantity;
        int remaining;
		int id;
		booknode * next;
	}*book_start;

	struct borrowed
	{
		int id;
		borrowed * next;
	};

	struct studentnode
	{
		int id;
		string name;
		string address;
		string clas;
		string div;
		long long int contact;
		borrowed * borrowedbooks;
		studentnode * next;
	}*stud_start;


	public:
    LIB()
    {
        book_count = 0;
        stud_count = 0;
        book_start = NULL;
        stud_start = NULL;
    }

	//students section
	void add_student(); //done
	void remove_student(); //done
	void edit_student(); //done
	void stud_details();
	void show_all_stud(); //done

	//books section
	void add_book(); //done
	void remove_book(); //done
	void edit_book(); //done
	void lend_book(); //done
	void return_book();
	void show_all_books(); //done
	
	//menu section
	void menu();
};