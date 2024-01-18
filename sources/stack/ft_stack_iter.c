/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:37:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/18 12:08:14 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_iter(t_stack *stack, void (*f)(void *))
{
	t_node	*current;

	if (!stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		f(current->data);
		current = current->next;
	}
}
