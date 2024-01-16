/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:00:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/16 17:35:59 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*pre;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

void	ft_new_stack(t_stack *stack);
int		ft_push(t_stack *stack, void *data);
void	*ft_pop(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_roll_down(t_stack *stack);
void	ft_roll_up(t_stack *stack);

#endif