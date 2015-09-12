#ifndef __GTESTS_H
#define __GTESTS_H

#include <QtCore/QString>
#include <math.h>
#include <gtest/gtest.h>

#define SWAP_DEFINED
#include "opentx.h"

#define CHANNEL_MAX (1024*256)

extern int32_t lastAct;
extern uint16_t anaInValues[NUM_STICKS+NUM_POTS];

void doMixerCalculations();

inline void MODEL_RESET()
{
  memset(&g_model, 0, sizeof(g_model));
  memset(&anaInValues, 0, sizeof(anaInValues));
  extern uint8_t s_mixer_first_run_done;
  s_mixer_first_run_done = false;
  lastFlightMode = 255;
}

inline void MIXER_RESET()
{
  memset(channelOutputs, 0, sizeof(channelOutputs));
  memset(chans, 0, sizeof(chans));
  memset(ex_chans, 0, sizeof(ex_chans));
  memset(act, 0, sizeof(act));
  memset(swOn, 0, sizeof(swOn));
#if !defined(CPUARM)
  s_last_switch_used = 0;
  s_last_switch_value = 0;
#endif
  mixerCurrentFlightMode = lastFlightMode = 0;
  lastAct = 0;
  logicalSwitchesReset();
}

#if defined(FRSKY)
inline void TELEMETRY_RESET()
{
  memclear(&frskyData, sizeof(frskyData));
  frskyData.rssi[0].value = 100;
}
#endif

bool checkScreenshot(QString test);

#endif
