#include "stdafx.h"
#include <sstream>
#include "../Shape/CShapeCreater.h"

void VerifyCommandHandling(const std::string &command, const std::string &expectedOutput)
{
	std::stringstream input;
	input = std::stringstream();
	CShapeCreater shapeCreater(input);
	std::shared_ptr<IShape> shape;

	CHECK(input << command);
	shape = shapeCreater.GetShapeFromStream();
	CHECK(shape->ToString() == expectedOutput);
}

void ExpectOperationFailure(const std::string &command)
{
	std::stringstream input;
	input = std::stringstream();
	CShapeCreater shapeCreater(input);
	std::shared_ptr<IShape> shape;

	CHECK(input << command);
	shape = shapeCreater.GetShapeFromStream();
	CHECK(!shape);
}

TEST_CASE("CShapeCreater can creat line")
{
	VerifyCommandHandling("line 10.0 20.5 70.0 40.0 4effa0",
		R"(Line segment:
Start point: (10.0, 20.5)
End point: (70.0, 40.0)
Area: 0.0
Perimeter: 63.1
Color: 4effa0
)");
}

TEST_CASE("CShapeCreater can creat triangle ")
{
	VerifyCommandHandling("triangle 0.0 0.0 15.0 0.0 0.0 40.0 4effa0 00ffff",
		R"(Triangle
First vertex: (0.0, 0.0)
Second vertex: (15.0, 0.0)
Third vertex: (0.0, 40.0)
Area: 300.0
Perimeter: 97.7
Line color: 4effa0
Fill color: 00ffff
)");
}

TEST_CASE("CShapeCreater can creat rectangle ")
{
	VerifyCommandHandling("rectangle 10.0 20.5 10.0 20.0 57ee41 86aa7b",
		R"(Rectangle
Left top vertex: (10.0, 20.5)
Right bottom vertex: (20.0, 0.5)
Width: 10.0
Height: 20.0
Area: 200.0
Perimeter: 60.0
Line color: 57ee41
Fill color: 86aa7b
)");
}

TEST_CASE("CShapeCreater can creat circle")
{
	VerifyCommandHandling("circle 15.0 20.4 10.0 00ffff 4effa0",
		R"(Circle
Center: (15.0, 20.4)
Radius: 10.0
Area: 314.2
Perimeter: 62.8
Line color: 00ffff
Fill color: 4effa0
)");
}
