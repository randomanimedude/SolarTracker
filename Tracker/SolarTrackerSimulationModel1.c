/*
 * SolarTrackerSimulationModel1.c
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

#include "SolarTrackerSimulationModel1.h"
#include "SolarTrackerSimulationModel1_private.h"
#include "SolarTrackerSimulationModel1_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define SolarT_IN_ScanAndGoToMaxVoltage (2UL)
#define SolarTrackerS_IN_GoToMaxVoltage (1UL)
#define SolarTrackerSi_IN_ResetPosition (3UL)
#define SolarTrackerSim_IN_GoToPosition (1UL)
#define SolarTrackerSim_IN_ScanVoltages (4UL)
#define SolarTrackerSimula_IN_Increment (2UL)
#define SolarTrackerSimulati_CALL_EVENT (-1L)

/* Named constants for Chart: '<Root>/voltage emulator' */
#define SolarTrackerSimula_IN_setValues (2UL)
#define SolarTracker_IN_calculateOutput (1UL)

/* Block signals (default storage) */
B_SolarTrackerSimulationModel_T SolarTrackerSimulationModel1_B;

/* Block states (default storage) */
DW_SolarTrackerSimulationMode_T SolarTrackerSimulationModel1_DW;

/* Real-time model */
static RT_MODEL_SolarTrackerSimulati_T SolarTrackerSimulationModel1_M_;
RT_MODEL_SolarTrackerSimulati_T *const SolarTrackerSimulationModel1_M =
  &SolarTrackerSimulationModel1_M_;

