#include "stack.h"

#include <stdlib.h>

Stack *jfl_Stack_new() { return NULL; }

int jfl_Stack_push(Stack **stack, void *data) {
    Stack *new_block = malloc(sizeof(Stack));
    if (!new_block) return 1;
    new_block->data = data;
    new_block->next = *stack;
    new_block->length_ = jfl_Stack_length(stack) + 1;
    *stack = new_block;
    return 0;
}

void *jfl_Stack_pop(Stack **stack) {
    Stack *popped = *stack;
    if (!popped) return NULL;
    void *data = popped->data;
    *stack = popped->next;
    free(popped);
    return data;
}

size_t jfl_Stack_length(Stack **stack) {
    if (!*stack) return 0;
    return (*stack)->length_;
}

void jfl_Stack_free(Stack **stack) {
    if (!stack) return;
    Stack *current = *stack;
    Stack *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}
