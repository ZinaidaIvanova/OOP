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
	SECTION("Turning on TVSet state is changed after turning off, second turning off doesn't change TVSet state")
	{
		tv.TurnOn();
		tv.TurnOff();
		CHECK(tv.IsTurnedOn() == false);
		tv.TurnOff();
		CHECK(tv.IsTurnedOn() == false);
	}
}

TEST_CASE("Changing TVSet channel")
{
	CTVSet tv;
	SECTION("Turningh off TVSet channel is 0")
	{
		CHECK(tv.GetChannel() == 0);
	}
	SECTION("First turning on TVSet channel is 1")
	{
		tv.TurnOn();
		CHECK(tv.GetChannel() == 1);
	}

	SECTION("TVSet channel selection")
	{
		tv.TurnOn();
		tv.SelectChannel(1);
		CHECK(tv.GetChannel() == 1);

		tv.SelectChannel(0);
		CHECK(tv.GetChannel() == 1);

		tv.SelectChannel(99);
		CHECK(tv.GetChannel() == 99);

		tv.SelectChannel(50);
		CHECK(tv.GetChannel() == 50);

		tv.SelectChannel(100);
		CHECK(tv.GetChannel() == 50);

		tv.TurnOff();
		tv.SelectChannel(2);
		CHECK(tv.GetChannel() == 0);
	}
	
	SECTION("TVSet channel doesn't change after turning off and next turning on")
	{
		tv.TurnOn();
		tv.SelectChannel(50);
		tv.TurnOff();
		CHECK(tv.GetChannel() == 0);
		tv.TurnOn();
		CHECK(tv.GetChannel() == 50);
	}

	SECTION("Previous TVSet channel selection")
	{
		tv.TurnOn();
		tv.SelectChannel(50);
		tv.SelectChannel(25);
		tv.SelectPreviousChannel();
		CHECK(tv.GetChannel() == 50);

		tv.TurnOff();
		tv.TurnOn();
		tv.SelectPreviousChannel();
		CHECK(tv.GetChannel() == 25);
	}
}