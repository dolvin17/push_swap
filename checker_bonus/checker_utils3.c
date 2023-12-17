/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:17:26 by ghuertas          #+#    #+#             */
/*   Updated: 2023/12/17 17:27:27 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_atoi(char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = sign * -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		iferror(num > INT_MAX, "Error\n");
		iferror(num < INT_MIN, "Error\n");
		str++;
	}
	return (num * sign);
}

bool	sorted(t_stack *stack)
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

void	match_and_move2(t_stack **stack_a, t_stack **stack_b, char *l)
{
	if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\n')
		rra(stack_a);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\n')
		rra(stack_b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\n')
		rrr_both(stack_a, stack_b);
}
