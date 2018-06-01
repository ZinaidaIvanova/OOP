#pragma once
#include <memory>
#include <map>
#include <functional>
#include "IShape.h"

class CShapeCreater
{
public:
	CShapeCreater(std::istream &input);
	std::shared_ptr<IShape> GetShapeFromStream(std::istream &input) const;

private:
	std::shared_ptr<IShape> CreateLine(std::istream &args) const;
	std::shared_ptr<IShape> CreateTriangle(std::istream &args) const;
	std::shared_ptr<IShape> CreateRectangle(std::istream &args) const;
	std::shared_ptr<IShape> CreateCircle(std::istream &args) const;
private:
	typedef std::map<std::string, std::function<std::shared_ptr<IShape>(std::istream & args)>> ActionMap;
	std::istream &m_input;
	const ActionMap m_actionMap;
};