#include "stdafx.h"
#include "TVSet.h"


bool CTVSet::IsTurnedOn()
{
	return m_isOn;
}

void CTVSet::SelectChannel(int newChannelNum)
{

}

int CTVSet::getChannel()
{
	return m_channelNum;
}

void CTVSet::TurnOn()
{
	if (!m_isOn)
	{
		m_isOn = true;
	}
	if (m_channelNum == 0)
	{
		m_channelNum = 1;
	}
}

void CTVSet::TurnOff()
{
	if (m_isOn)
	{
		m_isOn = false;
	}
}
