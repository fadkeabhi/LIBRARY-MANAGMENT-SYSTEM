void LIB::menu()
{

    int ch;
    do
    {
        system("CLS");
        cout << "***** WELCOME TO " << lib_name << " ******" << endl;
        cout << "\t1. Student Details.\n";
        cout << "\t2. Book section. \n";
        cout << "\t3. Save Data. \n";
        cout << "\t0. Exit. \n";
        cout<<"Enter Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            stud_menu();
            break;
        case 2:
            book_menu();
            break;
        case 3:
            save();
            break;
        case 0:
            save();
            exit(0);
        default:
            cout << "*Wrong Choice*" << endl;
            break;
        }
    } while (ch != 0);
}


void LIB::stud_menu()
{
    int ch1;
    bool frommenu=1;
    do
    {
        if(frommenu==0)
        {
            cout<<"\nPress Enter to continue.";
            getch();
        }
        frommenu=0;
        
        system("CLS");
        cout << "***STUDENT SECTION***" << endl;
        cout << "\t1. Add Student Data.\n";
        cout << "\t2. Delete Student Data.\n ";
        cout << "\t3. Edit Student Data.\n ";
        cout << "\t4. View Student Data.\n " ;
        cout << "\t5. Show all Student Data.\n " ;
        cout << "\t0. Exit.\n " ;
        cout<<"Enter Choice: ";
        cin >> ch1;
        cin.ignore(1,'\n');
        system("CLS");
        switch (ch1)
        {
        case 1:
            add_student();
            break;
        case 2:
            remove_student();
            break;
        case 3:
            edit_student();
            break;
        case 4:
            stud_details();
            break;
        case 5:
            show_all_stud();
            break;
        case 0:
            cout << "Exiting to main menu " << endl;
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
        }

    } while (ch1 != 0);
}
void LIB::book_menu()
{
    int ch2;

    bool frommenu=1;
    do
    {
        if(frommenu==0)
        {
            cout<<"\nPress Enter to continue.";
            getch();
        }
        frommenu=0;
        
        system("CLS");
        cout << "***BOOK SECTION***" << endl;
        cout << "\t1. Add Book Data.\n";
        cout << "\t2. Remove Book Data.\n ";
        cout << "\t3. Edit Book Data.\n ";
        cout << "\t4. View Book Data.\n " ;
        cout << "\t5. Show all Book Data.\n " ;
        cout << "\t6. Lend Book.\n " ;
        cout << "\t7. Return Book.\n " ;
        cout << "\t0. Exit.\n " ;
        cout<<"Enter Choice: ";
        cin >> ch2;
        cin.ignore(1,'\n');
        system("CLS");
        switch (ch2)
        {
        case 1:
            add_book();
            break;
        case 2:
            remove_book();
            break;
        case 3:
            edit_book();
            break;
        case 4:
            book_details();
            break;
        case 5:
            show_all_books();
            break;
        case 6:
            lend_book();
            break;
        case 7:
            return_book();
            break;
        case 0:
            cout << "Exiting to main menu " << endl;
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
        }

    } while (ch2 != 0);
}