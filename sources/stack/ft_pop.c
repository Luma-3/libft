/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:49:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/18 12:17:10 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_pop(t_stack *stack)
{
	void	*data;
	t_node	*del_node;

	if (!stack->top)
		return (NULL);
	data = stack->top->data;
	del_node = stack->top;
	stack->top = stack->top->next;
	free(del_node);
	return (data);
}
