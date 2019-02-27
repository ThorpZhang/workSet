#pragma once
#include"include\SDL.h"


class LTimer
{
public:
	//Initializes variables
	LTimer();

	//The various clock actions
	void start();
	void start(Uint32 t);
	void stop();
	void pause();
	void pause(Uint32 t);
	void unpause();
	void unpause(Uint32 t);

	//Gets the timer's time
	Uint32 getTicks();
	Uint32 getTicks(Uint32);

	//Checks the status of the timer
	bool isStarted();
	bool isPaused();



private:
	//The clock time when the timer started
	Uint32 mStartTicks;

	//The ticks stored when the timer was paused
	Uint32 mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;
};