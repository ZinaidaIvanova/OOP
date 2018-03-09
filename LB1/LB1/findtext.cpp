// LB1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void SearchString(std::istream& input, const std::string& inputString, bool& wasFound)
{
	std::string line;
	size_t lineNumber = 0;
	while (std::getline(input, line))
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
	
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	std::string inputString = argv[2];
	bool wasFound = false;

	if (!inputFile)
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