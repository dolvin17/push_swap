/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:01:59 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/11 19:17:58 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500

void	random_nbr(int *nbrs, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		nbrs[i] = i + 1;
		++i;
	}
	i = size - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		temp = nbrs[i];
		nbrs[i] = nbrs[j];
		nbrs[j] = temp;
		--i;
	}
}

int	main(void)
{
	int	size;
	int	random_nbrs[MAX_SIZE];
	int	i;

	srand(time(NULL));
	size = 500;
	random_nbr(random_nbrs, size);
	i = 0;
	while (i < size)
	{
		printf("%d ", random_nbrs[i]);
		++i;
	}
	return (0);
}
