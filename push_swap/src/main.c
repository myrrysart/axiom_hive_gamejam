/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:39:37 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/01 19:55:45 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stacks(t_stack *stack_a, t_stack *stack_b, int ret)
{
	if (stack_a)
	{
		if (stack_a->values)
		{
			free(stack_a->values);
			stack_a->values = NULL;
		}
		free(stack_a);
		stack_a = NULL;
	}
	if (stack_b)
	{
		if (stack_b->values)
		{
			free(stack_b->values);
			stack_b->values = NULL;
		}
		free(stack_b);
		stack_b = NULL;
	}
	if (ret)
		ft_printf("Error\n");
	return (ret);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	handle_arg(char *arg, t_stack *stack_a, t_stack *stack_b)
{
	char	**split_args;
	int		count;
	int		i;
	int		not_number;

	count = 0;
	i = 0;
	not_number = 0;
	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (1);
	while (split_args[count])
		count++;
	stack_a->values = malloc(sizeof(int) * count);
	stack_b->values = malloc(sizeof(int) * count);
	if (!stack_b->values || !stack_a->values)
	{
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
		return (1);
	}
	stack_a->size = count;
	stack_b->size = 0;
	while (i < count)
	{
		stack_a->values[count - 1 - i] = ft_atoi(split_args[i]);
		if (is_valid_number(split_args[i]))
			not_number = 1;
		free(split_args[i]);
		i++;
	}
	free(split_args);
	return (not_number);
}

int	init_stacks(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[j])
		j++;
	j -= 1;
	stack_a->values = malloc(sizeof(int) * j);
	if (!stack_a->values)
		return (free_stacks(stack_a, stack_b, 1));
	stack_b->values = malloc(sizeof(int) * j);
	if (!stack_b->values)
		return (free_stacks(stack_a, stack_b, 1));
	stack_a->size = j;
	while (argv[++i])
		stack_a->values[--j] = ft_atoi(argv[i]);
	stack_b->size = 0;
	return (0);
}

