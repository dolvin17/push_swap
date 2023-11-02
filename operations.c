/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:21:50 by dolvin17          #+#    #+#             */
/*   Updated: 2023/11/02 04:06:16 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (++i < stack.size)
		if (stack.content[i - 1] > stack.content[i])
			return (0);
	return (1);
}

void	ft_sa(char *operation, t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		write(1, operation, 3);
		temp = stack->content[0];
		stack->content[0] = stack->content[1];
		stack->content[1] = temp;
	}
}

void	ft_ra(char *operation, t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->content[0];
	if (stack->size > 1)
	{
		while (i < stack->size -1)
		{
			stack->content[i] = stack->content[i + 1];
			i++;
		}
		stack->content[stack->size -1] = temp;
		write(1, operation, 3);
	}
}

void	ft_rra(char *operation, t_stack *stack)
{
	int	temp;
	int	size;

	size = stack->size - 1;
	temp = stack->content[stack->size -1];
	if (stack->size > 1)
	{
		while (size > 0)
		{
			stack->content[size] = stack->content[size - 1];
			size--;
		}
		stack->content[0] = temp;
		write(1, operation, 4);

	}
}

void	ft_push_b(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	int	*temp;
	int	i;

	if (stack_a->size > 0)
	{
		write(1, operation, 3);
		stack_b->size++;
		temp = (int *)malloc(sizeof(int) * stack_b->size);
		if (!temp)
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
		write(1, operation, 3);
		stack_a->size++;
		temp = (int *)malloc(sizeof(int) * stack_a->size);
		if (!temp)
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
