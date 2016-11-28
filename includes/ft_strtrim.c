/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 06:27:53 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/17 04:39:59 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		st;
	int		end;

	if (!s)
		return (NULL);
	st = 0;
	end = ft_strlen((char *)s) - 1;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	return ((end <= st) ? ft_strnew(1) : ft_strsub(s, st, end - st + 1));
}