void	sa(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;

	(void)stack_b;
	if (stack_a->size < 2)
		return ;
	temp = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = stack_a->values[stack_a->size - 2];
	stack_a->values[stack_a->size - 2] = temp;
	(*ops)++;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;

	(void)stack_a;
	if (stack_b->size < 2)
		return ;
	temp = stack_b->values[stack_b->size - 1];
	stack_b->values[stack_b->size - 1] = stack_b->values[stack_b->size - 2];
	stack_b->values[stack_b->size - 2] = temp;
	(*ops)++;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;

	temp = stack_b->values[stack_b->size - 1];
	stack_b->values[stack_b->size - 1] = stack_b->values[stack_b->size - 2];
	stack_b->values[stack_b->size - 2] = temp;
	temp = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = stack_a->values[stack_a->size - 2];
	stack_a->values[stack_a->size - 2] = temp;
	(*ops)++;
	ft_putendl_fd("ss", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	if (stack_b->size == 0)
		return ;
	stack_a->values[stack_a->size] = stack_b->values[stack_b->size - 1];
	stack_b->size--;
	stack_a->size++;
	(*ops)++;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	if (stack_a->size == 0)
		return ;
	stack_b->values[stack_b->size] = stack_a->values[stack_a->size - 1];
	stack_a->size--;
	stack_b->size++;
	(*ops)++;
	ft_putendl_fd("pb", 1);
}

void	ra(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = stack_a->size - 1;
	(void)stack_b;
	temp = stack_a->values[i];
	while (i > 0)
	{
		stack_a->values[i] = stack_a->values[i - 1];
		i--;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = stack_b->size - 1;
	(void)stack_a;
	temp = stack_b->values[i];
	while (i > 0)
	{
		stack_b->values[i] = stack_b->values[i - 1];
		i--;
	}
	stack_b->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = stack_b->size - 1;
	temp = stack_b->values[i];
	while (i > 0)
	{
		stack_b->values[i] = stack_b->values[i - 1];
		i--;
	}
	stack_b->values[i] = temp;
	i = stack_a->size - 1;
	temp = stack_a->values[i];
	while (i > 0)
	{
		stack_a->values[i] = stack_a->values[i - 1];
		i--;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rr", 1);
}

void	rra(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	(void)stack_b;
	i = 0;
	temp = stack_a->values[i];
	while (i < (stack_a->size - 1))
	{
		stack_a->values[i] = stack_a->values[i + 1];
		i++;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	(void)stack_a;
	i = 0;
	temp = stack_b->values[i];
	while (i < (stack_b->size - 1))
	{
		stack_b->values[i] = stack_b->values[i + 1];
		i++;
	}
	stack_b->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack_b->values[i];
	while (i < (stack_b->size - 1))
	{
		stack_b->values[i] = stack_b->values[i + 1];
		i++;
	}
	stack_b->values[i] = temp;
	i = 0;
	temp = stack_a->values[i];
	while (i < (stack_a->size - 1))
	{
		stack_a->values[i] = stack_a->values[i + 1];
		i++;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rrr", 1);
}

void	operation(enum e_op op, t_stack *stack_a, t_stack *stack_b, int *ops)
{
	t_operation	operations[11];

	operations[PA] = &pa;
	operations[PB] = &pb;
	operations[SA] = &sa;
	operations[SB] = &sb;
	operations[RA] = &ra;
	operations[RB] = &rb;
	operations[RRA] = &rra;
	operations[RRB] = &rrb;
	operations[SS] = &ss;
	operations[RR] = &rr;
	operations[RRR] = &rrr;
	if (op >= 0 && op < 11)
		operations[op](stack_a, stack_b, ops);
	// debug
	print_stacks(stack_a, stack_b);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size <= 1)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->values[i] < stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	top;
	int	middle;
	int	bottom;

	if (is_sorted(stack_a))
		return ;
	top = stack_a->values[stack_a->size - 1];
	middle = stack_a->values[stack_a->size - 2];
	bottom = stack_a->values[stack_a->size - 3];
	if (top > middle && middle > bottom)
	{
		operation(SA, stack_a, stack_b, ops);
		operation(RRA, stack_a, stack_b, ops);
	}
	else if (top < middle && middle > bottom && top > bottom)
		operation(RRA, stack_a, stack_b, ops);
	else if (top > middle && middle < bottom && top > bottom)
		operation(RA, stack_a, stack_b, ops);
	else if (top < middle && middle > bottom && top < bottom)
	{
		operation(SA, stack_a, stack_b, ops);
		operation(RA, stack_a, stack_b, ops);
	}
	else if (top > middle && middle < bottom && top < bottom)
		operation(SA, stack_a, stack_b, ops);
	// debug
	print_stacks(stack_a, stack_b);
}

//DEBUG
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_printf("|");
	for (i = 0; i < stack_a->size; i++)
	{
		ft_printf("%d|", stack_a->values[i]);
	}
	ft_printf(" BOT----TOP> A\n");
	ft_printf("|");
	for (i = 0; i < stack_b->size; i++)
	{
		ft_printf("%d|", stack_b->values[i]);
	}
	ft_printf(" BOT----TOP> B\n\n");
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_printf("SORTED!\n");
	else
		ft_printf("NOT SORTED.\n");
}

int	check_for_duplicates(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a->size)
	{
		while (j < i)
		{
			if (stack_a->values[i] == stack_a->values[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ops;

	ops = 0;
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b || argc < 2)
		return (free_stacks(stack_a, stack_b, 1));
	if (argc == 2)
	{
		if (handle_arg(argv[1], stack_a, stack_b))
			return (free_stacks(stack_a, stack_b, 1));
	}
	else
	{
		if (init_stacks(argv, stack_a, stack_b))
			return (free_stacks(stack_a, stack_b, 1));
	}
	if (check_for_duplicates(stack_a))
		return (free_stacks(stack_a, stack_b, 1));
	if (stack_a->size == 2 || is_sorted(stack_a))
	{
		if (stack_a->values[1] > stack_a->values[0])
			operation(SA, stack_a, stack_b, &ops);
		return (free_stacks(stack_a, stack_b, 0));
	}
	if (stack_a->size > 3)
		sort_turk(stack_a, stack_b, &ops);
	else
		sort_small(stack_a, stack_b, &ops);
	print_stacks(stack_a, stack_b);
	ft_printf("operations count: %d\n", ops);
	return (free_stacks(stack_a, stack_b, 0));
}
