/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:19:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/05 14:33:43 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_enqueue(t_queue *queue, void *content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (ft_is_empty_queue(queue))
	{
		queue->first = new_node;
		queue->last = new_node;
	}
	else
	{
		queue->last->next = new_node;
		queue->last = new_node;
	}
}
