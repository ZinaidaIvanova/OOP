#include "stdafx.h"
#include "../Shape/IShape.h"
#include "../Shape/CPoint.h"
#include "../Shape/CLineSegment.h"


TEST_CASE("Check Point creation and get coordinates")
{
	CPoint newPoint(0.5, -1);
	CHECK(newPoint.x() == 0.5);
	CHECK(newPoint.y() == -1);

	newPoint.SetPoint(-5, 6);
	CHECK(newPoint.x() == -5);
	CHECK(newPoint.y() == 6);
}

TEST_CASE("Check line segment properties")
{
	CPoint vertix1(3, -4);
	CPoint vertix2(-8, 6);
	CPoint vertix3(0, 0);
	CLineSegment line1(vertix1, vertix3, "000000");
	CLineSegment line2(vertix3, vertix2, "FF0000");

	SECTION("All line segments areas equal zero")
	{
		CHECK(line1.GetArea() == 0);
		CHECK(line2.GetArea() == 0);
	}

	SECTION("Line segment perimeter is equal it's length")
	{
		CHECK(line1.GetPerimeter() == 5);
		CHECK(line2.GetPerimeter() == 10);
	}

	SECTION("Line segment has two ends")
	{
		CHECK(line1.GetStartPoint().x() == 3);
		CHECK(line1.GetStartPoint().y() == -4);

		CHECK(line1.GetEndPoint().x() == 0);
		CHECK(line1.GetEndPoint().y() == 0);
	}

	SECTION("Line segment has color")
	{
		CHECK(line1.GetOutlineColor() == "000000");
		CHECK(line2.GetOutlineColor() == "FF0000");
	}

	SECTION("Line segment info can be printed")
	{
		CHECK(line1.ToString() == R"(Line segment
Start point: (3, -4)
End point: (0, 0)
Area: 0.0
Perimeter: 5
Color: 000000)");
	}


}