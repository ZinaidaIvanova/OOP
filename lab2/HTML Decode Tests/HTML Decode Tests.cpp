#include "stdafx.h"
#include "../HTML Decode/HTMLDecode.h"



TEST_CASE("HtmlDecode should not modify empty string")
{
	std::string html = "";
	std::string result = HtmlDecode(html);
	REQUIRE(html == result);
}


TEST_CASE("HtmlDecode")
{
	REQUIRE("\"" == HtmlDecode("&quot;"));
	REQUIRE("'" == HtmlDecode("&apos;"));
	REQUIRE("<" == HtmlDecode("&lt;"));
	REQUIRE(">" == HtmlDecode("&gt;"));
	REQUIRE("&" == HtmlDecode("&amp;"));
	REQUIRE("cat's food" == HtmlDecode("cat&apos;s food"));
	REQUIRE("cat&aposs food" == HtmlDecode("cat&aposs food"));
	
	std::string html = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	std::string result = HtmlDecode(html);
	std::string htmlDecode = "Cat <says> \"Meow\". M&M's";
	REQUIRE(htmlDecode == result);
}
