// invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

typedef float squareMatrix2[2][2];
typedef float squareMatrix3[3][3];

bool IsFileOpen(std::string inputFile)
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

float Det2(squareMatrix2 matrix)
{
	float temp;
	temp = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	return temp;
}

void InitSquareMatrix2(squareMatrix2 matrix)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void InitSquareMatrix3(squareMatrix3 matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

float GetAlgebraicComplement(squareMatrix2 minor, int i, int j)
{
	return std::pow(-1, i + j) * Det2(minor);
}

void GetComplementaryMinor(squareMatrix3 matrix, squareMatrix2 minor, int i, int j)
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

float Det3(squareMatrix3 matrix)
{
	int i = 0;
	squareMatrix2 minor;
	InitSquareMatrix2(minor);
	float result = 0;
	for (size_t j = 0; j < 3; j++)
	{
		GetComplementaryMinor(matrix, minor, i, j);
		result += matrix[i][j] * GetAlgebraicComplement(minor, i, j);
	}
	return result;
}

void GetInvertMatrix(squareMatrix3 matrix, squareMatrix3 invertMatrix, bool& isDegenerateMatrix)
{
	squareMatrix2 minor;
	InitSquareMatrix2(minor);
	isDegenerateMatrix = (abs(Det3(matrix)) <= FLT_EPSILON);
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
}

void GetMatrix(const std::string& input, squareMatrix3 inputMatrix, bool& matrixError)
{
	std::ifstream inFile;
	inFile.open(input);
	std::string iStr;
	char delimeter = ' ';
	int i = 0;
	int j = 0;
	size_t pos = 0;
	float getNum = 0;
	while (std::getline(inFile, iStr))
	{
		while (!iStr.empty())
		{
			pos = iStr.find(delimeter);
			if (pos > 0) {
				if (pos < std::string::npos)
				{
					getNum = std::stof(iStr.substr(0, pos));
				}
				else
				{
					getNum = std::stof(iStr);
				}
			}
			if ((i < 3) && (j < 3))
			{
				inputMatrix[i][j] = getNum;
			}
			if (pos < std::string::npos)
			{
				iStr.erase(0, pos+1);
			}
			else
			{
				iStr.clear();
			}
			if (pos != 0)
			{
				j++;
			}
		}
		if (j != 3)
		{
			matrixError = true;
		}
		j = 0;
		i++;
	}

	if (i != 3)
	{
		matrixError = true;
	}
}

void PrintMatrix(squareMatrix3 matrix)
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

	if (!IsFileOpen(inputFile))
	{
		std::cout << "File don't open\n";
		return 1;
	}

	squareMatrix3 matrix, invertMatrix;
	InitSquareMatrix3(invertMatrix);
	bool matrixError = false;
	bool isDegenerateMatrix = false;
	GetMatrix(inputFile, matrix, matrixError);

	if (matrixError)
	{
		std::cout << "File contains invalid data\n";
		return 1;
	}

	GetInvertMatrix(matrix, invertMatrix, isDegenerateMatrix);

	if (isDegenerateMatrix)
	{
		std::cout << "Input matrix is degenerate matrix\n";
		return 1;
	}

	PrintMatrix(invertMatrix);

	return 0;
}

