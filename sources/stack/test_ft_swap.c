#include <stdio.h>
#include "ft_stack.h"

void test_ft_swap()
{
	// Create a stack and add some elements
	t_stack stack;
	stack.top = NULL;
	int nb1 = 10;
	int nb2 = 20;
	int nb3 = 30;
	ft_push(&stack, &nb1);
	ft_push(&stack, &nb2);
	ft_push(&stack, &nb3);

	// Print the stack before swapping
	printf("Before swap: ");
	t_node *current = stack.top;
	int i = 3;
	while (i > 0)
	{
		printf("%d ", *(int *)current->data);
		current = current->next;
		i--;
	}
	printf("\n");

	// Call ft_swap to swap the top two elements
	ft_swap(&stack);

	// Print the stack after swapping
	printf("After swap: ");
	current = stack.top;
	i = 3;
	while (i > 0)
	{
		printf("%d ", *(int *)current->data);
		current = current->next;
		i--;
	}
	printf("\n");
}

int main()
{
	test_ft_swap();
	return 0;
}
