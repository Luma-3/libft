/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:45:42 by jbrousse          #+#    #+#             */
/*   Updated: 2024/02/29 16:30:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, t_list *prev,
			t_list *node, void (*del)(void *))
{
	if (prev && node -> next)
		prev -> next = node -> next;
	else if (!prev && node -> next)
		lst = &node -> next;
	del(node -> content);
	free(node);
}
