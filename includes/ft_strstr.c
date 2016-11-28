/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 01:23:38 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/17 04:38:46 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *search)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!search[0])
		return (char *)(str);
	while (str[i])
	{
		if (str[i] == search[j])
		{
			while (search[j] == str[i + j])
			{
				j++;
				if (search[j] == '\0')
					return ((char *)&str[i]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}