/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:51:53 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/22 09:52:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_dup_queue(t_queue *queue)
{
	t_node	*tmp;
	t_queue	*new_queue;

	tmp = queue->first;
	new_queue = ft_init_queue();
	if (!new_queue)
		return (NULL);
	while (tmp)
	{
		ft_enqueue(new_queue, tmp->content);
		tmp = tmp->next;
	}
	return (new_queue);
}
