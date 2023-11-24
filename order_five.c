/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:48:57 by ghuertas          #+#    #+#             */
/*   Updated: 2023/11/24 23:46:34 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	place_min_on_top(t_stack *stack_a)
{
	int	min_value;
	int	index;
	int	min_index;

	min_value = INT_MAX;
	min_index = -1;
	index = 0;
	while (index < stack_a->size)
	{
		if (stack_a->content[index] < min_value)
		{
			min_value = stack_a->content[index];
			min_index = index;
		}
		index++;
	}
	if (min_index != -1 && min_index != 0)
	{
		if (min_index <= stack_a->size / 2)
		{
			while (min_index-- > 0)
				ft_ra("ra\n", stack_a);
		}
		else
		{
			min_index = stack_a->size - min_index;
			while (min_index-- > 0)
				ft_rra("rra\n", stack_a);
		}
	}
	return (*stack_a);
}

t_stack	order_five(t_stack stacks[2])
{
	stacks[0] = place_min_on_top(&stacks[0]);
	if (is_sorted(stacks[0]))
		return (stacks[0]);
	ft_push_b("pb\n", &stacks[0], &stacks[1]);
	stacks[0] = place_min_on_top(&stacks[0]);
	ft_push_b("pb\n", &stacks[0], &stacks[1]);
	if (!is_sorted(stacks[0]))
		stacks[0] = order_three(&stacks[0]);
	ft_push_a("pa\n", &stacks[0], &stacks[1]);
	ft_push_a("pa\n", &stacks[0], &stacks[1]);
	return (stacks[0]);
}
