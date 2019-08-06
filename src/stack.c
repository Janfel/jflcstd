#include "stack.h"

#include <stdlib.h>

struct Stack *jfl_Stack_new() {
    return NULL;
}

int jfl_Stack_push(struct Stack **stack, void *data) {
    struct Stack *new_block = malloc(sizeof(struct Stack));
    if (!new_block) return 1;
    new_block->data = data;
    new_block->next = *stack;
    new_block->length_ = jfl_Stack_length(stack) + 1;
    *stack = new_block;
    return 0;
}

void *jfl_Stack_pop(struct Stack **stack) {
    struct Stack *popped = *stack;
    if (!popped) return NULL;
    void *data = popped->data;
    *stack = popped->next;
    free(popped);
    return data;
}

size_t jfl_Stack_length(struct Stack **stack) {
    if (!*stack) return 0;
    return (*stack)->length_;
}

void jfl_Stack_free(struct Stack **stack) {
    if (!stack) return;
    struct Stack *current = *stack;
    struct Stack *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}
