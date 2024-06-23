
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "State_chart.h"
#include "State_chartRequired.h"
/*! \file Implementation of the state machine 'state_chart'
*/

/* prototypes of all internal functions */
static sc_boolean state_chart_check_main_region_Manual_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Manual_r1_switch_OFF_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Manual_r1_switch_ON_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_r1_GlowWaiting_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_r1_GlowWaiting_tr1_tr1(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_r1_DarkWating_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_r1_DarkWating_tr1_tr1(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_r1_switch_OFF_tr0_tr0(const State_chart* handle);
static sc_boolean state_chart_check_main_region_Automatic_r1_switch_ON_tr0_tr0(const State_chart* handle);
static void state_chart_effect_main_region_Manual_tr0(State_chart* handle);
static void state_chart_effect_main_region_Manual_r1_switch_OFF_tr0(State_chart* handle);
static void state_chart_effect_main_region_Manual_r1_switch_ON_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_r1_GlowWaiting_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_r1_GlowWaiting_tr1(State_chart* handle);
static void state_chart_effect_main_region_Automatic_r1_DarkWating_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_r1_DarkWating_tr1(State_chart* handle);
static void state_chart_effect_main_region_Automatic_r1_switch_OFF_tr0(State_chart* handle);
static void state_chart_effect_main_region_Automatic_r1_switch_ON_tr0(State_chart* handle);
static void state_chart_enact_main_region_Manual_r1_switch_OFF(State_chart* handle);
static void state_chart_enact_main_region_Manual_r1_switch_ON(State_chart* handle);
static void state_chart_enact_main_region_Automatic_r1_GlowWaiting(State_chart* handle);
static void state_chart_enact_main_region_Automatic_r1_DarkWating(State_chart* handle);
static void state_chart_enact_main_region_Automatic_r1_switch_OFF(State_chart* handle);
static void state_chart_enact_main_region_Automatic_r1_switch_ON(State_chart* handle);
static void state_chart_exact_main_region_Automatic_r1_GlowWaiting(State_chart* handle);
static void state_chart_exact_main_region_Automatic_r1_DarkWating(State_chart* handle);
static void state_chart_enseq_main_region_Manual_default(State_chart* handle);
static void state_chart_enseq_main_region_Manual_r1_switch_OFF_default(State_chart* handle);
static void state_chart_enseq_main_region_Manual_r1_switch_ON_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_r1_GlowWaiting_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_r1_DarkWating_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_r1_switch_OFF_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_r1_switch_ON_default(State_chart* handle);
static void state_chart_enseq_main_region_default(State_chart* handle);
static void state_chart_enseq_main_region_Manual_r1_default(State_chart* handle);
static void state_chart_enseq_main_region_Automatic_r1_default(State_chart* handle);
static void state_chart_exseq_main_region_Manual(State_chart* handle);
static void state_chart_exseq_main_region_Manual_r1_switch_OFF(State_chart* handle);
static void state_chart_exseq_main_region_Manual_r1_switch_ON(State_chart* handle);
static void state_chart_exseq_main_region_Automatic(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_r1_GlowWaiting(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_r1_DarkWating(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_r1_switch_OFF(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_r1_switch_ON(State_chart* handle);
static void state_chart_exseq_main_region(State_chart* handle);
static void state_chart_exseq_main_region_Manual_r1(State_chart* handle);
static void state_chart_exseq_main_region_Automatic_r1(State_chart* handle);
static void state_chart_react_main_region_Manual_r1_switch_OFF(State_chart* handle);
static void state_chart_react_main_region_Manual_r1_switch_ON(State_chart* handle);
static void state_chart_react_main_region_Automatic_r1_GlowWaiting(State_chart* handle);
static void state_chart_react_main_region_Automatic_r1_DarkWating(State_chart* handle);
static void state_chart_react_main_region_Automatic_r1_switch_OFF(State_chart* handle);
static void state_chart_react_main_region_Automatic_r1_switch_ON(State_chart* handle);
static void state_chart_react_main_region__entry_Default(State_chart* handle);
static void state_chart_react_main_region_Manual_r1__entry_Default(State_chart* handle);
static void state_chart_react_main_region_Automatic_r1__entry_Default(State_chart* handle);
static void state_chart_clearInEvents(State_chart* handle);
static void state_chart_clearOutEvents(State_chart* handle);


void state_chart_init(State_chart* handle)
{
		sc_integer i;
	
		for (i = 0; i < STATE_CHART_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = State_chart_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		state_chart_clearInEvents(handle);
		state_chart_clearOutEvents(handle);
	
}

void state_chart_enter(State_chart* handle)
{
	/* Default enter sequence for statechart state_chart */
	state_chart_enseq_main_region_default(handle);
}

void state_chart_exit(State_chart* handle)
{
	/* Default exit sequence for statechart state_chart */
	state_chart_exseq_main_region(handle);
}

sc_boolean state_chart_isActive(const State_chart* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < STATE_CHART_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != State_chart_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean state_chart_isFinal(const State_chart* handle)
{
   return bool_false;
}

static void state_chart_clearInEvents(State_chart* handle)
{
	handle->iface.ON_raised = bool_false;
	handle->iface.OFF_raised = bool_false;
	handle->iface.MODE_raised = bool_false;
	handle->iface.DARK_raised = bool_false;
	handle->iface.GLOW_raised = bool_false;
	handle->timeEvents.state_chart_main_region_Automatic_r1_GlowWaiting_tev0_raised = bool_false;
	handle->timeEvents.state_chart_main_region_Automatic_r1_DarkWating_tev0_raised = bool_false;
}

static void state_chart_clearOutEvents(State_chart* handle)
{
}

void state_chart_runCycle(State_chart* handle)
{
	
	state_chart_clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < STATE_CHART_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case State_chart_main_region_Manual_r1_switch_OFF:
		{
			state_chart_react_main_region_Manual_r1_switch_OFF(handle);
			break;
		}
		case State_chart_main_region_Manual_r1_switch_ON:
		{
			state_chart_react_main_region_Manual_r1_switch_ON(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_GlowWaiting:
		{
			state_chart_react_main_region_Automatic_r1_GlowWaiting(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_DarkWating:
		{
			state_chart_react_main_region_Automatic_r1_DarkWating(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_switch_OFF:
		{
			state_chart_react_main_region_Automatic_r1_switch_OFF(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_switch_ON:
		{
			state_chart_react_main_region_Automatic_r1_switch_ON(handle);
			break;
		}
		default:
			break;
		}
	}
	
	state_chart_clearInEvents(handle);
}

void state_chart_raiseTimeEvent(const State_chart* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(State_chartTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean state_chart_isStateActive(const State_chart* handle, State_chartStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case State_chart_main_region_Manual :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL] >= State_chart_main_region_Manual
				&& handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL] <= State_chart_main_region_Manual_r1_switch_ON);
			break;
		case State_chart_main_region_Manual_r1_switch_OFF :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL_R1_SWITCH_OFF] == State_chart_main_region_Manual_r1_switch_OFF
			);
			break;
		case State_chart_main_region_Manual_r1_switch_ON :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_MANUAL_R1_SWITCH_ON] == State_chart_main_region_Manual_r1_switch_ON
			);
			break;
		case State_chart_main_region_Automatic :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC] >= State_chart_main_region_Automatic
				&& handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC] <= State_chart_main_region_Automatic_r1_switch_ON);
			break;
		case State_chart_main_region_Automatic_r1_GlowWaiting :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_GLOWWAITING] == State_chart_main_region_Automatic_r1_GlowWaiting
			);
			break;
		case State_chart_main_region_Automatic_r1_DarkWating :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_DARKWATING] == State_chart_main_region_Automatic_r1_DarkWating
			);
			break;
		case State_chart_main_region_Automatic_r1_switch_OFF :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_SWITCH_OFF] == State_chart_main_region_Automatic_r1_switch_OFF
			);
			break;
		case State_chart_main_region_Automatic_r1_switch_ON :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATE_CHART_MAIN_REGION_AUTOMATIC_R1_SWITCH_ON] == State_chart_main_region_Automatic_r1_switch_ON
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void state_chartIface_raise_oN(State_chart* handle)
{
	handle->iface.ON_raised = bool_true;
}
void state_chartIface_raise_oFF(State_chart* handle)
{
	handle->iface.OFF_raised = bool_true;
}
void state_chartIface_raise_mODE(State_chart* handle)
{
	handle->iface.MODE_raised = bool_true;
}
void state_chartIface_raise_dARK(State_chart* handle)
{
	handle->iface.DARK_raised = bool_true;
}
void state_chartIface_raise_gLOW(State_chart* handle)
{
	handle->iface.GLOW_raised = bool_true;
}



