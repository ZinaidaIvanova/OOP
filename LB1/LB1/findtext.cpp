// LB1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count!\n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}
	
	return 0;
}