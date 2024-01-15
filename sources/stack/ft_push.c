/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:12:23 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/15 18:48:53 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_push(t_stack *stack, void *data)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		return (1);
	new_node->data = data;
	if (stack->top == NULL)
	{
		new_node->next = new_node;
		new_node->pre = new_node;
	}
	else
	{
		new_node->next = stack->top->next;
		new_node->pre = stack->top;
		stack->top->next->pre = new_node;
		stack->top->next = new_node;
	}
	stack->top = new_node;
	return (0);
}
