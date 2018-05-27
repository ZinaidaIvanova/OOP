
#include "stdafx.h"
#include "../Shape/IShape.h"
#include "../Shape/Point.h"


TEST_CASE("Check Point creation and get coordinates")
{
	CPoint newPoint(0.5, -1);
	CHECK(newPoint.x() == 0.5);
	CHECK(newPoint.y() == -1);
}