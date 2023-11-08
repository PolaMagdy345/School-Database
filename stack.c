#include <stdio.h>
#include "stack.h"
#include "string.h"
#include"school.h"


stackStatus_t push(void)
{
    if(sp<STACK_SIZE)
    {
        //school[sp]=student_scan();
        student_scanByAddress(&school[sp]);
        sp++;
        no++;
        return STACK_DONE;
}
    else
    {
        return STACK_FULL;
    }
}
stackStatus_t pop(void)
{
    if(sp>0)
    {
        sp--;
        return STACK_DONE;
    }
    else
        return STACK_EMPTY;
}
