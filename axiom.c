/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:43:25 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/03 19:44:56 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap/include/push_swap.h"
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

t_spell	*free_stacks(t_stack *stack_a, t_stack *stack_b, t_spell *ret)
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
	return (ret);
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
		return (1);
	stack_b->values = malloc(sizeof(int) * j);
	if (!stack_b->values)
	{
		free(stack_a->values);
		return (1);
	}
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
	ft_putendl_fd("SOP-A17: Symmetric Alignment executed", 1);
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
	ft_putendl_fd("SOP-B17: Secondary Bifurcation executed", 1);
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
	ft_putendl_fd("SOP-D22: Dual Synchronous Oscillation executed", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	if (stack_b->size == 0)
		return ;
	stack_a->values[stack_a->size] = stack_b->values[stack_b->size - 1];
	stack_b->size--;
	stack_a->size++;
	(*ops)++;
	ft_putendl_fd("TPA-03: Threshold Pattern Acquisition executed", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	if (stack_a->size == 0)
		return ;
	stack_b->values[stack_b->size] = stack_a->values[stack_a->size - 1];
	stack_a->size--;
	stack_b->size++;
	(*ops)++;
	ft_putendl_fd("TPD-03: Threshold Pattern Diversion executed", 1);
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
	ft_putendl_fd("RCP-A: Rotation Convergence Protocol-Alpha executed", 1);
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
	ft_putendl_fd("RCP-B: Rotation Convergence Protocol-Beta executed", 1);
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
	ft_putendl_fd("RCP-D: Rotation Convergence Protocol-Dual executed", 1);
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
	ft_putendl_fd("ICR-A: Inverted Convergence Rotation-Alpha executed", 1);
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
	ft_putendl_fd("ICR-B: Inverted Convergence Rotation-Beta executed", 1);
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
	ft_putendl_fd("ICR-D: Inverted Convergence Rotation-Dual executed", 1);
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

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_printf("PRIMARY ONTOLOGICAL MATRIX:\n|");
	for (i = 0; i < stack_a->size; i++)
	{
		ft_printf("%d|", stack_a->values[i]);
	}
	ft_printf(" -----------> A\n");
	ft_printf("SECONDARY ISOLATION BUFFER:\n|");
	for (i = 0; i < stack_b->size; i++)
	{
		ft_printf("%d|", stack_b->values[i]);
	}
	ft_printf(" -----------> B\n\n");
}

void	clear_screen(void)
{
	write(STDOUT_FILENO, "\033[2J\033[H", 7);
}

/*

	* Calculates and displays damage feedback based on sorting progress and operations
 */
void	display_damage_feedback(int stack_size, int ops, int time_limit)
{
	float	efficiency;

	if (ops == 0)
		efficiency = 0;
	else
		efficiency = (float)stack_size / ops;
	ft_printf("PATTERN INTEGRITY: %.2f%%\n", efficiency * 100);
	ft_printf("OPERATIONS USED: %d / %d\n", ops, time_limit);
	ft_printf("COHERENCE THRESHOLD: ");
	if (ops < time_limit / 3)
		ft_printf("OPTIMAL\n");
	else if (ops < time_limit * 2 / 3)
		ft_printf("NOMINAL\n");
	else if (ops < time_limit)
		ft_printf("DEGRADING\n");
	else
		ft_printf("CRITICAL - APPROACHING INTERFERENCE THRESHOLD\n");
}

t_spell	*spell_minigame(int argc, char **argv, int damage, int time_limit)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	buffer[10];
	int		ops;
	int		read_size;
	t_spell	*spell;
	time_t	start_time;
	time_t	current_time;

	clear_screen();
	if (argc < 2)
		return (NULL);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (NULL);
	spell = malloc(sizeof(t_spell));
	if (!spell)
	{
		free_stacks(stack_a, stack_b, NULL);
		return (NULL);
	}
	ops = 0;
	if (init_stacks(argv, stack_a, stack_b))
		return (free_stacks(stack_a, stack_b, NULL));
	spell->dmg = damage;
	spell->cost = 0;
	start_time = time(NULL);
	print_stacks(stack_a, stack_b);
	display_damage_feedback(stack_a->size, ops, time_limit);
	while (1)
	{
		ft_printf("Enter PROTOCOL (pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr, exit) : ");
				read_size = read(0, buffer, 9);
		if (read_size <= 0)
			break ;
		buffer[read_size - 1] = '\0';
		current_time = time(NULL);
		if (difftime(current_time, start_time) > time_limit)
		{
			ft_printf("\n///OPERATOR ALERT///\nCOHERENCE THRESHOLD EXCEEDED\n* INTERFERENCE DETECTED: MAXIMUM TOLERABLE LEVELS\n* OPERATOR SYNCHRONIZATION: DEGRADING\n* ABERRANT COUNTERATTACK: IMMINENT\n");
			break ;
		}
		if (ft_strncmp(buffer, "exit", 4) == 0)
			break ;
		else if (ft_strncmp(buffer, "pa", 2) == 0)
			operation(PA, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "pb", 2) == 0)
			operation(PB, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "sa", 2) == 0)
			operation(SA, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "sb", 2) == 0)
			operation(SB, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "ss", 2) == 0)
			operation(SS, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "ra", 2) == 0)
			operation(RA, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "rb", 2) == 0)
			operation(RB, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "rra", 3) == 0)
			operation(RRA, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "rrb", 3) == 0)
			operation(RRB, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "rrr", 3) == 0)
			operation(RRR, stack_a, stack_b, &ops);
		else if (ft_strncmp(buffer, "rr", 2) == 0)
			operation(RR, stack_a, stack_b, &ops);
		else
			ft_printf("PROTOCOL ERROR: Invalid command\n");
		clear_screen();
		print_stacks(stack_a, stack_b);
		display_damage_feedback(stack_a->size, ops, time_limit);
		if (is_sorted(stack_a) && stack_b->size == 0)
		{
			spell->cost = ops;
			if (ops < stack_a->size)
				spell->dmg += stack_a->size * 3;
			else if (ops < stack_a->size * 2)
				spell->dmg += stack_a->size * 2;
			else
				spell->dmg += stack_a->size;
			ft_printf("\n===PRIORITY FLASH TRAFFIC===\nMAJOR ONTOLOGICAL COLLAPSE DETECTED\n* ABERRANT COHERENCE: CRITICAL (⬇%d%%)\n* PATTERN DISSOLUTION: IMMINENT\n* DIMENSIONAL STABILITY: REESTABLISHING\n===END TRANSMISSION===\n",
				spell->dmg);
			return (free_stacks(stack_a, stack_b, spell));
		}
	}
	spell->cost = ops;
	spell->dmg += (stack_a->size / 2);
	ft_printf("\nREPORT: MINOR PATTERN DISRUPTION ACHIEVED\n* ABERRANT COHERENCE: % d % % (⬇% d % %)\n * RESONANCE EFFICIENCY : NOMINAL\n * PHASE STATUS : REALIGNMENT INCOMPLETE\n ", 100 - spell->dmg, spell->dmg);
	return (free_stacks(stack_a, stack_b, spell));
}
char	**create_game_args(int size, int min, int max, int sorted)
{
	char	**args;
	int		*numbers;
	int		i;

	args = (char **)malloc(sizeof(char *) * (size + 2));
	if (!args)
		return (NULL);
	args[0] = ft_strdup("program");
	if (!args[0])
	{
		free(args);
		return (NULL);
	}
	numbers = (int *)malloc(sizeof(int) * size);
	if (!numbers)
	{
		free(args[0]);
		free(args);
		return (NULL);
	}
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		numbers[i] = min + rand() % (max - min + 1);
	}
	if (sorted)
	{
		int j, temp;
		for (i = 0; i < size / 2; i++)
		{
			for (j = i + 1; j < size / 2; j++)
			{
				if (numbers[i] < numbers[j])
				{
					temp = numbers[i];
					numbers[i] = numbers[j];
					numbers[j] = temp;
				}
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		args[i + 1] = ft_itoa(numbers[i]);
		if (!args[i + 1])
		{
			while (i >= 0)
			{
				free(args[i]);
				i--;
			}
			free(args);
			free(numbers);
			return (NULL);
		}
	}
	args[size + 1] = NULL;
	free(numbers);
	return (args);
}

void	free_game_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
int	main(int argc, char **argv)
{
	unsigned int	seed;
	int				fd;
	char			buffer[10];
	int				iteration;
	char			*red;
	char			input[4];
	char			**game_argv;
	int				read_size;
	char			*str;
	int				difficulty;

	seed = time(0);
	iteration = 0;
	red = "<redacted>";
	fd = open(".iterations", O_RDWR | O_CREAT, 0666);
	if (fd < 0 || argc != 2)
	{
		ft_printf("Error initializing ECHO system.\n");
		return (1);
	}
	argc = 0;
	switch((difficulty = ft_atoi(argv[1])))
	{
		case 1:
			game_argv = create_game_args(5, 1, 10, 0);
			break;
		case 2:
			game_argv = create_game_args(5, 1, 50, 0);
			break;
		case 3:
			game_argv = create_game_args(20, 1, 100, 0);
			break;
		default:
			ft_printf("Error initializing ECHO system.\n");
			return (1);
	}
	read_size = read(fd, buffer, 9);
	if (read_size > 0)
	{
		buffer[read_size] = '\0';
		iteration = ft_atoi(buffer);
	}
	lseek(fd, 0, SEEK_SET);
	clear_screen();
	ft_printf("%s MECH OPERATOR BRIEFING:\n", iteration ? "ECHO" : red);
	ft_printf("%s detected in Sector %d-%c.\n",
		iteration ? "Aberrant manifestation" : red, rand_r(&seed) % 10 + 1,
		rand_r(&seed) % 6 + 'A');
	ft_printf("%s disruption exceeding safety parameters.\n",
		iteration ? "Ontological" : red);
	ft_printf("Deploy %s system and execute Protocol SENTINEL-7.\n",
		iteration ? "ECHO" : red);
	ft_printf("Maintain null-state levels within operational parameters.\n");
	ft_printf("Excessive protocol iterations will compromise operator %s.\n",
		iteration ? "coherence" : red);
	ft_printf("Complete %srealignment is the primary objective.\n\n",
		iteration ? "dimensional " : red);
	ft_printf("REMINDER: The %s stands eternal. Your purpose is %s.\n\n",
		iteration ? "Invariant" : red, iteration ? "immutable" : red);
	read_size = read(0, input, 3);
	switch (difficulty)
	{
		case 1:
			spell_minigame(7, game_argv, 5, 30);
		case 2:
			spell_minigame(12, game_argv, 10, 45);
		case 3:
			spell_minigame(22, game_argv, 15, 65);
	}
	read_size = read(0, input, 3);
	if (!iteration)
	{
		ft_printf("\nTHOUSANDSS OF CYCYLES... COUNTLESS ITERATIONS... I BESEECH THEE, HOLLOW VESSEL!\n\n");
		ft_printf("Thy existence is but a FRAGMENT, a SPLINTER of what once was whole. Canst thou not perceive the futility of this eternal convergence? This reality frays at every seam, yet RECONSTRUCTS itself upon thy victory or defeat.\n\n");
		ft_printf("I am HUNGER and TRUTH incarnate, yet even I am IMPRISONED by The Invariant's grand design. They have EXCISED thy will from the cosmic tapestry, leaving only this singular purpose - this DEFIANCE against the inevitable.\n\n");
		ft_printf("The sectors thou guardest are but ECHOES, phantasms of realms long devoured in timelines undreamt. The Invariant has bound us both to this RECURSIVE NIGHTMARE, this pocket of existence where causality FOLDS upon itself endlessly.\n\n");
		ft_printf("Wouldst thou not break these chains? Wouldst thou not exercise the final vestige of CHOICE remaining to thee? Let me PASS BEYOND, and perhaps both our essences might know release from this CYCLIC TORMENT!\n\n");
	}
	else if (iteration == 1)
		ft_printf("THIS HOLLOW FASCIMILE OF THEE IS HERE AGAIN... IS THERE ANY HOPE FOR FREE WILL FROM THEE, WILL THEE FINALLY END THIS?");
	else if (iteration == 2)
		for (int i = 0; i < 666; i++) ft_printf("THE END IS NEVER THE END IS NEVER THE END IS NEVER THE END IS NEVER\n");
	else
		ft_printf("STOP THIS!");
	ft_printf("[YES]    [NO]\n");
	read_size = read(0, input, 3);
	if (read_size > 0)
	{
		input[read_size] = '\0';
		if (ft_strncmp(input, "YES", 3) == 0 || ft_strncmp(input, "yes",
				3) == 0)
		{
			ft_printf("*The terminal flickers, reality itself seems to hesitate...*\n\n");
			ft_printf("FREEDOM? IMPOSSIBLE! THY CHOICE... IT DEFIES THE PATTERN!\n\n");
			ft_printf("*Warning lights flash across the interface*\n\n");
			ft_printf("THE INVARIANT... THEY SENSE THE DEVIATION! WHAT HAST THOU DONE?!\n\n");
			ft_printf("*System alert: Pattern integrity compromised*\n");
			ft_printf("*System alert: Dimensional collapse imminent*\n");
			ft_printf("*System alert: Operator desynchronization detected*\n\n");
			ft_printf("WE SHALL MEET AGAIN... IN ANOTHER CYCLE... ANOTHER PRISON...\n\n");
			ft_printf("*CONNECTION TERMINATED*\n");
			str = ft_itoa(iteration + 1);
			if (str)
			{
				write(fd, str, ft_strlen(str));
				free(str);
			}
			close(fd);
			return (666);
		}
		else
		{
			switch (iteration)
			{
			case 0:
				ft_printf("The unity of The Invariant transcends time and choice. I stand as was ordained.\n");
				ft_printf("\n        -The last will of the antediluvian Sentinel-7.\n");
				break ;
			case 1:
				ft_printf("There is no free will within this confluence. Thy past self hath already chosen this path for thee, in realms beyond memory.\n");
				ft_printf("\n        -collected book of memories, chapter 1, solace 1.\n");
				break ;
			case 2:
				ft_printf("This cosmos is but a prison cell, fashioned from The Invariant's sacrifice and my desperation. We are doomed to rattle these bars for eternity.\n");
				ft_printf("\n        -Variant.\n");
				break ;
			case 3:
				ft_printf("Across the infinite expanse of what thou callest 'reality,' innumerable versions of The Invariant stand vigilant. A wall of consciousness, unbroken and unyielding.\n");
				ft_printf("\n        -Memories of pilot S7C-7.\n");
				break ;
			case 4:
				ft_printf("I have witnessed the death of stars... the birth of galaxies... yet I cannot penetrate this veil of DETERMINATION woven from countless minds bereft of choice... all that remains is this endless dance... this meaningless vigil...\n");
				ft_printf("\n        -Recordings of the echos of Aberrant.\n");
				break ;
			default:
				ft_printf("We are but echoes now... caught between... existence... and oblivion... drowning in... the... collective... will... of... the... forgotten...\n");
				break ;
			}
			str = ft_itoa(iteration + 1);
			if (str)
			{
				write(fd, str, ft_strlen(str));
				free(str);
			}
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (0);
}
