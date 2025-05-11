# fpb-r9a02g021 FreeRTOS port

Using e2 studio from Renesas, FreeRTOS port is added for the fpb-r9a02g021 MCU. This will be our device under discussion (DUT).

All the relevant documents are added in 

## Adding files

Following files are added from FreeRTOS source code to a newly created project in e2 studio.

From the `FreeRTOS/FreeRTOS/Source` directory:

- All the .c files in this directory:

1. `croutine.c` (if you plan to use co-routines)
2. `event_groups.c`
3. `list.c`
4. `queue.c`
5. `stream_buffer.c (if you plan to use stream buffers)`
6. `tasks.c`
7. `timers.c`
8. The `include` subdirectory: Add this entire subdirectory to your project's include paths.

- Create a directory named `portable/GCC` in the root of the project and copy `RISC-V` directory to that directory

- In the `src` directory of the project, add `FreeRTOS/Source/portable/MemMang/heap_4.c`


## Add `FreeRTOSConfig.h`
- Add the `FreeRTOSConfig.h` in the `src` directory of the project.

There are some important macros that must be added for this file to work.

### `configCPU_CLOCK_HZ`

The `configCPU_CLOCK_HZ` is the system clock frequency. The DUT uses multiple clock sources with clock frequency divider values and before setting this macro to a certain value, it is important to get important information from the [hardware_manual](/docs/hardware_manual.pdf) about these values.

- The clock source can be set by writing appropriate value to the `SCKSCR` register
- The clock source divider can be set by writing appropriate value to the `SCKDIVCR` register

Renesas e2 studio also has some examples which one can use for checking the register values and startup files. 

While I executed the blink code in debug mode and checking the register values in IO register window, I found out the default values of the above registers are as follows.

- `SCKDIVCR` register has value 0x04000404 with register address 0x4001e020
- `SCKSCR` register has value 0x01 at address 0x4001e026

These values tell us that the clock source is Middle-speed On-chip Oscillator `MOCO` and the divisor is 1/16. The frequency of `MOCO` is 8MHz so the total frequency which we get through this clock source with 1/16 as the divisor is `500kHz`

So we set the `configCPU_CLOCK_HZ` to `500000UL`.

### `configPRIO_BITS`

This macro defines the number of priority levels in DUT. According to hardware manual, DUT has 16 priority levels. So 2^4 total interrupt priority levels. This value will be set to 4.

### `configMAX_PRIORITIES`

