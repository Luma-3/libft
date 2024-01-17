/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:52:17 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/17 18:28:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->down)
		return ;
	tmp = *stack;
	tmp->up->down = tmp->down;
	tmp->down = tmp->up;
	tmp->up = tmp->up->up;
	if (tmp->up != NULL)
		tmp->up->down = tmp;
	tmp->down->up = tmp;
	if (tmp->down->down == NULL)
		*stack = tmp->down;
}
