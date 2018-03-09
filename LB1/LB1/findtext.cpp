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

void SearchString(const std::string& inputFile, const std::string& inputString, bool& wasFound)
{
	std::ifstream inFile;
	inFile.open(inputFile);
	std::string line;
	size_t lineNumber = 0;
	while (std::getline(inFile, line))
	{
		lineNumber++;
		if (line.find(inputString) < std::string::npos)
		{
			std::cout << lineNumber << "\n";
			wasFound = true;
		}
	}

	if (!wasFound) {
		std::cout << "Text not found\n";
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
	
	std::string inputFile = argv[1];
	std::string inputString = argv[2];
	bool wasFound = false;

	if (!isFileOpen(inputFile))
	{
		std::cout << "File don't open\n";
		return 1;
	}

	SearchString(inputFile, inputString, wasFound);

	if (!wasFound)
	{
		return 1;
	}

	return 0;
}