/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 17:05:44 by hvasylie          #+#    #+#             */
/*   Updated: 2019/06/03 17:01:09 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int main(int ac, char **av)
{
    int i;
    int fd;
    int fd_2;
    char *line;

    i = 1;
    fd = open(av[1], O_RDONLY);
    while ((get_next_line(fd, &line)) == 1)
    {
        printf("[%d] %s\n", i++, line);
        free(line);
    }
    close(fd);
    fd_2 = open(av[2], O_RDONLY);
    while ((get_next_line(fd_2, &line)) == 1)
    {
        printf("[%d] %s\n", i++, line);
        free(line);
    }
    close(fd_2);
    return (ac);
}
