#pragma once
#include "macros.h"

#include <stddef.h>

JFLCSTD_PUBLIC struct Stack {
    void *data;
    struct Stack *next;
    size_t length_;
};

JFLCSTD_PUBLIC struct Stack *jfl_Stack_new();
JFLCSTD_PUBLIC int jfl_Stack_push(struct Stack **stack, void *data);
JFLCSTD_PUBLIC void *jfl_Stack_pop(struct Stack **stack);
JFLCSTD_PUBLIC size_t jfl_Stack_length(struct Stack **stack);
JFLCSTD_PUBLIC void jfl_Stack_free(struct Stack **stack);
