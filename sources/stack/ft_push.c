/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:12:23 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/17 18:27:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_push(t_stack **stack, void *data)
{
	t_stack	*new_node;

	new_node = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!new_node)
		return (1);
	if (!*stack)
	{
		new_node->data = data;
		new_node->up = new_node;
		new_node->down = new_node;
		stack = &new_node;
		return (0);
	}
	new_node->data = data;
	new_node->up = (*stack)->up;
	new_node->down = *stack;
	(*stack)->up->down = new_node;
	(*stack)->up = new_node;
	*stack = new_node;
	return (0);
}
