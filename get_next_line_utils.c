/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:00:08 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/28 20:36:40 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*array;

	len = ft_strlen(s1);
	array = (char *)malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	if ((char)c == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

size_t	ft_min(size_t i, size_t j)
{
	if (i <= j)
		return (i);
	else
		return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	if (ft_strlen(s) < start)
		j = 0;
	else
		j = ft_strlen(s) - start;
	substr = (char *)malloc(ft_min(len, j) + 1);
	if (!substr)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
