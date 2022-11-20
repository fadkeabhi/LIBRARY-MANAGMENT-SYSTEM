
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
        tmp->remaining=tmp->quantity;

        cout<<"Enter UniqueID of book: ";
        cin>>tmp->id;
        cin.ignore(1,'\n');

        //adding node to begining
        tmp->next = book_start;
        book_start=tmp;
        book_count++;


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
   if(book_start==NULL)
    {
        cout<<"No Book to delete\n";
        return;
    }

    int id;
    booknode * tmp, * prev_tmp;
   
    cout<<"Enter book id to delete.";
    cin>>id;

    tmp = book_start;

    do
    {
        prev_tmp=tmp;
        if(tmp->next==NULL)
        {
            cout<<"book not found.\n";
            return;
        }    
        else
            tmp=tmp->next;
    } while (tmp->id!=id && tmp != NULL);


    if(tmp->remaining!=tmp->quantity)
    {
        cout<<"Cannot delete book, all books are not reterned.\n";
        return;
    }
    // actual deleting part
    prev_tmp->next = tmp->next;
    delete tmp;
    book_count--;
}

void LIB::edit_book()
{
    cout<<"edit book from Library.\n";

    booknode * tmp;
    int id,ch_eb,add_quntity;
    cout<<"Enter Book id to be edited: "<<endl;
    cin>>id;
    tmp = book_start;
    while (tmp!=NULL && tmp->id!=id)
    {
        tmp = tmp->next;
    }

    if (tmp==NULL)
    {
        cout<<"*Book not Found*";
        return;
    }
    do
    {
        

        cout<<"\t1.Edit Name of book\n";
        cout<<"\t2.Edit Author of book\n";
        cout<<"\t3.Edit price of book\n";
        cout<<"\t4.Edit quantity of book\n";
        cout<<"\t0.Exit\n";
        cout<<"\n Enter your choice : ";
        cin>>ch_eb; 
        cin.ignore(1,'\n');
        switch (ch_eb)
        {
        case 0:
            cout<<"Exited Edit menu"<<endl;
            break;
        case 1:
            cout<<"Enter Name of Book : ";
            getline(cin,tmp->name);
            break;
        case 2:
            cout<<"Enter Name of author: ";
            getline(cin,tmp->author);
            break;
        case 3:
            cout<<"Enter price of Book: ";
            cin>>tmp->price;
            break;
        case 4:
            cout<<"Enter quantity of Books to add(use -quantity to remove): ";
            cin>>add_quntity;
            tmp->quantity += add_quntity ;  
            break;

        default:
            cout<<"*Wrong Choice*\n";
            break;
        }  
    } while (ch_eb!=0);
}

void LIB::lend_book()
{
    cout<<"lend a book from Library.\n";
    int bid,sid;
    booknode * btmp;
    studentnode * stmp;
    btmp = book_start;
    stmp = stud_start;
    
    cout<<"Enter book id to lend: ";
    cin>>bid;

    while(btmp != NULL && btmp->id!=bid)
    {
        btmp=btmp->next;
    }

    if(btmp==NULL)
    {
        cout<<"Book not found";
        return;
    }

    //check if books available
    if(btmp->remaining==0)
    {
        cout<<"Copy of Book is not avilable.";
        return;
    }

    //check if student have book quata remaining

    
    cout<<"Enter student id to lend: ";
    cin>>sid;
    while(stmp != NULL && stmp->id!=sid)
    {
        stmp=stmp->next;
    }

    if(stmp==NULL)
    {
        cout<<"Student not found";
        return;
    }

    int count;
    count = 0;
    borrowed * count_node;
    count_node = stmp->borrowedbooks;
    
    while(count_node!=NULL)
    {
        count++;
    }
    if(count>2)
    {
        cout<<"Borrow limit reached, Student have already borrowed 3 Books.";
        return;
    }

    //borrow book
    count_node = new borrowed;
    count_node->id = bid;
    count_node->next = NULL;
    
    if(stmp->borrowedbooks == NULL)
    {
        stmp->borrowedbooks = count_node;
    }
    else
    {
        count_node->next = stmp->borrowedbooks;
        stmp->borrowedbooks = count_node;
    }
    btmp->remaining--;
    cout<<"Book issued";

}


//todo
void LIB::return_book()
{
    cout<<"return book to Library.\n";

   
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