void LIB::load()
{
    ifstream ifile;
    ifile.open("data.txt");

    if(!ifile)
    {
        cout<<"New installation detected.\n";
        cout<<"Enter Library name  : ";
        getline(cin,lib_name);
        cout<<"Enter Librarian name: ";
        getline(cin,librarian_name);
        cout<<"Enter Username: ";
        getline(cin,username);
        cout<<"Enter password: ";
        getline(cin,password);
        return;
    }

    char restore;
    do
    {
        cout<<"Would you like to restore old data. y/n :";
        cin>>restore;
        if(restore=='n' || restore=='N')
        {
            cin.ignore(1,'\n');
            cout<<"Enter Library name  : ";
            getline(cin,lib_name);
            cout<<"Enter Librarian name: ";
            getline(cin,librarian_name);
            cout<<"Enter Username: ";
            getline(cin,username);
            cout<<"Enter password: ";
            getline(cin,password);
            return;
        }
        else if(restore!='y' &&  restore!='Y')
            cout<<"Wrong choise select option again.\n";
        
    } while (restore!='y' &&  restore!='Y');

    //password validation
    cout<<"Enter your password: ";
    cin>>password;
    string s;
    getline(ifile,s);
    if(password!=decrypt(s,"This is an master password"))
    {
        cout<<"password is incorrect.";
        exit(0);
    }


    cout<<"Restoring data...\n";
 
    
    string delim = "=>";
    int i,j;

    
    getline(ifile,s);
    s = decrypt(s,password);
    string arr[6];
    auto start = 0U;
    auto end = s.find(delim);
    i = 0;
    while (end != std::string::npos)
    {
        arr[i] = s.substr(start, end - start);
        start = end + delim.length();
        end = s.find(delim, start);
        i++;
    }

    lib_name = arr[0];
    librarian_name = arr[1];
    username = arr[2];
    password = arr[3];
    book_count = stoi(arr[4]);
    stud_count = stoi(arr[5]);


    //load student details
    studentnode * scurr, * sprev;
    borrowed * borr;
    for(i = 0; i<stud_count;i++)
    {   
        
        getline(ifile,s);
        s = decrypt(s,password);
        auto start = 0U;
        auto end = s.find(delim);
        j = 0;
        while (end != std::string::npos)
        {
            arr[j] = s.substr(start, end - start);
            start = end + delim.length();
            end = s.find(delim, start);
            j++;
        }
 
        scurr = new studentnode;
        scurr->next=NULL;
        scurr->id=stoi(arr[0]);
        scurr->name=arr[1];
        scurr->address=arr[2];
        scurr->clas=arr[3];
        scurr->div=arr[4];
        scurr->contact=stoll(arr[5]);
        scurr->borrowedbooks=NULL;

        if(stud_start==NULL)
        {
            stud_start = scurr;
        }
        else
        {
            sprev->next=scurr;
        }
        sprev=scurr;

        while(true)
        {
            getline(ifile,s);
            s = decrypt(s,password);
            
            if(s=="NULL")
            {
                break;
            }

            borr = new borrowed;
            borr->id=stoi(s);
            borr->next=scurr->borrowedbooks;
            scurr->borrowedbooks=borr;
        }

    }

    //load book details
    booknode * bcurr, * bprev;
    for(i = 0; i<book_count;i++)
    {   
        
        getline(ifile,s);
        s = decrypt(s,password);
        
        auto start = 0U;
        auto end = s.find(delim);
        j = 0;
        while (end != std::string::npos)
        {
            arr[j] = s.substr(start, end - start);
            start = end + delim.length();
            end = s.find(delim, start);
            j++;
        }
 
        bcurr = new booknode;
        bcurr->next=NULL;
        bcurr->id=stoi(arr[0]);
        bcurr->name=arr[1];
        bcurr->author=arr[2];
        bcurr->price=stof(arr[3]);
        bcurr->quantity=stoi(arr[4]);
        bcurr->remaining=stoi(arr[5]);
        bcurr->borrowers=NULL;


        if(book_start==NULL)
        {
            book_start = bcurr;
        }
        else
        {
            bprev->next=bcurr;
        }
        bprev=bcurr;

        while(true)
        {
            getline(ifile,s);
            s = decrypt(s,password);
            
            if(s=="NULL")
            {
                break;
            }

            borr = new borrowed;
            borr->id=stoi(s);
            borr->next=bcurr->borrowers;
            bcurr->borrowers=borr;
        }

    }
    ifile.close();



}



void LIB::save()
{
    ofstream ofile;
    string text;
    ofile.open("tmp.txt",ios::trunc);


    //saving password
    text = password;
    ofile<<encrypt(text,"This is an master password")<<endl;

//saving library details
    text=lib_name+"=>"+librarian_name+"=>"+username+"=>"+password+"=>"+to_string(book_count)+"=>"+to_string(stud_count)+"=>";
    ofile<<encrypt(text,password)<<endl;
    


//saving students details

    borrowed * borrow;

    studentnode * tmp;
    tmp = stud_start;
    while(tmp!=NULL)
    {
        text = to_string(tmp->id)+"=>"+tmp->name+"=>"+tmp->address+"=>" +tmp->clas+"=>"+tmp->div+"=>" +to_string(tmp->contact)+"=>";
        ofile<<encrypt(text,password)<<endl;

        borrow =tmp->borrowedbooks ;
        while(borrow!=NULL)
        {
            ofile<<encrypt(to_string(borrow->id),password)<<endl;
            borrow=borrow->next;
        }
        ofile<<encrypt("NULL",password)<<endl;
        
        tmp=tmp->next;
    }
    
    
    //saving books
    booknode * tmp1;
    tmp1 = book_start;
    while(tmp1!=NULL)
    {
        text=to_string(tmp1->id)+"=>"+tmp1->name+"=>"+tmp1->author+"=>"+to_string(tmp1->price)+"=>"+to_string(tmp1->quantity)+"=>"+to_string(tmp1->remaining)+"=>";
        ofile<<encrypt(text,password)<<endl;        
        borrow =tmp1->borrowers;
        while(borrow!=NULL)
        {
            ofile<<encrypt(to_string(borrow->id),password)<<endl;
            borrow=borrow->next;
        }
        ofile<<encrypt("NULL",password)<<endl;
        
        tmp1=tmp1->next;
    }

    ofile.close();
    remove("data.txt");
    if (rename("tmp.txt", "data.txt") != 0)
		perror("error saving");
	else
		cout << "Done saving."<<endl;
        
    cout<<"\nPress Enter to continue.";
     getch();



}