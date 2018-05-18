#pragma once
class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool IsTurnedOn();
	void rememberCurrChannel();
	void SelectChannel(int newChannelNum); 
	int getChannel();
	void SelectPreviousChannel();

private:
	bool m_isOn = false;
	int m_channelNum = 0;
	int m_prevChannelNum = 1;
};

