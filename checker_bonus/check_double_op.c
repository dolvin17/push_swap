/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:36:25 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/13 15:39:34 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr_both(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	ra(stack_b);
}

void	rrr_both(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rra(stack_b);
}