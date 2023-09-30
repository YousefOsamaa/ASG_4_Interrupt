#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"


#include "../HAL/LED/LED_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"


#include "LedLighter_Private.h"
#include "LedLighter_Config.h"


static LedLight_t str_LEDLight;

//APIs' implementaions
void Ledlighter_enu_IncrementCount(void* Copy_pvid_Parameters)
{
    if( str_LEDLight.LightCount < str_LEDLight.LEDsCount)
    {
        str_LEDLight.LightCount++;
    }
} 

void Ledlighter_enu_DecrementCount(void* Copy_pvid_Parameters)
{
    if( str_LEDLight.LightCount > 0)
    {
        str_LEDLight.LightCount--;
    }
}

extern ErrorState_t LedLighter_enu_initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    u8 Local_u8_Count = 0;

    //INitializing LEDs
    LED_enu_Initialization();

    //Getting LEDs count
    LED_enu_GetLEDCount(&Local_u8_Count);

    str_LEDLight.LEDsCount = Local_u8_Count;
    str_LEDLight.LightCount = 0;


    //Initializing EXTTI INT) and INT1
    EXTI_enu_Initialization();


    //Setting Call back functions
    EXTI_enu_SetCallBack(EXTI_INT0, Ledlighter_enu_IncrementCount, &str_LEDLight );
    EXTI_enu_SetCallBack(EXTI_INT1, Ledlighter_enu_DecrementCount, &str_LEDLight );

    //Enabling GIE 
    SREG_vid_EnableBitI();


    return Local_u8_ErrorFlag;
}

extern ErrorState_t LedLighter_enu_Operate(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    while(1)
    {
        enu_LightLEDS();
    }
    return Local_u8_ErrorFlag;
}

static ErrorState_t enu_LightLEDS(void)
{
    u8 Local_u8_ErrorFlag = ES_OK;
    u8 Local_u8_TempErrorFlag = ES_OK;
    u8 Local_u8_Couter = 0;
    
    //Tunrning off all LEDS
    LED_enu_TurnOffAllLEDs();

    for (Local_u8_Couter = 0; Local_u8_Couter < str_LEDLight.LightCount; Local_u8_Couter++)
    {
        //Turing on LEDS equal to LightCount
        Local_u8_TempErrorFlag = LED_enu_TurnOnLED(Local_u8_Couter);

        if(Local_u8_TempErrorFlag == ES_NOK)
        {
            Local_u8_ErrorFlag = ES_NOK;
        }
    }

    return Local_u8_ErrorFlag;

}