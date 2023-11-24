/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:46:52 by ghuertas          #+#    #+#             */
/*   Updated: 2023/11/24 22:16:55 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	order_three(t_stack stacks[2])
{
	int		*value;

	value = stacks[0].content;
	if (stacks[0].size < 4)
	{
		if (value[2] > value[0] && value[0] > value[1])
			ft_sa("sa\n", stacks);
		else if (value[0] > value[2] && value[2] > value[1])
			ft_ra("ra\n", stacks);
		else if (value[1] > value[0] && value[0] > value[2])
			ft_rra("rra\n", stacks);
		else if (value[0] > value[1] && value[1] > value[2])
			ft_ra("ra\n", stacks);
		else if (value[1] > value[2] && value[2] > value[0])
			ft_sa("sa\n", stacks);
	}
	if (is_sorted(stacks[0]))
		return (stacks[0]);
	return (order_three(stacks));
}
