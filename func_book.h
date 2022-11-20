//all book node related functions
/*struct booknode
	{
		string name;
		string author;
		int price;
		int quantity;
        int remaining;
		int id;
		booknode * next;
	}*book_start;*/

void LIB::add_book()
{
    cout<<"Adding new book to Library.\n";

    booknode * tmp;
    tmp = new booknode;
    if(!tmp == 0)
    {
        cout<<"Enter Book Name: ";
        getline(cin,tmp->name);
        
        cout<<"Enter author name: ";
        getline(cin,tmp->author);

        cout<<"Enter price of book: ";
        cin>>tmp->price;

        cout<<"Enter Book Quantity: ";
        cin>>tmp->quantity;

        cout<<"Enter UniqueID of book: ";
        cin>>tmp->id;
        cin.ignore(1,'\n');

        //adding node to begining
        tmp->next = book_start;
        book_start=tmp;    


            // cout<<tmp->id<<" "<<tmp->name<<" "<<tmp->address<<" " <<tmp->clas<<" "<<endl;
            // cout<<tmp->div<<" " <<tmp->contact<<" " ;
    }
    
    else
    {
        cout<<"Memory limit exceded";
    }
   
}

void LIB::remove_book()
{
   
}

void LIB::edit_book()
{
    cout<<"edit book from Library.\n";

    booknode * tmp;
    tmp = new booknode;
    if(!tmp == 0)
    {
        cout<<"Enter Book Name: ";
        getline(cin,tmp->name);
        
        cout<<"Enter author name: ";
        getline(cin,tmp->author);

        cout<<"Enter price of book: ";
        cin>>tmp->price;

        cout<<"Enter Book Quantity: ";
        cin>>tmp->quantity;

        cout<<"Enter UniqueID of book: ";
        cin>>tmp->id;
        cin.ignore(1,'\n');

        //adding node to begining
        tmp->next = book_start;
        book_start=tmp;    


            // cout<<tmp->id<<" "<<tmp->name<<" "<<tmp->address<<" " <<tmp->clas<<" "<<endl;
            // cout<<tmp->div<<" " <<tmp->contact<<" " ;
    }
    
    else
    {
        cout<<"Memory limit exceded";
    }
   
}

void LIB::lend_book()
{
    cout<<"lend a book from Library.\n";

    booknode * tmp;
    tmp = new booknode;
    if(!tmp == 0)
    {
        cout<<"Enter Book Name: ";
        getline(cin,tmp->name);
        
        cout<<"Enter author name: ";
        getline(cin,tmp->author);

        cout<<"Enter UniqueID of book: ";
        cin>>tmp->id;
        cin.ignore(1,'\n');

        //adding node to begining
        tmp->next = book_start;
        book_start=tmp;    

    }
    
    else
    {
        cout<<"Memory limit exceded";
    }
   
}

void LIB::return_book()
{
    cout<<"return book to Library.\n";

    booknode * tmp;
    tmp = new booknode;
    if(!tmp == 0)
    {
        cout<<"Enter Book Name: ";
        getline(cin,tmp->name);
        
        cout<<"Enter author name: ";
        getline(cin,tmp->author);

        cout<<"Enter UniqueID of book: ";
        cin>>tmp->id;
        cin.ignore(1,'\n');

        //adding node to begining
        tmp->next = book_start;
        book_start=tmp;    

    }
    
    else
    {
        cout<<"Memory limit exceded";
    }
   
}

void LIB::show_all_books()
{
    if(book_start==NULL)
    {
        cout<<"No Book to display";
    }
    else
    {
        booknode * tmp;
        tmp = book_start;
        while(tmp!=NULL)
        {
            cout<<tmp->name<<" "<<tmp->author<<" "<<tmp->price<<" " <<tmp->quantity<<" "<<tmp->remaining<<" " <<tmp->id<<" "<<endl;
            tmp=tmp->next;
        }
    }
}