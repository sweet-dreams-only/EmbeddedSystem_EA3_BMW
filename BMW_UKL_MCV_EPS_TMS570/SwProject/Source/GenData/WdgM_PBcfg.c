/*** Generated code, do not change!                                        ***/
/*** Module WdgM_PBcfg, written by Wdg_Mgr_Cfg_Gen 2.0.1 (build 204883) on ***/
/*** Wed 10-Sep-2014 17:34:58                                              ***/

#include "WdgM.h"
#include "WdgM_PBcfg.h"

#define NR_OF_CHECKPOINTS 39
#define NR_OF_ENTITIES 19
#define NR_OF_WATCHDOGS 1
#define NR_OF_TRIGGER_MODES 1
#define NR_OF_ALLOWED_CALLERS 1
#define NR_OF_GLOBAL_TRANSITIONS 14
#define NR_OF_LOCAL_TRANSITIONS 19


#define WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms10                                                 */
static WdgM_EntityStatusLType EntityStatusL_0;
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE1_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms10                                                   */
static WdgM_EntityStatusLType EntityStatusL_1;
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE2_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE4ms10                                                   */
static WdgM_EntityStatusLType EntityStatusL_2;
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE2_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE4ms10`                                 */
static WdgM_AliveCounterLType Alive_CounterL_0;
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE3_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE10ms9B                                                  */
static WdgM_EntityStatusLType EntityStatusL_3;
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE4_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms11                                                   */
static WdgM_EntityStatusLType EntityStatusL_4;
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE5_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms7                                                    */
static WdgM_EntityStatusLType EntityStatusL_5;
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE5_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE2ms7`                                  */
static WdgM_AliveCounterLType Alive_CounterL_1;
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE6_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE4ms7                                                    */
static WdgM_EntityStatusLType EntityStatusL_6;
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE6_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE4ms7`                                  */
static WdgM_AliveCounterLType Alive_CounterL_2;
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE7_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE10ms7                                                   */
static WdgM_EntityStatusLType EntityStatusL_7;
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE7_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE10ms7`                                 */
static WdgM_AliveCounterLType Alive_CounterL_3;
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE8_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms7                                                  */
static WdgM_EntityStatusLType EntityStatusL_8;
#define WDGM_SE8_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE8_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE100ms7`                                */
static WdgM_AliveCounterLType Alive_CounterL_4;
#define WDGM_SE8_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE9_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms9A                                                   */
static WdgM_EntityStatusLType EntityStatusL_9;
#define WDGM_SE9_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE10_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE10ms10B                                                 */
static WdgM_EntityStatusLType EntityStatusL_10;
#define WDGM_SE10_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE10_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE10ms10B`                               */
static WdgM_AliveCounterLType Alive_CounterL_5;
#define WDGM_SE10_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE11_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms9                                                  */
static WdgM_EntityStatusLType EntityStatusL_11;
#define WDGM_SE11_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE12_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE4ms9                                                    */
static WdgM_EntityStatusLType EntityStatusL_12;
#define WDGM_SE12_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE13_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms11                                                 */
static WdgM_EntityStatusLType EntityStatusL_13;
#define WDGM_SE13_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE13_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE100ms11`                               */
static WdgM_AliveCounterLType Alive_CounterL_6;
#define WDGM_SE13_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE14_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms8                                                    */
static WdgM_EntityStatusLType EntityStatusL_14;
#define WDGM_SE14_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE15_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE4ms8                                                    */
static WdgM_EntityStatusLType EntityStatusL_15;
#define WDGM_SE15_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE16_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE100ms8                                                  */
static WdgM_EntityStatusLType EntityStatusL_16;
#define WDGM_SE16_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE17_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE2ms9B                                                   */
static WdgM_EntityStatusLType EntityStatusL_17;
#define WDGM_SE17_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE17_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE2ms9B`                                 */
static WdgM_AliveCounterLType Alive_CounterL_7;
#define WDGM_SE17_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_SE18_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for SE5ms9                                                    */
static WdgM_EntityStatusLType EntityStatusL_18;
#define WDGM_SE18_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_SE18_START_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"
/* Local Alive Counters for CPs in `SE5ms9`                                  */
static WdgM_AliveCounterLType Alive_CounterL_8;
#define WDGM_SE18_STOP_SEC_VAR_NOINIT_32BIT 
#include "MemMap.h"


