/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:24:39 by dolvin17          #+#    #+#             */
/*   Updated: 2023/11/24 22:19:30 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	//printf("after stack_a pos cero %d\n", stacks[0].content[0]);
	//printf("after stack_a pos uno  %d\n", stacks[0].content[1]);
	//printf("after stack_a pos dos  %d\n", stacks[0].content[2]);
	//printf("after stack_a pos tres %d\n", stacks[0].content[3]);
	//printf("after stack_a pos cuat %d\n", stacks[0].content[4]);
	if (argc <= 4)
		order_three(stacks);
	else if (argc >= 5)
	{
		order_five(stacks);
	}
	/*
	printf("after stack B pos cero %d\n", stacks[1].content[0]);
	printf("after stack B pos uno  %d\n", stacks[1].content[1]);
	printf("after stack B pos dos  %d\n", stacks[1].content[2]);
	printf("after stack B pos tres %d\n", stacks[1].content[3]);
	printf("after stack B pos cuat %d\n", stacks[1].content[4]);
	printf("after stack_a pos cero %d\n", stacks[0].content[0]);
	printf("after stack_a pos uno  %d\n", stacks[0].content[1]);
	printf("after stack_a pos dos  %d\n", stacks[0].content[2]);
	printf("after stack_a pos tres %d\n", stacks[0].content[3]);
	printf("after stack_a pos cuat %d\n", stacks[0].content[4]);
	*/
	free(stacks[0].content);
	free(stacks[1].content);
	return (0);
}
