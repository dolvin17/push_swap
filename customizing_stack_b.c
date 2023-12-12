/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customizing_stack_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:48:57 by ghuertas          #+#    #+#             */
/*   Updated: 2023/12/11 19:16:47 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack	*stack_a, t_stack *stack_b)
{
	t_stack	*node_a;
	t_stack	*target_b;
	long	closest_big;

	while (stack_b)
	{
		closest_big = LONG_MAX;
		node_a = stack_a;
		while (node_a)
		{
			if (node_a->data > stack_b->data && node_a->data < closest_big)
			{
				closest_big = node_a->data;
				target_b = node_a;
			}
			node_a = node_a->next;
		}
		if (closest_big == LONG_MAX)
			stack_b->target = min_value(stack_a);
		else
			stack_b->target = target_b;
		stack_b = stack_b->next;
	}
}

void	customizing_stack_b(t_stack	*stack_a, t_stack *stack_b)
{
	set_and_check_pos(stack_a);
	set_and_check_pos(stack_b);
	set_target_b(stack_a, stack_b);
}

void	push_back_stack_a(t_stack	**stack_a, t_stack	**stack_b)
{
	ready_to_push(stack_a, (*stack_b)->target, 'a');
	ft_push("pa\n", stack_a, stack_b);
}
