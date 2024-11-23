/**
  PWM6 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm6.c

  @Summary
    This is the generated driver implementation file for the PWM6 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for PWM6.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1778
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "pwm6.h"

/**
  Section: PWM6 APIs
*/

void PWM6_Initialize(void)
{
    // set the PWM6 to the options selected in the User Interface

     //PHIE disabled; DCIE disabled; OFIE disabled; PRIE disabled; 
    PWM6INTE = 0x00;

     //PHIF cleared; OFIF cleared; DCIF cleared; PRIF cleared; 
    PWM6INTF = 0x00;

     //PS Divide_clock_src_by_8; CS FOSC; 
    PWM6CLKCON = 0x30;

     //LDS LD5_trigger; LDT disabled; LDA do_not_load; 
    PWM6LDCON = 0x00;

     //OFM independent_run; OFS OF5_match; OFO match_incrementing; 
    PWM6OFCON = 0x00;

     //PWM6PHH 0; 
    PWM6PHH = 0x00;

     //PWM6PHL 0; 
    PWM6PHL = 0x00;

     //PWM6DCH 8; 
    PWM6DCH = 0x08;

     //PWM6DCL 151; 
    PWM6DCL = 0x97;

     //PWM6PRH 156; 
    PWM6PRH = 0x9C;

     //PWM6PRL 63; 
    PWM6PRL = 0x3F;

     //PWM6OFH 0; 
    PWM6OFH = 0x00;

     //PWM6OFL 3; 
    PWM6OFL = 0x03;

     //PWM6TMRH 0; 
    PWM6TMRH = 0x00;

     //PWM6TMRL 0; 
    PWM6TMRL = 0x00;

     //MODE standard_PWM; POL active_hi; EN enabled; 
    PWM6CON = 0x80;

}    


void PWM6_Start(void)
{
    PWM6CONbits.EN = 1;		
}

void PWM6_Stop(void)
{
    PWM6CONbits.EN = 0;		
}

bool PWM6_CheckOutputStatus(void)
{
    return (PWM6CONbits.OUT);		
}

void PWM6_LoadBufferSet(void)
{
    PWM6LDCONbits.LDA = 1;		
}

void PWM6_PhaseSet(uint16_t phaseCount)
{
    PWM6PHH = (phaseCount>>8);        //writing 8 MSBs to PWMPHH register
    PWM6PHL = (phaseCount);           //writing 8 LSBs to PWMPHL register
}

void PWM6_DutyCycleSet(uint16_t dutyCycleCount)
{
    PWM6DCH = (dutyCycleCount>>8);	//writing 8 MSBs to PWMDCH register
    PWM6DCL = (dutyCycleCount);	//writing 8 LSBs to PWMDCL register		
}

void PWM6_PeriodSet(uint16_t periodCount)
{
    PWM6PRH = (periodCount>>8);	//writing 8 MSBs to PWMPRH register
    PWM6PRL = (periodCount);	//writing 8 LSBs to PWMPRL register		
}

void PWM6_OffsetSet(uint16_t offsetCount)
{
    PWM6OFH = (offsetCount>>8);	//writing 8 MSBs to PWMOFH register
    PWM6OFL = (offsetCount);	//writing 8 LSBs to PWMOFL register		
}

uint16_t PWM6_TimerCountGet(void)
{
    return ((uint16_t)((PWM6TMRH<<8) | PWM6TMRL));       		
}

bool PWM6_IsOffsetMatchOccured(void)
{
    return (PWM6INTFbits.OFIF);		
}

bool PWM6_IsPhaseMatchOccured(void)
{
    return (PWM6INTFbits.PHIF);	
}

bool PWM6_IsDutyCycleMatchOccured(void)
{
    return (PWM6INTFbits.DCIF);		
}

bool PWM6_IsPeriodMatchOccured(void)
{
    return (PWM6INTFbits.PRIF);		
}

/**
 End of File
*/


