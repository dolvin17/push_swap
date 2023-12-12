/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 02:06:11 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/12 05:16:56 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>	/*USE write*/
# include <limits.h>	/*AVOID OVERFLOW*/
# include <stdio.h>		/*Testing*/
# include <stdlib.h>	/*Use Malloc, free, exit*/
# include <stdbool.h>	/*USE cheapest value*/
# include <errno.h>		/*print errors value*/
# include "./gnl/get_next_line.h"

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

//HANDLE ERRORS AGAIN
int		error_syntax(char *str);
int		error_duplicated(t_stack *stack_a, long nbr);
char	**split(char *str, char c);
int		ft_atoi(char *str);
void	ft_free(t_stack **stack);
void	free_and_print(t_stack **stack_a);
void	iferror(bool iferror, int value, char *str);
//
#endif
