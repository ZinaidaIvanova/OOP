// HTML Decode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HTMLDecode.h"

int main()
{
	std::string html;
    std::getline(std::cin, html);
	std::cout << HtmlDecode(html) << "\n";
	return 0;
}

