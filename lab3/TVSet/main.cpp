//main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TVSet.h"
#include "CRemoteControl.h"


int main()
{
	CTVSet tv;
	CRemoteControl remoteControl(tv, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}
	return 0;
}

                           