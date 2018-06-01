#include "stdafx.h"
#include "CShapeCreater.h"
#include "CPoint.h"

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

std::shared_ptr<IShape> CShapeCreater::GetShapeFromStream(std::istream & input) const
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

	return std::shared_ptr<IShape>();
}

std::shared_ptr<IShape> CShapeCreater::CreateTriangle(std::istream & args) const
{
	return std::shared_ptr<IShape>();
}

std::shared_ptr<IShape> CShapeCreater::CreateRectangle(std::istream & args) const
{
	return std::shared_ptr<IShape>();
}

std::shared_ptr<IShape> CShapeCreater::CreateCircle(std::istream & args) const
{
	return std::shared_ptr<IShape>();
}
