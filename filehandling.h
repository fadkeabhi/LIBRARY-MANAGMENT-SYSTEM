void LIB::load()
{
    ifstream ifile;
    ifile.open("data.txt");
    string s;
    string delim = "=>";
    int i;

    
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
    for(i = 0; i<stud_count;i++)
    {
        getline(ifile,s);
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
//------------------------------work here        
        getline(ifile,s);

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