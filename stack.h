#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>

#include "school.h"
#include "string.h"
#define STACK_SIZE 1000

std_t school[STACK_SIZE];

int sp;

typedef enum
{
STACK_DONE,
STACK_EMPTY,
STACK_FULL
}stackStatus_t;

stackStatus_t push(void);

stackStatus_t pop(void);


#endif // STACK_H_