/* Model step function */
void SolarTrackerSimulationModel1_step(void)
{
  int16_T i;

  /* Memory: '<Root>/Memory' */
  SolarTrackerSimulationModel1_B.Memory =
    SolarTrackerSimulationModel1_DW.Memory_PreviousInput;

  /* Chart: '<Root>/voltage emulator' */
  SolarTrackerSimulationModel1_DW.sfEvent = SolarTrackerSimulati_CALL_EVENT;
  if (SolarTrackerSimulationModel1_DW.is_active_c3_SolarTrackerSimula == 0U) {
    SolarTrackerSimulationModel1_DW.is_active_c3_SolarTrackerSimula = 1U;
    SolarTrackerSimulationModel1_DW.is_c3_SolarTrackerSimulationMod =
      SolarTrackerSimula_IN_setValues;
    SolarTrackerSimulationModel1_DW.maxAngle = 62.0;
    SolarTrackerSimulationModel1_DW.maxVoltage = 2.5;
  } else if (SolarTrackerSimulationModel1_DW.is_c3_SolarTrackerSimulationMod ==
             SolarTracker_IN_calculateOutput) {
    SolarTrackerSimulationModel1_B.voltage = (2.0 - fabs
      ((SolarTrackerSimulationModel1_B.Memory -
        SolarTrackerSimulationModel1_DW.maxAngle) - 1.0) / 180.0) *
      (SolarTrackerSimulationModel1_DW.maxVoltage / 2.0);
  } else {
    /* case IN_setValues: */
    SolarTrackerSimulationModel1_DW.is_c3_SolarTrackerSimulationMod =
      SolarTracker_IN_calculateOutput;
    SolarTrackerSimulationModel1_B.voltage = (2.0 - fabs
      ((SolarTrackerSimulationModel1_B.Memory -
        SolarTrackerSimulationModel1_DW.maxAngle) - 1.0) / 180.0) *
      (SolarTrackerSimulationModel1_DW.maxVoltage / 2.0);
  }

  /* End of Chart: '<Root>/voltage emulator' */

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (SolarTrackerSimulationModel1_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    SolarTrackerSimulationModel1_B.ManualSwitch =
      SolarTrackerSimulationModel1_P.Constant_Value;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    SolarTrackerSimulationModel1_B.ManualSwitch =
      SolarTrackerSimulationModel1_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Chart: '<Root>/Chart' */
  if (SolarTrackerSimulationModel1_DW.temporalCounter_i1 < 31U) {
    SolarTrackerSimulationModel1_DW.temporalCounter_i1++;
  }

  SolarTrackerSimulationModel1_DW.sfEvent_k = SolarTrackerSimulati_CALL_EVENT;
  if (SolarTrackerSimulationModel1_DW.is_active_c1_SolarTrackerSimula == 0U) {
    SolarTrackerSimulationModel1_DW.is_active_c1_SolarTrackerSimula = 1U;
    SolarTrackerSimulationModel1_DW.is_c1_SolarTrackerSimulationMod =
      SolarTrackerSim_IN_GoToPosition;
    SolarTrackerSimulationModel1_B.writeVoltage =
      SolarTrackerSimulationModel1_B.voltage;
  } else if (SolarTrackerSimulationModel1_DW.is_c1_SolarTrackerSimulationMod ==
             SolarTrackerSim_IN_GoToPosition) {
    if (SolarTrackerSimulationModel1_B.ManualSwitch == 1.0) {
      SolarTrackerSimulationModel1_DW.is_c1_SolarTrackerSimulationMod =
        SolarT_IN_ScanAndGoToMaxVoltage;
      SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage =
        SolarTrackerSi_IN_ResetPosition;
      SolarTrackerSimulationModel1_B.maxVolt = 0.0;
      SolarTrackerSimulationModel1_B.maxVoltAngle = 0.0;
      SolarTrackerSimulationModel1_B.servoCmd = 0.0;
      for (i = 0; i < 181; i++) {
        SolarTrackerSimulationModel1_DW.angleRange[i] = i;
        SolarTrackerSimulationModel1_DW.voltage[i] = 0.0;
      }
    } else {
      SolarTrackerSimulationModel1_B.writeVoltage =
        SolarTrackerSimulationModel1_B.voltage;
    }

    /* case IN_ScanAndGoToMaxVoltage: */
  } else if (SolarTrackerSimulationModel1_B.ManualSwitch == 0.0) {
    SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage = 0UL;
    SolarTrackerSimulationModel1_DW.is_c1_SolarTrackerSimulationMod =
      SolarTrackerSim_IN_GoToPosition;
    SolarTrackerSimulationModel1_B.writeVoltage =
      SolarTrackerSimulationModel1_B.voltage;
  } else {
    switch (SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage) {
     case SolarTrackerS_IN_GoToMaxVoltage:
      if (SolarTrackerSimulationModel1_DW.temporalCounter_i1 >= 20U) {
        SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage =
          SolarTrackerSi_IN_ResetPosition;
        SolarTrackerSimulationModel1_B.maxVolt = 0.0;
        SolarTrackerSimulationModel1_B.maxVoltAngle = 0.0;
        SolarTrackerSimulationModel1_B.servoCmd = 0.0;
        memset(&SolarTrackerSimulationModel1_DW.voltage[0], 0, 181U * sizeof
               (real_T));
      } else {
        SolarTrackerSimulationModel1_B.servoCmd =
          SolarTrackerSimulationModel1_B.maxVoltAngle;
      }
      break;

     case SolarTrackerSimula_IN_Increment:
      if (SolarTrackerSimulationModel1_DW.temporalCounter_i1 >= 1U) {
        SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage =
          SolarTrackerSim_IN_ScanVoltages;
        SolarTrackerSimulationModel1_B.servoCmd =
          SolarTrackerSimulationModel1_DW.angleRange[(int16_T)
          SolarTrackerSimulationModel1_DW.i - 1];
        SolarTrackerSimulationModel1_DW.voltage[(int16_T)
          SolarTrackerSimulationModel1_DW.i - 1] =
          SolarTrackerSimulationModel1_B.voltage;
        if (SolarTrackerSimulationModel1_B.voltage >
            SolarTrackerSimulationModel1_B.maxVolt) {
          SolarTrackerSimulationModel1_B.maxVolt =
            SolarTrackerSimulationModel1_B.voltage;
          SolarTrackerSimulationModel1_B.maxVoltAngle =
            SolarTrackerSimulationModel1_DW.angleRange[(int16_T)
            SolarTrackerSimulationModel1_DW.i - 1];
        }

        SolarTrackerSimulationModel1_B.writeVoltage =
          SolarTrackerSimulationModel1_DW.voltage[(int16_T)
          SolarTrackerSimulationModel1_DW.i - 1];
      }
      break;

     case SolarTrackerSi_IN_ResetPosition:
      SolarTrackerSimulationModel1_DW.i = 1.0;
      SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage =
        SolarTrackerSim_IN_ScanVoltages;
      SolarTrackerSimulationModel1_B.servoCmd =
        SolarTrackerSimulationModel1_DW.angleRange[(int16_T)
        SolarTrackerSimulationModel1_DW.i - 1];
      SolarTrackerSimulationModel1_DW.voltage[(int16_T)
        SolarTrackerSimulationModel1_DW.i - 1] =
        SolarTrackerSimulationModel1_B.voltage;
      if (SolarTrackerSimulationModel1_B.voltage >
          SolarTrackerSimulationModel1_B.maxVolt) {
        SolarTrackerSimulationModel1_B.maxVolt =
          SolarTrackerSimulationModel1_B.voltage;
        SolarTrackerSimulationModel1_B.maxVoltAngle =
          SolarTrackerSimulationModel1_DW.angleRange[(int16_T)
          SolarTrackerSimulationModel1_DW.i - 1];
      }

      SolarTrackerSimulationModel1_B.writeVoltage =
        SolarTrackerSimulationModel1_DW.voltage[(int16_T)
        SolarTrackerSimulationModel1_DW.i - 1];
      break;

     default:
      /* case IN_ScanVoltages: */
      if (SolarTrackerSimulationModel1_DW.i < 181.0) {
        SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage =
          SolarTrackerSimula_IN_Increment;
        SolarTrackerSimulationModel1_DW.temporalCounter_i1 = 0U;
        SolarTrackerSimulationModel1_DW.i++;
      } else if (SolarTrackerSimulationModel1_DW.i == 181.0) {
        SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage =
          SolarTrackerS_IN_GoToMaxVoltage;
        SolarTrackerSimulationModel1_DW.temporalCounter_i1 = 0U;
        SolarTrackerSimulationModel1_B.servoCmd =
          SolarTrackerSimulationModel1_B.maxVoltAngle;
      } else {
        SolarTrackerSimulationModel1_B.servoCmd =
          SolarTrackerSimulationModel1_DW.angleRange[(int16_T)
          SolarTrackerSimulationModel1_DW.i - 1];
        SolarTrackerSimulationModel1_DW.voltage[(int16_T)
          SolarTrackerSimulationModel1_DW.i - 1] =
          SolarTrackerSimulationModel1_B.voltage;
        if (SolarTrackerSimulationModel1_B.voltage >
            SolarTrackerSimulationModel1_B.maxVolt) {
          SolarTrackerSimulationModel1_B.maxVolt =
            SolarTrackerSimulationModel1_B.voltage;
          SolarTrackerSimulationModel1_B.maxVoltAngle =
            SolarTrackerSimulationModel1_DW.angleRange[(int16_T)
            SolarTrackerSimulationModel1_DW.i - 1];
        }

        SolarTrackerSimulationModel1_B.writeVoltage =
          SolarTrackerSimulationModel1_DW.voltage[(int16_T)
          SolarTrackerSimulationModel1_DW.i - 1];
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Update for Memory: '<Root>/Memory' */
  SolarTrackerSimulationModel1_DW.Memory_PreviousInput =
    SolarTrackerSimulationModel1_B.servoCmd;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)SolarTrackerSimulationModel1_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(SolarTrackerSimulationModel1_M)!=-1) &&
        !((rtmGetTFinal(SolarTrackerSimulationModel1_M)-
           SolarTrackerSimulationModel1_M->Timing.taskTime0) >
          SolarTrackerSimulationModel1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(SolarTrackerSimulationModel1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(SolarTrackerSimulationModel1_M)) {
      rtmSetErrorStatus(SolarTrackerSimulationModel1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SolarTrackerSimulationModel1_M->Timing.clockTick0)) {
    ++SolarTrackerSimulationModel1_M->Timing.clockTickH0;
  }

  SolarTrackerSimulationModel1_M->Timing.taskTime0 =
    SolarTrackerSimulationModel1_M->Timing.clockTick0 *
    SolarTrackerSimulationModel1_M->Timing.stepSize0 +
    SolarTrackerSimulationModel1_M->Timing.clockTickH0 *
    SolarTrackerSimulationModel1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void SolarTrackerSimulationModel1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)SolarTrackerSimulationModel1_M, 0,
                sizeof(RT_MODEL_SolarTrackerSimulati_T));
  rtmSetTFinal(SolarTrackerSimulationModel1_M, -1);
  SolarTrackerSimulationModel1_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  SolarTrackerSimulationModel1_M->Sizes.checksums[0] = (526248201U);
  SolarTrackerSimulationModel1_M->Sizes.checksums[1] = (3802228557U);
  SolarTrackerSimulationModel1_M->Sizes.checksums[2] = (1305478663U);
  SolarTrackerSimulationModel1_M->Sizes.checksums[3] = (1518909951U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    SolarTrackerSimulationModel1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SolarTrackerSimulationModel1_M->extModeInfo,
      &SolarTrackerSimulationModel1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SolarTrackerSimulationModel1_M->extModeInfo,
                        SolarTrackerSimulationModel1_M->Sizes.checksums);
    rteiSetTPtr(SolarTrackerSimulationModel1_M->extModeInfo, rtmGetTPtr
                (SolarTrackerSimulationModel1_M));
  }

  /* block I/O */
  (void) memset(((void *) &SolarTrackerSimulationModel1_B), 0,
                sizeof(B_SolarTrackerSimulationModel_T));

  /* states (dwork) */
  (void) memset((void *)&SolarTrackerSimulationModel1_DW, 0,
                sizeof(DW_SolarTrackerSimulationMode_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SolarTrackerSimulationModel1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  SolarTrackerSimulationModel1_DW.Memory_PreviousInput =
    SolarTrackerSimulationModel1_P.Memory_InitialCondition;

  /* SystemInitialize for Chart: '<Root>/voltage emulator' */
  SolarTrackerSimulationModel1_DW.sfEvent = SolarTrackerSimulati_CALL_EVENT;
  SolarTrackerSimulationModel1_DW.is_active_c3_SolarTrackerSimula = 0U;
  SolarTrackerSimulationModel1_DW.is_c3_SolarTrackerSimulationMod = 0UL;
  SolarTrackerSimulationModel1_DW.maxAngle = 0.0;
  SolarTrackerSimulationModel1_DW.maxVoltage = 0.0;
  SolarTrackerSimulationModel1_B.voltage = 0.0;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  SolarTrackerSimulationModel1_DW.sfEvent_k = SolarTrackerSimulati_CALL_EVENT;
  SolarTrackerSimulationModel1_DW.is_ScanAndGoToMaxVoltage = 0UL;
  SolarTrackerSimulationModel1_DW.temporalCounter_i1 = 0U;
  SolarTrackerSimulationModel1_DW.is_active_c1_SolarTrackerSimula = 0U;
  SolarTrackerSimulationModel1_DW.is_c1_SolarTrackerSimulationMod = 0UL;
  SolarTrackerSimulationModel1_DW.i = 0.0;
  memset(&SolarTrackerSimulationModel1_DW.voltage[0], 0, 181U * sizeof(real_T));
  memset(&SolarTrackerSimulationModel1_DW.angleRange[0], 0, 181U * sizeof(real_T));
  SolarTrackerSimulationModel1_B.servoCmd = 0.0;
  SolarTrackerSimulationModel1_B.writeVoltage = 0.0;
  SolarTrackerSimulationModel1_B.maxVolt = 0.0;
  SolarTrackerSimulationModel1_B.maxVoltAngle = 0.0;
}

/* Model terminate function */
void SolarTrackerSimulationModel1_terminate(void)
{
  /* (no terminate code required) */
}
