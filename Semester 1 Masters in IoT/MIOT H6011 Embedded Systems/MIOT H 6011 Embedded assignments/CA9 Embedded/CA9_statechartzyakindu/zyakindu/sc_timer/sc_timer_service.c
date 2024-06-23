/*
 * sc_timer_service.c
 *
 *  Created on: 13.04.2016
 *      Author: korsinski, terfloth
 */

#include "../sc_timer/sc_timer_service.h"

#include <stdlib.h>
#include <stdio.h>


/*! \file Implementation of YAKINDU SCT timer functionality based on POSIX threads. */


/*! Callback that is called when a timer fires. */
static void sc_timer_fired(sc_timer_t *timer) {

	timer->service->raise_event(timer->handle, timer->pt_evid);
}



/*! Starts a timer with the specified parameters. */
void sc_timer_start(sc_timer_service_t *this, void* handle, const sc_eventid evid,
		const sc_integer time_ms, const sc_boolean periodic) {


	/* go through all timers ... */
	for (int i = 0; i < this->timer_count; i++) {

		/* ... and find an unused one. */
		if (this->timers[i].pt_evid == NULL) {

			/* set timer properties */
			this->timers[i].pt_evid = evid;
			this->timers[i].time_ms = time_ms;
			this->timers[i].periodic = periodic;
			this->timers[i].handle = handle;
			this->timers[i].service = this;

			// reset the elapsed time ...
			this->timers[i].elapsed_time_ms = 0;

			break;
		}
	}

}


/*! Cancels a timer for the specified time event. */
void sc_timer_cancel(sc_timer_service_t *this, const sc_eventid evid) {

	int i;

	for (i = 0; i < this->timer_count; i++) {
		if (this->timers[i].pt_evid == evid) {

			this->timers[i].pt_evid = NULL;
			this->timers[i].handle = NULL;

			break;
		}
	}
}


/*! Initializes a timer service with a set of timers. */
void sc_timer_service_init(sc_timer_service_t *tservice,
	sc_timer_t *timers,
	sc_integer count,
	sc_raise_time_event_fp raise_event) {

	tservice->timers = timers;
	tservice->timer_count = count;
	for (int i=0; i<count; i++) {
		tservice->timers->pt_evid = NULL;
		tservice->timers->service = tservice;
	}

	tservice->raise_event = raise_event;
}


void sc_timer_service_proceed(sc_timer_service_t *this, const sc_integer time_ms) {

	/* go through all timers ... */
	for (int i = 0; i < this->timer_count; i++) {

		/* ... and process all used. */
		if (this->timers[i].pt_evid != NULL) {

			if (this->timers[i].elapsed_time_ms < this->timers[i].time_ms) {
				this->timers[i].elapsed_time_ms += time_ms;

				if (this->timers[i].elapsed_time_ms >= this->timers[i].time_ms) {
					sc_timer_fired(&(this->timers[i]));
					if (this->timers[i].periodic) {
						this->timers[i].elapsed_time_ms -= this->timers[i].time_ms;
					}
				}
			}
		}
	}

}



//BT
#include "../src-gen/State_chart.h"

#define MAX_TIMERS 20 //number of timers our timer service can use
#define CYCLE_PERIOD 10 //number of milliseconds that pass between each statechart cycle<br>
static sc_timer_service_t timer_service;
static sc_timer_t timers[MAX_TIMERS];

//! callback implementation for the setting up time events
void state_chart_setTimer(State_chart* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
    sc_timer_start(&timer_service, (void*) handle, evid, time_ms, periodic);
}

//! callback implementation for canceling time events.
void state_chart_unsetTimer(State_chart* handle, const sc_eventid evid) {
    sc_timer_cancel(&timer_service, evid);
}

void sc_timer_setup(void)
{
	sc_timer_service_init(&timer_service,
								timers,
								MAX_TIMERS,
								(sc_raise_time_event_fp) &state_chart_raiseTimeEvent);
}


void sc_timer_increment(const sc_integer time_ms)
{
	sc_timer_service_proceed(&timer_service, time_ms);
}
//BT END
