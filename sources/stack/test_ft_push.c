#include <stdio.h>
#include "ft_stack.h"

void test_ft_push()
{
    // Create a stack
    t_stack stack;
    stack.top = NULL;

    // Test pushing a single element
    int num1 = 10;
    ft_push(&stack, &num1);
    printf("Stack after pushing %d: ", num1);
    t_node *current = stack.top;
	printf("%d ", *(int *)current->data);
	
    while (current != stack.top)
    {
        printf("%d ", *(int *)current->data);
        current = current->next;
    }
    printf("\n");

    // Test pushing multiple elements
    int num2 = 20;
    int num3 = 30;
    ft_push(&stack, &num2);
    ft_push(&stack, &num3);
    printf("Stack after pushing %d and %d: ", num2, num3);
    current = stack.top;
	printf("%d ", *(int *)current->data);
	current = current->next;
    while (current != stack.top)
    {
        printf("%d ", *(int *)current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    test_ft_push();
    return 0;
}