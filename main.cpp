#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>


using namespace std;

#include "class.h"
#include "func_stud.h"
#include "func_book.h"
#include "menu.h"
#include "fileecryption.h"
#include "filehandling.h"


int main()
{
	LIB obj;

	obj.load();
	obj.menu();

	return 0;
}