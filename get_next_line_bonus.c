/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:00:13 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/28 19:06:37 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	array = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (array == NULL)
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i] = s2[j];
		j++;
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*init_memory(char **memo, int fd)
{
	char	*memory;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
	{
		if (*memo != NULL)
		{
			free(*memo);
			*memo = NULL;
		}
		return (NULL);
	}
	if (*memo == NULL)
		*memo = ft_strdup("");
	memory = (char *)malloc(BUFFER_SIZE + 1);
	if (!memory)
		return (NULL);
	return (memory);
}

char	*read_line(int fd, char **memo)
{
	char	*buf;
	ssize_t	ret;
	char	*temp;

	buf = init_memory(memo, fd);
	if (buf == NULL)
		return (NULL);
	ret = 1;
	while (!ft_strchr(*memo, '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buf);
			free(*memo);
			*memo = NULL;
			return (NULL);
		}
		buf[ret] = '\0';
		temp = ft_strjoin(*memo, buf);
		free(*memo);
		*memo = temp;
	}
	free(buf);
	return (*memo);
}

char	*extract_line(char **memo)
{
	char	*line;
	char	*temp;

	if (ft_strchr(*memo, '\n') == NULL)
	{
		if (**memo == '\0')
		{
			free(*memo);
			*memo = NULL;
			return (NULL);
		}
		line = ft_strdup(*memo);
		free(*memo);
		*memo = NULL;
	}
	else
	{
		line = ft_substr(*memo, 0, ft_strchr(*memo, '\n') - *memo + 1);
		temp = ft_strdup(ft_strchr(*memo, '\n') + 1);
		free(*memo);
		*memo = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memo[OPEN_MAX];

	if (read_line(fd, &memo[fd]) == NULL)
		return (NULL);
	return (extract_line(&memo[fd]));
}