/* implementations of all internal functions */

static sc_boolean state_chart_check_main_region_Manual_tr0_tr0(const State_chart* handle)
{
	return handle->iface.MODE_raised;
}

static sc_boolean state_chart_check_main_region_Manual_r1_switch_OFF_tr0_tr0(const State_chart* handle)
{
	return handle->iface.ON_raised;
}

static sc_boolean state_chart_check_main_region_Manual_r1_switch_ON_tr0_tr0(const State_chart* handle)
{
	return handle->iface.OFF_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_tr0_tr0(const State_chart* handle)
{
	return handle->iface.MODE_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_r1_GlowWaiting_tr0_tr0(const State_chart* handle)
{
	return handle->timeEvents.state_chart_main_region_Automatic_r1_GlowWaiting_tev0_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_r1_GlowWaiting_tr1_tr1(const State_chart* handle)
{
	return handle->iface.GLOW_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_r1_DarkWating_tr0_tr0(const State_chart* handle)
{
	return handle->timeEvents.state_chart_main_region_Automatic_r1_DarkWating_tev0_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_r1_DarkWating_tr1_tr1(const State_chart* handle)
{
	return handle->iface.DARK_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_r1_switch_OFF_tr0_tr0(const State_chart* handle)
{
	return handle->iface.DARK_raised;
}

static sc_boolean state_chart_check_main_region_Automatic_r1_switch_ON_tr0_tr0(const State_chart* handle)
{
	return handle->iface.GLOW_raised;
}

static void state_chart_effect_main_region_Manual_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Manual(handle);
	state_chart_enseq_main_region_Automatic_default(handle);
}

static void state_chart_effect_main_region_Manual_r1_switch_OFF_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Manual_r1_switch_OFF(handle);
	state_chart_enseq_main_region_Manual_r1_switch_ON_default(handle);
}

static void state_chart_effect_main_region_Manual_r1_switch_ON_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Manual_r1_switch_ON(handle);
	state_chart_enseq_main_region_Manual_r1_switch_OFF_default(handle);
}

static void state_chart_effect_main_region_Automatic_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic(handle);
	state_chart_enseq_main_region_Manual_default(handle);
}

static void state_chart_effect_main_region_Automatic_r1_GlowWaiting_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_r1_GlowWaiting(handle);
	state_chart_enseq_main_region_Automatic_r1_switch_ON_default(handle);
}

static void state_chart_effect_main_region_Automatic_r1_GlowWaiting_tr1(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_r1_GlowWaiting(handle);
	state_chart_enseq_main_region_Automatic_r1_switch_OFF_default(handle);
}

static void state_chart_effect_main_region_Automatic_r1_DarkWating_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_r1_DarkWating(handle);
	state_chart_enseq_main_region_Automatic_r1_switch_OFF_default(handle);
}

