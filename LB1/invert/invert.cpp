// invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using SquareMatrix2 = std::array<std::array<float, 2>, 2>;
using SquareMatrix3 = std::array<std::array<float, 3>, 3>;


float Det2(SquareMatrix2 matrix)
{
	float temp;
	temp = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	return temp;
}

float GetAlgebraicComplement(SquareMatrix2 minor, int i, int j)
{
	return static_cast<float>(std::pow(-1, i + j) * Det2(minor));
}

void GetComplementaryMinor(SquareMatrix3 matrix, SquareMatrix2 &minor, int i, int j)
{
	int firstMinorInd;
	int secondMinorInd;
	for (int k = 0; k < 2; k++)
	{
		for (int l = 0; l < 2; l++)
		{
			(k >= i) ? (firstMinorInd = k + 1) : (firstMinorInd = k);			
			(l >= j) ? (secondMinorInd = l + 1) : (secondMinorInd = l);
			minor[k][l] = matrix[firstMinorInd][secondMinorInd];
		}
	}
}


float Det3(SquareMatrix3 matrix)
{
	int i = 0;
	SquareMatrix2 minor = { 0, 0, 0, 0 };
	float result = 0;
	for (size_t j = 0; j < 3; j++)
	{
		GetComplementaryMinor(matrix, minor, i, j);
		result += matrix[i][j] * GetAlgebraicComplement(minor, i, j);
	}
	return result;
}

bool TryInvertMatrix(SquareMatrix3 matrix, SquareMatrix3 &invertMatrix)
{
	SquareMatrix2 minor = { 0, 0, 0, 0 };
	bool isDegenerateMatrix = (abs(Det3(matrix)) <= FLT_EPSILON);
	if (!isDegenerateMatrix)
	{
		float coef = 1 / Det3(matrix);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				GetComplementaryMinor(matrix, minor, i, j);
				invertMatrix[j][i] = coef * GetAlgebraicComplement(minor, i, j);
			}
		}
	}
	return (!isDegenerateMatrix);
}

bool ReadMatrix(const std::string& inputFileName, SquareMatrix3 &inputMatrix)
{
	bool wasMatrixReading = true;
	std::ifstream inFile;
	inFile.open(inputFileName);

	if (!inFile)
	{
		std::cout << "File don't open\n";
		return false;
	}

	std::string line;
	for (int i = 0; i < 3; i++)
	{
		if (!std::getline(inFile, line))
		{
			wasMatrixReading = false;
			std::cout << "Invalid line count!\n" << "Must be 3 line";
		}
		std::istringstream lineStream(line);
		if (!(lineStream >> inputMatrix[i][0] >> inputMatrix[i][1] >> inputMatrix[i][2]))
		{
			wasMatrixReading = false;
			std::cout << "Invalid column count!\n" << "Must be 3 column";
		}
	}

	return wasMatrixReading;
}

void PrintMatrix(SquareMatrix3 matrix)
{
	std::cout.setf(std::ios::dec);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << std::fixed << std::setprecision(3) << matrix[i][j] << "     ";
		}
		std::cout << "\n";
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

	std::string inputFile = argv[1];	
	SquareMatrix3 matrix = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	SquareMatrix3 invertMatrix = matrix;

	if (!ReadMatrix(argv[1], matrix))
	{
		return 1;
	}
	
	if (!TryInvertMatrix(matrix, invertMatrix))
	{
		std::cout << "Input matrix is degenerate matrix\n";
		return 1;
	}

	PrintMatrix(invertMatrix);

	return 0;
}