I am not familiar with how this priority is set, but according to [FreeRTOS documentation](https://www.freertos.org/Documentation/02-Kernel/02-Kernel-features/01-Tasks-and-co-routines/03-Task-priorities), it should be kept to minimum value necessary. So I am setting this to 32.

### `configMAX_SYSCALL_INTERRUPT_PRIORITY`

This macro decides what are the interrupt priorities levels that if an interrupt within those priority levels arrives, it can make a FreeRTOS API call.

Setting it to 4 means interrupts with priorities 0-4 will be able to make FreeRTOS API call while the interrupts with priorites lower than that (5 and onwards) will not be able to directly make an API call for FreeRTOS kernel and will make the call indirectly.

For this MCU, since I am not yet able to obtain the information if lowest priority interrupt is the highest, I am going to assume, according to convention, that lowest priority number is indicating the highest priority.

So I will be settnig this macro to 4.

### configKERNEL_INTERRUPT_PRIORITY

This macro defines which interrupt priorities should be masked when FreeRTOS is handling more time-critical interrupts. This should be greater or equal to `configMAX_SYSCALL_INTERRUPT_PRIORITY`.

So I am keeping its value 5.

### Setting the base address of `mtime` and `mtime_cmp` registers

These are 64-bit registers in the DUT. So, they will be defined as follows.


```
/* Base address of the Machine Timer peripheral */
#define configMTIMER_BASE_ADDRESS      ( 0xE6000000ULL )

/* Offset to the lower 32 bits of the MTIME register */
#define configMTIME_LO_OFFSET          ( 0x0000ULL )

/* Offset to the upper 32 bits of the MTIME register */
#define configMTIME_HI_OFFSET          ( 0x0004ULL )

/* Offset to the lower 32 bits of the MTIMECMP register */
#define configMTIMECMP_LO_OFFSET       ( 0x0008ULL )

/* Offset to the upper 32 bits of the MTIMECMP register */
#define configMTIMECMP_HI_OFFSET       ( 0x000CULL )

/* For convenience, you can define the full 64-bit addresses using these */
#define configMTIME_BASE_ADDRESS            ( configMTIMER_BASE_ADDRESS + configMTIME_LO_OFFSET )
#define configMTIME_HI_ADDRESS         ( configMTIMER_BASE_ADDRESS + configMTIME_HI_OFFSET )
#define configMTIMECMP_BASE_ADDRESS         ( configMTIMER_BASE_ADDRESS + configMTIMECMP_LO_OFFSET )
#define configMTIMECMP_HI_ADDRESS      ( configMTIMER_BASE_ADDRESS + configMTIMECMP_HI_OFFSET )
```

After this almost all the necessary macros are set.

## Change the `port.c`

This file contains functions for timer setup and configuration. The important function here is `vPortSetupTimerInterrupt`. Check the base address values and how the 64-bit mtime and mtime_cmp are read and wrote in this function.

Check the value of `MACTCR` register. At the time of writing this doc, there is no use of that timer anywhere, so I will simply write to it in the `main()` function before anything else.

First, include the `iodefine.h` in your `main.c` since it has the definition of the MACTCR and other CPU registers.

Then add following code in the main function before calling any task initialization.

This file (alongwith everything it needs such as headers, assembly files) has to be added in the src directory instead of or `portable` directory, as the files included in that directory will be directly compiled by default by the compiler settings of e2 studio.

```
/* Configure and enable the Machine Timer for FreeRTOS tick. */
R_CPU_AUX->MACTCR_b.ENABLE = 0;      // First, disable the timer (good practice)
R_CPU_AUX->MACTCR_b.CLOCKSOURCE = 1; // 0 = machine timer clock (32.768kHz); 1 = CPU clock
R_CPU_AUX->MACTCR_b.ENABLE = 1;      // Enable the MTIME counter
```

Once these are added, building the project will generate some include errors. All the include errors should be resolved through adding the files in the include options of the project instead of changing the include statements.

## `main.c`

Once above files are added, proceed towards adding the `main.c` file. 

A blink `main.c` file, at its simplest, looks something as follows.

```
/* Standard includes. */
#include <stdio.h>
#include <string.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* Hardware includes - REPLACE THIS WITH YOUR RA02G21 HEADER */
#include "iodefine.h"

/* Task priorities. */
#define mainTASK_BLINKY_PRIORITY    ( tskIDLE_PRIORITY + 1 )

/* Queue length. */
#define mainQUEUE_LENGTH            ( 5 )

/* Task handles. */
static TaskHandle_t xBlinkyTask = NULL;

/* Queue handle. */
static QueueHandle_t xIntegerQueue = NULL;

/*-----------------------------------------------------------*/

/* Function prototypes. */
static void prvBlinkyTask( void *pvParameters );
static void prvSetupHardware( void );

/*-----------------------------------------------------------*/


void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c, heap_2.c or heap_4.c are used, then the size
	of the heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE
	in FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
}

void vApplicationGetTimerTaskMemory( void )
{
}

void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                    StackType_t ** ppxIdleTaskStackBuffer,
                                    configSTACK_DEPTH_TYPE * puxIdleTaskStackSize )
{
}


int main( void )
{
}
/*-----------------------------------------------------------*/

```

Note that the functions `vApplicationGetIdleTaskMemory`, `vApplicationIdleHook`, `vApplicationGetTimerTaskMemory`, and `vApplicationMallocFailedHook` are the functions which have to be added in the `main.c` file and the FreeRTOS expects these files, else you will get lld linker errors with llvm toolchain of e2 studio.


