/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:46:52 by ghuertas          #+#    #+#             */
/*   Updated: 2023/12/11 18:17:24 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three(t_stack **stack_a)
{
	t_stack	*biggest_index;

	biggest_index = max_value(*stack_a);
	if (biggest_index == *stack_a)
		ft_ra("ra\n", stack_a);
	else if ((*stack_a)->next == biggest_index)
		ft_rra("rra\n", stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_sa("sa\n", stack_a);
}

void	order_biggest(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;

	len_stack_a = check_len(*stack_a);
	if (len_stack_a-- > 3 && !is_sorted(*stack_a))
		ft_push("pb\n", stack_b, stack_a);
	if (len_stack_a-- > 3 && !is_sorted(*stack_a))
		ft_push("pb\n", stack_b, stack_a);
	while (len_stack_a-- > 3 && !is_sorted(*stack_a))
	{
		customizing_stack_a(*stack_a, *stack_b);
		push_cheapest(stack_a, stack_b);
	}
	order_three(stack_a);
	while (*stack_b)
	{
		customizing_stack_b(*stack_a, *stack_b);
		push_back_stack_a(stack_a, stack_b);
	}
	set_and_check_pos(*stack_a);
	while ((*stack_a)->data != min_value(*stack_a)->data)
	{
		if (min_value(*stack_a)->top_half)
			ft_ra("ra\n", stack_a);
		else
			ft_rra("rra\n", stack_a);
	}
}