static void state_chart_effect_main_region_Automatic_r1_DarkWating_tr1(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_r1_DarkWating(handle);
	state_chart_enseq_main_region_Automatic_r1_switch_ON_default(handle);
}

static void state_chart_effect_main_region_Automatic_r1_switch_OFF_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_r1_switch_OFF(handle);
	state_chart_enseq_main_region_Automatic_r1_GlowWaiting_default(handle);
}

static void state_chart_effect_main_region_Automatic_r1_switch_ON_tr0(State_chart* handle)
{
	state_chart_exseq_main_region_Automatic_r1_switch_ON(handle);
	state_chart_enseq_main_region_Automatic_r1_DarkWating_default(handle);
}

/* Entry action for state 'switch OFF'. */
static void state_chart_enact_main_region_Manual_r1_switch_OFF(State_chart* handle)
{
	/* Entry action for state 'switch OFF'. */
	state_chartIface_setLight(handle, bool_false);
}

/* Entry action for state 'switch ON'. */
static void state_chart_enact_main_region_Manual_r1_switch_ON(State_chart* handle)
{
	/* Entry action for state 'switch ON'. */
	state_chartIface_setLight(handle, bool_true);
}

/* Entry action for state 'GlowWaiting'. */
static void state_chart_enact_main_region_Automatic_r1_GlowWaiting(State_chart* handle)
{
	/* Entry action for state 'GlowWaiting'. */
	state_chart_setTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_r1_GlowWaiting_tev0_raised) , 1000, bool_false);
}

