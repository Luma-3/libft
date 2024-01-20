/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:00:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/21 00:11:13 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
}			t_stack;

t_stack		*ft_create_stack(void);
void		ft_free_stack(t_stack *stack, void (*del)(void *));
void		*ft_pop(t_stack *stack);
void		ft_push(t_stack *stack, void *data);
void		ft_roll_down(t_stack *stack);
void		ft_roll_up(t_stack *stack);
void		ft_stack_iter(t_stack *stack, void (*f)(void *));
size_t		ft_stack_len(t_stack *stack);
void		ft_swap(t_stack *stack);
void		*ft_valueof(t_stack *stack, int index);

#endif