/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:29:33 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/10 15:30:29 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (count != 8 && count != 6)
		return (0);
	return (count);
}

int		character_counter(char *buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (0);
	if (count != 4)
		return (0);
	return (1);
}

int		check_figure(char *buf)
{
	if (!character_counter(buf))
		return (0);
	if (!neighbor_counter(buf))
		return (0);
	return (1);
}
