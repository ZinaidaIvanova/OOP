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
TEST_CASE("Check line segment propertyes")
{
	CPoint vertix1(1, -1);
	CPoint vertix2(-2, 3);
	CPoint vertix3(0, 0);
	CLineSegment line1(vertix1, vertix2, "000000");
	CLineSegment line2(vertix3, vertix2, "FF0000");

	SECTION("All line segments areas equal  zero")
	{
		CHECK(line1.GetArea() == 0);
		CHECK(line2.GetArea() == 0);
	}

}