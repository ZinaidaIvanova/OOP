#pragma once

#include <string>
#include <vector>
#include <array>
#include <algorithm>

struct Code
{
	std::string Character;
	std::string HtmlEntity;
};

std::string HtmlDecode(std::string const& html);

