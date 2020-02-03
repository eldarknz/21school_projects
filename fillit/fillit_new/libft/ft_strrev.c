/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:35:32 by hkayla            #+#    #+#             */
/*   Updated: 2019/09/25 19:36:10 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		x;
	char	i;
	int		start;

	x = 0;
	start = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	while (start < x / 2)
	{
		i = str[x - 1 - start];
		str[x - 1 - start] = str[start];
		str[start] = i;
		start++;
	}
	return (str);
}
