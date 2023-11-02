/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:35:07 by dolvin17          #+#    #+#             */
/*   Updated: 2023/11/01 23:58:07 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define SA "sa"

typedef struct s_stack
{
	int	*content;
	int	size;
}	t_stack;

int		main(int argc, char **argv);
void	ft_sa(char *operation, t_stack *stack);
void	ft_ra(char *operation, t_stack *stack);
void	ft_rra(char *operation, t_stack *stack);
void	ft_push_b(char *operation, t_stack *stack_a, t_stack *stack_b);
void	ft_push_a(char *operation, t_stack *stack_a, t_stack *stack_b);
void	just_order_first(t_stack stacks[2]);
int		is_sorted(t_stack stack);
int		order_three(t_stack stacks[2]);
int		order_five(t_stack stacks[2]);

#endif