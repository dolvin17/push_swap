/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:24:39 by dolvin17          #+#    #+#             */
/*   Updated: 2023/10/25 22:42:47 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (++i < stack.size)
		if (stack.content[i - 1] > stack.content[i])
			return (0);
	return (1);
}

int	order_three(t_stack stacks[2])
{
	int		*value;
	t_stack	*stack_a;
	t_stack	*stack_b;

	value = stacks[0].content;
	if (stacks[0].size < 4)
	{
		if (value[2] > value[0] && value[0] > value[1])
			ft_sa("SA", stacks);
		else if (value[0] > value[2] && value[2] > value[1])
			ft_ra("RA", stacks);
		else if (value[1] > value[0] && value[0] > value[2])
			ft_rra("RRA", stacks);
		else if (value[0] > value[1] && value[1] > value[2])
			ft_ra("RA", stacks);
		else if (value[1] > value[2] && value[2] > value[0])
			ft_sa("SA", stacks);
	}
	if (is_sorted(stacks[0]))
		return (EXIT_SUCCESS);
	return (order_three(stacks));
}

int	main(int argc, char **argv)
{
	t_stack	stacks[2];
	int		pos;

	pos = 1;
	stacks[0].size = argc - 1;
	stacks[1].size = stacks[0].size;
	stacks[0].content = (int *)malloc(sizeof(int) * stacks[0].size);
	stacks[1].content = (int *)malloc(sizeof(int) * stacks[1].size);
	while (pos < argc)
	{
		if (argv[pos])
		stacks[0].content[pos - 1] = atoi(argv[pos]);
		pos++;
	}
	if (argc <= 4)
		order_three(stacks);
	else if (argc >= 5)
		order_five(stacks);
	//printf("after stack_b %d\n", stacks[1].content[0]);
	//printf("after stack_b %d\n", stacks[1].content[1]);
	//printf("after stack_a %d\n", stacks[0].content[0]);
	//printf("after stack_a %d\n", stacks[0].content[1]);
	//printf("after stack_a %d\n", stacks[0].content[2]);
	free(stacks[0].content);
	free(stacks[1].content);
	return (0);
}
