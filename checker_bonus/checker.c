/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:53:53 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/13 16:19:33 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	adding_node(t_stack **stack, long nbr)
{
	t_stack	*aux;
	t_stack	*node;
	t_stack	*last_node;

	if (!*stack)
		;
	node = malloc(sizeof(t_stack));
	if (!node)
		;
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
	long	nbr;
	int		i;

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

char	*match_and_move(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(stack_a);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr_both(stack_a, stack_b);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		rrr_both(stack_a, stack_b);
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(stack_a);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rra(stack_a);
	if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push(stack_b, stack_a);
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push(stack_a, stack_b);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		rra(stack_b);
	if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ra(stack_b);
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
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	iferror(argc == 2 && !argv[1][0], EINVAL, "Error\n");
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
	return (0);

}