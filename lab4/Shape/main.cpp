
#include "stdafx.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "IShape.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "ISolidShape.h"
#include "CShapeCreater.h"

bool CompareShapeArea(std::shared_ptr<IShape> firstShape, std::shared_ptr<IShape> secondShape)
{
	return (firstShape.get()->GetArea()) < (secondShape.get()->GetArea());
}


std::shared_ptr<IShape> GetMaxAreaShape(std::vector<std::shared_ptr<IShape>> shapeList)
{
	
	return *std::max_element(shapeList.begin(), shapeList.end(), CompareShapeArea);
}


bool CompareShapePerimeter(std::shared_ptr<IShape> firstShape, std::shared_ptr<IShape> secondShape)
{
	return (firstShape.get()->GetPerimeter()) < (secondShape.get()->GetPerimeter());
}

std::shared_ptr<IShape> GetMinPerimeterShape(std::vector<std::shared_ptr<IShape>> shapeList)
{
	return *std::min_element(shapeList.begin(), shapeList.end(), CompareShapePerimeter);
}


int main()
{
	std::vector<std::shared_ptr<IShape>> shapeList;
	CShapeCreater shapeCreater(std::cin);
	std::cout << "> ";

	while (auto shape = shapeCreater.GetShapeFromStream())
	{
		std::cout << "> ";
		shapeList.push_back(shape);
	}

	if (!shapeList.empty())
	{
			std::cout << GetMaxAreaShape(shapeList)->ToString() << "\n"
				<< GetMinPerimeterShape(shapeList)->ToString() << "\n";
	}
	return 0;
}

