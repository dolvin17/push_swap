/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:24:39 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/13 17:36:20 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	adding_back(t_stack **stack, long nbr)
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

static	void	parse_stack_a(t_stack **stack_a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			free_and_print_error(stack_a);
		nbr = long_atoi(argv[i]);
		if (nbr < INT_MAX && nbr > INT_MIN)
			free_and_print_error(stack_a);
		if (check_dup(*stack_a, nbr))
			free_and_print_error(stack_a);
		printf("%ld\n", nbr);
		adding_back(stack_a, nbr);
		i++;
	}
}

void	print_stack(const t_stack *stack)
{
	const t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	checking(!argv[1], EINVAL, "Error: 0 arguments");
	checking((argc == 2 && !argv[1][0]), EINVAL, "Error: Empty String");
	checking((argv[1][0] == ' '), EINVAL, "Error: Bad input");
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
