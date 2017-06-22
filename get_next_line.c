/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 01:04:41 by tiskow            #+#    #+#             */
/*   Updated: 2017/06/20 13:09:22 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int ft_strclen(char *tmp, char c)
{
	unsigned int i;

	i = 0;
	while (tmp[i] != c && tmp[i] != '\0')
		i++;
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	static char		*tmp[1023];
	char			buff[BUFF_SIZE + 1];
	char 			*ptr;
	int				res;
	
	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0 ||
		(!(tmp[fd]) && (tmp[fd] = ft_strnew(0)) == NULL))
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		ptr = tmp[fd];
		tmp[fd] = ft_strjoin(ptr, buff);
		free(ptr);
	}
	if (!ft_strlen(tmp[fd]))
		return (0);
	*line = ft_strsub(tmp[fd], 0, ft_strclen(tmp[fd], '\n'));
	if (ft_strchr(tmp[fd], '\n'))
		ft_strcpy(tmp[fd], ft_strchr(tmp[fd], '\n') + 1);
	else
		ft_strcpy(tmp[fd], ft_strchr(tmp[fd], '\0'));
	return (1);
}
