#include "stdafx.h"
#include "TVSet.h"


bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

int CTVSet::GetChannel() const
{
	if (!m_isOn)
	{
		return 0;
	}
	return m_channelNum;
}

void CTVSet::TurnOn()
{
	if (!m_isOn)
	{
		m_isOn = true;
	}
}

void CTVSet::TurnOff()
{
	if (m_isOn)
	{
		m_isOn = false;
	}
}

bool CTVSet::SelectChannel(int newChannelNum)
{
	if ((m_isOn) &&(newChannelNum <= 99) && (newChannelNum >= 1))
	{
		m_prevChannelNum = m_channelNum;
		m_channelNum = newChannelNum;
		return true;
	}
	return false;
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		std::swap(m_channelNum, m_prevChannelNum);
		return true;
	}
	return false;
}
