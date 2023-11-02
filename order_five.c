/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:48:57 by ghuertas          #+#    #+#             */
/*   Updated: 2023/11/02 01:07:38 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_five(char *operation, t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		write(1, "ra\n", 3);
		temp = stack->content[0];
		stack->content[0] = stack->content[1];
		stack->content[1] = stack->content[2];
		stack->content[2] = stack->content[3];
		stack->content[3] = stack->content[4];
		stack->content[4] = temp;
	}
}

void	just_order_first(t_stack stacks[2])
{
	int		*value;

	value = stacks[0].content;
	if (stacks[0].size < 6)
	{
		if (value[2] > value[0] && value[0] > value[1])
			ft_sa("SA", stacks);
		if (value[0] > value[2] && value[2] > value[1])
			ft_ra("RA", stacks);
		if (value[1] > value[0] && value[0] > value[2])
			ft_rra("RRA", stacks);
		if (value[0] > value[1] && value[1] > value[2])
		{
			ft_ra("RA", stacks);
			ft_sa("SA", stacks);
		}
		if (value[1] > value[2] && value[2] > value[0])
			ft_sa("SA", stacks);
	}
}

int	order_five(t_stack stacks[2])
{
	int		*value;

	value = stacks[0].content;
	if (stacks[0].size < 6)
	{
		if (value[0] > value[1] && value[0] > value[2]
			&& value[0] > value[3] && value[0] > value[4])
			ft_ra_five("ra", stacks);
		if (value[0] > value[1] && value[0] > value[2]
			&& value[0] > value[3] && value[0] < value[4])
			ft_ra_five("ra", stacks);
		if (value[1] > value[0] && value[1] > value[2]
			&& value[1] > value[3] && value[1] > value[4])
			ft_ra_five("ra", stacks);
		just_order_first(stacks);
		ft_push_b("pb", &stacks[0], &stacks[1]);
		ft_push_b("pb", &stacks[0], &stacks[1]);
		order_three(stacks);
		ft_push_a("pa", &stacks[0], &stacks[1]);
		ft_push_a("pa", &stacks[0], &stacks[1]);
	}
	if (is_sorted(stacks[0]))
		return (EXIT_SUCCESS);
	return (order_five(stacks));
}
