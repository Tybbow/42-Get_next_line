/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:09:46 by tiskow            #+#    #+#             */
/*   Updated: 2017/12/05 21:34:01 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	int fd;
	char *line;

	fd = open("/dev/random", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putstr(" LINE : ");
		ft_putstr(line);
		ft_putchar(10);
	}
	close(fd);
}