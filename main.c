/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:24:39 by dolvin17          #+#    #+#             */
/*   Updated: 2024/04/10 15:42:17 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	adding_back(t_stack **stack, long nbr)
{
	t_stack	*aux;
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
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

static	void	parse_stack_a(t_stack **stack_a, char **argv)
{
	int	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			free_and_print_error(stack_a);
		nbr = long_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_and_print_error(stack_a);
		if (check_dup(*stack_a, nbr))
			free_and_print_error(stack_a);
		adding_back(stack_a, nbr);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!argv[1])
		return (0);
	checking((argc == 2 && !argv[1][0]), "Error\n");
	checking((argv[1][0] == ' '), "Error\n");
	if (argc == 2 && !ft_strchr(argv[1], ' '))
		exit(EXIT_SUCCESS);
	if (argc == 2)
		argv = ft_split(argv[1], 32);
	parse_stack_a(&stack_a, argv + 1);
	if (!(is_sorted(stack_a)))
	{
		if (check_len(stack_a) == 2)
			ft_sa("sa\n", &stack_a);
		else if (check_len(stack_a) == 3)
			order_three(&stack_a);
		else
			order_biggest(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
