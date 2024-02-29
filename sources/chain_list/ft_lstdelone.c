/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:45:42 by jbrousse          #+#    #+#             */
/*   Updated: 2024/02/29 16:48:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	next = (*lst)->next;
	while (next)
	{
		if (next == node)
			break ;
		prev = next;
		next = next->next;
	}
	if (!prev)
		*lst = node->next;
	else
		prev->next = node->next;
	del(node->content);
	free(node);
}
