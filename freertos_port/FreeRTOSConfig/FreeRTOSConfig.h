#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configTICK_RATE_HZ          ( 1000 ) /* Define the FreeRTOS tick rate in Hz */
#define configMAX_PRIORITIES 		( 32 )
/* We need the CPU clock frequency for the RISC-V port. Let's define a placeholder
 * for now. We will replace this with the actual value from the RA02G21
 * Hardware Manual.
 */
#define configCPU_CLOCK_HZ          ( 500000UL ) // Default System oscillator is MOCO and it is operating on 8MHz and default clock divider is 1/16 so frequency comes out to be 500kHz

/* Define the total heap size for FreeRTOS. Adjust as needed. */
#define configTOTAL_HEAP_SIZE       ( 16384 ) /* Size in bytes */

/* Minimum stack size for tasks (in words). */
#define configMINIMAL_STACK_SIZE    ( 128 )

/* Stack type used by FreeRTOS tasks. */
#define configTASK_STACK_DEPTH_TYPE  uint32_t

/* Set the maximum priority from which FreeRTOS API functions can be called safely.
 * This depends on your interrupt priority setup on the RA02G21 and the CLIC.
 * We will need to revisit this once we understand the CLIC priority levels.
 * For now, let's use a common starting point. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY ( 4 ) /* Example value, needs verification */

/* The priority of the FreeRTOS kernel's interrupt (e.g., the tick interrupt).
 * Again, this needs to align with the CLIC priority levels. */
#define configKERNEL_INTERRUPT_PRIORITY      ( 5 ) /* Example value, needs verification */

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK             ( 1 )
#define configUSE_TICK_HOOK             ( 0 )
#define configCHECK_FOR_STACK_OVERFLOW  ( 2 ) /* Or 1 if you want basic checking */
#define configUSE_MALLOC_FAILED_HOOK    ( 1 )

/* Task related definitions. */
#define configUSE_PREEMPTION            ( 1 )
#define configUSE_TIME_SLICING          ( 1 )
#define configIDLE_SHOULD_YIELD         ( 1 )
#define configUSE_TASK_NOTIFICATIONS    ( 1 )
#define configSUPPORT_STATIC_ALLOCATION ( 1 )
#define configSUPPORT_DYNAMIC_ALLOCATION ( 1 )

/* Queue related definitions. */
#define configUSE_QUEUE_SETS          ( 0 )
#define configUSE_QUEUE_STORAGE_CALLS ( 0 )

/* Software timer related definitions. */
#define configUSE_TIMERS              ( 1 )
#define configTIMER_TASK_PRIORITY     ( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH      ( 10 )
#define configTIMER_TASK_STACK_DEPTH  ( configMINIMAL_STACK_SIZE * 2 )

/* Stream buffer related definitions. */
#define configUSE_STREAM_BUFFERS      ( 0 )

/* Event group related definitions. */
#define configUSE_EVENT_GROUPS        ( 1 )

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES         ( 0 )
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Memory region related definitions. */
#define configUSE_REGION_PERMISSIONS  ( 0 )

/* Define the base addresses for the machine timer. These should match
 * the addresses in the RA02G21 Hardware Manual. */
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


#define configUSE_16_BIT_TICKS    ( 1 )

/* Set this to the number of bits used to represent a priority level.
 * We need to determine this from the RA02G21's CLIC implementation.
 * This is a placeholder for now. */
#define configPRIO_BITS               ( 4 ) // Because there are 16 priority levels and 2^4=16

#endif /* FREERTOS_CONFIG_H */
