/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:34:48 by dolvin17          #+#    #+#             */
/*   Updated: 2024/04/10 15:42:32 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
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

int	check_dup(t_stack *stack_a, long nbr)
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

void	free_stack(t_stack **stack)
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

void	free_and_print_error(t_stack **stack_a)
{
	free_stack(stack_a);
	write(1, "Error\n", 6);
	exit(1);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
