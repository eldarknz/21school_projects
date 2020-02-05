/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:59:27 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/03 16:59:29 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		character_counter(char *buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (0);
	return (count);
}

int		neighbor_counter(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int		check(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (character_counter(buf + i) != 4)
			return (0);
		if (neighbor_counter(buf + i) != 6 && neighbor_counter(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
