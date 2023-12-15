/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:21:50 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/14 22:01:19 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(char *operation, t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	write(1, operation, 3);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	ft_ra(char *operation, t_stack **head)
{
	t_stack	*last_node;
	t_stack	*aux;

	if (!*head || !(*head)->next)
		return ;
	write(1, operation, 3);
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

void	ft_rra(char *operation, t_stack **head)
{
	t_stack	*last_node;
	t_stack	*aux;

	if (!*head || !(*head)->next)
		return ;
	write(1, operation, 4);
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

void	ft_push(char	*operation, t_stack **dest, t_stack **src)
{
	t_stack	*push_element;

	if (!*src)
		return ;
	write(1, operation, 3);
	push_element = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_element->prev = NULL;
	if (!*dest)
	{
		*dest = push_element;
		push_element->next = NULL;
	}
	else
	{
		push_element->next = *dest;
		push_element->next->prev = push_element;
		*dest = push_element;
	}
}
