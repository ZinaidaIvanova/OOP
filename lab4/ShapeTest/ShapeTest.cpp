#include "stdafx.h"
#include "../Shape/CCircle.h"
#include "../Shape/IShape.h"
#include "../Shape/CPoint.h"
#include "../Shape/CLineSegment.h"
#include "../Shape/ISolidShape.h"
#include "../Shape/CTriangle.h"
#include "../Shape/CRectangle.h"

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
		CHECK(line1.ToString() == R"(Line segment:
Start point: (3.0, -4.0)
End point: (0.0, 0.0)
Area: 0.0
Perimeter: 5.0
Color: 000000
)");
	}
}

TEST_CASE("Check triangle properties")
{
	CPoint vertix1(3, -4);
	CPoint vertix2(-8, 6);
	CPoint vertix3(0, 0);
	std::string outlineColor = "000000";
	std::string color = "FF00FF";

	CTriangle triangle(vertix1, vertix2, vertix3, outlineColor, color);

	SECTION("Triangle has perimeter")
	{
		double perim = 15.0 + std::sqrt(221);
		CHECK(triangle.GetPerimeter() == perim);
	}

	SECTION("Triangle has area")
	{
		CHECK(static_cast<int>(triangle.GetArea()) == 7);
	}

	SECTION("Triangle has color")
	{
		CHECK(triangle.GetFillColor() == "FF00FF");
		CHECK(triangle.GetOutlineColor() == "000000");
	}

	SECTION("Triangle has vertices")
	{
		CHECK(triangle.GetVertex1().x() == 3.0);
		CHECK(triangle.GetVertex1().y() == -4.0);

		CHECK(triangle.GetVertex2().x() == -8);
		CHECK(triangle.GetVertex2().y() == 6);
		
		CHECK(triangle.GetVertex3().x() == 0);
		CHECK(triangle.GetVertex3().y() == 0);
	} 

	SECTION("Triangle info can be printed")
	{
		CHECK(triangle.ToString() == R"(Triangle
First vertex: (3.0, -4.0)
Second vertex: (-8.0, 6.0)
Third vertex: (0.0, 0.0)
Area: 7.0
Perimeter: 29.9
Line color: 000000
Fill color: FF00FF
)");
	}
}


TEST_CASE("Check rectangle properties")
{
	CPoint leftTopVertix(30, 40);
	std::string outlineColor = "000000";
	std::string color = "FF00FF";
	CRectangle rectangle(leftTopVertix, 50, 70, outlineColor, color);

	SECTION("Rectangle has perimeter")
	{
		CHECK(rectangle.GetPerimeter() == 240);
	}

	SECTION("Rectangle has area")
	{
		CHECK(rectangle.GetArea() == 3500);
	}

	SECTION("Rectangle has color")
	{
		CHECK(rectangle.GetFillColor() == "FF00FF");
		CHECK(rectangle.GetOutlineColor() == "000000");
	}

	SECTION("Rectangle has vertices, width and height")
	{
		CHECK(rectangle.GetLeftTop().x() == 30);
		CHECK(rectangle.GetLeftTop().y() == 40);

		CHECK(rectangle.GetRightBottom().x() == 80);
		CHECK(rectangle.GetRightBottom().y() == -30);

		CHECK(rectangle.GetWidth() == 50);
		CHECK(rectangle.GetHeight() == 70);
	}

	SECTION("Rectangle info can be printed")
	{
		CHECK(rectangle.ToString() == R"(Rectangle
Left top vertex: (30.0, 40.0)
Right bottom vertex: (80.0, -30.0)
Width: 50.0
Height: 70.0
Area: 3500.0
Perimeter: 240.0
Line color: 000000
Fill color: FF00FF
)");
	}
}

TEST_CASE("Check circle properties")
{
	CPoint center(130, 80);
	std::string outlineColor = "000000";
	std::string color = "FF00FF";
	CCircle circle(center, 50, outlineColor, color);
	constexpr double M_PI = 3.141592;

	SECTION("Circle has perimeter")
	{
		double lenght = 100 * M_PI;
		CHECK(circle.GetPerimeter() == 314.1592);
	}

	SECTION("Circle has area")
	{
		CHECK(circle.GetArea() == 2500 * M_PI);
	}

	SECTION("Circle has color")
	{
		CHECK(circle.GetFillColor() == "FF00FF");
		CHECK(circle.GetOutlineColor() == "000000");
	}

	SECTION("Circle has vertices, width and height")
	{
		CHECK(circle.GetCenter().x() == 130);
		CHECK(circle.GetCenter().y() == 80);

		CHECK(circle.GetRadius() == 50);
	}

	SECTION("Circle info can be printed")
	{
		CHECK(circle.ToString() == R"(Circle
Center: (130.0, 80.0)
Radius: 50.0
Area: 7854.0
Perimeter: 314.2
Line color: 000000
Fill color: FF00FF
)");
	}
}

