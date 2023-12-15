/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:21:50 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/14 22:00:57 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*last_node;
	t_stack	*aux;

	if (!*head || !(*head)->next)
		return ;
	aux = *head;
	while (aux->next)
		aux = aux->next;
	last_node = aux;
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

static	void	reverse_rotate(t_stack **head)
{
	t_stack	*last_node;
	t_stack	*aux;

	if (!*head || !(*head)->next)
		return ;
	aux = *head;
	while (aux->next)
		aux = aux->next;
	last_node = aux;
	last_node->prev->next = NULL;
	last_node->next = *head;
	last_node->prev = NULL;
	*head = last_node;
	last_node->next->prev = last_node;
}

void	ft_rr(char	*operation, t_stack **stack_a, t_stack **stack_b)
{
	write(1, operation, 3);
	rotate(stack_a);
	rotate(stack_b);
}

void	ft_rrr(char	*operation, t_stack **stack_a, t_stack **stack_b)
{
	write(1, operation, 4);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
