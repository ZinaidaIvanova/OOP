#pragma once
class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool IsTurnedOn() const;
	bool SelectChannel(int newChannelNum); 
	int GetChannel() const;
	bool SelectPreviousChannel();

private:
	bool m_isOn = false;
	int m_channelNum = 1;
	int m_prevChannelNum = 1;
};

