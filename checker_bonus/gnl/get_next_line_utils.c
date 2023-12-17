/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 03:17:21 by ghuertas          #+#    #+#             */
/*   Updated: 2023/12/17 17:27:17 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*s;
	int		len_str1;
	int		len_str2;

	len_str1 = 0;
	if (!str1 && !str2)
		return (NULL);
	while (str1 && str1[len_str1])
		len_str1++;
	len_str2 = 0;
	while (str2 && str2[len_str2])
		len_str2++;
	s = ft_calloc(len_str1 + len_str2 + 1, sizeof * s);
	if (!s)
		return (NULL);
	len_str1 = -1;
	while (str1 && str1[++len_str1])
		s[len_str1] = str1[len_str1];
	len_str2 = -1;
	while (str2 && str2[++len_str2])
		s[len_str1 + len_str2] = str2[len_str2];
	return (s);
}

char	*ft_strdup(const char *str1)
{
	char	*str2;
	int		size;

	if (!str1)
		return (ft_strdup(""));
	size = 0;
	while (str1[size])
		size++;
	str2 = ft_calloc(size + 1, sizeof * str2);
	if (!str2)
		return (NULL);
	size = 0;
	while (str1[size])
	{
		str2[size] = str1[size];
		size++;
	}
	return (str2);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = NULL;
	if (!count || (count && SIZE_MAX / count > size))
	{
		p = malloc(count * size);
		if (p != NULL)
		{
			i = 0;
			while (i < count * size)
				*(p + i++) = '\0';
		}
	}
	return (p);
}

void	ft_free_strs(char **str, char **str1, char **str2)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}
