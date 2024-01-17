/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:49:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/17 18:28:19 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_pop(t_stack **stack)
{
	void	*data;
	t_stack	*del_node;

	if (!*stack)
		return (NULL);
	data = (*stack)->data;
	del_node = *stack;
	if ((*stack)->up == *stack)
		*stack = NULL;
	else
	{
		(*stack)->down->up = (*stack)->up;
		(*stack)->up->down = (*stack)->down;
		*stack = (*stack)->down;
	}
	free(del_node);
	return (data);
}
