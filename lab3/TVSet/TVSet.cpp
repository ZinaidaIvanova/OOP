#include "stdafx.h"
#include "TVSet.h"


bool CTVSet::IsTurnedOn()
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	if (!m_isOn)
	{
		m_isOn = true;
	}
}