// LB1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void SearchString(std::istream input, std::string inputString, bool findInd)
{
	std::getline;
	while (std::getline())
	{

	}
}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count!\n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}
	
	std::ifstream inputFile;
	inputFile.open(argv[1]);

	if (!inputFile)
	{
		std::cout << "File don't open\n";
		return 1;
	}

	std::string inputString = argv[2];
	bool findInd = false;

	

	return 0;
}