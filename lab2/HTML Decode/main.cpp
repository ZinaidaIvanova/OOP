// HTML Decode.cpp: ���������� ����� ����� ��� ����������� ����������.
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

