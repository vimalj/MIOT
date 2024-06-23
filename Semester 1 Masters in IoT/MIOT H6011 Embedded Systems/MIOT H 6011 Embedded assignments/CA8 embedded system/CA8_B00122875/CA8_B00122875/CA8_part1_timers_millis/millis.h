/*
 * millis.h
 */

#ifndef MILLIS_H_
#define MILLIS_H_

/*
 * This function should set up timer 0 to expire at some sub-muliple of 1mS.
 */
void millisInit(void);


/* This function should return the number of milliseconds passed (elapsedMillis)
 * since the millisInit() function was called.
 * The count of elapsedMillis is incremented by an ISR.
 */

uint32_t millis(void);

#endif /* MILLIS_H_ */
