void LIB::load()
{
    ifstream ifile;
    ifile.open("data.txt");
    string s;
    string delim = "=>";
    int i,j;

    
    getline(ifile,s);
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

    //load student details
    booknode * bcurr, * bprev;
    for(i = 0; i<book_count;i++)
    {   
        
        getline(ifile,s);
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



}



void LIB::save()
{
    ofstream ofile;
    ofile.open("tmp.txt",ios::trunc);
//saving library details

    ofile<<lib_name<<"=>";
    ofile<<librarian_name<<"=>";
    ofile<<username<<"=>";
    ofile<<password<<"=>";
    ofile<<book_count<<"=>";
    ofile<<stud_count<<"=>"<<endl;
    


//saving students details

    borrowed * borrow;

    studentnode * tmp;
    tmp = stud_start;
    while(tmp!=NULL)
    {
        ofile<<tmp->id<<"=>"<<tmp->name<<"=>"<<tmp->address<<"=>" <<tmp->clas<<"=>"<<tmp->div<<"=>" <<tmp->contact<<"=>" <<endl;
        borrow =tmp->borrowedbooks ;
        while(borrow!=NULL)
        {
            ofile<<borrow->id<<endl;
            borrow=borrow->next;
        }
        ofile<<"NULL"<<endl;
        
        tmp=tmp->next;
    }
    
    
    //saving books
    booknode * tmp1;
    tmp1 = book_start;
    while(tmp1!=NULL)
    {
        ofile<<tmp1->id<<"=>" <<tmp1->name<<"=>" <<tmp1->author<<"=>" <<tmp1->price<<"=>" <<tmp1->quantity<<"=>" <<tmp1->remaining<<"=>" <<endl;
        borrow =tmp1->borrowers ;
        while(borrow!=NULL)
        {
            ofile<<borrow->id<<endl;
            borrow=borrow->next;
        }
        ofile<<"NULL"<<endl;
        
        tmp1=tmp1->next;
    }

    ofile.close();
    remove("data.txt");
    if (rename("tmp.txt", "data.txt") != 0)
		perror("error saving");
	else
		cout << "Done saving.";



}