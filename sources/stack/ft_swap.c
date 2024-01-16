/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:52:17 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/16 17:35:05 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->top || !stack || !stack->top->next)
		return ;
	tmp = stack->top;
	tmp->next->pre = tmp->pre;
	tmp->pre = tmp->next;
	tmp->next = tmp->next->next;
	if (tmp->next != NULL)
		tmp->next->pre = tmp;
	tmp->pre->next = tmp;
	if (tmp->pre->pre == NULL)
		stack->top = tmp->pre;
}
