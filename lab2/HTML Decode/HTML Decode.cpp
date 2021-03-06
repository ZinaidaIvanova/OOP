#include "stdafx.h"
#include "HTMLDecode.h"

const std::vector<Code> encodedCharList = {
	{ "\"" , "&quot;" },
	{ "'" , "&apos;" },
	{ "<" , "&lt;" },
	{ ">" , "&gt;" },
	{ "&" , "&amp;" }
};


std::string Replace(const std::string& inputString, Code& encodedCharListElement)
{
	size_t pos = 0;
	std::string result;
	while (pos < inputString.length())
	{
		size_t foundPos = inputString.find(encodedCharListElement.HtmlEntity, pos);
		result.append(inputString, pos, foundPos - pos);
		if (foundPos != std::string::npos)
		{
			result.append(encodedCharListElement.Character);
			pos = foundPos + encodedCharListElement.HtmlEntity.length();
		}
		else
		{
			break;
		}
	}
	return result;
}

std::string HtmlDecode(const std::string& html)
{
	std::string str = html;
	std::string result;
	for (Code ch : encodedCharList)
	{
		result = Replace(str, ch);
		std::swap(result, str);
	}
	return str;
}