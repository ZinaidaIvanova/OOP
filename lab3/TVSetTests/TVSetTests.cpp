#include "stdafx.h"
#include "../TVSet/TVSet.h"



TEST_CASE("Turning the TVSet on and off")
{
	CTVSet tv;
	SECTION("TVSet is turned off after creation")
	{
		CHECK(tv.IsTurnedOn() == false);
	}
	SECTION("TVSet state is changed after turning on, but second turning on doesn't change TVSet state")
	{
		tv.TurnOn();
		CHECK(tv.IsTurnedOn() == true);
		tv.TurnOn();
		CHECK(tv.IsTurnedOn() == true);
	}
}