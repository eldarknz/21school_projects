/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:29:33 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/09 17:23:30 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		neighbor_counter(char *buf, int i)
{
	int neighbor;

	neighbor = 0;
	if (i + 1 <= 18 && buf[i + 1] == '#')
		neighbor++;
	if (i - 1 >= 0 && buf[i - 1] == '#')
		neighbor++;
	if (i + 5 <= 18 && buf[i + 5] == '#')
		neighbor++;
	if (i - 5 >= 0 && buf[i - 5] == '#')
		neighbor++;
	return (neighbor);
}

int		character_counter(char *buf)
{
	int i;
	int count;
	int neighbor;

	neighbor = 0;
	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		if (buf[i] == '#')
		{
			neighbor += neighbor_counter(buf, i);
			count++;
		}
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (0);
	if (neighbor != 8 && neighbor != 6)
		return (0);
	return (count);
}

int		check_figure(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (character_counter(buf + i) != 4)
			return (0);
		i += 21;
	}
	return (1);
}
