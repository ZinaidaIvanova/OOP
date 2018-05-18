#pragma once
class CTVSet
{
public:
	void TurnOn();
	bool IsTurnedOn();

private:
	bool m_isOn = false;
	int m_channelNum = 0;
};

