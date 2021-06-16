#include "SolarTrackerSimulationModel1.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  SolarTrackerSimulationModel1_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.1;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(SolarTrackerSimulationModel1_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  SolarTrackerSimulationModel1_initialize();
  cli();
  sei ();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(SolarTrackerSimulationModel1_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(SolarTrackerSimulationModel1_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(SolarTrackerSimulationModel1_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(SolarTrackerSimulationModel1_M) == (NULL)) &&
    !rtmGetStopRequested(SolarTrackerSimulationModel1_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(SolarTrackerSimulationModel1_M->extModeInfo, 1,
                       &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(SolarTrackerSimulationModel1_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(SolarTrackerSimulationModel1_M) ==
                       (NULL)) && !rtmGetStopRequested
                      (SolarTrackerSimulationModel1_M));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  SolarTrackerSimulationModel1_terminate();
  rtExtModeShutdown(1);
  cli();
  return 0;
}
