/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customizing_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:48:57 by ghuertas          #+#    #+#             */
/*   Updated: 2023/12/14 22:01:02 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_and_check_pos(t_stack	*stack)
{
	int	current_position;
	int	media;

	if (!stack)
		return ;
	current_position = 0;
	media = check_len(stack) / 2;
	while (stack)
	{
		stack->index = current_position;
		if (current_position <= media)
			stack->top_half = true;
		else
			stack->top_half = false;
		stack = stack->next;
		current_position++;
	}
}

static	void	targeting_node(t_stack	*stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	closer_smallest;

	while (stack_a)
	{
		closer_smallest = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->data < stack_a->data
				&& current_b->data > closer_smallest)
			{
				closer_smallest = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closer_smallest == LONG_MIN)
			stack_a->target = max_value(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

static	void	checking_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = check_len(stack_a);
	stack_b_len = check_len(stack_b);
	while (stack_a)
	{
		stack_a->push_expense = stack_a->index;
		if (!(stack_a->top_half))
			stack_a->push_expense = stack_a_len - (stack_a->index);
		if (stack_a->target->top_half)
			stack_a->push_expense += stack_a->target->index;
		else
			stack_a->push_expense += stack_b_len - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

static	void	match_cheapest(t_stack	*stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_expense < cheapest_value)
		{
			cheapest_value = stack->push_expense;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	customizing_stack_a(t_stack	*stack_a, t_stack *stack_b)
{
	set_and_check_pos(stack_a);
	set_and_check_pos(stack_b);
	targeting_node(stack_a, stack_b);
	checking_cost(stack_a, stack_b);
	match_cheapest(stack_a);
}
