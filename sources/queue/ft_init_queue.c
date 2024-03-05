/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:19:10 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/05 14:31:03 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_init_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}
