// radix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char * argv[])
{
	/*Проверка количества переданных аргументов*/
	if (argc != 4)
	{
		std::cout << "Invalid argument count!\n" << "Usage: radix.exe <source notation> <destination notation> <value>\n";
		return 1;
	}

	//if (argv[1] )

	/*Проверка корректности переданных аргументов*/
    return 0;
}

