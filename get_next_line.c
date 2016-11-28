/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 01:04:41 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/26 06:20:14 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int ft_strclen(char *save)
{
	unsigned int i;

	i = 0;
	while (save[i] != '\n')
		i++;
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	static char		*tmp[1023];
	char			buff[BUFF_SIZE + 1];	
	int				res;
	
	if (!(tmp[fd]))
		tmp[fd] = ft_strnew(1);
	if (fd < 0 || !tmp[fd] || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buff);
	}
	*line = ft_strsub(tmp[fd], 0, ft_strclen(tmp[fd]));
	if (ft_strlen(tmp[fd]) > 0)
		if (ft_strcpy(tmp[fd], ft_strchr(tmp[fd], '\n') + 1))
			return (1);
	return (0);
}
