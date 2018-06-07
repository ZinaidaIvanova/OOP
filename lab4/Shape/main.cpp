
#include "stdafx.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "IShape.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "ISolidShape.h"
#include "CShapeCreater.h"

std::shared_ptr<IShape> GetMaxAreaShape(std::vector<std::shared_ptr<IShape>> shapeList)
{
	
	
	return std::shared_ptr<IShape>();
}



int main()
{
	std::vector<std::shared_ptr<IShape>> shapeList;
	CShapeCreater shapeCreater(std::cin);

	while (auto shape = shapeCreater.GetShapeFromStream())
	{
		std::cout << "> ";
		shapeList.push_back(shape);
	}

	if (!shapeList.empty())
	{
		for (auto elem : shapeList)
		{
			std::cout << elem.get()->ToString() << "\n";
		}
	}

	return 0;
}

