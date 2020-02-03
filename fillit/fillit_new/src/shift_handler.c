/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:01:59 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/24 16:02:13 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void        swap_char(char *c1, char *c2)
{
	char ch;

	ch = *c1;
	*c1 = *c2;
	*c2 = ch;
}

void		shift_left(char **fig, int size)
{
	int	i;
	int	j;
	int	left;
	int	flag;

	i = 0;
	left = 0;
	while (i < size)
	{
		j = 0;
		flag = 0;
		while (j < size)
		{
			if (fig[j][i] != '.')
			{
				swap_char(&fig[j][i], &fig[j][left]);
				flag++;
			}
			j++;
		}
		if (flag)
			left++;
		i++;
	}
}

static void shift_up(char **fig, int size)
{
	int	i;
	int	j;
	int	top;
	int	flag;

	i = 0;
	top = 0;
	while (i < size)
	{
		j = 0;
		flag = 0;
		while (j < size)
		{
			if (fig[i][j] != '.')
			{
				swap_char(&fig[i][j], &fig[top][j]);
				flag++;
			}
			j++;
		}
		if (flag)
			top++;
		i++;
	}
}

void        shift_top(t_figure *fig)
{
    shift_up(fig->figure, fig->size);
    shift_left(fig->figure, fig->size);
}
