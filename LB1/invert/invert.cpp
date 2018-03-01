// invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void GetMatrix(std::istream& input, float inputMatrix[3][3], bool& matrixError)
{
	std::string inputString;
	int i = 0;
	while (std::getline(input, inputString))
	{
		i++;
	}

	if (i != 3)
	{
		matrixError = true;
	}
}



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

	float matrix[3][3];
	bool matrixError = false;
	GetMatrix(inputFile, matrix, matrixError);

	if (matrixError)
	{
		std::cout << "File contains invalid data\n";
		return 1;
	}

	return 0;
}

