#ifndef TIMER_H
#define TIMER_H

	#include <Arduino.h>
	#include <math.h>
	
	class Timer
	{
		private:
			unsigned long Start;
			unsigned long Trigger;

			boolean Active;

			boolean Debug;

			unsigned long GetCurrentTime();
			String Time2Chr(unsigned long Sec);
		public:
			Timer();
			Timer(boolean Debug);
			~Timer();
			void Toggle();
			void Check();
			String GetTimeLeft();
			boolean IsRunning();
			boolean IsActive();
			void AddSecond();
			void AddMinute();
			void AddHour();
	};

#endif