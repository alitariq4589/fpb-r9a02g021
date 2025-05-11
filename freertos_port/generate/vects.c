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
* Copyright (C) 2021-2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : vects.c
* Version          : V1.00
* Device(s)        : R9A02G021
* Description      : None
* Creation Date    : 2024/03/21
***********************************************************************************************************************/

#include <stdint.h>
#include "iodefine.h"
#include "interrupt_handlers.h"

void nvect_function(void);
void initialize_vect(void);

#define VECT_SECT          __attribute__ ((section (".vects")))
const void *InterruptVectors[] VECT_SECT = {
	// ID 0 : Reserved
	INT_DUMMY,
	// ID 1 : Reserved
	INT_DUMMY,
	// ID 2 : Reserved
	INT_DUMMY,
	// ID 3 : INT_ACLINT_MSIP
	INT_ACLINT_MSIP,
	// ID 4 : Reserved
	INT_DUMMY,
	// ID 5 : Reserved
	INT_DUMMY,
	// ID 6 : Reserved
	INT_DUMMY,
	// ID 7 : INT_ACLINT_MTIP
	INT_ACLINT_MTIP,
	// ID 8 : Reserved
	INT_DUMMY,
	// ID 9 : Reserved
	INT_DUMMY,
	// ID 10 : Reserved
	INT_DUMMY,
	// ID 11 : Reserved
	INT_DUMMY,
	// ID 12 : Reserved
	INT_DUMMY,
	// ID 13 : Reserved
	INT_DUMMY,
	// ID 14 : Reserved
	INT_DUMMY,
	// ID 15 : Reserved
	INT_DUMMY,
	// ID 16 : Reserved
	INT_DUMMY,
	// ID 17 : Reserved
	INT_DUMMY,
	// ID 18 : Reserved
	INT_DUMMY,
	// ID 19 : INT_IELSR0
	INT_IELSR0,
	// ID 20 : INT_IELSR1
	INT_IELSR1,
	// ID 21 : INT_IELSR2
	INT_IELSR2,
	// ID 22 : INT_IELSR3
	INT_IELSR3,
	// ID 23 : INT_IELSR4
	INT_IELSR4,
	// ID 24 : INT_IELSR5
	INT_IELSR5,
	// ID 25 : INT_IELSR6
	INT_IELSR6,
	// ID 26 : INT_IELSR7
	INT_IELSR7,
	// ID 27 : INT_IELSR8
	INT_IELSR8,
	// ID 28 : INT_IELSR9
	INT_IELSR9,
	// ID 29 : INT_IELSR10
	INT_IELSR10,
	// ID 30 : INT_IELSR11
	INT_IELSR11,
	// ID 31 : INT_IELSR12
	INT_IELSR12,
	// ID 32 : INT_IELSR13
	INT_IELSR13,
	// ID 33 : INT_IELSR14
	INT_IELSR14,
	// ID 34 : INT_IELSR15
	INT_IELSR15,
	// ID 35 : INT_IELSR16
	INT_IELSR16,
	// ID 36 : INT_IELSR17
	INT_IELSR17,
	// ID 37 : INT_IELSR18
	INT_IELSR18,
	// ID 38 : INT_IELSR19
	INT_IELSR19,
	// ID 39 : INT_IELSR20
	INT_IELSR20,
	// ID 40 : INT_IELSR21
	INT_IELSR21,
	// ID 41 : INT_IELSR22
	INT_IELSR22,
	// ID 42 : INT_IELSR23
	INT_IELSR23,
	// ID 43 : INT_IELSR24
	INT_IELSR24,
	// ID 44 : INT_IELSR25
	INT_IELSR25,
	// ID 45 : INT_IELSR26
	INT_IELSR26,
	// ID 46 : INT_IELSR27
	INT_IELSR27,
	// ID 47 : INT_IELSR28
	INT_IELSR28,
	// ID 48 : INT_IELSR29
	INT_IELSR29,
	// ID 49 : INT_IELSR30
	INT_IELSR30,
	// ID 50 : INT_IELSR31
	INT_IELSR31,
};

#define EXVECT_SECT          __attribute__ ((section (".nvect")))
const void *ExceptVectors[] EXVECT_SECT = {
    // Address 0x140
    nvect_function
};

void nvect_function(void)
{
	// Check the contents of mcause and implement a process to branch to the appropriate process after determining what happened.
};

void initialize_vect(void)
{
	// The mtvec register must be set even if the interrupt vector table is not used.
	// Set the value (address of nvect_function()(0x1C0) >> 6)  to mtvec[31:6]
	// mtvec.BASE = 0x07;
	asm( "li t0, 0x1C2" );
	asm( "csrw mtvec, t0" );    // Set mtvec.

	// The mtvt register must be set when using the interrupt vector table.
	// Set the value (address of VECT_SECT(0xC0) >> 6) to mtvt[31:6]
	// mtvt.MTVT = 0x03;
	asm( "li t0, 0xC0" );
	asm( "csrw mtvt, t0" );     // Set mtvt.

	// The cliclintattr[i].shv bit must be set to 1 when using the interrupt vector table.
	// Set shv bit of cliclintattr[i] : CLIC Interrupt Attrtibute Register i (i = 0 to 50)
	uint8_t * pclicintattr = (uint8_t *)&R_CLIC->clicintattr0;
	for (uint8_t i = 0; i < 51; i++)
	{
		(*pclicintattr) |= 0x01;    // Set shv bit to 1.
		pclicintattr += 4;			// See next clicintattr[i] register.
	}
};

const unsigned long Option_OFS0[]  __attribute__ ((section (".option_ofs0"))) = {
    // Address 0x400
	0xffffffff
};

const unsigned long Option_OFS1[]  __attribute__ ((section (".option_ofs1"))) = {
	// Address 0x404
	0xffffcfd7
};

const unsigned long Option_FPR[]  __attribute__ ((section (".option_frp"))) = {
	// Address 0x408 - 0x43b
	0xffffffff, // 0x408
	0xffffffff, // 0x40c
	0xffffffff, // 0x410
	0xffffffff, // 0x414
	0xffffffff, // 0x418
	0xffffffff, // 0x41c
	0xffffffff, // 0x420
	0xffffffff, // 0x424
	0xffffffff, // 0x428
	0xffffffff, // 0x42c
	0xffffffff, // 0x430
	0xffffffff, // 0x434
	0xffffffff  // 0x438
};

const unsigned long Option_OSIS[]  __attribute__ ((section (".option_osis"))) = {
	// Address 0x800 - 0x80F
	0xffffffff, // 0x800
	0xffffffff, // 0x804
	0xffffffff, // 0x808
	0xffffffff  // 0x80C
};

const unsigned long Option_SECS[]  __attribute__ ((section (".option_secs"))) = {
	// Address 0x1010008
	0xffffffff
};

const unsigned long Option_AWS[]  __attribute__ ((section (".option_aws"))) = {
	// Address 0x1010010
	0xffffffff
};

const unsigned long Option_UIDS0[]  __attribute__ ((section (".option_uids0"))) = {
    // Address 0x1010018
	0xffffffff
};

const unsigned long Option_UIDS1[]  __attribute__ ((section (".option_uids1"))) = {
    // Address 0x1010020
	0xffffffff
};

const unsigned long Option_UIDS2[]  __attribute__ ((section (".option_uids2"))) = {
    // Address 0x1010028
	0xffffffff
};

const unsigned long Option_UIDS3[]  __attribute__ ((section (".option_uids3"))) = {
    // Address 0x1010030
	0xffffffff
};
