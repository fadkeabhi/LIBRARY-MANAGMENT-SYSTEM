void LIB::add_student()
{
    cout<<"***************************************"<<endl;
    cout<<"Adding new Student.\n";

    studentnode * tmp;
    tmp = new studentnode;
    if(!tmp == 0)
    {
        cout<<"Enter Student Name:           ";
        getline(cin,tmp->name);
        
        cout<<"Enter Permanat Address:       ";
        getline(cin,tmp->address);

        cout<<"Enter Student Class:          ";
        cin>>tmp->clas;

        cout<<"Enter Student Div:            ";
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

        stud_count++;
        cout<<"Student details added accessfully.\n";
        cout<<"The student ID is "<<tmp->id ;


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
        cout<<"No Student to display";
    }
    else
    {
        studentnode * tmp;
        tmp = stud_start;
        while(tmp!=NULL)
        {
            // cout<<tmp->id<<" "<<tmp->name<<" "<<tmp->address<<" " <<tmp->clas<<" "<<tmp->div<<" " <<tmp->contact<<" "<<endl;
                cout<<"************************************************************"<<endl;
                cout<<"Student Name :     "<<tmp->name<<endl;
                cout<<"Student ADDRESS :  "<<tmp->address<<endl;
                cout<<"Student CLASS :    "<<tmp->clas<<endl;
                cout<<"Student DIV :      "<<tmp->div<<endl;
                cout<<"Student Contact :  "<<tmp->contact<<endl;
            tmp=tmp->next;
        }
    }
    
}

void LIB::remove_student()
{
    if(stud_start==NULL)
    {
        cout<<"No Student to delete\n";
        return;
    }

    int id;
    studentnode * tmp, * prev_tmp;
   
    cout<<"Enter Student ID to delete.";
    cin>>id;

    //is node at first place
    if(stud_start->id == id)
    {
        //check if student have borrowed books
        if(stud_start->borrowedbooks!=NULL)
        {
            cout<<"Cannot delete, Student have borrowed Books.\n";
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
    if(tmp->borrowedbooks != NULL)
        {
            cout<<"Cannot delete, Student have borrowed books.\n";
            return;
        }
    prev_tmp->next = tmp->next;
    delete tmp;
    stud_count--;
}





void LIB::edit_student()
{
    int id,ch_es;
    cout<<"Enter Student ID to edit: ";
    cin>>id;
    studentnode * tmp;
    tmp = stud_start;
    while(tmp!=NULL && tmp->id!=id)
    {
        tmp=tmp->next;
    }

    if(tmp==NULL)
    {
        cout<<"Student not found";
        return;
    }

    do
    {
        system("CLS");
        cout<<"***********************************************************"<<endl;
        cout<<"Student Name :     "<<tmp->name<<endl;
        cout<<"Student ADDRESS :  "<<tmp->address<<endl;
        cout<<"Student CLASS :    "<<tmp->clas<<endl;
        cout<<"Student DIV :      "<<tmp->div<<endl;
        cout<<"Student contact :  "<<tmp->contact<<endl;

        cout<<"*******************************************************************"<<endl;
        cout<<"\t1. Edit Name\n";
        cout<<"\t2. Edit address\n";
        cout<<"\t3. Edit class\n";
        cout<<"\t4. Edit div\n";
        cout<<"\t5. Edit contact\n";
        cout<<"\t0. Exit edit menu\n";
        cout<<"Enter your choise: ";
        cin>>ch_es;
        cin.ignore(1,'\n');
        switch(ch_es)
        {
            case 1:
                cout<<"Enter NAME: ";
                getline(cin,tmp->name);
                break;
            case 2:
                cout<<"Enter ADDRESS: ";
                getline(cin,tmp->address);
                break;
            case 3:
                cout<<"Enter CLASS: ";
                cin>>tmp->clas;
                break;
            case 4:
                cout<<"Enter DIV: ";
                cin>>tmp->div;
                break;
            case 5:
                cout<<"Enter Contact: ";
                cin>>tmp->contact;
                break;
            case 0:
                cout<<"Exiting Edit Menu...";
                break;
            default:
                cout<<"wrong choise ";
        }
        
    } while (ch_es!=0);
}

void LIB::stud_details()
{
    int id;
    cout<<"Enter Student ID: ";
    cin>>id;
    studentnode * tmp;
    tmp = stud_start;
    while(tmp!=NULL && tmp->id!=id)
    {
        tmp=tmp->next;
    }

    if(tmp==NULL)
    {
        cout<<"Student not found";
        return;
    }
    cout<<"***************************************************"<<endl;
    cout<<"Student Name :     "<<tmp->name<<endl;
    cout<<"Student ADDRESS :  "<<tmp->address<<endl;
    cout<<"Student CLASS :    "<<tmp->clas<<endl;
    cout<<"Student DIV :      "<<tmp->div<<endl;
    cout<<"Student Contact :  "<<tmp->contact<<endl;

    if(tmp->borrowedbooks==NULL)
    {
        cout<<"No Books borrowed";
        return;
    }
    cout<<"Borrowed Book ID's : ";
    borrowed * tmp1;
    tmp1 = tmp->borrowedbooks;
    while(tmp1!=NULL)
    {
        cout<<tmp1->id<<" ";
        tmp1=tmp1->next;
    }

}