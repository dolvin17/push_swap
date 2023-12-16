/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:53:53 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/16 19:25:44 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"


void	adding_node(t_stack **stack, long nbr)
{
	t_stack	*aux;
	t_stack	*node;
	t_stack	*last_node;

	if (!*stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->data = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		last_node = aux;
		last_node->next = node;
		node->prev = last_node;
	}
}

void	parsing_args(t_stack **stack_a, char **argv)
{
	int	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_and_print(stack_a);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_and_print(stack_a);
		if (error_duplicated(*stack_a, nbr))
			free_and_print(stack_a);
		adding_node(stack_a, nbr);
		i++;
	}
}

void	match_and_move2(t_stack **stack_a, t_stack **stack_b, char *l)
{
	if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\n')
		rra(stack_a);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\n')
		rra(stack_b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\n')
		rrr_both(stack_a, stack_b);
}

char	*match_and_move(t_stack **stack_a, t_stack **stack_b, char *l)
{
	if (l[0] == 's' && l[1] == 'a' && l[2] == '\n')
		sa(stack_a);
	else if (l[0] == 's' && l[1] == 'b' && l[2] == '\n')
		;
	else if (l[0] == 's' && l[1] == 's' && l[2] == '\n')
		;
	else if (l[0] == 'p' && l[1] == 'a' && l[2] == '\n')
		push(stack_a, stack_b);
	else if (l[0] == 'p' && l[1] == 'b' && l[2] == '\n')
		push(stack_b, stack_a);
	else if (l[0] == 'r' && l[1] == 'a' && l[2] == '\n')
		ra(stack_a);
	else if (l[0] == 'r' && l[1] == 'b' && l[2] == '\n')
		ra(stack_b);
	else if (l[0] == 'r' && l[1] == 'r' && l[3] == '\n')
		match_and_move2(stack_a, stack_b, l);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == '\n')
		rr_both(stack_a, stack_b);
	else
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	return (get_next_line(0));
}

void	lets_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = match_and_move(stack_a, stack_b, temp);
		free(temp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!sorted(*stack_a))
		write(1, "KO\n", 3);
	else if (sorted(*stack_a))
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!argv[1])
		return (0);
	iferror(argc == 2 && !argv[1][0], "Error\n");
	if (argc == 2)
		argv = split(argv[1], ' ');
	parsing_args(&stack_a, argv +1);
	line = get_next_line(0);
	if (!line && !sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && sorted(stack_a))
		write(1, "OK\n", 3);
	else
		lets_check(&stack_a, &stack_b, line);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
