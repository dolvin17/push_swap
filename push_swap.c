/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:24:39 by dolvin17          #+#    #+#             */
/*   Updated: 2023/10/14 21:26:16 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_three(t_stack stacks[2])
{
	int	*value;

	value = stacks[0].content;
	if (stacks[0].size < 4)
	{
		if (value[2] > value[0] && value[0] > value[1])
			printf("SA");
		else if (value[0] > value[2] && value[2] > value[1])
			printf("RA");
		else if (value[1] > value[0] && value[0] > value[2])
			printf("RRA");
		else if (value[0] > value[1] && value[1] > value[2])
			printf("RA SA");
		else if (value[1] > value[2] && value[2] > value[0])
			printf("PB SA PA");
	}
	else
		printf("entra");
	return (0);
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
		printf("input: %d\n", stacks[0].content[pos - 1]);
		pos++;
	}
	order_three(stacks);
	free(stacks[0].content);
	free(stacks[1].content);
	return (0);
}
