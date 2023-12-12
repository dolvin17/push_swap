/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_cheapest_stack_b.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:48:57 by ghuertas          #+#    #+#             */
/*   Updated: 2023/12/10 12:41:38 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack	*stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack *cheapest, t_stack	**stack_a, t_stack **stack_b)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		ft_rr("rr\n", stack_a, stack_b);
	set_and_check_pos(*stack_a);
	set_and_check_pos(*stack_b);
}

void	rev_rot_both(t_stack *cheapest, t_stack	**stack_a, t_stack **stack_b)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		ft_rrr("rrr\n", stack_a, stack_b);
	set_and_check_pos(*stack_a);
	set_and_check_pos(*stack_b);
}

void	ready_to_push(t_stack **stack, t_stack *top, char c)
{
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->top_half)
				ft_ra("ra\n", stack);
			else
				ft_rra("rra\n", stack);
		}
		else if (c == 'b')
		{
			if (top->top_half)
				ft_ra("rb\n", stack);
			else
				ft_rra("rrb\n", stack);
		}
	}
}

void	push_cheapest(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->top_half && cheapest_node->target->top_half)
		rotate_both(cheapest_node, stack_a, stack_b);
	else if (!(cheapest_node->top_half) && !(cheapest_node->target->top_half))
		rev_rot_both(cheapest_node, stack_a, stack_b);
	ready_to_push(stack_a, cheapest_node, 'a');
	ready_to_push(stack_b, cheapest_node->target, 'b');
	ft_push("pb\n", stack_b, stack_a);
}
