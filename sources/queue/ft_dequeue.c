/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:19:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/05 14:33:28 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dequeue(t_queue *queue)
{
	t_node	*tmp;
	void	*content;

	if (ft_is_empty_queue(queue))
		return (NULL);
	tmp = queue->first;
	content = tmp->content;
	queue->first = queue->first->next;
	free(tmp);
	return (content);
}
