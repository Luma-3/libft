/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:49:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/15 18:59:07 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_pop(t_stack *stack)
{
	void	*data;
	t_node	*del_node;

	if (stack->top == NULL)
		return (NULL);
	del_node = stack->top;
	data = del_node->data;
	if (stack->top->next == stack->top)
		stack->top = NULL;
	else
	{
		stack->top->pre->next = stack->top->next;
		stack->top->next->pre = stack->top->pre;
		stack->top = stack->top->pre;
	}
	free(del_node);
	return (data);
}
