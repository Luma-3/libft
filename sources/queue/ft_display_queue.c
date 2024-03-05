/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:19:01 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/05 14:31:06 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_queue(t_queue *queue, void (*display)(void *))
{
	t_node	*tmp;

	tmp = queue->first;
	while (tmp)
	{
		display(tmp->content);
		tmp = tmp->next;
	}
}
