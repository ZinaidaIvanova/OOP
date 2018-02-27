// LB1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void SearchString(std::istream& input, std::string inputString, bool& findInd)
{
	std::string line;
	size_t i = 0;
	size_t pos = 0;
	size_t result;
	while (std::getline(input, line))
	{
		i++;
		result = line.find(inputString, pos);
		if (result < line.length())
		{
			std::cout << i << "\n";
			findInd = true;
		}
	}

	if (!findInd) {
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
	bool findInd = false;

	if (!inputFile)
	{
		std::cout << "File don't open\n";
		return 1;
	}

	SearchString(inputFile, inputString, findInd);

	if (!findInd)
	{
		return 1;
	}

	return 0;
}