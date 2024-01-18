/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:00:17 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/18 17:21:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}
