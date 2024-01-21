/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:22:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/21 11:28:33 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_node	*ft_get_node(t_stack *stack, int index)
{
	t_node	*current;

	current = stack->top;
	while (index-- > 0)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
	}
	return (current);
}