#define WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* Global Status for Supervised Entities                                     */
static WdgM_EntityStatusGType EntityStatusG_0;
static WdgM_EntityStatusGType EntityStatusG_1;
static WdgM_EntityStatusGType EntityStatusG_2;
static WdgM_EntityStatusGType EntityStatusG_3;
static WdgM_EntityStatusGType EntityStatusG_4;
static WdgM_EntityStatusGType EntityStatusG_5;
static WdgM_EntityStatusGType EntityStatusG_6;
static WdgM_EntityStatusGType EntityStatusG_7;
static WdgM_EntityStatusGType EntityStatusG_8;
static WdgM_EntityStatusGType EntityStatusG_9;
static WdgM_EntityStatusGType EntityStatusG_10;
static WdgM_EntityStatusGType EntityStatusG_11;
static WdgM_EntityStatusGType EntityStatusG_12;
static WdgM_EntityStatusGType EntityStatusG_13;
static WdgM_EntityStatusGType EntityStatusG_14;
static WdgM_EntityStatusGType EntityStatusG_15;
static WdgM_EntityStatusGType EntityStatusG_16;
static WdgM_EntityStatusGType EntityStatusG_17;
static WdgM_EntityStatusGType EntityStatusG_18;

/* Global Alive Counters for Checkpoints in SE `SE4ms10`                     */
static WdgM_AliveCounterGType Alive_CounterG_0;

/* Global Alive Counters for Checkpoints in SE `SE2ms7`                      */
static WdgM_AliveCounterGType Alive_CounterG_1;

/* Global Alive Counters for Checkpoints in SE `SE4ms7`                      */
static WdgM_AliveCounterGType Alive_CounterG_2;

/* Global Alive Counters for Checkpoints in SE `SE10ms7`                     */
static WdgM_AliveCounterGType Alive_CounterG_3;

/* Global Alive Counters for Checkpoints in SE `SE100ms7`                    */
static WdgM_AliveCounterGType Alive_CounterG_4;

/* Global Alive Counters for Checkpoints in SE `SE10ms10B`                   */
static WdgM_AliveCounterGType Alive_CounterG_5;

/* Global Alive Counters for Checkpoints in SE `SE100ms11`                   */
static WdgM_AliveCounterGType Alive_CounterG_6;

/* Global Alive Counters for Checkpoints in SE `SE2ms9B`                     */
static WdgM_AliveCounterGType Alive_CounterG_7;

/* Global Alive Counters for Checkpoints in SE `SE5ms9`                      */
static WdgM_AliveCounterGType Alive_CounterG_8;

