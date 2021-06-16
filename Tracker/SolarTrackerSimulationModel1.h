/*
 * SolarTrackerSimulationModel1.h
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

#ifndef RTW_HEADER_SolarTrackerSimulationModel1_h_
#define RTW_HEADER_SolarTrackerSimulationModel1_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef SolarTrackerSimulationModel1_COMMON_INCLUDES_
#define SolarTrackerSimulationModel1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                       /* SolarTrackerSimulationModel1_COMMON_INCLUDES_ */

#include "SolarTrackerSimulationModel1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Memory;                       /* '<Root>/Memory' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T voltage;                      /* '<Root>/voltage emulator' */
  real_T servoCmd;                     /* '<Root>/Chart' */
  real_T writeVoltage;                 /* '<Root>/Chart' */
  real_T maxVolt;                      /* '<Root>/Chart' */
  real_T maxVoltAngle;                 /* '<Root>/Chart' */
} B_SolarTrackerSimulationModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T maxAngle;                     /* '<Root>/voltage emulator' */
  real_T maxVoltage;                   /* '<Root>/voltage emulator' */
  real_T voltage[181];                 /* '<Root>/Chart' */
  real_T i;                            /* '<Root>/Chart' */
  real_T angleRange[181];              /* '<Root>/Chart' */
  int32_T sfEvent;                     /* '<Root>/voltage emulator' */
  int32_T sfEvent_k;                   /* '<Root>/Chart' */
  uint32_T is_c3_SolarTrackerSimulationMod;/* '<Root>/voltage emulator' */
  uint32_T is_c1_SolarTrackerSimulationMod;/* '<Root>/Chart' */
  uint32_T is_ScanAndGoToMaxVoltage;   /* '<Root>/Chart' */
  uint8_T is_active_c3_SolarTrackerSimula;/* '<Root>/voltage emulator' */
  uint8_T is_active_c1_SolarTrackerSimula;/* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_SolarTrackerSimulationMode_T;

/* Parameters (default storage) */
struct P_SolarTrackerSimulationModel_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_SolarTrackerSimulatio_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_SolarTrackerSimulationModel_T SolarTrackerSimulationModel1_P;

/* Block signals (default storage) */
extern B_SolarTrackerSimulationModel_T SolarTrackerSimulationModel1_B;

/* Block states (default storage) */
extern DW_SolarTrackerSimulationMode_T SolarTrackerSimulationModel1_DW;

/* Model entry point functions */
extern void SolarTrackerSimulationModel1_initialize(void);
extern void SolarTrackerSimulationModel1_step(void);
extern void SolarTrackerSimulationModel1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SolarTrackerSimulati_T *const SolarTrackerSimulationModel1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SolarTrackerSimulationModel1'
 * '<S1>'   : 'SolarTrackerSimulationModel1/Chart'
 * '<S2>'   : 'SolarTrackerSimulationModel1/voltage emulator'
 */
#endif                          /* RTW_HEADER_SolarTrackerSimulationModel1_h_ */
