/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:48:57 by ghuertas          #+#    #+#             */
/*   Updated: 2023/11/02 05:56:28 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(int	*value, int size)
{
	int	max_index;
	int	max_value;
	int	index;

	if (size <= 0)
		return (EXIT_FAILURE);
	max_index = 0;
	max_value = value[0];
	index = 1;
	while (index < size)
	{
		if (value[index] > max_value)
		{
			max_index = index;
			max_value = value[index];
		}
		index++;
	}
	return (max_index);
}

void	just_order_first(t_stack stacks[2])
{
	int		*value;

	value = stacks[0].content;
	if (stacks[0].size < 6)
	{
		if (value[2] > value[0] && value[0] > value[1])
			ft_sa("sa\n", stacks);
		if (value[0] > value[2] && value[2] > value[1])
			ft_ra("ra\n", stacks);
		if (value[1] > value[0] && value[0] > value[2])
			ft_rra("rra\n", stacks);
		if (value[0] > value[1] && value[1] > value[2])
		{
			ft_ra("ra\n", stacks);
			ft_sa("sa\n", stacks);
		}
		if (value[1] > value[2] && value[2] > value[0])
			ft_sa("sa\n", stacks);
	}
}

int	order_five(t_stack stacks[2])
{
	int		*value;
	int		max_index;

	if (is_sorted(stacks[0]))
		return (EXIT_SUCCESS);
	value = stacks[0].content;
	max_index = find_max_index(value, stacks[0].size);
	if (stacks[0].size < 6)
	{
		if (max_index == 0 || max_index == 1 || max_index == 2)
			ft_ra("ra\n", stacks);
		if (max_index == 0 || max_index == 1 || max_index == 2)
			ft_ra("ra\n", stacks);
		just_order_first(stacks);
		ft_push_b("pb\n", &stacks[0], &stacks[1]);
		ft_push_b("pb\n", &stacks[0], &stacks[1]);
		order_three(stacks);
		ft_push_a("pa\n", &stacks[0], &stacks[1]);
		ft_push_a("pa\n", &stacks[0], &stacks[1]);
	
	}
	return (order_five(stacks));
}
