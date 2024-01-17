
#include <stdio.h>
#include "libft.h"

typedef int Data;

void printData(void *data)
{
    printf("%d ", *(int *)data);
}

int main()
{
    t_stack *stack_top = NULL;

    // Test de ft_push
    for (int i = 1; i <= 5; ++i)
    {
        ft_push(&stack_top, &i);
    }

    // Test de ft_stack_iter
    printf("Stack contents: ");
    ft_stack_iter(&stack_top, printData);
    printf("\n");

    // Test de ft_swap
    ft_swap(&stack_top);
    printf("After ft_swap: ");
    ft_stack_iter(&stack_top, printData);
    printf("\n");

    // Test de ft_roll_up
    ft_roll_up(&stack_top);
    printf("After ft_roll_up: ");
    ft_stack_iter(&stack_top, printData);
    printf("\n");

    // Test de ft_roll_down
    ft_roll_down(&stack_top);
    printf("After ft_roll_down: ");
    ft_stack_iter(&stack_top, printData);
    printf("\n");

    // Test de ft_pop
    //printf("Popped value: %d\n", *(Data *)ft_pop(&stack_top));

    // Test de ft_stack_iter après la suppression
    printf("Stack contents after ft_pop: ");
    ft_stack_iter(&stack_top, printData);
    printf("\n");

    // N'oubliez pas de libérer la mémoire allouée
    // free(*&stack_top);
    // free(&stack_top);

    return 0;
}