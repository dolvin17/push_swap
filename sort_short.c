/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:21:50 by dolvin17          #+#    #+#             */
/*   Updated: 2023/10/25 22:18:06 by dolvin17         ###   ########.fr       */
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

void	ft_push_b(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	int	*temp;
	int	i;

	if (stack_a->size > 0)
	{
		write(1, "pb\n", 3);
		stack_b->size++;
		temp = (int *)malloc(sizeof(int) * stack_b->size);
		if (!temp)
			// Maneja el error de memoria si no se puede asignar.
			exit(1);
		temp[0] = stack_a->content[0];
		i = 1;
		while (i < stack_b->size)
		{
			temp[i] = stack_b->content[i - 1];
			i++;
		}
		free(stack_b->content);
		stack_b->content = temp;
		// Actualiza el tamaño y contenido del stack A.
		stack_a->size--;
		if (stack_a->size > 0)
		{
			temp = (int *)malloc(sizeof(int) * stack_a->size);
			if (!temp)
				exit(1);
			i = 0;
			while (i < stack_a->size)
			{
				temp[i] = stack_a->content[i + 1];
				i++;
			}
			free(stack_a->content);
			stack_a->content = temp;
		}
		else
		{
			free(stack_a->content);
			stack_a->content = NULL;
		}
	}
}

void	ft_push_a(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	int	*temp;
	int	i;

	if (stack_b->size > 0)
	{
		write(1, "pa\n", 3);
		stack_b->size++;
		temp = (int *)malloc(sizeof(int) * stack_a->size);
		if (!temp)
			// Maneja el error de memoria si no se puede asignar.
			exit(1);
		temp[0] = stack_b->content[0];
		i = 1;
		while (i < stack_a->size)
		{
			temp[i] = stack_a->content[i - 1];
			i++;
		}
		free(stack_a->content);
		stack_a->content = temp;
		// Actualiza el tamaño y contenido del stack A.
		stack_b->size--;
		if (stack_b->size > 0)
		{
			temp = (int *)malloc(sizeof(int) * stack_b->size);
			if (!temp)
				exit(1);
			i = 0;
			while (i < stack_b->size)
			{
				temp[i] = stack_b->content[i + 1];
				i++;
			}
			free(stack_b->content);
			stack_b->content = temp;
		}
		else
		{
			free(stack_b->content);
			stack_b->content = NULL;
		}
	}
}