/* Entry action for state 'DarkWating'. */
static void state_chart_enact_main_region_Automatic_r1_DarkWating(State_chart* handle)
{
	/* Entry action for state 'DarkWating'. */
	state_chart_setTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_r1_DarkWating_tev0_raised) , 1000, bool_false);
}

/* Entry action for state 'switch OFF'. */
static void state_chart_enact_main_region_Automatic_r1_switch_OFF(State_chart* handle)
{
	/* Entry action for state 'switch OFF'. */
	state_chartIface_setLight(handle, bool_false);
}

/* Entry action for state 'switch ON'. */
static void state_chart_enact_main_region_Automatic_r1_switch_ON(State_chart* handle)
{
	/* Entry action for state 'switch ON'. */
	state_chartIface_setLight(handle, bool_true);
}

/* Exit action for state 'GlowWaiting'. */
static void state_chart_exact_main_region_Automatic_r1_GlowWaiting(State_chart* handle)
{
	/* Exit action for state 'GlowWaiting'. */
	state_chart_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_r1_GlowWaiting_tev0_raised) );		
}

/* Exit action for state 'DarkWating'. */
static void state_chart_exact_main_region_Automatic_r1_DarkWating(State_chart* handle)
{
	/* Exit action for state 'DarkWating'. */
	state_chart_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.state_chart_main_region_Automatic_r1_DarkWating_tev0_raised) );		
}

/* 'default' enter sequence for state Manual */
static void state_chart_enseq_main_region_Manual_default(State_chart* handle)
{
	/* 'default' enter sequence for state Manual */
	state_chart_enseq_main_region_Manual_r1_default(handle);
}

