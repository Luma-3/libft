/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:19:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/05 14:33:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_peek(t_queue *queue)
{
	if (ft_is_empty_queue(queue))
		return (NULL);
	return (queue->first->content);
}
