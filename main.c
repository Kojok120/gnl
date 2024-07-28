/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:47:29 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/28 19:10:31 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

// int main()
// {
//     int fd1;
//     // int fd2;
//     // int fd3;
//     char *line;
//     // char *line2;
//     // char *line3;
//     int i;
//     int j;
    
//     i = 1;
//     j = 1;

//     fd1 = open("test.txt", O_RDONLY);
//     // fd2 = open("test_2.txt", O_RDONLY);
//     // fd3 = open("test_3.txt", O_RDONLY);
//     while (i)
//     {
//         line = get_next_line(fd1);
//         // line2 = get_next_line(fd2);
//         // line3 = get_next_line(fd3);
//         if (line == NULL)
//         {
//             printf("%s¥n", line);
//             i = 0;
//         }
//         else
//             printf("1 line: %d\n%s", j, line);
//         // if (line2 == NULL)
//         //     i = 0;
//         // else
//         //     printf("2 line: %d\n%s\n", j, line2);
//         // if (line3 == NULL)
//         //     i = 0;
//         // else
//         //     printf("3 line: %d\n%s\n", j, line3);
//         free(line);
//         // free(line2);
//         // free(line3);
//         j++;
//     }
//     close(fd1);
//     // close(fd2);
//     // close(fd3);
//     return (0);
// }

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main()
{
    int fd1;
    int fd2;
    int fd3;
    char *line;
    char *line2;
    char *line3;
    int i;
    int j;
    
    i = 1;
    j = 1;
    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("test_2.txt", O_RDONLY);
    fd3 = open("test_3.txt", O_RDONLY);
    while (i)
    {
        line = get_next_line(fd1);
        line2 = get_next_line(fd2);
        line3 = get_next_line(fd3);
        if (line == NULL)
            i = 0;
        else
            printf("1 line: %d\n%s\n", j, line);
        if (line2 == NULL)
            i = 0;
        else
            printf("2 line: %d\n%s\n", j, line2);
        if (line3 == NULL)
            i = 0;
        else
            printf("3 line: %d\n%s\n", j, line3);
        free(line);
        free(line2);
        free(line3);
        j++;
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}

// cc -Wall -Wextra -Werror  -D BUFFER_SIZE=0 get_next_line.c get_next_line_utils.c main.c
// ccw -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
// ccw -D BUFFER_SIZE=2147483646 get_next_line.c get_next_line_utils.c main.c
// ccw -D BUFFER_SIZE=2147483647 get_next_line.c get_next_line_utils.c main.c
