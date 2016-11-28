/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 06:38:56 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/17 06:08:21 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_realloc2d(char **str)
{
    int     i;
    char    **tmp;

    tmp = (char **)ft_memalloc(ft_strlen((const char *)str) + 2);
	i = -1;
	while (str[i++])
		tmp[i] = str[i];
    free(str);
	tmp[i] = 0;
    return (tmp);
}

static char		*ft_realloc(char *str)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(ft_strlen(str) + 2);
	if (tmp)
		tmp = ft_strcpy(tmp, str);
	free(str);
	return (tmp);
}

static char		*ft_word(const char *s, char c, int i)
{
	char	*word;
	int		y;

	y = 0;
	word = ft_memalloc(1);
	if (word)
	{
		word[0] = s[i];
		while (s[i] != c && s[i] != '\0')
		{
			word = ft_realloc(word);
			word[y++] = s[i++];
		}
		word[y] = '\0';
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	y;
	char	*word;
	char	**split;

	y = 0;
	i = 0;
	if (!s || !c)
		return (NULL);
	split = ft_memalloc(1);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			word = ft_word(s, c, i);
			if (word)
			{
				split = ft_realloc2d(split);
				split[y++] = word;
				split[y] = 0;
				i = i + ft_strlen(word);
			}
		}
	}
	return (split);
}
