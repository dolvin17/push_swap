/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:35:07 by dolvin17          #+#    #+#             */
/*   Updated: 2023/10/16 21:35:34 by dolvin17         ###   ########.fr       */
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

#endif