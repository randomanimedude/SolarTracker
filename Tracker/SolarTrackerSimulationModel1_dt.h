/*
 * SolarTrackerSimulationModel1_dt.h
 *
 * Code generation for model "SolarTrackerSimulationModel1".
 *
 * Model version              : 3.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sat Apr 24 16:29:40 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(void*),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&SolarTrackerSimulationModel1_B.Memory), 0, 0, 7 }
  ,

  { (char_T *)(&SolarTrackerSimulationModel1_DW.Memory_PreviousInput), 0, 0, 366
  },

  { (char_T *)(&SolarTrackerSimulationModel1_DW.sfEvent), 6, 0, 2 },

  { (char_T *)(&SolarTrackerSimulationModel1_DW.is_c3_SolarTrackerSimulationMod),
    7, 0, 3 },

  { (char_T *)(&SolarTrackerSimulationModel1_DW.is_active_c3_SolarTrackerSimula),
    3, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&SolarTrackerSimulationModel1_P.Constant_Value), 0, 0, 3 },

  { (char_T *)(&SolarTrackerSimulationModel1_P.ManualSwitch_CurrentSetting), 3,
    0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] SolarTrackerSimulationModel1_dt.h */
