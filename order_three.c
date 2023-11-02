/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:46:52 by ghuertas          #+#    #+#             */
/*   Updated: 2023/11/01 23:54:17 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_three(t_stack stacks[2])
{
	int		*value;

	value = stacks[0].content;
	if (stacks[0].size < 4)
	{
		if (value[2] > value[0] && value[0] > value[1])
			ft_sa("SA", stacks);
		else if (value[0] > value[2] && value[2] > value[1])
			ft_ra("RA", stacks);
		else if (value[1] > value[0] && value[0] > value[2])
			ft_rra("RRA", stacks);
		else if (value[0] > value[1] && value[1] > value[2])
			ft_ra("RA", stacks);
		else if (value[1] > value[2] && value[2] > value[0])
			ft_sa("SA", stacks);
	}
	if (is_sorted(stacks[0]))
		return (EXIT_SUCCESS);
	return (order_three(stacks));
}
