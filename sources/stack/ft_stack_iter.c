/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:37:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/17 18:28:07 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_iter(t_stack **stack, void (*f)(void *))
{
	t_stack	*current;

	if (!*stack)
		return ;
	current = *stack;
	f(current->data);
	current = current->down;
	while (current != *stack && current != NULL)
	{
		f(current->data);
		current = current->down;
	}
}