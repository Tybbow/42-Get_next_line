/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 05:07:21 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/17 06:03:03 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t 	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t			intlen;
	unsigned int 	nb;
	char			*tmp;
	
	nb = (n < 0) ? -n : n;
	intlen = ft_intlen(nb);
	tmp = ft_strnew(intlen);
	if (!tmp)
		return (NULL);
	while (nb)
	{
		tmp[intlen--] = (nb % 10 + 48);
		nb = nb / 10;
	}
	tmp[intlen] = (n == 0) ? '0' : '-';
	tmp = (n > 0) ? ft_strdup(&tmp[intlen + 1]) : tmp;
	return (tmp);
}