/* RAM section for Global Status                                             */
static WdgM_DataGType StatusG;
#define WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"
/* RAM section for Global Shared data                                        */
static WdgM_DataGSType StatusGS;
static WdgM_EntityGSType EntityGS [NR_OF_ENTITIES];
static WdgM_GlobalTransitionFlagGSType GlobalTransitionFlagsGS [NR_OF_GLOBAL_TRANSITIONS];
#define WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_TransitionType WdgMTransition [NR_OF_LOCAL_TRANSITIONS] =
  { { 0 /* SE100ms10 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp10_100msStart */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [0]                                                               */
  , { 1 /* SE2ms10 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp10_2msStart */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [1]                                                               */
  , { 2 /* SE4ms10 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp10_4msStart */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [2]                                                               */
  , { 3 /* SE10ms9B */ /* EntitySourceId                                     */
    , 0 /* ChkPtAp9_10msStartB */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [3]                                                               */
  , { 4 /* SE2ms11 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp11_2msStart */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [4]                                                               */
  , { 5 /* SE2ms7 */ /* EntitySourceId                                       */
    , 0 /* ChkPtAp7_2msStart */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [5]                                                               */
  , { 6 /* SE4ms7 */ /* EntitySourceId                                       */
    , 0 /* ChkPtAp7_4msStart */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [6]                                                               */
  , { 7 /* SE10ms7 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp7_10msStart */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [7]                                                               */
  , { 8 /* SE100ms7 */ /* EntitySourceId                                     */
    , 0 /* ChkPtAp7_100msStart */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [8]                                                               */
  , { 9 /* SE2ms9A */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp9_2msStartA */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [9]                                                               */
  , { 10 /* SE10ms10B */ /* EntitySourceId                                   */
    , 0 /* ChkPtAp10_10msStartB */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [10]                                                              */
  , { 11 /* SE100ms9 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp9_100msStart */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [11]                                                              */
  , { 12 /* SE4ms9 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp9_4msStart */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [12]                                                              */
  , { 13 /* SE100ms11 */ /* EntitySourceId                                   */
    , 0 /* ChkPtAp11_100msStart */ /* CheckpointSourceId                     */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [13]                                                              */
  , { 14 /* SE2ms8 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp8_2msStart */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [14]                                                              */
  , { 15 /* SE4ms8 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp8_4msStart */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [15]                                                              */
  , { 16 /* SE100ms8 */ /* EntitySourceId                                    */
    , 0 /* ChkPtAp8_100msStart */ /* CheckpointSourceId                      */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [16]                                                              */
  , { 17 /* SE2ms9B */ /* EntitySourceId                                     */
    , 0 /* ChkPtAp9_2msStartB */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [17]                                                              */
  , { 18 /* SE5ms9 */ /* EntitySourceId                                      */
    , 0 /* ChkPtAp9_5msStart */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    } /* [18]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_GlobalTransitionType WdgMGlobalTransition [NR_OF_GLOBAL_TRANSITIONS] =
  { { 11 /* SE100ms9 */ /* EntitySourceId                                    */
    , 1 /* ChkPtAp9_100msEnd */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 0 /* GlobalTransitionFlagId                                              */
    } /* [0]                                                               */
  , { 9 /* SE2ms9A */ /* EntitySourceId                                      */
    , 1 /* ChkPtAp9_2msEndA */ /* CheckpointSourceId                         */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 1 /* GlobalTransitionFlagId                                              */
    } /* [1]                                                               */
  , { 15 /* SE4ms8 */ /* EntitySourceId                                      */
    , 1 /* ChkPtAp8_4msEnd */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 2 /* GlobalTransitionFlagId                                              */
    } /* [2]                                                               */
  , { 7 /* SE10ms7 */ /* EntitySourceId                                      */
    , 1 /* ChkPtAp7_10msEnd */ /* CheckpointSourceId                         */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 3 /* GlobalTransitionFlagId                                              */
    } /* [3]                                                               */
  , { 1 /* SE2ms10 */ /* EntitySourceId                                      */
    , 1 /* ChkPtAp10_2msEnd */ /* CheckpointSourceId                         */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 4 /* GlobalTransitionFlagId                                              */
    } /* [4]                                                               */
  , { 5 /* SE2ms7 */ /* EntitySourceId                                       */
    , 1 /* ChkPtAp7_2msEnd */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 5 /* GlobalTransitionFlagId                                              */
    } /* [5]                                                               */
  , { 3 /* SE10ms9B */ /* EntitySourceId                                     */
    , 1 /* ChkPtAp9_10msEndB */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 6 /* GlobalTransitionFlagId                                              */
    } /* [6]                                                               */
  , { 16 /* SE100ms8 */ /* EntitySourceId                                    */
    , 1 /* ChkPtAp8_100msEnd */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 7 /* GlobalTransitionFlagId                                              */
    } /* [7]                                                               */
  , { 6 /* SE4ms7 */ /* EntitySourceId                                       */
    , 1 /* ChkPtAp7_4msEnd */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 8 /* GlobalTransitionFlagId                                              */
    } /* [8]                                                               */
  , { 0 /* SE100ms10 */ /* EntitySourceId                                    */
    , 1 /* ChkPtAp10_100msEnd */ /* CheckpointSourceId                       */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 9 /* GlobalTransitionFlagId                                              */
    } /* [9]                                                               */
  , { 4 /* SE2ms11 */ /* EntitySourceId                                      */
    , 1 /* ChkPtAp11_2msEnd */ /* CheckpointSourceId                         */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 10 /* GlobalTransitionFlagId                                             */
    } /* [10]                                                              */
  , { 12 /* SE4ms9 */ /* EntitySourceId                                      */
    , 1 /* ChkPtAp9_4msEnd */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 11 /* GlobalTransitionFlagId                                             */
    } /* [11]                                                              */
  , { 8 /* SE100ms7 */ /* EntitySourceId                                     */
    , 1 /* ChkPtAp7_100msEnd */ /* CheckpointSourceId                        */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 12 /* GlobalTransitionFlagId                                             */
    } /* [12]                                                              */
  , { 14 /* SE2ms8 */ /* EntitySourceId                                      */
    , 1 /* ChkPtAp8_2msEnd */ /* CheckpointSourceId                          */
    , 0 /* WdgMDeadlineMin                                                   */
    , 0 /* WdgMDeadlineMax                                                     */
    , 13 /* GlobalTransitionFlagId                                             */
    } /* [13]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_TransitionIdType StartsGlobalTransition_SE10ms7_ChkPtAp7_10msEnd [1] =
  { 3 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE10ms9B_ChkPtAp9_10msEndB [1] =
  { 6 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE2ms7_ChkPtAp7_2msEnd [1] =
  { 5 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE4ms7_ChkPtAp7_4msEnd [1] =
  { 8 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE2ms11_ChkPtAp11_2msEnd [1] =
  { 10 /* [0]                                                                */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE2ms8_ChkPtAp8_2msEnd [1] =
  { 13 /* [0]                                                                */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE2ms9A_ChkPtAp9_2msEndA [1] =
  { 1 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE4ms8_ChkPtAp8_4msEnd [1] =
  { 2 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE2ms10_ChkPtAp10_2msEnd [1] =
  { 4 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE100ms10_ChkPtAp10_100msEnd [1] =
  { 9 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE100ms8_ChkPtAp8_100msEnd [1] =
  { 7 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE100ms7_ChkPtAp7_100msEnd [1] =
  { 12 /* [0]                                                                */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE100ms9_ChkPtAp9_100msEnd [1] =
  { 0 /* [0]                                                                 */
  };
static const WdgM_TransitionIdType StartsGlobalTransition_SE4ms9_ChkPtAp9_4msEnd [1] =
  { 11 /* [0]                                                                */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_CheckPointType WdgMCheckPoint [NR_OF_CHECKPOINTS] =
  { { 0 /* SE100ms10/ChkPtAp10_100msStart */ /* WdgMCheckpointId             */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [0] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [0]                                                               */
  , { 1 /* SE100ms10/ChkPtAp10_100msEnd */ /* WdgMCheckpointId               */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [0] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE100ms10_ChkPtAp10_100msEnd /* WdgMStartedGlobal */
     /* TransitionIds     */
    } /* [1]                                                               */
  , { 0 /* SE2ms10/ChkPtAp10_2msStart */ /* WdgMCheckpointId                 */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [1] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [2]                                                               */
  , { 1 /* SE2ms10/ChkPtAp10_2msEnd */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [1] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE2ms10_ChkPtAp10_2msEnd /* WdgMStartedGlobalTran */
     /* sitionIds             */
    } /* [3]                                                               */
  , { 0 /* SE4ms10/ChkPtAp10_4msStart */ /* WdgMCheckpointId                 */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [2] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [4]                                                               */
  , { 1 /* SE4ms10/ChkPtAp10_4msEnd */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_0 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_0 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [2] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [5]                                                               */
  , { 0 /* SE10ms9B/ChkPtAp9_10msStartB */ /* WdgMCheckpointId               */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [3] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [6]                                                               */
  , { 1 /* SE10ms9B/ChkPtAp9_10msEndB */ /* WdgMCheckpointId                 */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [3] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE10ms9B_ChkPtAp9_10msEndB /* WdgMStartedGlobalTr */
     /* ansitionIds         */
    } /* [7]                                                               */
  , { 0 /* SE2ms11/ChkPtAp11_2msStart */ /* WdgMCheckpointId                 */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [4] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [8]                                                               */
  , { 1 /* SE2ms11/ChkPtAp11_2msEnd */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [4] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE2ms11_ChkPtAp11_2msEnd /* WdgMStartedGlobalTran */
     /* sitionIds             */
    } /* [9]                                                               */
  , { 0 /* SE2ms7/ChkPtAp7_2msStart */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_1 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_1 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [10]                                                              */
  , { 1 /* SE2ms7/ChkPtAp7_2msEnd */ /* WdgMCheckpointId                     */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [5] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE2ms7_ChkPtAp7_2msEnd /* WdgMStartedGlobalTransi */
     /* tionIds                 */
    } /* [11]                                                              */
  , { 2 /* SE2ms7/GlblFinal_CP0 */ /* WdgMCheckpointId                       */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , TRUE /* WdgMIsEndCheckpointGlobal                                      */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [12]                                                              */
  , { 0 /* SE4ms7/ChkPtAp7_4msStart */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_2 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_2 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [13]                                                              */
  , { 1 /* SE4ms7/ChkPtAp7_4msEnd */ /* WdgMCheckpointId                     */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [6] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE4ms7_ChkPtAp7_4msEnd /* WdgMStartedGlobalTransi */
     /* tionIds                 */
    } /* [14]                                                              */
  , { 0 /* SE10ms7/ChkPtAp7_10msStart */ /* WdgMCheckpointId                 */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 5 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_3 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_3 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [15]                                                              */
  , { 1 /* SE10ms7/ChkPtAp7_10msEnd */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [7] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE10ms7_ChkPtAp7_10msEnd /* WdgMStartedGlobalTran */
     /* sitionIds             */
    } /* [16]                                                              */
  , { 0 /* SE100ms7/ChkPtAp7_100msStart */ /* WdgMCheckpointId               */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 25 /* WdgMSupervisionReferenceCycle                                      */
    , &Alive_CounterL_4 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_4 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [17]                                                              */
  , { 1 /* SE100ms7/ChkPtAp7_100msEnd */ /* WdgMCheckpointId                 */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [8] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE100ms7_ChkPtAp7_100msEnd /* WdgMStartedGlobalTr */
     /* ansitionIds         */
    } /* [18]                                                              */
  , { 0 /* SE2ms9A/ChkPtAp9_2msStartA */ /* WdgMCheckpointId                 */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [5] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [19]                                                              */
  , { 1 /* SE2ms9A/ChkPtAp9_2msEndA */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [9] /* WdgMLocalTransitionRef                            */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE2ms9A_ChkPtAp9_2msEndA /* WdgMStartedGlobalTran */
     /* sitionIds             */
    } /* [20]                                                              */
  , { 0 /* SE10ms10B/ChkPtAp10_10msStartB */ /* WdgMCheckpointId             */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [6] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [21]                                                              */
  , { 1 /* SE10ms10B/ChkPtAp10_10msEndB */ /* WdgMCheckpointId               */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 5 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_5 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_5 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [10] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [22]                                                              */
  , { 0 /* SE100ms9/ChkPtAp9_100msStart */ /* WdgMCheckpointId               */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [7] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [23]                                                              */
  , { 1 /* SE100ms9/ChkPtAp9_100msEnd */ /* WdgMCheckpointId                 */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [11] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE100ms9_ChkPtAp9_100msEnd /* WdgMStartedGlobalTr */
     /* ansitionIds         */
    } /* [24]                                                              */
  , { 0 /* SE4ms9/ChkPtAp9_4msStart */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [8] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [25]                                                              */
  , { 1 /* SE4ms9/ChkPtAp9_4msEnd */ /* WdgMCheckpointId                     */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [12] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE4ms9_ChkPtAp9_4msEnd /* WdgMStartedGlobalTransi */
     /* tionIds                 */
    } /* [26]                                                              */
  , { 0 /* SE100ms11/ChkPtAp11_100msStart */ /* WdgMCheckpointId             */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [9] /* WdgMGlobalTransitionsRef                    */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [27]                                                              */
  , { 1 /* SE100ms11/ChkPtAp11_100msEnd */ /* WdgMCheckpointId               */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 1 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 25 /* WdgMSupervisionReferenceCycle                                      */
    , &Alive_CounterL_6 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_6 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [13] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [28]                                                              */
  , { 0 /* SE2ms8/ChkPtAp8_2msStart */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [10] /* WdgMGlobalTransitionsRef                   */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [29]                                                              */
  , { 1 /* SE2ms8/ChkPtAp8_2msEnd */ /* WdgMCheckpointId                     */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [14] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE2ms8_ChkPtAp8_2msEnd /* WdgMStartedGlobalTransi */
     /* tionIds                 */
    } /* [30]                                                              */
  , { 0 /* SE4ms8/ChkPtAp8_4msStart */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [11] /* WdgMGlobalTransitionsRef                   */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [31]                                                              */
  , { 1 /* SE4ms8/ChkPtAp8_4msEnd */ /* WdgMCheckpointId                     */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [15] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE4ms8_ChkPtAp8_4msEnd /* WdgMStartedGlobalTransi */
     /* tionIds                 */
    } /* [32]                                                              */
  , { 0 /* SE100ms8/ChkPtAp8_100msStart */ /* WdgMCheckpointId               */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [12] /* WdgMGlobalTransitionsRef                   */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [33]                                                              */
  , { 1 /* SE100ms8/ChkPtAp8_100msEnd */ /* WdgMCheckpointId                 */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [16] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , TRUE /* WdgMStartsAGlobalTransition                                      */
    , 1 /* NrOfStartedGlobalTransitions                                        */
    , StartsGlobalTransition_SE100ms8_ChkPtAp8_100msEnd /* WdgMStartedGlobalTr */
     /* ansitionIds         */
    } /* [34]                                                              */
  , { 0 /* SE2ms9B/ChkPtAp9_2msStartB */ /* WdgMCheckpointId                 */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 1 /* NrOfGlobalTransitions                                               */
    , &WdgMGlobalTransition [13] /* WdgMGlobalTransitionsRef                   */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [35]                                                              */
  , { 1 /* SE2ms9B/ChkPtAp9_2msEndB */ /* WdgMCheckpointId                   */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 2 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 1 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_7 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_7 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [17] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [36]                                                              */
  , { 0 /* SE5ms9/ChkPtAp9_5msStart */ /* WdgMCheckpointId                   */
    , FALSE /* WdgMIsEndCheckpoint                                           */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 0 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 0 /* WdgMSupervisionReferenceCycle                                       */
    , NULL_PTR /* WdgMAliveLRef                                                */
    , NULL_PTR /* WdgMAliveGRef                                                */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 0 /* NrOfLocalTransitions                                                */
    , NULL_PTR /* WdgMLocalTransitionRef                                       */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [37]                                                              */
  , { 1 /* SE5ms9/ChkPtAp9_5msEnd */ /* WdgMCheckpointId                     */
    , TRUE /* WdgMIsEndCheckpoint                                            */
    , FALSE /* WdgMIsEndCheckpointGlobal                                     */
    , 4 /* WdgMExpectedAliveIndications                                        */
    , 0 /* WdgMMinMargin                                                       */
    , 0 /* WdgMMaxMargin                                                       */
    , 5 /* WdgMSupervisionReferenceCycle                                       */
    , &Alive_CounterL_8 /* WdgMAliveLRef                                       */
    , &Alive_CounterG_8 /* WdgMAliveGRef                                       */
    , FALSE /* WdgMDeadlineMonitoring                                          */
    , 0 /* WdgMOutgoingDeadlineMax                                             */
    , 1 /* NrOfLocalTransitions                                                */
    , &WdgMTransition [18] /* WdgMLocalTransitionRef                           */
    , 0 /* NrOfGlobalTransitions                                               */
    , NULL_PTR /* WdgMGlobalTransitionsRef                                     */
    , FALSE /* WdgMStartsAGlobalTransition                                     */
    , 0 /* NrOfStartedGlobalTransitions                                        */
    , NULL_PTR /* WdgMStartedGlobalTransitionIds                               */
    } /* [38]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_SupervisedEntityType WdgMSupervisedEntity [NR_OF_ENTITIES] =
  { { 0 /* SE100ms10 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [0] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_0 /* EntityStatusLRef                                     */
    , &EntityStatusG_0 /* EntityStatusGRef                                     */
    } /* [0]                                                               */
  , { 1 /* SE2ms10 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [2] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_1 /* EntityStatusLRef                                     */
    , &EntityStatusG_1 /* EntityStatusGRef                                     */
    } /* [1]                                                               */
  , { 2 /* SE4ms10 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [4] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_2 /* EntityStatusLRef                                     */
    , &EntityStatusG_2 /* EntityStatusGRef                                     */
    } /* [2]                                                               */
  , { 3 /* SE10ms9B */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [6] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_3 /* EntityStatusLRef                                     */
    , &EntityStatusG_3 /* EntityStatusGRef                                     */
    } /* [3]                                                               */
  , { 4 /* SE2ms11 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [8] /* WdgMCheckpointRef                                 */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_4 /* EntityStatusLRef                                     */
    , &EntityStatusG_4 /* EntityStatusGRef                                     */
    } /* [4]                                                               */
  , { 5 /* SE2ms7 */ /* WdgMSupervisedEntityId                               */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 3 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [10] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_5 /* EntityStatusLRef                                     */
    , &EntityStatusG_5 /* EntityStatusGRef                                     */
    } /* [5]                                                               */
  , { 6 /* SE4ms7 */ /* WdgMSupervisedEntityId                               */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [13] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_6 /* EntityStatusLRef                                     */
    , &EntityStatusG_6 /* EntityStatusGRef                                     */
    } /* [6]                                                               */
  , { 7 /* SE10ms7 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [15] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_7 /* EntityStatusLRef                                     */
    , &EntityStatusG_7 /* EntityStatusGRef                                     */
    } /* [7]                                                               */
  , { 8 /* SE100ms7 */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [17] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_8 /* EntityStatusLRef                                     */
    , &EntityStatusG_8 /* EntityStatusGRef                                     */
    } /* [8]                                                               */
  , { 9 /* SE2ms9A */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [19] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_9 /* EntityStatusLRef                                     */
    , &EntityStatusG_9 /* EntityStatusGRef                                     */
    } /* [9]                                                               */
  , { 10 /* SE10ms10B */ /* WdgMSupervisedEntityId                           */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [21] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_10 /* EntityStatusLRef                                    */
    , &EntityStatusG_10 /* EntityStatusGRef                                    */
    } /* [10]                                                              */
  , { 11 /* SE100ms9 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [23] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_11 /* EntityStatusLRef                                    */
    , &EntityStatusG_11 /* EntityStatusGRef                                    */
    } /* [11]                                                              */
  , { 12 /* SE4ms9 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [25] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_12 /* EntityStatusLRef                                    */
    , &EntityStatusG_12 /* EntityStatusGRef                                    */
    } /* [12]                                                              */
  , { 13 /* SE100ms11 */ /* WdgMSupervisedEntityId                           */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [27] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_13 /* EntityStatusLRef                                    */
    , &EntityStatusG_13 /* EntityStatusGRef                                    */
    } /* [13]                                                              */
  , { 14 /* SE2ms8 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [29] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_14 /* EntityStatusLRef                                    */
    , &EntityStatusG_14 /* EntityStatusGRef                                    */
    } /* [14]                                                              */
  , { 15 /* SE4ms8 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [31] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_15 /* EntityStatusLRef                                    */
    , &EntityStatusG_15 /* EntityStatusGRef                                    */
    } /* [15]                                                              */
  , { 16 /* SE100ms8 */ /* WdgMSupervisedEntityId                            */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [33] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_16 /* EntityStatusLRef                                    */
    , &EntityStatusG_16 /* EntityStatusGRef                                    */
    } /* [16]                                                              */
  , { 17 /* SE2ms9B */ /* WdgMSupervisedEntityId                             */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [35] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_17 /* EntityStatusLRef                                    */
    , &EntityStatusG_17 /* EntityStatusGRef                                    */
    } /* [17]                                                              */
  , { 18 /* SE5ms9 */ /* WdgMSupervisedEntityId                              */
    , FALSE /* WdgMEnableEntityDeactivation                                  */
    , 0 /* WdgMCheckpointLocInitialId                                        */
    , 2 /* NrOfCheckpoints                                                     */
    , &WdgMCheckPoint [37] /* WdgMCheckpointRef                                */
    , WDGM_LOCAL_STATUS_OK /* WdgMInitialStatus                                */
    , 0 /* WdgMFailedSupervisionRefCycleTol                                    */
    , 0 /* WdgMFailedDeadlineRefCycleTol                                       */
    , 0 /* WdgMDeadlineReferenceCycle                                          */
    , 0 /* WdgMFailedProgramFlowRefCycleTol                                    */
    , 0 /* WdgMProgramFlowReferenceCycle                                       */
    , TRUE /* WdgMProgramFlowMonitoring                                        */
    , WDGM_INVALID_OSAPPLICATION /* OSApplication                              */
    , NULL_PTR /* WdgM_LocalStateChangeCbk                                     */
    , &EntityStatusL_18 /* EntityStatusLRef                                    */
    , &EntityStatusG_18 /* EntityStatusGRef                                    */
    } /* [18]                                                              */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

static const WdgM_TriggerModeType WdgMTriggerMode  [NR_OF_WATCHDOGS * NR_OF_TRIGGER_MODES] =
  { { 2 /* WdgMTriggerWindowStart                                            */
    , 2000  /* WdgMTicksPerSecond[Hz]=1000000 */ /* WdgMTriggerWindowStartTi */
     /* cks                      */
    , 6 /* WdgMTriggerTimeout                                                  */
    , 6000 /* WdgMTriggerTimeoutTicks                                          */
    , WDGIF_SLOW_MODE /* WdgMWatchdogMode                                      */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
/* [0]: Watchdog `WdgMWatchdog`, trigger mode ID `0`                         */


#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_WatchdogDeviceType WdgMWatchdogDevice [NR_OF_WATCHDOGS] =
  { { &WdgMTriggerMode  [0] /* WdgMTriggerModeRef                            */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
static const WdgM_CallersType WdgMAllowedCallers  [NR_OF_ALLOWED_CALLERS] =
  { { 0 /* WdgMAllowedCaller                                                 */
    } /* [0]                                                               */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
const WdgM_ConfigType WdgMConfig_Mode0 =
  { 2 /* WdgMConfigMajorVersion                                              */
  , 0 /* WdgMConfigMinorVersion                                              */
  , 0 /* WdgMConfigId                                                        */
  , 0 /* WdgMInitialTriggerModeId                                              */
  , 0 /* WdgMExpiredSupervisionCycleTol                                        */
  , 5 /* WdgMGlobInitialEntityId                                               */
  , 0 /* WdgMGlobInitialCheckpointId                                           */
  , NR_OF_CHECKPOINTS /* NrOfAllCheckpoints                                    */
  , NR_OF_GLOBAL_TRANSITIONS /* NrOfGlobalTransitions                          */
  , NR_OF_WATCHDOGS /* NrOfWatchdogDevices                                     */
  , NR_OF_TRIGGER_MODES /* NrOfTriggerModes                                    */
  , WdgMWatchdogDevice /* WdgMWatchdogDeviceRef                                */
  , NR_OF_ALLOWED_CALLERS /* NrOfAllowedCallers                                */
  , WdgMAllowedCallers  /* WdgMCallersRef                                      */
  , NR_OF_ENTITIES /* NrOfSupervisedEntities                                   */
  , WdgMSupervisedEntity /* WdgMSupervisedEntityRef                            */
  , &StatusG /* DataGRef                                                       */
  , &StatusGS /* DataGSRef                                                     */
  , EntityGS /* EntityGSRef                                                    */
  , GlobalTransitionFlagsGS /* GlobalTransitionFlagsGSRef                      */
  , NULL_PTR /* WdgM_GlobalStateChangeCbk                                      */
  , 301 /* WdgMConfigChecksum                                                  */
  };
#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h"
