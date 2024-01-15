#include <stdio.h>
#include "ft_stack.h"

int main() {
    // Create a stack
    t_stack stack;
	ft_new_stack(&stack);

    // Push some elements onto the stack
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    ft_push(&stack, &num1);
    ft_push(&stack, &num2);
    ft_push(&stack, &num3);

    // Test popping elements from the stack
    void* popped1 = ft_pop(&stack);
    void* popped2 = ft_pop(&stack);
    void* popped3 = ft_pop(&stack);

    // Check if the popped elements are correct
    printf("Popped element 1: %d\n", *(int*)popped1); // Expected output: 30
    printf("Popped element 2: %d\n", *(int*)popped2); // Expected output: 20
    printf("Popped element 3: %d\n", *(int*)popped3); // Expected output: 10

    // Test popping from an empty stack
    void* popped4 = ft_pop(&stack);
    printf("Popped element 4: %p\n", popped4); // Expected output: (nil)

    return 0;
}