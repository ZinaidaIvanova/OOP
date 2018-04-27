#include "stdafx.h"
#include "HTMLDecode.h"

const std::vector<Code> encodedCharList = {
	{ "\"" , "&quot;" },
    { "'" , "&apos;" },
    { "<" , "&lt;" },
    { ">" , "&gt;" },
    { "&" , "&amp;" }
};


std::string HtmlDecode(std::string const& html)
{
	size_t pos = 0;
	std::string str = html;
	std::string result;
	for (Code ch : encodedCharList)
	{
		while (pos < str.length())
		{
			size_t foundPos = str.find(ch.HtmlEntity, pos);
			result.append(str, pos, foundPos - pos);
			if (foundPos != std::string::npos)
			{
				result.append(ch.Character);
				pos = foundPos + ch.HtmlEntity.length();
			}
			else
			{
				break;
			}
		}
		pos = 0;
		str.clear();
		str.append(result);
		result.clear();
	}
	return str;
}