#include "stack.h"

#include <stdlib.h>

int push_and_pop() {
    Stack *stack = jfl_Stack_new();
    jfl_Stack_push(&stack, (void *) 1);
    jfl_Stack_push(&stack, (void *) 2);
    jfl_Stack_push(&stack, (void *) 3);
    jfl_Stack_push(&stack, (void *) 4);
    jfl_Stack_push(&stack, (void *) 5);
    if (jfl_Stack_length(&stack) != 5) return 1;
    if ((int) jfl_Stack_pop(&stack) != 5) return 2;
    if ((int) jfl_Stack_pop(&stack) != 4) return 3;
    if ((int) jfl_Stack_pop(&stack) != 3) return 4;
    if ((int) jfl_Stack_pop(&stack) != 2) return 5;
    if ((int) jfl_Stack_pop(&stack) != 1) return 6;
    if (jfl_Stack_pop(&stack) != NULL) return 7;
    return 0;
}

void freeing() {
    Stack *stack1 = jfl_Stack_new();
    jfl_Stack_free(&stack1);

    Stack *stack2 = jfl_Stack_new();
    int *data2 = calloc(5, sizeof(int));
    jfl_Stack_push(&stack2, (void *) 5);
    jfl_Stack_free(&stack2);
    data2[3] = 15;
    free(data2);
}

int length() {
    Stack *stack = jfl_Stack_new();
    if (jfl_Stack_length(&stack) != 0) return 8;
    jfl_Stack_push(&stack, (void *) 1);
    if (jfl_Stack_length(&stack) != 1) return 9;
    jfl_Stack_push(&stack, (void *) 1);
    if (jfl_Stack_length(&stack) != 2) return 10;
    jfl_Stack_pop(&stack);
    if (jfl_Stack_length(&stack) != 1) return 11;
    jfl_Stack_pop(&stack);
    if (jfl_Stack_length(&stack) != 0) return 12;
    jfl_Stack_pop(&stack);
    if (jfl_Stack_length(&stack) != 0) return 13;
    return 0;
}

int main() {
    int err;
    err = push_and_pop();
    if (err) return err;
    freeing();
    err = length();
    if (err) return err;
    return 0;
}
