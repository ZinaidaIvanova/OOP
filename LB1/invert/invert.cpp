// invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count!\n"
			<< "Usage: invert.exe <matrix file>\n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	if (!inputFile)
	{
		std::cout << "File don't open\n";
		return 1;
	}

	return 0;
}

