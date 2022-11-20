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
		int price;
		int quantity;
        int remaining;
		int id;
		booknode * next;
	}*book_start;

	struct borrowed_stud
	{
		int id;
		borrowed_stud * next;
	};

	struct studentnode
	{
		int id;
		string name;
		string address;
		string clas;
		string div;
		long contact;
		borrowed_stud * borrowedbooks;
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
	void add_student();
	void remove_student();
	void edit_student();
	void stud_details();
	void show_all_stud();

	
};