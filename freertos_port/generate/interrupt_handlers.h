/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : interrupt_handlers.h
* Version          : V0.51
* Device(s)        : R9A02G021
* Description      : None
* Creation Date    : 2023/6/7
***********************************************************************************************************************/

#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

// INT_ACLINT_MSIP (ID 3 : 0xC)
void INT_ACLINT_MSIP(void) __attribute__ ((interrupt));

// INT_ACLINT_MTIP (ID 7 : 0x1C)
void INT_ACLINT_MTIP(void) __attribute__ ((interrupt));

// INT_IELSR0 (ID 19 : 0x4C)
void INT_IELSR0(void) __attribute__ ((interrupt));

// INT_IELSR1 (ID 20 : 0x50)
void INT_IELSR1(void) __attribute__ ((interrupt));

// INT_IELSR2 (ID 21 : 0x54)
void INT_IELSR2(void) __attribute__ ((interrupt));

// INT_IELSR3 (ID 22 : 0x58)
void INT_IELSR3(void) __attribute__ ((interrupt));

// INT_IELSR4 (ID 23 : 0x5C)
void INT_IELSR4(void) __attribute__ ((interrupt));

// INT_IELSR5 (ID 24 : 0x60)
void INT_IELSR5(void) __attribute__ ((interrupt));

// INT_IELSR6 (ID 25 : 0x64)
void INT_IELSR6(void) __attribute__ ((interrupt));

// INT_IELSR7 (ID 26 : 0x68)
void INT_IELSR7(void) __attribute__ ((interrupt));

// INT_IELSR8 (ID 27 : 0x6C)
void INT_IELSR8(void) __attribute__ ((interrupt));

// INT_IELSR9 (ID 28 : 0x70)
void INT_IELSR9(void) __attribute__ ((interrupt));

// INT_IELSR10 (ID 29 : 0x74)
void INT_IELSR10(void) __attribute__ ((interrupt));

// INT_IELSR11 (ID 30 : 0x78)
void INT_IELSR11(void) __attribute__ ((interrupt));

// INT_IELSR12 (ID 31 : 0x7C)
void INT_IELSR12(void) __attribute__ ((interrupt));

// INT_IELSR13 (ID 32 : 0x80)
void INT_IELSR13(void) __attribute__ ((interrupt));

// INT_IELSR14 (ID 33 : 0x84)
void INT_IELSR14(void) __attribute__ ((interrupt));

// INT_IELSR15 (ID 34 : 0x88)
void INT_IELSR15(void) __attribute__ ((interrupt));

// INT_IELSR16 (ID 35 : 0x8C)
void INT_IELSR16(void) __attribute__ ((interrupt));

// INT_IELSR17 (ID 36 : 0x90)
void INT_IELSR17(void) __attribute__ ((interrupt));

// INT_IELSR18 (ID 37 : 0x94)
void INT_IELSR18(void) __attribute__ ((interrupt));

// INT_IELSR19 (ID 38 : 0x98)
void INT_IELSR19(void) __attribute__ ((interrupt));

// INT_IELSR20 (ID 39 : 0x9C)
void INT_IELSR20(void) __attribute__ ((interrupt));

// INT_IELSR21 (ID 40 : 0xA0)
void INT_IELSR21(void) __attribute__ ((interrupt));

// INT_IELSR22 (ID 41 : 0xA4)
void INT_IELSR22(void) __attribute__ ((interrupt));

// INT_IELSR23 (ID 42 : 0xA8)
void INT_IELSR23(void) __attribute__ ((interrupt));

// INT_IELSR24 (ID 43 : 0xAC)
void INT_IELSR24(void) __attribute__ ((interrupt));

// INT_IELSR25 (ID 44 : 0xB0)
void INT_IELSR25(void) __attribute__ ((interrupt));

// INT_IELSR26 (ID 45 : 0xB4)
void INT_IELSR26(void) __attribute__ ((interrupt));

// INT_IELSR27 (ID 46 : 0xB8)
void INT_IELSR27(void) __attribute__ ((interrupt));

// INT_IELSR28 (ID 47 : 0xBC)
void INT_IELSR28(void) __attribute__ ((interrupt));

// INT_IELSR29 (ID 48 : 0xC0)
void INT_IELSR29(void) __attribute__ ((interrupt));

// INT_IELSR30 (ID 49 : 0xC4)
void INT_IELSR30(void) __attribute__ ((interrupt));

// INT_IELSR31 (ID 50 : 0xC8)
void INT_IELSR31(void) __attribute__ ((interrupt));

// INT_DUMMY for reserved interrupt source
void INT_DUMMY(void) __attribute__ ((interrupt));

#endif
