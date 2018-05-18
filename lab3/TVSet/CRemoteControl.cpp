#include "stdafx.h"
#include "CRemoteControl.h"

CRemoteControl::CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "TurnOn", bind(&CRemoteControl::TurnOn, this, std::placeholders::_1) },
		{ "TurnOff", bind(&CRemoteControl::TurnOff, this, std::placeholders::_1) },
		{ "SelectChannel", bind(&CRemoteControl::SelectChannel, this, std::placeholders::_1)},
		{ "SelectPrevChannel", bind(&CRemoteControl::SelectPrevChannel, this, std::placeholders::_1) },
		{ "Info", bind(&CRemoteControl::Info, this, std::placeholders::_1) }
		})
{

}

bool CRemoteControl::HandleCommand()
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CRemoteControl::TurnOn(std::istream & args)
{
	m_tv.TurnOn();
	m_output << "TV is turned on\n";
	return true;
}

bool CRemoteControl::TurnOff(std::istream & args)
{
	m_tv.TurnOff();
	m_output << "TV is turned off\n";
	return true;
}

bool CRemoteControl::SelectChannel(std::istream & args)
{
	std::string numString;
	std::getline(args, numString);
	int num = std::stoi(numString);
	if ((num > 99) && (num < 1))
	{
		m_output << "Channel number must be range from 1 to 99";
		return true;
	}
	m_tv.SelectChannel(num);
	m_output << "Channel is changed to " << m_tv.GetChannel() << "\n";
	return true;
}

bool CRemoteControl::SelectPrevChannel(std::istream & args)
{
	m_tv.SelectPreviousChannel();
	m_output << "Channel is changed to " << m_tv.GetChannel() << "\n";
	return true;
}

bool CRemoteControl::Info(std::istream & args)
{
	std::string info = (m_tv.IsTurnedOn())
		? ("TV is turned on\nChannel is: " + std::to_string(m_tv.GetChannel()) + "\n")
		: "TV is turned off\n";

	m_output << info;

	return true;
}
