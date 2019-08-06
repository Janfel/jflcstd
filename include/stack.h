#pragma once
#if defined _WIN32 || defined __CYGWIN__
#    ifdef BUILDING_JFLCSTD
#        define JFLCSTD_PUBLIC __declspec(dllexport)
#    else
#        define JFLCSTD_PUBLIC __declspec(dllimport)
#    endif
#else
#    ifdef BUILDING_JFLCSTD
#        define JFLCSTD_PUBLIC __attribute__((visibility("default")))
#    else
#        define JFLCSTD_PUBLIC
#    endif
#endif

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
