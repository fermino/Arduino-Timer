// Timer lib for Arduino 1
	#include "Timer.h"
	
	Timer::Timer()
	{
		Start = 0;
		Trigger = 0;
		Active = false;
		Debug = false;
	}

	Timer::Timer(boolean Debug)
	{
		Start = 0;
		Trigger = 0;
		Active = false;
		Debug = true;
	}

	Timer::~Timer()
	{ }

	void Timer::Toggle()
	{
		if(Start > 0)
			Start = 0;
		else
			if(Trigger > 0)
				Start = GetCurrentTime();
	}

	void Timer::Check()
	{
		if(IsRunning() && GetCurrentTime() >= (Start + Trigger))
		{
			Active = true;
			Start = 0;
		}

		if(Debug)
		{
			Serial.print(Start);
			Serial.print(" ");
			Serial.print(Trigger);
			Serial.print(" ");
			Serial.print(GetCurrentTime());
			Serial.print(" ");
			Serial.print(GetTimeLeft());
			Serial.print(" ");
			Serial.println(Active);
		}
	}

	String Timer::GetTimeLeft()
	{
		if(IsRunning() && Active == false)
			return Time2Chr(Start - GetCurrentTime() + Trigger);
		else
			return Time2Chr(Trigger);
	}

	boolean Timer::IsRunning()
	{ return (Start > 0 && Trigger > 0); }

	boolean IsActive()
	{ /*return Active;*/ }

	void Timer::AddSecond()
	{ Trigger += 1; }
	void Timer::AddMinute()
	{ Trigger += 60; }
	void Timer::AddHour()
	{ Trigger += 3600; }

	unsigned long Timer::GetCurrentTime()
	{ return millis() / 1000; }

	String Timer::Time2Chr(unsigned long Sec)
	{
		int H = floor(Sec / 3600);
		int M = ((Sec / 60) % 60);
		int S = Sec % 60;

		String Hours = String(H);
		String Minutes = String(M);
		String Seconds = String(S);

		if(H < 10)
			Hours = String("0" + Hours);
		if(M < 10)
			Minutes = String("0" + Minutes);
		if(S < 10)
			Seconds = String("0" + Seconds);

		return String(Hours + ":" + Minutes + ":" + Seconds);
	}
