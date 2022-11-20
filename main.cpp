#include<iostream>
using namespace std;

#include "class.h"
#include "func_stud.h"
#include "func_book.h"




int main()
{
	LIB obj;
	/*obj.add_student();
	obj.add_student();
	obj.show_all_stud();
	obj.remove_student();
	obj.show_all_stud();
	obj.remove_student();
	obj.show_all_stud();
	obj.remove_student();
	obj.show_all_stud();
	*/
	cout<<"--------------"<<endl;
	obj.add_book();
	cout<<"--------------"<<endl;
	obj.add_book();
	cout<<"--------------"<<endl;
	obj.add_book();
	cout<<"--------------"<<endl;
	obj.add_book();
	cout<<"--------------"<<endl;
	obj.show_all_books();
	cout<<"--------------"<<endl;
	// obj.remove_book();
	// cout<<"--------------"<<endl;
	obj.edit_book();
	obj.show_all_books();


	return 0;
}