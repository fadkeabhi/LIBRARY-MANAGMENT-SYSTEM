void LIB::add_student()
{
    cout<<"Adding new student.\n";

    studentnode * tmp;
    tmp = new studentnode;
    if(!tmp == 0)
    {
        cout<<"Enter Student Name: ";
        getline(cin,tmp->name);
        
        cout<<"Enter Permanat address: ";
        getline(cin,tmp->address);

        cout<<"Enter Student Class: ";
        cin>>tmp->clas;

        cout<<"Enter Student Div: ";
        cin>>tmp->div;

        cout<<"Enter Student contact number: ";
        cin>>tmp->contact;
        cin.ignore(1,'\n');

        tmp->borrowedbooks = NULL;

        if(stud_start==NULL)
        {
            tmp->id=1;
        }
        else
        {
            tmp->id=stud_start->id+1;
        }

        //adding node to begining
        tmp->next = stud_start;
        stud_start=tmp;    


            // cout<<tmp->id<<" "<<tmp->name<<" "<<tmp->address<<" " <<tmp->clas<<" "<<endl;
            // cout<<tmp->div<<" " <<tmp->contact<<" " ;
    }

    else
    {
        cout<<"Memory limit exceded";
    }
   
}



void LIB::show_all_stud()
{
    if(stud_start==NULL)
    {
        cout<<"No student to display";
    }
    else
    {
        studentnode * tmp;
        tmp = stud_start;
        while(tmp!=NULL)
        {
            cout<<tmp->id<<" "<<tmp->name<<" "<<tmp->address<<" " <<tmp->clas<<" "<<tmp->div<<" " <<tmp->contact<<" "<<endl;
            tmp=tmp->next;
        }
    }
}

void LIB::remove_student()
{
    if(stud_start==NULL)
    {
        cout<<"No student to delete\n";
        return;
    }

    int id;
    studentnode * tmp, * prev_tmp;
   
    cout<<"Enter student id to delete.";
    cin>>id;

    //is node at first place
    if(stud_start->id == id)
    {
        //check if student have borrowed books
        if(stud_start->borrowedbooks!=NULL)
        {
            cout<<"Cannot delete, Student have borrowed books.\n";
            return;
        }
        tmp = stud_start->next;
        cout<<"Student deleted.\n";
        delete stud_start;
        stud_start = tmp;
        return;
    }

    tmp = stud_start;

    do
    {
        
        prev_tmp=tmp;
        if(tmp->next==NULL)
        {
            cout<<"Student not found.\n";
            return;
        }    
        else
            tmp=tmp->next;
    } while (tmp->id!=id && tmp != NULL);


    // actual deleting part
    prev_tmp->next = tmp->next;
    delete tmp;

}



