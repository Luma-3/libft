/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:17:56 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/18 13:00:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_free_stack(t_stack *stack, void (*del)(void *))
{
	t_node	*current;
	t_node	*next;

	if (!stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		del(current->data);
		free(current);
		current = next;
	}
	stack->top = NULL;
}
