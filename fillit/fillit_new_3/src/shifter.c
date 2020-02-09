/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:30:14 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/09 14:08:41 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		shift_axis(t_figure *figure, int n, char axis)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (axis == 'x')
			figure->coord_x[i] += n;
		if (axis == 'y')
			figure->coord_y[i] += n;
		i++;
	}
}

t_figure	*shift_top_left(t_figure *figure)
{
	while (figure->coord_x[0] != 0 && \
			figure->coord_x[1] != 0 && \
			figure->coord_x[2] != 0 && \
			figure->coord_x[3] != 0)
		shift_axis(figure, -1, 'x');
	while (figure->coord_y[0] != 0 && \
			figure->coord_y[1] != 0 && \
			figure->coord_y[2] != 0 && \
			figure->coord_y[3] != 0)
		shift_axis(figure, -1, 'y');
	return (figure);
}
