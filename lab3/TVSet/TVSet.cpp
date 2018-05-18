#include "stdafx.h"
#include "TVSet.h"


bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

int CTVSet::GetChannel() const
{
	return m_channelNum;
}

void CTVSet::TurnOn()
{
	if (!m_isOn)
	{
		m_isOn = true;
		m_channelNum = m_channelNumAfterTurningOn;
	}
}

void CTVSet::TurnOff()
{
	if (m_isOn)
	{
		m_isOn = false;
		m_channelNumAfterTurningOn = m_channelNum;
		m_channelNum = 0;
	}
}

void CTVSet::SelectChannel(int newChannelNum)
{
	if ((m_isOn) &&(newChannelNum <= 99) && (newChannelNum >= 1))
	{
		m_prevChannelNum = m_channelNum;
		m_channelNum = newChannelNum;
	}
}

void CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		std::swap(m_channelNum, m_prevChannelNum);
	}
}
