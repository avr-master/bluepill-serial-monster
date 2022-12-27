#include <string.h>
#include "stm32f10x.h"
#include "system_interrupts.h"

void system_interrupts_init() {
    NVIC_SetPriorityGrouping(SYSTEM_INTERRUPTS_PRIORITY_GROUPING);
}
