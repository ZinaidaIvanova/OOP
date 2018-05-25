#include "stdafx.h"
#include "../TVSet/TVSet.h"
#include "../TVSet/CRemoteControl.h"
#include <sstream>

void VerifyCommandHandling(CTVSet &tv, const std::string &command, const std::string &expectedOutput)
{
	std::stringstream output, input;
	output = std::stringstream();
	input = std::stringstream();
	CRemoteControl tvControle(tv, input, output);

	CHECK(input << command);
	CHECK(tvControle.HandleCommand());
	CHECK(input.eof());
	CHECK(output.str() == expectedOutput);
}

TEST_CASE("Can handle TurnOn commande")
{
	CTVSet tv;
	VerifyCommandHandling(tv, "TurnOn", "TV is turned on\n");
}
TEST_CASE("Can handle TurnOff commande")
{
	CTVSet tv;
	VerifyCommandHandling(tv, "TurnOff", "TV is turned off\n");
}

TEST_CASE("Can handle SelectChannel commande when TV is turned on")
{
	CTVSet tv;
	tv.TurnOn();
	VerifyCommandHandling(tv, "SelectChannel 5", "Channel is changed to 5\n");
}

TEST_CASE("Can't handle SelectChannel commande when TV is turned off")
{
	CTVSet tv;
	VerifyCommandHandling(tv, "SelectChannel 6", "Channel isn't changed\nTV is turned off\n");
}

TEST_CASE("Can't handle SelectChannel commande when channel number is out from range")
{
	CTVSet tv;
	tv.TurnOn();
	VerifyCommandHandling(tv, "SelectChannel 0", "Channel isn't changed\nChannel number must be range from 1 to 99\n");
	VerifyCommandHandling(tv, "SelectChannel 100", "Channel isn't changed\nChannel number must be range from 1 to 99\n");
}

TEST_CASE("Can handle SelectPrevChannel commande when TV is turned on")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(50);
	VerifyCommandHandling(tv, "SelectPrevChannel", "Channel is changed to 1\n");
}

TEST_CASE("Can't handle SelectPrevChannel commande when TV is turned off")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(50);
	tv.TurnOff();
	VerifyCommandHandling(tv, "SelectPrevChannel", "Channel isn't changed\nTV is turned off\n");
}

TEST_CASE("Can print info about TVSet")
{
	CTVSet tv;
	VerifyCommandHandling(tv, "Info", "TV is turned off\n");
	tv.TurnOn();
	VerifyCommandHandling(tv, "Info", "TV is turned on\nChannel is: 1\n");
	tv.SelectChannel(7);
	VerifyCommandHandling(tv, "Info", "TV is turned on\nChannel is: 7\n");
}