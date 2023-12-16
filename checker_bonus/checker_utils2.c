/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 02:20:55 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/14 11:51:25 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_count_words(char *str, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == c)
			++str;
		while (*str != c && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		++cursor;
	while ((str[cursor + len] != c) && str[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		next_word[i++] = str[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *str, char c)
{
	int		nb_words;
	char	**res;
	int		i;

	i = 0;
	nb_words = ft_count_words(str, c);
	if (!nb_words)
		exit(1);
	res = malloc(sizeof(char *) * (size_t)(nb_words + 2));
	if (!res)
		return (NULL);
	while (nb_words-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ;
		}
		res[i++] = get_next_word(str, c);
	}
	res[i] = NULL;
	return (res);
}

int	ft_atoi(char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = sign * -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		iferror(num > INT_MAX, "Error\n");
		iferror(num < INT_MIN, "Error\n");
		str++;
	}
	return (num * sign);
}

bool	sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}