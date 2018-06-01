#include "stdafx.h"
#include "CShapeCreater.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"

CShapeCreater::CShapeCreater(std::istream &input):
	m_input(input),
	m_actionMap({
		{"line", bind(&CShapeCreater::CreateLine, this, std::placeholders::_1)},
		{"triangle", bind(&CShapeCreater::CreateTriangle, this, std::placeholders::_1)},
		{"rectangle", bind(&CShapeCreater::CreateRectangle, this, std::placeholders::_1)},
		{"circle", bind(&CShapeCreater::CreateCircle, this, std::placeholders::_1) }
	})
{
}

std::shared_ptr<IShape> CShapeCreater::GetShapeFromStream() const
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string shape;
	strm >> shape;

	auto it = m_actionMap.find(shape);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return nullptr;
}

std::shared_ptr<IShape> CShapeCreater::CreateLine(std::istream & args) const
{
	CPoint first, second;
	std::string color;
	double x, y;
	try
	{
		if (args >> x >> y)
		{
			first.SetPoint(x, y);
		}
		if (args >> x >> y)
		{
			second.SetPoint(x, y);
		}
		args >> color;

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}
	return std::make_shared<CLineSegment>(first, second, color);
}

std::shared_ptr<IShape> CShapeCreater::CreateTriangle(std::istream & args) const
{
	CPoint vertex1, vertex2, vertex3;
	std::string outLineColor, color;
	double x, y;
	try
	{
		if (args >> x >> y)
		{
			vertex1.SetPoint(x, y);
		}
		if (args >> x >> y)
		{
			vertex2.SetPoint(x, y);
		}
		if (args >> x >> y)
		{
			vertex3.SetPoint(x, y);
		}

		args >> outLineColor >> color;

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}
	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outLineColor, color);
}

std::shared_ptr<IShape> CShapeCreater::CreateRectangle(std::istream & args) const
{
	CPoint leftTopVertex;
	std::string outLineColor, color;
	double x, y, whidth, height;
	try
	{
		if (args >> x >> y)
		{
			leftTopVertex.SetPoint(x, y);
		}
		args >> whidth >> height;
		args >> outLineColor >> color;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CRectangle>(leftTopVertex, whidth, height, outLineColor, color);
}

std::shared_ptr<IShape> CShapeCreater::CreateCircle(std::istream & args) const
{
	CPoint center;
	std::string outLineColor, color;
	double x, y, radius;
	try
	{
		if (args >> x >> y)
		{
			center.SetPoint(x, y);
		}
		args >> radius;
		args >> outLineColor >> color;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CCircle>(center, radius, outLineColor, color);
}
