#include<iostream>
using namespace std;

#include "class.h"
#include "func_stud.h"
#include "func_book.h"




int main()
{
	LIB obj;
	// obj.add_student();
	// obj.add_student();
	// obj.show_all_stud();
	obj.add_book();
	obj.add_book();
	obj.add_book();
	obj.remove_book();
	obj.edit_book();
	obj.show_all_books();


	return 0;
}