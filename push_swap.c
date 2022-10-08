/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:24:39 by dolvin17          #+#    #+#             */
/*   Updated: 2022/10/08 11:58:57 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	chek_zero(char **argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

static	int	check_number(char **argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-' && argv[i + 1] != '\0')
		i++;
	while ((argv[i]) && (argv[i] >= '0' && argv[i] <= '9'))
		i++;
	if ((argv[i] != '\0') && (!(argv[i] >= '0' && argv[i] <= '9')))
		return (0);
	return (1);
}
static	int	check_dup(char **argv)
{
	int	i;
	int	j;

	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && argv[i] - argv[j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
static int	check_input(char **argv)
{
	int i;
	int nzeros;

	nzeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!check_number(argv[i]))
			return (0);
		nzeros = nzeros + chek_zero(argv[i]);
		i++;
	}
	if (nzeros > 1)
		return (0);
	if (check_dup(argv))
		return (0);
	return (1);
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	stack_size;

	if (argc < 2)
		return (0);
	if (!check_input(argv))
		return (42);
	stack_b = NULL;
	stack_a = 2, 3, 4;//funcion colocar valores en stack;
	stack_size = 3;// size del stack;
	return (0);
}
