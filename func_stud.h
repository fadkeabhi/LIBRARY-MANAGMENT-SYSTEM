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