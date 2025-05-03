/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:57:52 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/01 20:37:19 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int			*values;
	int			size;
}	t_stack;

typedef struct s_node
{
	int			value;
	int			index;
	int			target_pos;
	int			cost_a;
	int			cost_b;
	int			total_cost;
}	t_node;
enum	e_op
{
	PA,
	PB,
	SA,
	SB,
	RA,
	RB,
	RRA,
	RRB,
	SS,
	RR,
	RRR
};

typedef void	(*t_operation)(t_stack *, t_stack *, int *);
// Game mode functions debug DEBUG
void			print_stacks(t_stack *stack_a, t_stack *stack_b);
void			game_mode(t_stack *stack_a, t_stack *stack_b);

//sorting
void			sort_turk(t_stack *stack_a, t_stack *stack_b, int *ops);
void			operation(enum e_op op, t_stack *stack_a, t_stack *stack_b,
					int *ops);
void			sort_small(t_stack *stack_a, t_stack *stack_b, int *ops);

#endif
