/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:21:50 by dolvin17          #+#    #+#             */
/*   Updated: 2023/10/16 21:18:14 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(char *operation, t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		write(1, "sa\n", 3);
		temp = stack->content[0];
		stack->content[0] = stack->content[1];
		stack->content[1] = temp;
	}
}

void	ft_ra(char *operation, t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		write(1, "ra\n", 3);
		temp = stack->content[0];
		stack->content[0] = stack->content[1];
		stack->content[1] = stack->content[2];
		stack->content[2] = temp;
	}
}

void	ft_rra(char *operation, t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		write(1, "rra\n", 4);
		temp = stack->content[0];
		stack->content[0] = stack->content[2];
		stack->content[2] = stack->content[1];
		stack->content[1] = temp;
	}
}
