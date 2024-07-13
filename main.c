/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:47:29 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/13 22:47:04 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int main()
{
    int fd;
    char *line;
    int i;

    i = 1;
    fd = open("test.txt", O_RDONLY);
    while (i)
    {
        line = get_next_line(fd);
        if (line == NULL)
            i = 0;
        else
            printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
