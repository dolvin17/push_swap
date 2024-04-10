/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:35:07 by dolvin17          #+#    #+#             */
/*   Updated: 2024/04/10 15:21:31 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>	/*USE write*/
# include <limits.h>	/*AVOID OVERFLOW*/
# include <stdio.h>		/*Testing*/
# include <stdlib.h>	/*Use Malloc, free, exit*/
# include <stdbool.h>	/*USE cheapest value*/
# include <errno.h>		/*print errors value*/
# include <string.h>	/*USE STRCHR*/

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_expense;
	bool			top_half;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

// Handle errors
char	**ft_split(char *str, char c);
int		long_atoi(char *str);
int		check_syntax(char *str);
int		check_dup(t_stack *stack_a, long nbr);
void	free_stack(t_stack **stack);
void	free_and_print_error(t_stack **stack_a);
char	*ft_strchr(const char *str, int c);
// Utils
void	checking(bool if_error, char *str);
t_stack	*max_value(t_stack *stack);
t_stack	*min_value(t_stack *stack);
bool	is_sorted(t_stack *stack);
int		check_len(t_stack *stack);
// Custom nodes
void	set_and_check_pos(t_stack	*stack);
void	ready_to_push(t_stack **stack, t_stack *top, char c);
void	customizing_stack_a(t_stack	*stack_a, t_stack *stack_b);
void	customizing_stack_b(t_stack	*stack_a, t_stack *stack_b);
void	push_cheapest(t_stack	**stack_a, t_stack	**stack_b);
void	push_back_stack_a(t_stack	**stack_a, t_stack	**stack_b);
// Operations
void	ft_sa(char *operation, t_stack **head);
void	ft_ra(char *operation, t_stack **head);
void	ft_rra(char *operation, t_stack **head);
void	ft_push(char	*operation, t_stack **dest, t_stack **src);
// Double Operations
void	ft_rr(char	*operation, t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(char	*operation, t_stack **stack_a, t_stack **stack_b);
// Algorithm
void	order_three(t_stack **stack_a);
void	order_biggest(t_stack **stack_a, t_stack **stack_b);

#endif