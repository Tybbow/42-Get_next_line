/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 01:51:54 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/17 04:38:37 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!search)
		return ((char *)str);
	while (str[i] || i < n)
	{
		if (str[i] == search[j])
		{
			while (str[i + j] == search[j])
			{
				j++;
				if (search[j] == '\0')
					return ((char *)&str[i + j]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}