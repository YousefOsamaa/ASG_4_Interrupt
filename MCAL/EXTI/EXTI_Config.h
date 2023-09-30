#ifndef EXTI_CONFIG_FILE
#define EXTI_CONFIG_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"


#define EXTI_INT_COUNT  2

typedef struct 
{
    u8 INTNumber;
    u8 INTMode;
    u8 INTSenseLevel;
}EXTI_t;

#endif