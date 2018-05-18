#pragma once
class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool IsTurnedOn();
	void SelectChannel(int newChannelNum); 
	int getChannel();

private:
	bool m_isOn = false;
	int m_channelNum = 0;
};

