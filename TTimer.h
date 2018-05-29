/*
 * Timer.h
 *
 *  Created on: 09/12/2014
 *      Author: Monge
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "SDL2/SDL.h"

class TTimer
{
        private:
        //The clock time when the timer started
        Uint32 mStartTicks;

        //The ticks stored when the timer was paused
        Uint32 mPausedTicks;

        //The timer status
        bool mPaused;
        bool mStarted;

        public:
        //Initializes variables
        TTimer();
        ~TTimer();

        //The various clock actions
        void start();
        void stop();
        void pause();
        void unpause();

        //Gets the timer's time
        Uint32 getTicks();

        //Checks the status of the timer
        bool isStarted() const;
        bool isPaused() const;


};



#endif /* TIMER_H_ */
