// LB1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool isFileOpen(std::string inputFile)
{
	std::ifstream inFile;
	bool temp = true;
	inFile.open(inputFile);
	if (!inFile)
	{
		temp = false;
	}
	return temp;
}

bool PrintLineNumbersContainingText(const std::string& inputFileName, const std::string& stringToSearch)
{
	bool wasFound = false;
	std::ifstream inFile;
	inFile.open(inputFileName);
	std::string line;
	size_t lineNumber = 0;
	while (std::getline(inFile, line))
	{
		lineNumber++;
		if (line.find(stringToSearch) < std::string::npos)
		{
			std::cout << lineNumber << "\n";
			wasFound = true;
		}
	}

	if (!wasFound) {
		std::cout << "Text not found\n";
	}
	return wasFound;
}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count!\n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}
	
	std::string inputFileName = argv[1];
	std::string stringToSearch = argv[2];
	
	if (!isFileOpen(inputFileName))
	{
		std::cout << "File don't open\n";
		return 1;
	}

	if (!PrintLineNumbersContainingText(inputFileName, stringToSearch))
	{
		return 1;
	}

	return 0;
}