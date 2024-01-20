/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:06:42 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/21 00:21:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_stack_len(t_stack *stack)
{
	size_t	len;
	t_node	*current;

	len = 0;
	current = stack->top;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}
