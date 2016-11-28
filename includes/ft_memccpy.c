/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:00:57 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/17 04:39:02 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((char *)src)[i - 1] != (unsigned char)c)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((char *)dest)[i] == (unsigned char)c)
			return (&(((char *)dest)[i + 1]));
		i++;
	}
	return (NULL);
}
