/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:19:04 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/05 14:31:09 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_queue(t_queue *queue, void (*del)(void *))
{
	t_node	*tmp;

	while (queue->first)
	{
		tmp = queue->first;
		queue->first = queue->first->next;
		del(tmp->content);
		free(tmp);
	}
	free(queue);
}
