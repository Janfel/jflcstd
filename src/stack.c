#include "stack.h"

Stack **jfl_Stack_new();
int jfl_Stack_push(Stack **stack, void *data);
void *jfl_Stack_pop(Stack **stack);
size_t jfl_Stack_length(Stack **stack);
void jfl_Stack_free(Stack **stack);
