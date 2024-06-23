
#ifndef STATE_CHART_H_
#define STATE_CHART_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'state_chart'.
*/


/*! Enumeration of all states */ 
typedef enum
{
	State_chart_last_state,
	State_chart_main_region_Manual,
	State_chart_main_region_Manual_r1_switch_OFF,
	State_chart_main_region_Manual_r1_switch_ON,
	State_chart_main_region_Automatic,
	State_chart_main_region_Automatic_r1_GlowWaiting,
	State_chart_main_region_Automatic_r1_DarkWating,
	State_chart_main_region_Automatic_r1_switch_OFF,
	State_chart_main_region_Automatic_r1_switch_ON
} State_chartStates;

/*! Type definition of the data structure for the State_chartIface interface scope. */
typedef struct
{
	sc_boolean ON_raised;
	sc_boolean OFF_raised;
	sc_boolean MODE_raised;
	sc_boolean DARK_raised;
	sc_boolean GLOW_raised;
} State_chartIface;

/*! Type definition of the data structure for the State_chartTimeEvents interface scope. */
typedef struct
{
	sc_boolean state_chart_main_region_Automatic_r1_GlowWaiting_tev0_raised;
	sc_boolean state_chart_main_region_Automatic_r1_DarkWating_tev0_raised;
} State_chartTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define STATE_CHART_MAX_ORTHOGONAL_STATES 1

/*! Define indices of states in the StateConfVector */
#define SCVI_STATE_CHART_MAIN_REGION_MANUAL 0
#define SCVI_STATE_CHART_MAIN_REGION_MANUAL_R1_SWITCH_OFF 0
#define SCVI_STATE_CHART_MAIN_REGION_MANUAL_R1_SWITCH_ON 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_GLOWWAITING 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_DARKWATING 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_SWITCH_OFF 0
#define SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_SWITCH_ON 0

/*! 
 * Type definition of the data structure for the State_chart state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	State_chartStates stateConfVector[STATE_CHART_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	State_chartIface iface;
	State_chartTimeEvents timeEvents;
} State_chart;


/*! Initializes the State_chart state machine data structures. Must be called before first usage.*/
extern void state_chart_init(State_chart* handle);

/*! Activates the state machine */
extern void state_chart_enter(State_chart* handle);

/*! Deactivates the state machine */
extern void state_chart_exit(State_chart* handle);

/*! Performs a 'run to completion' step. */
extern void state_chart_runCycle(State_chart* handle);

/*! Raises a time event. */
extern void state_chart_raiseTimeEvent(const State_chart* handle, sc_eventid evid);

/*! Raises the in event 'ON' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_oN(State_chart* handle);

/*! Raises the in event 'OFF' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_oFF(State_chart* handle);

/*! Raises the in event 'MODE' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_mODE(State_chart* handle);

/*! Raises the in event 'DARK' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_dARK(State_chart* handle);

/*! Raises the in event 'GLOW' that is defined in the default interface scope. */ 
extern void state_chartIface_raise_gLOW(State_chart* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean state_chart_isActive(const State_chart* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean state_chart_isFinal(const State_chart* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean state_chart_isStateActive(const State_chart* handle, State_chartStates state);



#ifdef __cplusplus
}
#endif 

#endif /* STATE_CHART_H_ */
