#pragma once
#include "macros.h"

#include <stddef.h>

JFLCSTD_PUBLIC typedef struct Stack {
    void *data;
    struct Stack *next;
    size_t length_;
} Stack;

JFLCSTD_PUBLIC Stack *jfl_Stack_new();
JFLCSTD_PUBLIC int jfl_Stack_push(Stack **stack, void *data);
JFLCSTD_PUBLIC void *jfl_Stack_pop(Stack **stack);
JFLCSTD_PUBLIC size_t jfl_Stack_length(Stack **stack);
JFLCSTD_PUBLIC void jfl_Stack_free(Stack **stack);
