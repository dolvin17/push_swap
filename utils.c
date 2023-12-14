/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:03:24 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/14 11:58:19 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checking(bool if_error, char	*str)
{
	if (if_error)
	{
		write(1, str, 7);
		exit(EXIT_FAILURE);
	}
}

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*max_value(t_stack *stack)
{
	long	max_value;
	t_stack	*max_index;

	if (!stack)
		return (NULL);
	max_value = LONG_MIN;
	while (stack)
	{
		if (stack->data > max_value)
		{
			max_value = stack->data;
			max_index = stack;
		}
		stack = stack->next;
	}
	return (max_index);
}

t_stack	*min_value(t_stack *stack)
{
	long	min_value;
	t_stack	*min_index;

	if (!stack)
		return (NULL);
	min_value = LONG_MAX;
	while (stack)
	{
		if (stack->data < min_value)
		{
			min_value = stack->data;
			min_index = stack;
		}
		stack = stack->next;
	}
	return (min_index);
}

int	check_len(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