/* 'default' enter sequence for state switch OFF */
static void state_chart_enseq_main_region_Manual_r1_switch_OFF_default(State_chart* handle)
{
	/* 'default' enter sequence for state switch OFF */
	state_chart_enact_main_region_Manual_r1_switch_OFF(handle);
	handle->stateConfVector[0] = State_chart_main_region_Manual_r1_switch_OFF;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state switch ON */
static void state_chart_enseq_main_region_Manual_r1_switch_ON_default(State_chart* handle)
{
	/* 'default' enter sequence for state switch ON */
	state_chart_enact_main_region_Manual_r1_switch_ON(handle);
	handle->stateConfVector[0] = State_chart_main_region_Manual_r1_switch_ON;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Automatic */
static void state_chart_enseq_main_region_Automatic_default(State_chart* handle)
{
	/* 'default' enter sequence for state Automatic */
	state_chart_enseq_main_region_Automatic_r1_default(handle);
}

/* 'default' enter sequence for state GlowWaiting */
static void state_chart_enseq_main_region_Automatic_r1_GlowWaiting_default(State_chart* handle)
{
	/* 'default' enter sequence for state GlowWaiting */
	state_chart_enact_main_region_Automatic_r1_GlowWaiting(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_r1_GlowWaiting;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DarkWating */
static void state_chart_enseq_main_region_Automatic_r1_DarkWating_default(State_chart* handle)
{
	/* 'default' enter sequence for state DarkWating */
	state_chart_enact_main_region_Automatic_r1_DarkWating(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_r1_DarkWating;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state switch OFF */
static void state_chart_enseq_main_region_Automatic_r1_switch_OFF_default(State_chart* handle)
{
	/* 'default' enter sequence for state switch OFF */
	state_chart_enact_main_region_Automatic_r1_switch_OFF(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_r1_switch_OFF;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state switch ON */
static void state_chart_enseq_main_region_Automatic_r1_switch_ON_default(State_chart* handle)
{
	/* 'default' enter sequence for state switch ON */
	state_chart_enact_main_region_Automatic_r1_switch_ON(handle);
	handle->stateConfVector[0] = State_chart_main_region_Automatic_r1_switch_ON;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void state_chart_enseq_main_region_default(State_chart* handle)
{
	/* 'default' enter sequence for region main region */
	state_chart_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void state_chart_enseq_main_region_Manual_r1_default(State_chart* handle)
{
	/* 'default' enter sequence for region r1 */
	state_chart_react_main_region_Manual_r1__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void state_chart_enseq_main_region_Automatic_r1_default(State_chart* handle)
{
	/* 'default' enter sequence for region r1 */
	state_chart_react_main_region_Automatic_r1__entry_Default(handle);
}

/* Default exit sequence for state Manual */
static void state_chart_exseq_main_region_Manual(State_chart* handle)
{
	/* Default exit sequence for state Manual */
	state_chart_exseq_main_region_Manual_r1(handle);
}

/* Default exit sequence for state switch OFF */
static void state_chart_exseq_main_region_Manual_r1_switch_OFF(State_chart* handle)
{
	/* Default exit sequence for state switch OFF */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state switch ON */
static void state_chart_exseq_main_region_Manual_r1_switch_ON(State_chart* handle)
{
	/* Default exit sequence for state switch ON */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Automatic */
static void state_chart_exseq_main_region_Automatic(State_chart* handle)
{
	/* Default exit sequence for state Automatic */
	state_chart_exseq_main_region_Automatic_r1(handle);
}

/* Default exit sequence for state GlowWaiting */
static void state_chart_exseq_main_region_Automatic_r1_GlowWaiting(State_chart* handle)
{
	/* Default exit sequence for state GlowWaiting */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
	state_chart_exact_main_region_Automatic_r1_GlowWaiting(handle);
}

/* Default exit sequence for state DarkWating */
static void state_chart_exseq_main_region_Automatic_r1_DarkWating(State_chart* handle)
{
	/* Default exit sequence for state DarkWating */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
	state_chart_exact_main_region_Automatic_r1_DarkWating(handle);
}

/* Default exit sequence for state switch OFF */
static void state_chart_exseq_main_region_Automatic_r1_switch_OFF(State_chart* handle)
{
	/* Default exit sequence for state switch OFF */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state switch ON */
static void state_chart_exseq_main_region_Automatic_r1_switch_ON(State_chart* handle)
{
	/* Default exit sequence for state switch ON */
	handle->stateConfVector[0] = State_chart_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
static void state_chart_exseq_main_region(State_chart* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of state_chart.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case State_chart_main_region_Manual_r1_switch_OFF :
		{
			state_chart_exseq_main_region_Manual_r1_switch_OFF(handle);
			break;
		}
		case State_chart_main_region_Manual_r1_switch_ON :
		{
			state_chart_exseq_main_region_Manual_r1_switch_ON(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_GlowWaiting :
		{
			state_chart_exseq_main_region_Automatic_r1_GlowWaiting(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_DarkWating :
		{
			state_chart_exseq_main_region_Automatic_r1_DarkWating(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_switch_OFF :
		{
			state_chart_exseq_main_region_Automatic_r1_switch_OFF(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_switch_ON :
		{
			state_chart_exseq_main_region_Automatic_r1_switch_ON(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void state_chart_exseq_main_region_Manual_r1(State_chart* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of state_chart.main_region.Manual.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case State_chart_main_region_Manual_r1_switch_OFF :
		{
			state_chart_exseq_main_region_Manual_r1_switch_OFF(handle);
			break;
		}
		case State_chart_main_region_Manual_r1_switch_ON :
		{
			state_chart_exseq_main_region_Manual_r1_switch_ON(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void state_chart_exseq_main_region_Automatic_r1(State_chart* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of state_chart.main_region.Automatic.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case State_chart_main_region_Automatic_r1_GlowWaiting :
		{
			state_chart_exseq_main_region_Automatic_r1_GlowWaiting(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_DarkWating :
		{
			state_chart_exseq_main_region_Automatic_r1_DarkWating(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_switch_OFF :
		{
			state_chart_exseq_main_region_Automatic_r1_switch_OFF(handle);
			break;
		}
		case State_chart_main_region_Automatic_r1_switch_ON :
		{
			state_chart_exseq_main_region_Automatic_r1_switch_ON(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state switch OFF. */
static void state_chart_react_main_region_Manual_r1_switch_OFF(State_chart* handle)
{
	/* The reactions of state switch OFF. */
	if (state_chart_check_main_region_Manual_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Manual_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Manual_r1_switch_OFF_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Manual_r1_switch_OFF_tr0(handle);
		} 
	}
}

/* The reactions of state switch ON. */
static void state_chart_react_main_region_Manual_r1_switch_ON(State_chart* handle)
{
	/* The reactions of state switch ON. */
	if (state_chart_check_main_region_Manual_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Manual_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Manual_r1_switch_ON_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Manual_r1_switch_ON_tr0(handle);
		} 
	}
}

/* The reactions of state GlowWaiting. */
static void state_chart_react_main_region_Automatic_r1_GlowWaiting(State_chart* handle)
{
	/* The reactions of state GlowWaiting. */
	if (state_chart_check_main_region_Automatic_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_r1_GlowWaiting_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_r1_GlowWaiting_tr0(handle);
		}  else
		{
			if (state_chart_check_main_region_Automatic_r1_GlowWaiting_tr1_tr1(handle) == bool_true)
			{ 
				state_chart_effect_main_region_Automatic_r1_GlowWaiting_tr1(handle);
			} 
		}
	}
}

/* The reactions of state DarkWating. */
static void state_chart_react_main_region_Automatic_r1_DarkWating(State_chart* handle)
{
	/* The reactions of state DarkWating. */
	if (state_chart_check_main_region_Automatic_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_r1_DarkWating_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_r1_DarkWating_tr0(handle);
		}  else
		{
			if (state_chart_check_main_region_Automatic_r1_DarkWating_tr1_tr1(handle) == bool_true)
			{ 
				state_chart_effect_main_region_Automatic_r1_DarkWating_tr1(handle);
			} 
		}
	}
}

/* The reactions of state switch OFF. */
static void state_chart_react_main_region_Automatic_r1_switch_OFF(State_chart* handle)
{
	/* The reactions of state switch OFF. */
	if (state_chart_check_main_region_Automatic_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_r1_switch_OFF_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_r1_switch_OFF_tr0(handle);
		} 
	}
}

/* The reactions of state switch ON. */
static void state_chart_react_main_region_Automatic_r1_switch_ON(State_chart* handle)
{
	/* The reactions of state switch ON. */
	if (state_chart_check_main_region_Automatic_tr0_tr0(handle) == bool_true)
	{ 
		state_chart_effect_main_region_Automatic_tr0(handle);
	}  else
	{
		if (state_chart_check_main_region_Automatic_r1_switch_ON_tr0_tr0(handle) == bool_true)
		{ 
			state_chart_effect_main_region_Automatic_r1_switch_ON_tr0(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void state_chart_react_main_region__entry_Default(State_chart* handle)
{
	/* Default react sequence for initial entry  */
	state_chart_enseq_main_region_Manual_default(handle);
}

/* Default react sequence for initial entry  */
static void state_chart_react_main_region_Manual_r1__entry_Default(State_chart* handle)
{
	/* Default react sequence for initial entry  */
	state_chart_enseq_main_region_Manual_r1_switch_OFF_default(handle);
}

/* Default react sequence for initial entry  */
static void state_chart_react_main_region_Automatic_r1__entry_Default(State_chart* handle)
{
	/* Default react sequence for initial entry  */
	state_chart_enseq_main_region_Automatic_r1_switch_OFF_default(handle);
}


