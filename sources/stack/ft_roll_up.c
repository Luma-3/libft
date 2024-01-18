/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:27:23 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/18 13:31:39 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_roll_up(t_stack *stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = NULL;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = tmp;
}
