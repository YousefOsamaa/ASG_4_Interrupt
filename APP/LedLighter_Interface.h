#ifndef LEDLIGHTER_INTERFACE_FILE
#define LEDLIGHTER_INTERFACE_FILE

#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"


//APIs' prototypes
void Ledlighter_enu_IncrementCount(void* Copy_pvid_Parameters);

void Ledlighter_enu_DecrementCount(void* Copy_pvid_Parameters);

extern ErrorState_t LedLighter_enu_initialization(void);

extern ErrorState_t LedLighter_enu_Operate(void);


#endif