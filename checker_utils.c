/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 02:04:25 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/12 02:17:53 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if (str[i] == '+' || str[i] == '-' && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	if (str[i] <= '0' && str[i] >= '9')
		return (1);
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicated(t_stack *stack_a, long nbr)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->data == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	ft_free(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*pos;

	if (!stack)
		return ;
	pos = *stack;
	while (pos)
	{
		aux = pos->next;
		pos->data = 0;
		free(pos);
		pos = aux;
	}
	*stack = NULL;
}

void	free_and_print(t_stack **stack_a)
{
	ft_free(stack_a);
	write(1, "Error\n", 6);
	exit(1);
}

void	iferror(bool if_error, int value, char	*str)
{
	if (if_error)
	{
		errno = value;
		perror(str);
		exit(EXIT_FAILURE);
	}
}