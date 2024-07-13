/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:00:13 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/13 22:52:55 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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


char    *get_next_line(int fd)
{
    static char *memo;
    char *line;
    char *buf;
    ssize_t ret;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (buf == NULL)
        return (NULL);
    if (memo == NULL)
        memo = ft_strdup("");
    while (!ft_strchr(memo, '\n') && ret > 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret <= 0)
        {
            free(buf);
            return (NULL);
        }
        buf[ret] = '\0';
        memo = ft_strjoin(memo, buf);
    }
    free(buf);
    if (ft_strchr(memo, '\n') == NULL)
    {
        line = ft_strdup(memo);
        free(memo);
        memo = NULL;
    }
    else
    {
        line = ft_substr(memo, 0, ft_strchr(memo, '\n') - memo + 1);
        memo = ft_strdup(ft_strchr(memo, '\n') + 1);
    }
    if (line != NULL)
        free(line);
    return (line);
}