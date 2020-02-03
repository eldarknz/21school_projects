/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:52:52 by hkayla            #+#    #+#             */
/*   Updated: 2019/09/25 17:42:29 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_word(const char *str, int i, char **result, char c)
{
	int		len;
	int		space;

	space = 0;
	len = 0;
	while (*str == c)
	{
		str++;
		space++;
	}
	while (str[len] && str[len] != c)
		len++;
	if (len > 0)
	{
		result[i] = ft_strnew(len);
		ft_strncpy(result[i], str, len);
	}
	return (space + len);
}

static int		ft_count_words(const char *str, int i, char c)
{
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str == c)
			str++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**result;
	int		i;
	int		word_cnt;

	if (!s)
		return (NULL);
	word_cnt = ft_count_words(s, 0, c);
	len = 0;
	result = (char **)ft_memalloc((word_cnt + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_find_word(s, i++, result, c);
		s += len;
	}
	result[word_cnt] = 0;
	return (result);
}
