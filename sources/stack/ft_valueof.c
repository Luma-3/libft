/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valueof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:13:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/20 18:12:43 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_valueof(t_stack *stack, int index)
{
	t_node	*current;

	current = stack->top;
	while (index-- >= 0)
	{
		current = current->next;
	}
	return (current->data);
}
