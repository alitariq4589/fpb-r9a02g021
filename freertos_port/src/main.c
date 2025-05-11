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
    /* Perform any necessary hardware initialization. */
    prvSetupHardware();
//
//    /* Configure and enable the Machine Timer for FreeRTOS tick. */
//    R_CPU_AUX->MACTCR_b.ENABLE = 0;      // First, disable the timer (good practice)
//    R_CPU_AUX->MACTCR_b.CLOCKSOURCE = 1; // Select the clock source (0 is an example, refer to the manual!)
//    R_CPU_AUX->MACTCR_b.ENABLE = 1;      // Enable the MTIME counter
//
//    /* Create a simple queue. */
//    xIntegerQueue = xQueueCreate( mainQUEUE_LENGTH, sizeof( uint32_t ) );
//
//    /* Create a blinky task. */
//    xTaskCreate( prvBlinkyTask,       /* The function that implements the task. */
//                 "Blinky",           /* The text name assigned to the task - for debug only. */
//                 configMINIMAL_STACK_SIZE, /* The size of the stack to allocate to the task. */
//                 NULL,               /* The parameter passed to the task - not used in this case. */
//                 mainTASK_BLINKY_PRIORITY, /* The priority assigned to the task. */
//                 &xBlinkyTask );     /* The task handle is not required, so NULL is passed. */
//
//    /* Start the FreeRTOS scheduler. */
//    vTaskStartScheduler();
//
//    /* Should never reach here. */
//    for( ;; );
//    return 0;
//}
///*-----------------------------------------------------------*/
//
//static void prvBlinkyTask( void *pvParameters )
//{
//    TickType_t xDelayTime;
//    const TickType_t xDelay200ms = pdMS_TO_TICKS( 200 );
//    uint32_t ulLEDState = 0;
//
//    /* Remove compiler warning about unused parameter. */
//    ( void ) pvParameters;
//
//    for( ;; )
//    {
//        /* Control an LED here. You'll need to use the RA02G21's
//           register definitions from iodefine.h (or a similar header).
//           Example (you will need to adapt this):
//
//           if (ulLEDState == 0) {
//               // Set LED ON using iodefine.h macros for your LED pin
//               // Example: P1.DOUT.BIT.B0 = 1;
//               ulLEDState = 1;
//           } else {
//               // Set LED OFF
//               // Example: P1.DOUT.BIT.B0 = 0;
//               ulLEDState = 0;
//           }
//        */
//
//        /* Send the current LED state to the queue (optional). */
//        xQueueSend( xIntegerQueue, &ulLEDState, 0 );
//
//        /* Delay for a bit. */
////        vTaskDelay( xDelay200ms );
//    }
//}
///*-----------------------------------------------------------*/
//
//static void prvSetupHardware( void )
//{
//    /* Configure the system clock and enable peripherals here.
//       This is where you will need to add the code to:
//
//       1. Initialize the clock system for your RA02G21.
//       2. Configure the GPIO pin connected to your LED as an output.
//       3. **Crucially, configure and enable the MTIME timer for the FreeRTOS tick.**
//
//       You will use the register definitions from iodefine.h (or a similar
//       header file for the RA02G21) to access the hardware registers.
//
//       Example for enabling MTIME (you will need to adapt the clock source):
//
//       CPU_AUX.MACTCR &= ~(0b11 << 1); // Clear CLOCKSOURCE bits
//       CPU_AUX.MACTCR |= (0b00 << 1);  // Example: Select a clock source
//       CPU_AUX.MACTCR |= (1 << 0);     // Enable MTIME
//    */
//
//    /* Placeholder for hardware initialization. */
}
/*-----------------------------------------------------------*/
